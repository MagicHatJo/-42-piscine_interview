#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	printf("Init Successful\n");
	tankPush(tank, 10);
	printTanks(tank);
	tankPush(tank, 50);
	printTanks(tank);
	printf("popped: %d\n", tankPop(tank));
	printTanks(tank);
	tankPush(tank, 980);
	printTanks(tank);
	tankPush(tank, 100);
	printTanks(tank);
	tankPush(tank, 890);
	printTanks(tank);
	tankPush(tank, 500);
	printTanks(tank);
	printf("popped: %d\n", tankPop(tank));
	printTanks(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
