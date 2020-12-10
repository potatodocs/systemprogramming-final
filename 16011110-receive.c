#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void sighandler(int signo, siginfo_t *si)
{
	//After checking if si_code is si_queue,
	//display the information received.
	if(si->si_code == SI_QUEUE) { //RTS signal 
		printf("User RTS signal %d\n", si->si_pid);
		printf("Sig Number %d\n", si->si_signo);
		printf("User Data is %d\n",si->si_value.sival_int);
		getchar();
	}
	else { //standard signal
		printf("Get none RTS %d\n",signo);
	}
}

int main()
{
	struct sigaction sigact;
	
	printf("My PID is %d\n",getpid()); //print process id(PID)	
	
	//set signal handler for SIGRTMIN
	sigemptyset(&sigact.sa_mask);      //empty sa_mask
	sigact.sa_flags=SA_SIGINFO;	   //set sa_flags to SA_SIGINFO
	sigact.sa_restorer=NULL;	   //sa_restorer is NULL
	sigact.sa_sigaction=sighandler;    //register signal handler

	//sigaction() for RTS signal
	if(sigaction(SIGRTMIN,&sigact,0)==1) {
		printf("signal error\n"); //error occur
		exit(0); 
	}

	//do something
	while(1) {
		sleep(1);
	}
}
