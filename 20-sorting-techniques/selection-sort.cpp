#include <iostream>

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
};

void selection_sort(int arr[], int n) {
  int k, j;
  for (int i = 0; i < n-1; ++i) {
    k = j = i;
    for (int j = i+1; j < n; ++j) {
      if (arr[j] < arr[k]) k = j;
    };
    if (k != i) swap(arr[i], arr[k]);
  };
};

void display(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout<<arr[i]<<" ";
  };
  std::cout<<std::endl;
}

int main() {
  int arr[] = {32, 12, 55, 67, 32, 66, 1};
  
  int length = sizeof(arr)/sizeof(arr[0]);

  display(arr, length);

  selection_sort(arr, length);

  display(arr, length);
};