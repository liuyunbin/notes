
## 使用
```
$ sudo apt install libreadline-dev # 安装依赖
$ make                             # 编译
$ ./a.out                          # 使用
```

## 功能
1. 支持管道, 重定向, 作业控制

## 程序流程
### 1. 初始化
1. 初始化内置命令
2. 忽略终端信号: SIGINT SIGQUIT SIGTSTP
3. 设置信号处理: SIGCHLD
    * 子进程暂停 继续 或 退出时, 父进程更新对应的数据结构
    * 如果某一作业是前台进程组, 且当前的作业的所有进程都停止或暂停, 修改主进程为前台进程组

### 2. 主流程
1. 设置输入提示符
2. 读取用户输入
3. 解析用户输入
    * 判断是否为后台命令
    * 以管道作为分割符解析用户输入, 并存储其重定向的文件
4. 如果用户输入无管道, 重定向 且是内置命令, 直接在当前进程运行即可
5. 阻塞信号 SIGCHLD, 避免在处理用户命令时, SIGCHLD 造成状态混乱
6. 如果还有下一条命令, 新建管道, 用于命令之间数据交互
7. fork() 子进程
    * 子进程设置新的进程组
    * 如果还有下一条命令, 将标准输出重定向到管道
    * 恢复信号处理 SIGINT SIGQUIT SIGTSTP SIGCHLD
    * 解阻塞信号 SIGCHLD
    * 执行命令
8. 父进程存储子进程信息
9. 父进程设置子进程的进程组
10. 如果还有下一条命令, 将标准输入重定向到管道, 重复 6-9
11. 否则, 将标准输入重定向到终端
12. 如果是前台作业, 父进程将子进程的进程组设置为前台进程组, 并等待前台进程组的改变
13. 否则, 列出后台作业
14. 解除信号 SIGCHLD 阻塞
15. 检测并处理目前已完成的作业, 并修改对应的数据结构
16. 最后跳转到 1
