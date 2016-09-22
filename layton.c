#include <stdio.h>

/*
User puts in a number and from range(1,num), get the individual digits of the number
counts the number of times the digit '1' appears in all the numbers from range(1,num)
*/

int main () {
	int number, count=0, digit, n, i;

	printf("What number?\n");
	scanf("%d", &number);

	for (i=1; i<=number; i++) {
		n = i;
		while (n != 0) {
			digit = n%10; //gets single digits from number
			
			if (digit == 1) {
				count++;
			}
			n = n/10;
			printf("n: %d\n", n);
		} 
	}

	printf("%d\n", count);

	return 0;
}