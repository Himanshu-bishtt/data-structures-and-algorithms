#include <iostream>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
};

void bubble_sort(int arr[], int n) {
  bool swapped = false;
  for (int i = 0; i < n - 1; ++i) {
    swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      };
    };
    if (!swapped) break;
  };
};

void print(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  };
  printf("\n");
};

int main() {
  int arr[] = {8, 5, 7, 3, 2};

  int length = sizeof(arr)/sizeof(arr[0]);

  bubble_sort(arr, length);

  print(arr, length);

  return 0;
}