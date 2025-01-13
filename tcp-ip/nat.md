
## NAT 用途
* 子网机器 => NAT => 互联网或其他网络
* 可以解决 IPv4 地址短缺的问题(使用一个IP地址可以让子网内的用户都可以上网)
* 可以使得访问更安全(通过 NAT 过滤)

## NAT 类型
### 基础NAT(只修改 IP)(基本不用)
### NAPT(修改IP和端口号)
* 完全圆锥形NAT(Full cone NAT)
    1. 如果内网机器(A:X)通过NAT(D:X1)发送数据给公网机器(B:Y)
    2. 那么, 内网机器(A:X)发往任何机器的任何端口号的数据都会通过NAT(D:X1)发送
    3. 任何外网机器的任何端口号都可通过NAT(D:X1)向内网机器(A:X)发送数据(任意IP, 任意端口号)
* 受限圆锥形NAT(Address-Restricted cone NAT)
    1. 如果内网机器(A:X)通过NAT(D:X1)发送数据给公网机器(B:Y)
    2. 那么, 内网机器(A:X)发往任何机器的任何端口号的数据都会通过NAT(D:X1)发送
    3. 外网机器(B)的任何端口号都可通过NAT(D:X1)向内网机器(A:X)发送数据(同IP, 任意端口号)
* 端口受限圆锥形NAT(port-Restricted cone NAT)
    1. 如果内网机器(A:X)通过NAT(D:X1)发送数据给公网机器(B:Y)
    2. 那么, 内网机器(A:X)发往任何机器的任何端口号的数据都会通过NAT(D:X1)发送
    3. 外网机器(B:Y)才可以通过NAT(D:X1)向内网机器(A:X)发送数据(同IP, 同端口号)
* 对称NAT(Symmetric NAT)
    1. 如果内网机器(A:X)通过NAT(D:X1)发送数据给公网机器(B:Y)
    2. 那么, 内网机器(A:X)通过NAT(D:X2)发送数据给公网机器(B:Z), X1 != X2 (IP 相同, 端口号不同)
    3. 那么, 内网机器(A:X)通过NAT(D:X3)发送数据给公网机器(C:Y), X1 != X3 (IP 不同, 端口号相同)
    4. 那么, 内网机器(A:X)通过NAT(D:X4)发送数据给公网机器(C:Z), X1 != X4 (IP 不同, 端口号不同)
    5. 外网机器(B:Y)才可以通过NAT(D:X1)向内网机器(A:X)发送数据(同IP, 同端口号)
    6. 外网机器(B:Z)才可以通过NAT(D:X2)向内网机器(A:X)发送数据(同IP, 同端口号)
    7. 外网机器(C:Y)才可以通过NAT(D:X3)向内网机器(A:X)发送数据(同IP, 同端口号)
    8. 外网机器(C:Z)才可以通过NAT(D:X4)向内网机器(A:X)发送数据(同IP, 同端口号)

## 检测NAT的类型(需要公网机器(B:Y), 公网机器(C:Z))
0. 内网机器(A:X)给公网机器(B:Y)发送数据
1. 公网机器(B:Y)返回内网机器(A:X)的地址: D:X1
2. 如果 D == A && X1 == X, 则为公网 IP
3. 否则, 公网机器(C:Z)通过NAT(D:X1)给内网机器(A:X)发送消息(IP和端口号都不同)
4. 如果内网机器(A:X)可以收到消息，则为 完全圆锥形 NAT
5. 否则, 公网机器(B:Z)通过NAT(D:X1)给内网机器(A:X)发送消息(IP相同, 端口号不同)
6. 如果内网机器(A:X)可以收到消息，则为 受限圆锥形 NAT
7. 否则, 内网机器(A:X)给公网机器(C:Z)发送数据
8. 公网机器(C:Z)返回内网机器的地址: D:X2
9. 如果 X1 == X2, 则为 端口受限圆锥形 NAT, 否则为对称 NAT

## P2P 通信
### 通过公共机器直接通信(不受任何NAT类型的限制, 但效率比较低, 会给服务器造成很大的消耗)
* 内网机器(A)与公网机器器(C)相连
* 内网机器(B)与公网机器器(C)相连
* 内网机器(A)将数据发给公网机器(C), 公网机器(C)再将数据发送给内网机器(B)
* 内网机器(B)将数据发给公网机器(C), 公网机器(C)再将数据发送给内网机器(A)

