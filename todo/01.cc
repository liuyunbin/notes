
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <map>
#include <string>

void log(const std::string& msg = "") {
    time_t     now  = time(NULL);
    struct tm* info = localtime(&now);
    char       buf[1024];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S %z", info);
    std::cout << buf << " " << msg << std::endl;
}

void show(pid_t pid) {
    std::string msg = "进程 " + std::to_string(pid);
    msg += " 进程组 " + std::to_string(getpgid(pid));
    msg += " 会话 " + std::to_string(getsid(pid));
    log(msg);
}

void test() {
    log();
    show(getpid());

    std::string msg = "新建会话";
    if (setsid() < 0) {
        msg += ": ";
        msg += strerror(errno);
    }
    log(msg);

    show(getpid());
}
