
# 进程--任务控制的基本单位
## 新建进程
* fork(): 父子进程的执行顺序不确定
* vfork(): 在子进程退出或执行exec之前, 父进程处于不可被信号打断的休眠状态
* 将继承父进程的进程组, 会话

## 修改进程
* PID 无法变化

## 销毁进程
* 将向父进程发送信号 SIGCHLD, 内核会保存退出状态
* 如果此进程是该进程组的最后一个进程, 此进程退出后, 该进程组消失
* 如果此进程是该会话的最后一个进程, 此进程退出后, 该会话消失

## 其他特性
* 启动命令: 完整的启动命令, 包括路径和参数, 如果是符号链接, 只会记录和展示符号本身
* 进程名称: 启动名称去掉路径和参数, 查找或输出时, 只会使用前 15 位(一般使用15位足够了)
* 一个进程只能属于一个父进程
* 一个父进程可以有多个子进程
* 一个进程只能属于一个进程组
* 一个进程只能属于一个会话
* 实际用户和组
* 有效用户和组
* 保存用户和组
* 文件用户和组, 一般和有效的用户相同
* 附属组
* 优先级

## 进程状态及改变
* 就绪
* 运行(R)
* 休眠(S)(可被信号打断)(指被捕获的信号)
    * pause() 只有收到未忽略的信号才返回
    * sleep() 只有收到未忽略的信号 或 到达指定秒数才返回 -- 01.cc
        1. 使用 fork() 产生子进程
        2. 子进程设置信号(SIGUSR1)处理函数
        3. 子进程休眠10s
        4. 父进程休眠1s
        5. 此时, 可以看到, 子进程处于休眠状态
        6. 向子进程发送信号(SIGUSR1)
        7. 此时, 子进程被唤醒(休眠时间小于10s)
* 休眠(D)(不可被信号打断)(指被捕获的信号)
   * 调用 vfork() 后的父进程 -- 02.cc
        1. 使用 fork() 产生测试的父进程
        2. 测试的父进程设置信号(SIGUSR1)处理函数
        3. 测试的父进程使用 vfork() 产生测试的子进程
        4. 测试的子进程休眠10s
        5. 测试的父进程休眠1s
        6. 此时, 可以看到, 测试的父进程处于不可被打断的状态
        7. 向测试的父进程发送信号(SIGUSR1)
        8. 此时, 父进程处于不可打断的状态, 所以不会处理
        9. 测试的子进程休眠完成(休眠时间为10s)
        10. 测试的父进程处理信号, 直到结束
   * SIGSTOP 也会被阻塞 -- 03.cc
        1. 使用 fork() 产生测试的父进程
        2. 测试的父进程使用 vfork() 产生测试的子进程
        3. 测试的子进程休眠10s
        4. 测试的父进程休眠1s
        5. 此时, 可以看到, 测试的父进程处于不可被打断的状态
        6. 向测试的父进程发送信号(SIGSTOP)
        7. 此时, 父进程处于不可打断的状态, 所以不会处理
        8. 向测试的父进程发送信号(SIGCONT)
        9. 此时, 父进程处于不可打断的状态, 所以不会处理
        10. 测试的子进程休眠完成(休眠时间为10s)
        11. 测试的父进程继续运行, 直到结束
   * SIGKILL 不会被阻塞 -- 04.cc
        1. 使用 fork() 产生测试的父进程
        2. 测试的父进程使用 vfork() 产生测试的子进程
        3. 测试的子进程休眠10s
        4. 测试的父进程休眠1s
        5. 此时, 可以看到, 测试的父进程处于不可被打断的状态
        6. 向测试的父进程发送信号(SIGKILL)
        7. 测试的父进程退出
        8. 测试的子进程休眠完成(休眠时间为10s)
        9. 主进程结束
