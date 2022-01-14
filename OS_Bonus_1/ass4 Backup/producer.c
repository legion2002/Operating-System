#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
    int FD = open("/dev/urandom", O_RDONLY);
    if (FD < 0)
    {
        printf("Come error in opening urandom file\n");
    }
    else
    {
        long data;
        int i = 0;
        while(1){
        int check = read(FD, &data, sizeof(data));
        if (check < 0)
        {
            printf("Read was unsuccessful \n");
        }
        else{
            // data = 123456;

            printf("\nThis is the random data to be enqueued: %ld \n", data);
            syscall(449, data);
            sleep(2);

        }
        i++;
        }
        
    }
    close(FD);
}