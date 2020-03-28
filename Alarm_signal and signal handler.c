#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    printf("alarm delivered signum %d\n", signum);
    exit(0); // exit!
}

int main()
{
    alarm(1); // time in seconds!
    signal(SIGALRM, signal_handler);
    /*
    if this signal handler is not there then the system will kill it abruptly and code below will not be executed!
    also, it is important to catch the right signal i.e "SIGALRM" is for alarm() signal!
    if u exit in the siganl handler than code below signal will not be executed!
    */

    for (;;)
        sleep(1);
    return 0;
}