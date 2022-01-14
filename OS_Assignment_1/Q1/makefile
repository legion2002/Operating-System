all: thread_final process_final

thread_final: thread_asm thread_obj

thread_asm: Q1_thread.c
	gcc -S Q1_thread.c

thread_obj: Q1_thread.s 
	gcc Q1_thread.s -o thread_final.out -lpthread

process_final: process_asm process_obj

process_asm: Q1_process.c 
	gcc -S Q1_process.c

process_obj: Q1_process.c 
	gcc Q1_process.s -o process_final.out

clean:
	rm *.out  *.s 
	



