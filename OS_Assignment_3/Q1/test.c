#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <limits.h>
#include <syscall.h>

#include <sys/resource.h>
int main()
{
    pid_t p = getpid();
    int which = PRIO_PROCESS;
    int priority = 35;
    int ret;
    ret = setpriority(which, p, priority);
    unsigned long long hello = syscall(448, 10000000, p);
    unsigned long long hello1 = syscall(448, 10000000, p);
    // unsigned long long hello2= syscall(448, INT_MAX, p);
    // unsigned long long hello3 = syscall(448, INT_MAX, p);
    // unsigned long long hello4 = syscall(448, INT_MAX, p);
    // unsigned long long hello5 = syscall(448, INT_MAX, p);
    // unsigned long long hello6 = syscall(448, INT_MAX, p);
    // unsigned long long hello7 = syscall(448, INT_MAX, p);
    // unsigned long long hello8 = syscall(448, INT_MAX, p);
    // unsigned long long hello9 = syscall(448, INT_MAX, p);
    // unsigned long long hello11 = syscall(448, INT_MAX, p);
    // unsigned long long hello12 = syscall(448, INT_MAX, p);

    // printf("%d\n", hello);
    int i, j;
    int n = 10000;

    printf("Prime numbers are:-\n");
    for (i = 2; i <= n; i++)
    {
        int c = 0;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                c++;
            }
        }

        if (c == 2)
        {
            printf("%d ", i);
        }
    }
    return 0;
}