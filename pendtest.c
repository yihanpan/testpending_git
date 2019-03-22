#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void printpend(sigset_t *pend)
{
	int i;
	for (i =1; i<32; i++)
	{
		if(sigismember(pend, i)== 1)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
	}
	printf("\n");
}


int main(void)
{
	sigset_t myset, pend, oldset;
	sigemptyset(&myset);
	sigaddset(&myset, SIGQUIT);
	
	sigaddset(&myset, SIGINT);
	sigaddset(&myset, SIGTSTP);
	
	
	sigprocmask(SIG_BLOCK, &myset, &oldset);

	while(1)
	{
		sigpending(&pend);
		printpend(&pend);
		sleep(1);
	}
	
	return 0;	
}
