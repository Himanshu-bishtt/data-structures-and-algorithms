#include <iostream>
using namespace std;

void printString(char name[]) {
  for (int i = 0; name[i] != '\0'; ++i)  
    cout<<name[i];

  cout<<endl;
}

char * createStringAndReturn(int n) {
  char *p;

  p = (char *)malloc(n*sizeof(char));

  char ch;
  
  cout<<"Enter "<<n<<" Characters"<<endl;

  for (int i = 0; i < n; ++i) {
    cin>>ch;
    p[i] = ch;
  }

  return p;
}

int main() {
  int length = 20;
  char name[length] = {"Himanshu Bisht"};

  printString(name);

  char *p;

  p = createStringAndReturn(length);

  printString(p);

  return 0;
}