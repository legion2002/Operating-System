Submitted By - Tanishk Goyal Roll Number 2020141

Instructions to Compile and Run the Programme - 
1) Run the 'make' command to obtain the object files
2) For each usecase there are 2 object files namely 
	MessageQueue - SenderMQ and ReaderMQ
	FIFO 	- SenderFIFO and ReaderFIFO
	Sockets - SenderSocket and ReaderSocket
3) Open two seperate artix terminals and for each IPC, first run the Sender file in one terminal and after that the Reader file in the other terminal
	For eg - ./SenderMQ in first terminal and ./ReaderMQ in second terminal


Logic Used - 
First we create 50 random strings of length 5, these strings are stored in a 2 dimensional array of size (50,6). We store the extra character '\0' after each string to denote
that the string has ended.

We then create packets using the preparePackets() function, this function takes in the starting index as an argument, and returns a packet with strings and indexes from startIndex to startIndex + PacketSize
In our case packet size is 5.
Each packet is of the form [ID1, String1, ID2, String2, .... IDN, StringN]. In sockets and FIFO's the '\0' character is removed from these strings while creating packets.
the IDs are converted to characters while being stored in packets, in the case of sockets and FIFO's we add an offset of 50 to the ascii value of these IDs, so that the characters we obtain are of readable form.
We then subtract this offset in the Reader processes, to obtain the final ID.

Main Logic - we iteratively call the preparePacket function starting from index 0, and update the lastID to the ID received from the Reader Process. 
The sender process then calls the preparePacket function with this updated LastID and then sends the packet back to the reader process, where it is parsed, converted into seperate strings and displayed.

Variations in Different IPCs -
Sources - Some syntax has been taken from geeks for geeks, the official linux man pages and a github repository which have all been linked in the comments.

1) Sockets - Unix domain sockets were created using the socket() system call, subsequently bind, listen , accept,connect system calls were used to establish communication between sender and reader process.

2) FIFOs - A temporary FIFO file was made, from which both Reader and sender processes queried read and write functions.

3) Message Queues - A message queue was generated, and packets were added to this message queue from both Sended and Receiver Processes using the msgsend and msgrcv system call.




