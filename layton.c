#include <stdio.h>

int main () {
	int number, count=0, digit, n, i;

	printf("What number?\n");
	scanf("%d", &number);

	for (i=1; i<=number; i++) {
		n = i;
		while (n != 0) {
			digit = n%10; //gets single digits from number
			
			//printf("digit: %d\n", digit);
			if (digit == 1) {
				count++;
				//printf("count: %d\n", count);
			}
			n = n/10;
			printf("n: %d\n", n);
		} 
	}

	printf("%d\n", count);

	return 0;
}