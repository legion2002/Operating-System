// References - https://www.youtube.com/watch?v=yUhjskNO2yY&list=PLN9r3gitIiJ67Mru9fNUUb3BThF9dIZOA&index=1&ab_channel=CSEPracticals
// References - https://www.geeksforgeeks.org/socket-programming-cc/
//References - https://github.com/csepracticals/SerVerDesign/blob/master/AF_UNIX/server.c

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
#include <sys/un.h>
#include <string.h>


#define STRING_LENGTH 5
#define NUMBER_OF_STRINGS 50
#define PACKET_SIZE 5
#define MESSAGE_LENGTH (PACKET_SIZE * (STRING_LENGTH + 1))
#define SOCKET_NAME "/tmp/SocketTransfer"
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
    struct sockaddr_un name;
    int fd;
    int sockNum;
    int check;
    

    char buffer[1000];
    
    unlink(SOCKET_NAME);

    fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (fd == -1) {
        printf("Error in creating socket");
        return -1;
    }
  
    memset(&name, 0, sizeof(struct sockaddr_un));

    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

    check = bind(fd, (const struct sockaddr *) &name,
            sizeof(struct sockaddr_un));

    if (check == -1) {
        printf("Error in binding socket");
        return -1;
    }


    check = listen(fd, 20);
    if (check == -1) {
        printf("Error in listening to socket");
        return -1;
    }


        sockNum = accept(fd, NULL, NULL);

        if (sockNum == -1) {
            printf("Error in accepting socket");
            return -1;
        }
    
    read( sockNum , buffer, 1000);
    printf("Testing: %s\n",buffer );


    int receivedID = -1;
    while(receivedID != NUMBER_OF_STRINGS -1){
        
        preparePackets(receivedID+1);
        
        char *serverSending = packet;
        printf("Sending Packet %s\n", packet);
        send(sockNum , serverSending , strlen(serverSending) , 0 );
        read( sockNum , buffer, 1000);
        printf("Received ID: %d\n",buffer[1] );
        receivedID = buffer[1];
    }
    

    close(sockNum);
    printf("Message Transfer Completed Successfully\n");
    unlink(SOCKET_NAME);
    return 0;
}