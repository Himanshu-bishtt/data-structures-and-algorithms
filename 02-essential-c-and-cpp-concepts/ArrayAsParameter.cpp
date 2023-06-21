#include <iostream>

using namespace std;

void printArray(int arr[], int length) {
  cout<<"------------------------------------"<<endl;
  for (int i = 0; i < length; ++i)
    cout<<arr[i]<<endl;

  // This will not work
  // for (int x: arr)
  //   cout<<x<<endl;
}

void incrementArrayValues(int arr[], int length) {
  for (int i = 0; i < length; ++i) {
    arr[i]++;
  }

}

int * createIntArrayOfSize(int n) {
  int *p;

  p = (int*)malloc(n*sizeof(int));

  if (p == NULL) {
    cout<<"Dyanamic memory allocation failed :("<<endl;
  };

  cout<<"Array of size "<<n<<" successfully created dynamically :)"<<endl;

  for (int i = 0; i < n; ++i) {
    int x;
    cout<<"Enter value "<<i+1<<": ";;
    cin>>x;
    p[i] = x;
  }

  return p;
}

int main() {
  int A[5] = {53, 13, 54, 22, 65};
  int length = sizeof(A)/sizeof(A[0]);

  printArray(A, length);

  incrementArrayValues(A, length);

  printArray(A, length);

  int *p;

  p = createIntArrayOfSize(length);

  printArray(p, length);

  free(p);

  int *t;

  if (t == NULL) 
    cout<<"Null Pointed"<<endl;

  return 0;
}