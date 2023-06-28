#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int fdin, fdout;
	ssize_t nread;
	char buffer[1024];
	char review;
	

	if(argc != 3){
		printf("Usage: cp  <source file>  <destination file>\n");
		exit(-1);
	}
	
	fdin = open(argv[1], O_RDONLY);
	
    	if(fdin == -1){
	   printf("cannot open the open file\n");
	   exit(-1);
	}
	
    if (access(argv[2], F_OK) == 0) {
        printf("want to overwrite %s? (y / n)",argv[2]);
        scanf("%c",&review);
        if (review=='y'){

	fdout = open(argv[2], O_WRONLY, 0644);

    	if (access(argv[2], R_OK) == -1){
	   printf("cannot open the destination file\n");
	   exit(-1);
	}	

	while((nread=read(fdin, buffer, 1024))>0){
		if(write(fdout, buffer, nread) < nread){
			close(fdin);
			close(fdout);
			break;
		}
	}	
	}
	
	
	else if (review=='n') {
	printf("copy is aborted\n");
	exit(-1);
	}
        else{
       printf("invalid option\n");
	exit(-1);
	}
	}

    else {
	
	fdout = open(argv[2], O_WRONLY|O_CREAT|O_EXCL, 0644);

    	if (access(argv[2], R_OK) == -1){
	   printf("cannot open the destination file\n");
	   exit(-1);
	}	
	

	while((nread=read(fdin, buffer, 1024))>0){
		if(write(fdout, buffer, nread) < nread){
			close(fdin);
			close(fdout);
			break;
		}
	}
	}
	


	return 0;
}

