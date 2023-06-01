#include <iostream>
#include <math.h>

int linear_search(int arr[], int n, int key) {
  for (int i = 0; i < n; ++i)
    if (arr[i] == key) return i;
  return -1;
};

int binary_search(int arr[], int n, int key) {
  int left = 0, right = n - 1;

  while (left <= right) {
    // int mid = left + (right - left) / 2;

    int mid = floor((left + right)/2);

    if (arr[mid] == key) return mid;

    if (arr[mid] < key) {
      left = mid + 1;
    };

    if (arr[mid] > key) {
      right = mid - 1;
    };
  };

  return -1;
}