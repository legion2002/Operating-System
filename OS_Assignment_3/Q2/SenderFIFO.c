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

char data[NUMBER_OF_STRINGS][STRING_LENGTH + 1];
char packet[MESSAGE_LENGTH];

void preparePackets(int startIndex)
{
    int textIndex = 0;

    for (int i = startIndex; i < startIndex + PACKET_SIZE; i++)
    {
        packet[textIndex] = i + 50;
        textIndex++;
        printf("Added to Packet: %s\n", data[i]);
        for (int j = 0; j < STRING_LENGTH; j++)
        {
            packet[textIndex] = data[i][j];
            textIndex++;
        }
    }
}
int main()
{

    srand(time(0));
    for (int i = 0; i < NUMBER_OF_STRINGS; i++)
    {

        for (int j = 0; j < STRING_LENGTH; j++)
        {
            int ascii = (rand() % 90) + 33;
            char c = ascii;
            data[i][j] = c;
        }
        data[i][STRING_LENGTH] = '\0';
    }
    int fd;
    char *fifoTemp = "fifotrial";
    mkfifo(fifoTemp, 0666);

    int receivedID = -1;
    while (receivedID != NUMBER_OF_STRINGS - 1)
    {
        preparePackets(receivedID + 1);
        printf("Sending Packet %s\n", packet);
        fd = open(fifoTemp, O_WRONLY);
        write(fd, packet, strlen(packet));
        close(fd);

        fd = open(fifoTemp, O_RDONLY);
        char IDreturned[1];
        read(fd, IDreturned, sizeof(IDreturned));
        printf("ID returned: %d\n", IDreturned[0]);
        close(fd);
        receivedID = IDreturned[0];
    }
    printf("Message Transfer Completed\n");
    return 0;
}