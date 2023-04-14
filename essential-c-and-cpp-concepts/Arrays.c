#include<stdio.h>

int main() {
	int n;

	printf("Enter size: ");

	scanf("%d", &n);


	int array[n];

	printf("Enter %d elements\n", n);

	for (int i = 0; i < n; ++i) {
		printf("Enter %d value: ", i+1);
		scanf("%d", &array[i]);
	}

	printf("Printing values: ");

	for (int i = 0; i < n; ++i)
		printf("%d, ", array[i]);

	printf("\n");

	return 0;
}
