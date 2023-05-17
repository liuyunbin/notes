
#include "log.h"

int main() {
    log("测试新建自身进程对应的进程组");
    log();

    test(getpid(), getpid());
    if (fork() == 0) {
        test(getpid(), getpid());
        exit(-1);
    }
    sleep(1);
    log("主进程退出");

    return 0;
}
