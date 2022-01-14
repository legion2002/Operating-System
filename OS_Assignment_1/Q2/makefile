all: assemble compile 

assemble:
	nasm -f elf64 B.asm 

compile:
	gcc A.c B.o C.c -o final.out -no-pie

clean:
	rm *.out  *.o

