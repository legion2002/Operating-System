all: q1

q1:
	gcc main.c q1.c -lm -o q1.out

q2a:
	nasm -f elf64 q2.asm
	gcc q2.o caller.c -o  final2.out -no-pie
clean:
	rm *.out  *.o

