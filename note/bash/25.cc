
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <map>
#include <string>

void log(const std::string& msg = "") {
    std::cout << "进程(" << getpid() << "): " << msg << std::endl;
}

void set_signal() {
    struct sigaction act;
    act.sa_handler = SIG_DFL;
    act.sa_flags = SA_NOCLDWAIT;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD, &act, NULL);
}

int main() {
    log("测试预防僵尸进程产生之设置 SIGCHLD 处理为: 设置 SA_NOCLDWAIT");
    log();

    log("设置 SIGCHLD 的信号处理");
    set_signal();

    log("阻塞信号 SIGCHLD");
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_SETMASK, &mask, NULL);

    std::string cmd = "ps -o pid,comm,state -p ";

    for (int i = 1; i <= 5; ++i) {
        pid_t fd = fork();
        if (fd == 0) {
            // 子进程
            log("第 " + std::to_string(i) + " 个子进程启动后退出");
            exit(-1);
        } else {
            // 父进程
            cmd += std::to_string(fd) + ",";
            sleep(1);
        }
    }

    cmd.pop_back();

    log("解除信号 SIGCHLD 的阻塞");
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
    sleep(1);
    log("此时, 子进程的状态");
    system(cmd.data());

    log();
    log("主进程退出");

    return 0;
}