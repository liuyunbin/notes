
#include "00.h"

int main() {
    log();
    log("测试新建父进程对应的进程组");
    log();

    if (fork() == 0) {
        // 测试的父进程
        if (fork() == 0) {
            // 测试的子进程
            log("新建父进程(" + std::to_string(getppid()) + ")的进程组");
            test(getppid(), getppid());
            kill(getppid(), SIGKILL);
            exit(-1);
        }
        for (;;)
            ;
    }
    sleep(1);
    log("主进程退出");
    log();

    return 0;
}