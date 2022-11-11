
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <map>

void log(const std::string& msg) {
    std::cout << "进程(" << getpid() <<  "): " << msg << std::endl;
}

int main() {
    log("测试僵尸进程");
    log("测试子进程已退出, 父进程未处理的情况");
    pid_t fd = fork();

    if (fd == 0) {
        // 子进程
        log("子进程启动");
        sleep(2);
        log("子进程退出");
        return 0;
    } else {
        // 父进程
        sleep(1);
        log("子进程状态");
        std::string cmd = "ps -o pid,ppid,state -p " + std::to_string(fd);
        system(cmd.data());
        log("父进程未捕获或忽略任何信号");
        sleep(2);
        log("子进程状态");
        system(cmd.data());
        log("父进程退出");
    }

    return 0;
}