* 暂停(T)(作业控制)
    * 收到信号 SIGSTOP
    * 收到信号 SIGTSTP, 可由 ctrl+z 产生
    * 收到信号 SIGTTIN, 处于后台进程时读终端
    * 收到信号 SIGTTOT, 处于后台进程时写终端, 这个得看设置是否允许后台进程写终端
    * 继续, 收到信号 SIGCONT -- 05.cc
        1. 使用 fork() 产生子进程
        2. 子进程设置信号(SIGUSR1)处理函数
        3. 子进程空循环
        4. 父进程发送信号给子进程(SIGSTOP)
        5. 子进程暂停
        6. 父进程发送信号给子进程(SIGUSR1)
        7. 此时, 子进程处于暂停, 不会处理该信号
        8. 父进程发送信号给子进程(SIGCONT)
        9. 子进程继续, 然后处理 SIGUSR1, 直到结束
* 暂停(t)(由于 DEBUG 产生)
* 空闲(I)
    * 处于不可被打断的休眠状态时, 有时 CPU 是空闲的
* 僵尸(Z)
    * 子进程已退出, 父进程还未处理
* 退出(X)

## proc 文件
```
/proc/loadavg     # 系统负载
/proc/cpuinfo     # cpu 信息
/proc/uptime      # 运行时间
/proc/sys

/proc/PID/cmdline # 完整的启动命令
                  # 如果以符号链接启动, 将存储符号链接本身
/proc/PID/comm    # 进程名称, 不包含路径名称, 最多 15 位
                  # 如果以符号链接启动, 将存储符号链接本身
/proc/PID/cwd     # 进程当前的目录
/proc/PID/exe     # 符号链接, 指向运行的进程
/proc/PID/environ # 进程使用的环境变量
/proc/PID/fd      # 进程所打开的文件描述符
/proc/PID/limits  # 进程对各种资源的限制
/proc/PID/task    # 进程使用的线程情况
```

