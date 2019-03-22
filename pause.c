#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

void catch_signalrm(int signo)
{}

unsigned int mysleep(unsigned int seconds)
{
	struct sigaction act, oldact;
	int ret;
	act.sa_handler = catch_signalrm;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	ret = sigaction(SIGALRM, &act, &oldact);
	if(ret == -1)
	{
		perror("sigaction error");
		exit(1);
	}
	alarm(seconds);
	ret = pause();
	if(ret == -1 && errno == EINTR)
		printf("pause sucess");
	
	ret = alarm(0);
	sigaction(SIGALRM, &oldact, NULL);

	return ret ;	
}


	

int main(void)
{
	
	while(1)
	{
		mysleep(3);
		printf("-----\n");
	}
	return 0;
}
