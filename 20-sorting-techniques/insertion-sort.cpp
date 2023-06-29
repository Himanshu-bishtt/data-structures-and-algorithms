#include <iostream>

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
};

void insertion_sort(int arr[], int n) {
  int x, i, j;
  for (i = 1; i < n; ++i) {
    x =  arr[i];
    j = i-1;
    while (j > -1 && arr[j] > x) {
      arr[j+1] = arr[j]; // shifting
      j--;
    };
    arr[j+1] = x;
  };
};

void print(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  };
  printf("\n");
};

int main() {
  int arr[8] = {112, 213, 34, 415, 56, 647, 78};

  int length = sizeof(arr)/sizeof(arr[0]);

  print(arr, length);

  insertion_sort(arr, length);

  print(arr, length);
};