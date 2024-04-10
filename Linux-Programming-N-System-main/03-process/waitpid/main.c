#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])   
{
    int wstatus, wpid;
    pid_t child_pid;                     
    child_pid = fork();         
    
    if (child_pid >= 0) {
        if (0 == child_pid) {       /* Process con */
            printf("\nIm the child process\n");
            printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
            sleep(3);
            
        } else {                    /* Process cha */
	    // while (1);
            wpid = waitpid(child_pid, &wstatus, 0);

            if(wpid == - 1)
            {
                printf("waitpid() unsuccessful\n");
            }
            printf("\nIm the parent process\n");
            printf("My PID is: %d\n", getpid());

            if(WIFEXITED(wstatus))
            {
                printf("exited, status = %d\n", WEXITSTATUS(wstatus));
            }
            else if(WIFSIGNALED(wstatus))
            {
                printf("killed by signal %d\n", WTERMSIG(wstatus));
            }
            else if(WIFSTOPPED(wstatus))
            {
                printf("stopped by signal %d\n", WSTOPSIG(wstatus));
            }
            else if(WIFCONTINUED(wstatus))
            {
                printf("continued\n");
            }
        }
    } else {
        printf("fork() unsuccessfully\n");      // fork() return -1 nếu lỗi.
    }

    return 0;
}


