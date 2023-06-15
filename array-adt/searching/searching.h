#include <iostream>
#include <math.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};

int linear_search(int arr[], int n, int key) {
  for (int i = 0; i < n; ++i)
    if (arr[i] == key) return i;
  return -1;
};

int transposition_linear_search(int arr[], int n, int key) {
  for (int i = 0; i < n; ++i) {
    if (arr[i] == key) {
      if (i-1 >= 0) {
        swap(&arr[i], &arr[i-1]);
        return i-1;
      };
      return i;
    };
  };
  return -1;
};

int move_to_head_linear_search(int arr[], int n, int key) {
  for (int i = 0; i < n; ++i) {
    if (arr[i] == key) {
      swap(&arr[i], &arr[0]);
      return 0;
    };
  };
  return -1;
};

int binary_search(int arr[], int n, int key) {
  int left = 0, right = n - 1;
  while(left <= right) {
    int mid = floor((left + right)/2);
    if (arr[mid] == key) return mid;
    if (key < arr[mid]) right = mid-1;
    if (key > arr[mid]) left = mid+1;
  };
  return -1;
};

int recursive_binary_search(int arr[], int n, int left, int right, int key) {
  if (left <= right) {
    int mid = floor((left + right)/2);
    if (key == arr[mid]) return mid;
    else if (key > arr[mid]) return recursive_binary_search(arr, n, mid+1, right, key);
    else return recursive_binary_search(arr, n, left, mid-1, key); 
  };
  return -1;
};