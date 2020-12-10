#include<stdio.h>
#include<signal.h>

int main(int argc, char **argv)
{
	union sigval sv;
	sv.sival_int=atoi(argv[2]);
	sigqueue(atoi(argv[1]),SIGRTMIN,sv);

}
