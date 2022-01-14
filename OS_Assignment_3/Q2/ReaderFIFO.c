#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define STRING_LENGTH 5
#define NUMBER_OF_STRINGS 50
#define PACKET_SIZE 5
#define MESSAGE_LENGTH (PACKET_SIZE * (STRING_LENGTH + 1))

int main()
{
    int fd;

    // FIFO file path
    char *fifoTemp = "fifotrial";
    mkfifo(fifoTemp, 0666);
    char buffer[MESSAGE_LENGTH];

    int lastID = 0;
    while (lastID != NUMBER_OF_STRINGS - 1)
    {
        fd = open(fifoTemp, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        close(fd);

        int textCount = 0;
        for (int i = 0; i < PACKET_SIZE; i++)
        {
            printf("ID: %d, ", buffer[textCount] - 50);
            textCount++;
            char word[STRING_LENGTH + 1];
            for (int j = 0; j < STRING_LENGTH; j++)
            {
                word[j] = buffer[textCount];
                textCount++;
            }
            printf("String: %s\n", word);
        }
        fd = open(fifoTemp, O_WRONLY);

        lastID = buffer[MESSAGE_LENGTH - 6] - 50;
        printf("Sending Back ID: %d\n", lastID);
        char IDsend[1];

        IDsend[0] = lastID;
        write(fd, IDsend, sizeof(IDsend) );
        close(fd);
        
    }
    
    printf("Message Transfer Completed\n");
    return 0;
}