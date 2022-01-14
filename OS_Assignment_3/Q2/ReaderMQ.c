#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define STRING_LENGTH 5
#define NUMBER_OF_STRINGS 50
#define PACKET_SIZE 5
#define MESSAGE_LENGTH (PACKET_SIZE * (STRING_LENGTH + 2))

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[MESSAGE_LENGTH];
} message;
struct mesg_send
{
    long mesg_type;
    char mesg_text[1];
} sending, receiving;

int main()
{
    key_t key;
    int msgid;
    struct msqid_ds msqid_ds, *buf;
    buf = &msqid_ds;
    key = ftok("tanishkFile", 60);
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("MSG Queue ID is %d\n", msgid);
    int lastID = 0;

    while (lastID != NUMBER_OF_STRINGS - 1)
    {

        msgrcv(msgid, &message, sizeof(message), 1, 0);

        int textCount = 0;
        for (int i = 0; i < PACKET_SIZE; i++)
        {
            printf("ID: %d, ", message.mesg_text[textCount]);
            textCount++;
            char word[STRING_LENGTH + 1];
            for (int j = 0; j <= STRING_LENGTH; j++)
            {
                word[j] = message.mesg_text[textCount];
                textCount++;
            }
            printf("String: %s\n", word);
        }
        lastID = message.mesg_text[MESSAGE_LENGTH - 7];
        printf("Sending Back ID: %d\n", lastID);

        sending.mesg_type = 2;
        sending.mesg_text[0] = lastID;

        int check = msgsnd(msgid, &sending, sizeof(sending), 0);

        if (check != 0)
        {
            printf("There is some error in sending\n");
        }
    }
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}