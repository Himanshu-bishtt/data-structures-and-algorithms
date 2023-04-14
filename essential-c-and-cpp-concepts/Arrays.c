#include<stdio.h>

int main() {
	int array[10];

	for (int i = 0; i < 10; ++i) {
		printf("Enter %d value: ", i+1);
		scanf("%d", &array[i]);
	};

	printf("Printing 10 elements: ");

	for (int i = 0; i < 10; ++i)
		printf("%d, ", array[i]);

	return 0;
}
