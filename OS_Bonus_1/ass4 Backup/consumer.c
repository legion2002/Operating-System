#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
    
        long data;
        int i = 0;
        while(1){
        
            data = syscall(448, data);
            printf("\nThis is the random data received: %ld \n", data);
            sleep(2);

        i++;

        }
        
        
    
}