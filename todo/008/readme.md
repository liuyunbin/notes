
## 为什么存在用户?
* 要登录一个系统, 肯定需要一个名称, 用以区分不同的用户

## 为什么存在组?
* 为了多个用户之间共享数据

## 用户, 用户名称, 用户ID, 组, 组名称, 组ID之间的关系
* 用户和用户名称一一对应, 组和组名称一一对应
* 一个用户只能对应一个用户ID, 一个组只能对应一个组ID
* 多个用户可以对应一个用户ID, 多个组可以对应一个组ID
* 一个用户可以对应多个组, 但只能有一个主组

## 用户名称和组名称有什么限制?
* 只能包含 大小写字母 数字 下划线 短横线 小数点, 末尾可以有 $
* 短横线不能在开头, 用以区分可选项和名称
* . 和 .. 不允许
* 不能重复
* 不能是纯数字, 因为一些命令同时接受 ID 和名称的形式
* 长度最多 32 位

## 为什么存在用户ID和组ID?
* 节省空间
* 提高比较的效率

## 用户ID和组ID有什么限制
* 必须大于等于 0
* 0 一般是 root 使用

## 用户的属性
* 用户名称, 用户ID, 组名称, 组ID, 附属组ID
* 主目录, 主目录模板
* 默认 shell
* 用户过期日期
* 锁定用户, 解锁用户
* 密码过期到临时不可用的时间
* 密码修改的最小最大间隔, 警告天数
* UID GID 的值一般默认即可, 不需要特殊设置

## 当前终端的登录用户
* 经过终端或伪终端登录后, 不会再变化

## 当前终端的有效用户
* 经过终端或伪终端登录后, 通过 su 可再变化

## 配置文件
```
/etc/passwd          # 用户基本信息
/etc/shadow          # 用户密码信息
/etc/group           # 组基本信息
/etc/gshadow         # 组密码信息
/etc/default/useradd # useradd 默认配置
/etc/skel/           # 默认主目录模板
/etc/subgid          # 用户隶属的 GID
/etc/subuid          # 用户隶属的 UID
/etc/login.defs      # 有关登录的配置信息
```

## 相关命令
```
useradd           # 添加用户或修改默认配置
useradd -c ...    #   指定关于用户的一段描述
useradd -e ...    #   指定用户过期日期, YYYY-MM-DD
useradd -f ...    #   指定用户密码过期到账户临时不可用的天数
useradd -g ...    #   指定主组, 主组必须存在
useradd -G ...    #   指定附属组, 附属组必须存在, 可以多个, 以逗号分割
useradd -k ...    #   指定主目录模板, 如果主目录由 useradd 创建, 模板目录中的文件将拷贝到新的主目录中
useradd -K ...    #   修改默认参数
useradd -s ...    #   指定shell
useradd -D        #   查看默认配置
useradd -D ...    #   修改默认配置
useradd    -b ... #   指明主目录的父目录, 父目录必须存在
useradd -m -b ... #   指明主目录的父目录, 父目录不必存在, 会自动新建
useradd    -d ... #   指明主目录, 主目录可以不存在, 不存在的话不会新建
useradd -m -d ... #   指明主目录, 主目录可以不存在, 不存在的话会自动新建
useradd -m ...    #   用户主目录不存在的话自动新建
useradd -M ...    #   用户主目录不会新建
useradd -N ...    #   不创建和用户同名的组
useradd -o ...    #   允许 UID 重复
useradd -r ...    #   创建系统用户
useradd -u ...    #   指定 UID 的值
useradd -U ...    #   创建和用户同名的组

userdel    ...    # 删除用户
userdel -r ...    #   删除用户及其主目录

usermod           # 修改用户
usermod -a -G ... #   添加附属组
usermod -m ...    #   移动主目录
usermod -l ...    #   修改登录名
usermod -L ...    #   锁定用户
usermod -U ...    #   解锁用户
                  #   其他选项同 useradd

newusers          # 批量新增用户

passwd            # 修改 root 密码
passwd -stdin     # 修改 root 密码, 从标准输入读取
passwd        lyb # 修改 lyb  密码

chage            # 修改密码相关信息
chage -d ... lyb # 设置上次密码修改的日期
chage -d 0   lyb # 下次登录必须修改密码
chage -E ... lyb # 设置密码过期的日期
chage -I ... lyb # 设置密码过期到账户被锁的天数
chage -m ... lyb # 设置密码修改的最小间隔
chage -M ... lyb # 设置密码修改的最大间隔
chage -W ... lyb # 设置密码过期前的警告的天数
chage -l     lyb # 列出密码相关信息

chfn             # 修改个人信息, 手机号之类
chsh -s ...      # 修改默认的 shell
chsh -l          # 列出所有支持的 shell

groups    # 列出用户所属的组名称
groupadd  # 添加组
groupmod  # 修改组信息, 包括组的ID和组名称
groupdel  # 删除组
groupmems # 管理当前用户的主组, 新增或删除成员
gpasswd   # 管理组, 新增或删除成员, 删除密码, 设置组管理人员等
newgrp    # 切换组
sg        # 使用其他组执行命令

su        # 切到 root
su -      # 切到 root, 更新主目录, 环境变量等, 相当于重新登录
su   lyb  # 切到 lyb

sudo                                          # 权限管理文件: /etc/sudoers, 使用 visudo 编辑
sudo -u USERNAME COMMAND                      # 指定用户执行命令
sudo -S date -s "20210722 10:10:10" <<< "123" # 脚本中免密码使用

sudoedit ...                                  # 编辑文件

users  # 列出所有登陆用户

w      # 列出谁登录, 以及目前在干什么
who    # 列出谁登录
who -m # 列出当前终端登录的用户
whoami # 列出当前终端的有效用户

id        # 输出实际或有效的用户和组信息

last      # 列出最近保存的登录的信息
lastb     # 列出最近保存的登录的信息, 包括失败情况

lastlog           # 列出最近一次的登录信息
lastlog -b 10     # 最近一次的登录在 10 天前的信息
lastlog -t 10     # 最近一次的登录在 10 天内的信息
lastlog -C -u lyb # 清除 lyb 最近一次的登录信息
lastlog -S -u lyb # 设置 lyb 最近一次的登录信息
lastlog    -u lyb # 查看 lyb 最近一次的登录信息
```
