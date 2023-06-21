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
    cout<<"Enter "<<i+1<<"st value: ";
    cin>>value;
    p[i] = value;  
  };

  for (int i = 0; i < n; ++i)
    cout<<p[i]<<endl;

  
  cout<<"-------------------------------"<<endl;

  int *p1;
  char *p2;
  float *p3;
  double *p4;

  cout<<sizeof(p1)<<endl;
  cout<<sizeof(p2)<<endl;
  cout<<sizeof(p3)<<endl;
  cout<<sizeof(p4)<<endl;

  return 0;
}