#include <iostream>

void swap(int* xp, int* yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
};

int main() {
  int arr[] = {5, 7, 3, 2, 54, 12, 654};

  int length = sizeof(arr)/sizeof(arr[0]);

  bool swapped = false;

  for (int i = 0; i < length - 1; i++) {
    swapped = false;
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      };
    };
    if (swapped == false) break;
  };

  printf("Array...\n");

  for (int i = 0; i < length; ++i) {
    std::cout<<arr[i]<<" ";
  };

  printf("\n");
}