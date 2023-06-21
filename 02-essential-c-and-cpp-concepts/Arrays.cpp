#include<iostream>

using namespace std;

int main() {
	int array1[5] = {5, 4, 3, 2, 1};
	int array2[5] = {1,2,3,4,5};
	int array3[10] = {0};
	int a = 0;

	for (int i = 0; i < 5; ++i) {
		array3[a++] = array1[i];
	};


	for (int i = 0; i < 5; ++i) {
		array3[a++] = array2[i];
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (array3[i] < array3[j]) {
				int temp = array3[i];
				array3[i] = array3[j];
				array3[j] = temp;
			}
		}
	};

	for (int x: array3)
		cout<<x<<endl;

	return 0;
}
