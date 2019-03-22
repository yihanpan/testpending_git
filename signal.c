#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

void catchsigint(int signo)
{
	printf("----aaa------\n");
}

int main(void)
{
	sighandler_t sigh;

	sigh = signal(SIGINT, catchsigint);
	if(sigh == SIG_ERR)
	{
		perror("signal error");
		exit(1);
	}
	
	while(1);

	return 0;
}