## 常用命令
```
kill         pid # 通过进程ID发送信号给进程或进程组
kill -signal pid # 指定信号，默认值为 SIGTERM
kill -l          # 列出所有信号

killall             # 通过进程名称发送信号给进程或进程组, 进程名称精确匹配
killall -l          # 列出所有信号
killall -o 2m a.out # 发给 2 分钟前启动的 a.out
killall -y 2m a.out # 发给 2 分钟内启动的 a.out
killall -w    a.out # 等待进程结束

pkill         ... # 杀死进程, 扩展的正则表达式，参数和 pgrep 类似 -- 常用
pkill -signal ... # 指定信号，默认值为 SIGTERM

nohup sleep 1000 & # 脱离终端, 在后台运行, 忽略信号 SIGHUP

                             # 多个命令之间取或
ps -U RUID -G RGID           # 实际的用户和组
ps -u EUID -g EGID           # 有效的用户和组
ps -p PID                    # 进程ID, 多个进程可以重复使用 -p 或者参数以分号分割 -- 常用
ps -s SID                    # 会话ID
ps --ppid PPID               # 父进程ID
ps -t ...                    # 终端
ps -C vim                    # 进程名称, 全名称 或 前 15 位

ps -o ruid,ruser,rgid,rgroup # 实际的用户和组
ps -o euid,euser,egid,egroup # 有效的用户和组
ps -o suid,suser,sgid,sgroup # 保存的用户和组
ps -o fuid,fuser,fgid,fgroup # 文件的用户和组, 一般和有效的相同
ps -o supgid,supgrp          # 附属组ID
ps -o pid,ppid,pgid,sid      # 进程ID, 父进程ID, 进程组ID, 会话ID
ps -o ouid                   # 会话ID所属用户ID
ps -o tty                    # 终端
ps -o tpgid                  # 输出前台进程的ID
ps -o luid,lsession          # 终端登录的用户ID和会话ID
ps -o stat,state             # 进程状态
                             # R 正在运行
                             # S 正在休眠(可被打断)
                             # D 正在休眠(不可被打断)
                             # T 后台暂停的作业
                             # t debug 调试中
                             # Z 僵尸进程
ps -o pmem,rsz,vsz           # 内存百分比,内存,内存(含交换分区)
ps -o pcpu,c,bsdtime,cputime # cpu: 百分比,百分比整数,user+system,system
ps -o lstart,etime,etimes    # 启动时间,运行时间,运行时间(秒), 无法对 etimes 进行排序
ps -o nice,pri,psr,rtprio    # 优先级
ps -o wchan                  # 进程休眠, 返回当前使用的内核函数
                             # 进程运行, 返回 -
                             # 列出线程, 返回 *
ps -o cmd                    # 启动命令
ps -o comm                   # 进程名称
ps -o fname                  # 进程名称的前 8 位

ps -e           # 所有进程
ps -H           # 输出进程树
ps -ww          # 不限制输出宽度
ps --no-headers # 不输出列头部
ps --headers    #   输出列头部
ps --sort -pcpu # cpu 使用率逆序

ps -o lwp,nlwp # 线程ID, 线程数
ps -L          # 列每一个线程

pstree     [PID] # 以进程 PID 为根画进程树, 默认为 1
pstree  -c [PID] # 展示所有子树
pstree  -p [PID] # 展示进程ID
pstree  -g [PID] # 展示进程组ID
pstree  -n [PID] # 使用 PID 排序而不是 进程名称
pstree  -l [PID] # 使用长行, 方便写入文件

              # 多个命令之间取且
pgrep         # 使用进程名称查找, 使用扩展的正则表达式
pgrep -f  ... # 使用启动命令匹配, 默认使用进程名称匹配(最多15位)
pgrep -c  ... # 输出匹配到的进程数目           -- 常用
pgrep -d，... # 设置输出的分割符，默认是换行符 -- 常用
pgrep -i  ... # 忽略大小写
pgrep -l  ... # 列出进程名称(最多15位)         -- 常用
pgrep -a  ... # 列出启动命令                   -- 常用
pgrep -n  ... # 仅列出最新的进程
pgrep -o  ... # 仅列出最旧的进程
pgrep -g  ... # 指定进程组ID
pgrep -G  ... # 指定实际组ID
pgrep -P  ... # 指定父进程ID
pgrep -s  ... # 指定会话ID
pgrep -t  ... # 指定终端
pgrep -u  ... # 指定有效用户ID
pgrep -U  ... # 指定实际用户ID
pgrep -v  ... # 反转结果
pgrep -x  ... # 精确匹配，默认不需要完全匹配
pgrep -w  ... # 列出线程ID

pidof    # 进程名称 => PID, 精确匹配, 没有长度限制
pwdx pid # 列出进程的当前工作目录

setsid # 以新的 session 执行命令

top     # 第一行 系统时间 运行时间 用户数 平均负载
        # 第二行 进程总结
        # 第三行 CPU 总结
        # 第四行 物理内存总结
        # 第五行 虚拟内存总结
        # 交互命令
        #   空格 或 回车 刷新
        #   l 切换负载的显示
        #   t 切换任务的显示
        #   m 切换内存的显示
        #   f 选择展示的字段
        #   R 反向排序
        #   c 显示命令名称 或 完整命令行
        #   i 显示空闲任务
        #   u 显示特定用户的进程
        #   k 结束任务
        #   h 帮助
        #   L 搜索字符串
        #   H 显示线程
        #   0 不显示统计值为 0 的项
        #   1   显示所有的cpu信息
        #   < 排序字段左移
        #   > 排序字段右移
        #   M 内存排序
        #   P CPU 排序
        #   T 时间排序
top -n 1   # 刷新次数
top -b     # 方便写入文件
top -c     # 显示完整命令行
top -p ... # 指定 PID
top -u lyb # 指定用户

c++filt  a.out   # 可以解析动态库里的符号

g++ -0g main.cc
g++ -01 main.cc
g++ -02 main.cc
g++ -03 main.cc
g++ -g  main.cc   # 生成 gdb 的文件

gdb [a.out] [pid]            # 启动 gdb               -- 常用
gdb> file a.out              # 设置可执行文件         -- 常用
gdb> set args	             # 设置程序启动命令行参数 -- 常用
gdb> show args	             # 查看设置的命令行参数
gdb> run [arguments]         # 运行程序(r)            -- 常用
gdb> attach pid              # gdb 正在运行的程序     -- 常用
gdb> info breakpoints        # 列出断点信息(i)        -- 常用
gdb> break file:line         # 在指定行设置断点(b)    -- 常用
gdb> break function          # 在制定函数设置断点(b)
gdb> break function if b==0  # 根据条件设置断点(b)
gdb> tbreak file:line        # 在指定行设置临时断点(tb)
gdb> disable breakpoints num # 禁用断点 num          -- 常用
gdb>  enable breakpoints num # 启用断点 num          -- 常用
gdb>  delete breakpoints num # 删除断点 num
gdb> clear   line            # 清除指定行的断点
gdb> continue [num]          # 继续运行到指定断点(c) -- 常用
gdb> until     line          # 运行到指定行(u)       -- 常用
gdb> jump      line          # 跳转到指定行(j), 和 until 的区别是跳过的代码不会执行
gdb> next     [num]          # 继续运行多次(n)       -- 常用
gdb> step                    # 进入函数(s)           -- 常用
gdb> finish                  # 退出函数(fin), 会执行完当前函数 -- 常用
gdb> return ...              # 退出函数, 并指定返回值, 和 finish 的区别是不会继续执行之后的代码, 直接返回
gdb> print v                 # 输出变量的值(p)       -- 常用
gdb> print v=123             # 修改变量的值(p)
gdb> p *pointer              # 输出指针指向的值
gdb> p arr[1]@3              # 输出数组 arr[1] 开始的3个元素
gdb> p/t var                 # 按  二进制格式显示变量
gdb> p/o var                 # 按  八进制格式显示变量
gdb> p/d var                 # 按  十进制格式显示变量
gdb> p/u var                 # 按  十进制格式显示无符号整型
gdb> p/x var                 # 按十六进制格式显示变量
gdb> p/a var                 # 按十六进制格式显示地址
gdb> p/c var                 # 按字符格式显示变量
gdb> p/f var                 # 按浮点数格式显示变量
gdb> p/s var                 # 字符串
gdb>         display v       # 和 p 类似, 但后续会自动输出变量的值
gdb> disable display num     # 暂时取消输出
gdb>  enable display num     # 恢复输出
gdb>  delete display num     # 删除自动输出变量的值的编号
gdb>       undisplay num     # 删除自动输出变量的值的编号
gdb> info    display         # 列出自动打印变量的值
gdb> x/8xb &v                # 输出 double 的二进制表示 -- 常用
gdb> x/nfu  v                # n 表示打印多少个内存单元
                             # f 打印格式, x d u o t a c f(默认8位)
                             # u 内存单元, b=1 h=2 w=4 g=8
                             # x 和 p 的区别
                             #   * p 的参数是变量的值, x 的参数是变量的地址
                             #   * p 打印的单位长度即是变量的长度, x 可以指定单位长度
                             #   * x 可以打印连续的多个单位长度(这个可以方便看 double 的每一个字节的内容)
gdb> list                    # 显示当前行之后的源程序(l) -- 常用
gdb> list -                  # 显示当前行之前的源程序
gdb> list 2,10               # 显示 2 - 10 行的源程序
gdb>  set listsize 20        # 设置列出源码的行数
gdb> show listsize           # 输出列出源码的行数
gdb> set  print elements 0   # 设置打印变量长度不受限制 -- 常用
gdb> show print elements
gdb> backtrace               # 显示堆栈信息(bt)        -- 常用
gdb> frame     n             # 查看指定层的堆栈信息(f) -- 常用
gdb> thread	                 # 切换到指定线程
gdb> watch	                 # 监视某一个变量的值是否发生变化
gdb> ptype	                 # 查看变量类型

strace               # 追踪进程的系统调用和信号处理
strace cmd argv      # strace 和命令 同时启动
strace -p pid        # 追踪正在运行的程序, 多个进程, 指定 -p 多次
strace -c            # 统计系统调用的时间, 次数
strace -o ...        # 输出到指定的文件
strace -tt           # 显示调用时间 时分秒.毫秒
strace -T            # 显示系统调用的耗时
strace -f            # 跟踪子进程, 不包括 vfork
strace -F            # 跟踪 vfork
strace -e trace=...  # 跟踪指定信号调用
strace -s ...        # 参数是字符串时, 最大输出长度, 默认是32个字节
strace -e signal=... # 跟踪指定信号
```

## 建议
* 使用 pgrep 获取 PID, 使用 ps 列出详细信息
* 使用 etimes 可以方便计算出启动时间, 并格式化 年-月-日 时-分-秒 时区
* 一般使用进程的前 15 位即可
* 使用 pkill 发送信号
