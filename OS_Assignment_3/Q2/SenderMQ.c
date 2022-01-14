#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#define STRING_LENGTH 5
#define NUMBER_OF_STRINGS 50
#define PACKET_SIZE 5
#define MESSAGE_LENGTH (PACKET_SIZE * (STRING_LENGTH + 2))

char data[NUMBER_OF_STRINGS][STRING_LENGTH + 1];
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[MESSAGE_LENGTH];
} message;
struct mesg_receive
{
    long mesg_type;
    char mesg_text[1];
}test;

void preparePackets(int startIndex)
{
    int textIndex = 0;

    for (int i = startIndex; i < startIndex + PACKET_SIZE; i++)
    {
        message.mesg_text[textIndex] = i;
        textIndex++;
        printf("Added to Packet: %s\n", data[i]);
        for (int j = 0; j <= STRING_LENGTH; j++)
        {
            message.mesg_text[textIndex] = data[i][j];
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

    key_t key;
    int msgid;
    struct msqid_ds msqid_ds, *buf;
    buf = &msqid_ds;
    key = ftok("tanishkFile", 60);
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("MSG Queue ID is %d\n", msgid);
    int receivedID = -1;
    
    while (receivedID != NUMBER_OF_STRINGS - 1)
    {

        message.mesg_type = 1;
        preparePackets(receivedID+1);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Data send complete\n");
        // msgctl(msgid, IPC_STAT, buf);
        // printf("The number of messages is %d\n", buf->msg_qnum);

        int check = msgrcv(msgid, &test, sizeof(test), 2, 0);
        if (check == -1)
        {
            printf("Some error in msgrcv\n");
        }
        printf("Received ID: %d\n", test.mesg_text[0]);
        receivedID = test.mesg_text[0];
        
    }
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}