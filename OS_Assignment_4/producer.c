
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int urandomFD = open("/dev/urandom", O_RDONLY);
    if (urandomFD < 0)
    {
        printf("There is some error in opening urandom\n");
    }
    else
    {
    // printf("HELLOOOO \n");

        char myRandomData[8];
        int result = read(randomData, myRandomData, sizeof myRandomData);
        if (result < 0)
        {
            // something went wrong
        }
        else{
            printf("\nThis is the random data: %s \n", myRandomData);

        }
    }
    close(randomData);
}
