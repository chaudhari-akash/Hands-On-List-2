/*
============================================================================
Name : 1a.c
Author : Akash Chaudhari
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10 micro second
				a. ITIMER_REAL
				b. ITIMER_VIRTUAL
				c. ITIMER_PROF
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void my_sig()
{
	printf("Timer Expired\n");
}

int main()
{

	struct itimerval new;

	new.it_interval.tv_sec = 10;
	new.it_interval.tv_usec = 10;

	new.it_value.tv_sec = 10;
	new.it_value.tv_usec = 10;

	int status = setitimer(ITIMER_REAL, &new, NULL);

	while (1)
	{
		signal(SIGALRM, my_sig);
	}
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 1a.c -o 1a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./1a
Timer Expired
Timer Expired
Timer Expired
============================================================================
*/