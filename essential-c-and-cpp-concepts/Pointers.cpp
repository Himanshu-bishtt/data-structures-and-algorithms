#include <iostream>

using namespace std;

int main() {
  int *p;
  int n = 5;

  // p = (int*)malloc(n*sizeof(int));
  p = new int[5];

  cout<<"Enter "<<n<<" values"<<endl;

  int value;

  for (int i = 0; i < n; ++i) {
    cin>>value;
    p[i] = value;  
  };

  for (int i = 0; i < n; ++i)
    cout<<p[i]<<endl;


  return 0;
}