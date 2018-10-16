#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   pid_t pid;
   int mypipefd[2];
   int ret; 
   char buf[20];
   ret = pipe(mypipefd);
   if(ret == -1)
   {
   	 perror("pipe");
   	 exit(1);
   }
    
    pid = fork();

    if(pid == 0)
    {
    	// child process
        write(mypipefd[1], "Hello There!", 12);
        close(mypipefd[1]);

    }  else {
        // parent process
        read(mypipefd[0], buf, 15);
        printf("buf: %s\n", buf);
        close(mypipefd[0]);
    }

    return 0;
}