#include <stdlib.h>	/* to define exit() */
#include <unistd.h>	/* to use fork() and getpid() */
#include <stdio.h>	/* to use printf() */
#include <sys/wait.h>

void taskParent()
{
 printf("Job is done\n");
}

int main(int argc, char **argv) 
{
int pid;	/* PID */
char child_1[10];
char child_2[10];
char child_3[10];
char child_4[10];

switch (pid = fork())
{
case 0:		/* fork always return 0 if child */
	printf("First child's name: ");
	scanf("%[^\n]%*c",child_1);
	printf("Second child's name: ");
	scanf("%[^\n]%*c",child_2);
	printf("Third child's name: ");
	scanf("%[^\n]%*c",child_3);
	printf("Fourth child's name: ");
	scanf("%[^\n]%*c",child_4);

	for(int i = 0; i <= 3; i++)
	{
		if(i == 0){
		printf("First child: My name is %s\n", child_1);
		i = i+1;
		}

		else if(i == 1){
		printf("Second child: My name is  %s\n", child_2);
		i = i + 1;
		}

		else if(i == 2){
		printf("Third child: My name is  %s\n", child_3);
		i = i + 1;
		}

		else if(i == 3){
		printf("Fourth child: My name is  %s\n", child_4);
		i = i + 1;
		}

		else{
		perror("fork");
		return(1);
		}
	}
	break;

default:	/* fork to return pid of parent */
	wait(NULL);
	taskParent();
	break;

case -1:	/* wrong value */
	perror("fork");
	exit(1);
	}
exit(0);
}
