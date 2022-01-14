#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<fcntl.h>
#include<errno.h>

int main(){
	pid_t pid1;
	printf("\nbefore fork()\n");
	if((pid1 = fork()) > 0){
        printf("\n hello world\n");
		waitpid(pid1, NULL, 0);
        printf("\n hello world 2\n");
	}
	else if(pid1 == 0){
        
		execl("/usr/bin/bash","bash",NULL);
		printf("\ndone launching the shell\n");
	}
	else{
		perror("fork()");
	}
}