
#include "log.h"

int main() {
    log();
    log("操作系统-会话-新建");
    log("测试不是进程组的首进程建立新会话");
    log();

    if (fork() == 0) {
        test_sid();
        exit(-1);
    }

    sleep(1);
    log("主进程退出");
    log();

    return 0;
}