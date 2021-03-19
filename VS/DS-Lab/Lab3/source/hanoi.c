#include <stdio.h>
#include <stdlib.h>

#define MOVE(N, FROM, TO) printf("move %d from %c to %c\n", N, FROM, TO);


void hanoi(int n, char src, char mid, char dest)
{
	static int stacklv = 0, count = 0; 
	stacklv++;
	
	//hanoi recursion
	if (n == 1)
	{
		MOVE(1, src, dest);
		count++;
	}
	else if (n > 1)
	{
		hanoi(n - 1, src, dest, mid); 
		MOVE(n, src, dest);
		count++; 
		hanoi(n - 1, mid, src, dest);
	}

	// check stack level
	// if finished, print final move count and exit
	if (stacklv == 1 && count != 0)
	{
		printf("total move count is %d\n", count);
		return;
	}
	// pop off stack
	stacklv--; 
}


int main()
{
	int n;
	printf("enter number of blocks: ");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'B', 'C');
}



