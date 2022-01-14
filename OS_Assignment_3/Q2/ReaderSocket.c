#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define STRING_LENGTH 5
#define NUMBER_OF_STRINGS 50
#define PACKET_SIZE 5
#define MESSAGE_LENGTH (PACKET_SIZE * (STRING_LENGTH + 1))
#define SOCKET_NAME "/tmp/SocketTransfer"
char data[NUMBER_OF_STRINGS][STRING_LENGTH + 1];

int main()
{
    
    // int i;
    int check;
    int sockNum;
    char buffer[1000];
    struct sockaddr_un addr;


    sockNum = socket(AF_UNIX, SOCK_STREAM, 0);

    if (sockNum == -1) {
        printf("Error in creating socket");
        return -1;
    }


    memset(&addr, 0, sizeof(struct sockaddr_un));


    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

    check = connect (sockNum, (const struct sockaddr *) &addr,
            sizeof(struct sockaddr_un));

    if (check == -1) {
       printf("No server found");
        return -1;
    }

    
    int lastID = 0;
    char *test = "Connected Successully";
    send(sockNum, test, strlen(test), 0);

    while (lastID != NUMBER_OF_STRINGS - 1)
    {
        

        read(sockNum, buffer, 1000);
        int textCount = 0;
        for (int i = 0; i < PACKET_SIZE; i++)
        {
            printf("ID: %d ", buffer[textCount] - 50);
            textCount++;

            char word[STRING_LENGTH + 1];
            for (int j = 0; j < STRING_LENGTH; j++)
            {
                //  printf("%c \n", buffer[textCount]);
                word[j] = buffer[textCount];
                textCount++;
            }
            word[STRING_LENGTH] = '\0';
            printf("String: %s\n", word);
        }
        lastID = buffer[MESSAGE_LENGTH - 6] - 50;
        printf("Sending Back ID: %d\n", lastID);
        char stringID = lastID;
        char *sending = &stringID;

        send(sockNum, sending, strlen(sending), 0);
    }
    printf("Message Transfer Completed Successfully\n");
    close(sockNum);
    return 0;
}