### 机器(A:X)和机器(B:Y)都是公网IP
两个机器可以直接相连

### 机器(A:X)或机器(B:Y)只有一个是公网IP
* 假设, 机器(A:X)有公网IP
* 通过 机器(B:Y) => NAT(E:Q) => 机器(A:X) 发送数据, 因为机器(A:X)为公网IP
* 此时 机器(A:X) => NAT(E:Q) => 机器(B:Y) 也通了

### 机器(A:X)和机器(B:Y)位于不同 NAT, 有一个公网机器(C:Y)
1. 机器(A:X)或机器(B:Y)所属的 NAT 为完全锥形 NAT
    * 假定机器(A:X)所属的 NAT 为完全锥形 NAT
    * 通过 机器(A:X) => NAT(D:P) => 公网机器(C:Z) 发送数据
    * 通过 机器(B:Y) => NAT(E:Q) => 公网机器(C:Z) 发送数据
    * 通过 公网机器(C:Z) => NAT(E:Q) => 机器(B:Y) 发送数据NAT(D:P)
    * 通过 机器(B:Y) => NAT(E:R) => NAT(D:P) => 机器(A:X) 发送数据(完全锥形 NAT)
    * 此时 机器(A:X) => NAT(D:P) => NAT(E:R) => 机器(B:Y) 也通了
2. 机器(A:X)或机器(B:Y)所属的 NAT 为受限锥形 NAT
    * 假定机器(A:X)所属的 NAT 为受限锥形 NAT
    * 通过 机器(A:X) => NAT(D:P) => 公网机器(C:Z) 发送数据
    * 通过 机器(B:Y) => NAT(E:Q) => 公网机器(C:Z) 发送数据
    * 通过 公网机器(C:Z) => NAT(D:P) => 机器(A:X) 发送数据NAT(E:Q)
    * 通过 公网机器(C:Z) => NAT(E:Q) => 机器(B:Y) 发送数据NAT(D:P)
    * 通过 机器(A:X) => NAT(D:P) => NAT(E:Q) 发送数据, 会被丢弃
        * 因为NAT(E:Q) 不知道数据要发往哪里
        * 但 NAT(E) => NAT(D:P) => 机器(A:X) 这条路已经通了,
        * 此时, NAT(E)的任何端口号都通过 NAT(D:P)=>机器(A:X) 发送数据(受限锥形 NAT)
    * 通过 机器(B:Y) => NAT(E:R) => NAT(D:P) => 机器(A:X) 发送数据, 会成功,
        * 因为NAT(E) => NAT(D:P) => 机器(A:X) 是通的
    * 此时, 机器(A:X) => NAT(D:P) => NAT(E:R) => 机器(B:Y) 也通了
3. 机器(A:X)和机器(B:Y)所属的 NAT 均为端口受限锥形 NAT
    * 通过 机器(A:X) => NAT(D:P) => 公网机器(C:Z) 发送数据
    * 通过 机器(B:Y) => NAT(E:Q) => 公网机器(C:Z) 发送数据
    * 通过 公网机器(C:Z) => NAT(D:P) => 机器(A:X) 发送数据NAT(E:Q)
    * 通过 公网机器(C:Z) => NAT(E:Q) => 机器(B:Y) 发送数据NAT(D:P)
    * 通过 机器(A:X) => NAT(D:P) => NAT(E:Q) 发送数据, 会被丢弃
        * 因为NAT(E:Q) 不知道数据要发往哪里
        * 但 NAT(E:Q) => NAT(D:P) => 机器(A:X) 这条路已经通了(端口受限锥形 NAT)
    * 通过 机器(B:Y) => NAT(E:Q) => NAT(D:P) => 机器(A:X) 发送数据, 会成功,
        * 因为机器NAT(E:Q) => NAT(D:P) => 机器(A:X) 是通的
    * 此时, 机器(A:X) => NAT(D:P) => NAT(E:Q) => 机器(B:Y)  也通了
4. 机器(A:X)和机器(B:Y)所属的 NAT 均为对称 NAT
    * 无法穿透
    * 可以考虑通过公网机器发送数据
5. 机器(A:X)和机器(B:Y)所属的 NAT 一个为对称 NAT，一个为端口受限的 NAT
    * 无法穿透
    * 可以考虑通过公网机器发送数据

## 说明
* 上述讨论的主要是使用 UDP 打洞, 使用 TCP 也可以打洞

## 相关公共协议
* STUN
