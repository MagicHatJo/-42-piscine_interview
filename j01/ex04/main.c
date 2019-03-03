#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	setbuf(stdin, NULL);
	struct s_queue *queue = queueInit();
	printf("is empty: %d\n", isEmpty(queue));
	printf("empty peek: %s\n", peek(queue));
	enqueue(queue, "Hello");
	printf("is empty: %d\n", isEmpty(queue));
	printf("Peek: %s\n", peek(queue));
	printf("Peek: %s\n", peek(queue));
	printf("pop: %s\n", dequeue(queue));
	printf("is empty:  %d\n", isEmpty(queue));
	enqueue(queue, "Hello");
	enqueue(queue, "There");
	printf("pop: %s\n", dequeue(queue));
	printf("pop: %s\n", dequeue(queue));
	return (0);
}



// Function used for the test
// Don't go further :)

