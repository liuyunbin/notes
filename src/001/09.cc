
#include "00.h"

int main() {
    log();
    log("测试信号 SIGABRT 处理为 SIG_IGN");
    log();

    log("设置 SIGABRT 处理为 SIG_IGN");
    signal(SIGABRT, SIG_IGN);

    log("调用 abort()");
    abort();

    sleep(1);

    log("主进程正常退出");
    log();

    return 0;
}