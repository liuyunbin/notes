
#### 程序简介：
本目录下的程序，用来实现和测试 echo 回射服务器

#### 安装 libevent
```
apt install libevent-dev
```

#### 程序说明：
echo 回射服务器只是简单的将客户端发送来的数据，返回给客户端

#### 需要考虑的问题：
1. 如何处理恶意客户端只发送，不接收的情况？
2. 如何处理客户先发送数据，然后关闭 socket 的写端，然后，读数据的情况？
3. 如何处理客户端长期不发数据的情况？

#### 本目录实现的服务器：

第一种：

实现了一个多进程的 echo 服务器，即，每个客户端建立一个进程，
* 添加了写超时，用于处理恶意用户
* 使用了 TCP 层的 KEEPALIVE，使得客户端长期无数据时，自动踢掉客户端
* 捕获信号 SIGCHLD, 避免产生僵尸进程
* 捕获信号 SIGPIPE, 避免服务器意外退出

见 [echo_fork](./echo_fork.cc)

第二种：

利用 libevent 实现了一个单线程的非阻塞 IO 的 echo 服务器，
* 设置了读的高水位值，添加了写超时，用于处理恶意用户
* 捕获信号 SIGPIPE, 避免服务器意外退出
* 当接收到 EOF 时，如果发送缓冲区还有数据，将尝试发送数据

见 [echo_libevent](./echo_libevent.cc)

第三种：

利用 libevent 实现了一个多线程的非阻塞 IO 的 echo 服务器，
* 设置了读的高水位值，添加了写超时，用于处理恶意用户
* 捕获信号 SIGPIPE, 避免服务器意外退出
* 当接收到 EOF 时，如果发送缓冲区还有数据，将尝试发送数据
* 主程序处理监听 socket，将已连接 socket 发送给各个子线程处理

见 [echo_libevent_thread](./echo_libevent_thread.cc)
