#include <stdlib.h>	/* to define exit() */
#include <unistd.h>	/* to use fork() and getpid() */
#include <stdio.h>	/* to use printf() */
#include <sys/wait.h>
void taskParent(){
printf("Job is done\n");
}
int main(int argc, char **argv){
int pid;	/* process ID */
char c1[20];
char c2[20];
char c3[20];
char c4[20];
switch (pid = fork()){
case 0:		/* pid child returned by fork */
	printf("First child's name:\n");
	scanf("%[^\n]%*c",c1);
	printf("Second child's name:\n");
	scanf("%[^\n]%*c",c2);
	printf("Third child's name:\n");
	scanf("%[^\n]%*c",c3);
	printf("Fourth child's name:\n");
	scanf("%[^\n]%*c",c4);

	for(int i = 0; i <= 3; i++){
	if(i == 0){
		printf("First child is %s\n", c1);
		i=i+1;
		}
	if(i == 1){
		printf("Second child is %s\n", c2);
		i=i+1;
		}
	if(i == 2){
		printf("Third child is %s\n", c3);
		i=i+1;
		}
	if(i == 3){
		printf("Fourth child is %s\n", c4);
		i=i+1;
		}
	else{
		perror("fork");
		return(1);
		}
	}
	break;

default:	/* pid parent returned by fork */
	wait(NULL);
	taskParent();
	break;

case -1:	/* wrong value */
	perror("fork");
	exit(1);
}

exit(0);
}

