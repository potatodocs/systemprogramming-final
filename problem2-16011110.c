#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void act(int signo);

int main()
{
	int i=0;
	struct sigaction sig;
	
	sig.sa_handler=act;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags=0;

	if(sigaction(SIGTSTP,&sig,0)==-1) {
		printf("signal(SIGTSTP) error\n");
		return -1;
	}
	if(sigaction(SIGINT,&sig,0)==-1) {
                printf("signal(SIGINT) error\n");
                return -1;
        }



	while(1) {
		printf("Wait for signal to be received! Count:%d\n",i);
		i++;
		sleep(1);
	}
}
void act(int signo)
{
	psignal(signo,"Received siganl:");
}
