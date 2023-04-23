#include <iostream>

using namespace std;

int main() {
  int row1, col1, row2, col2;

  cout<<"Enter row1 and col1: ";
  cin>>row1>>col1;

  cout<<"Enter row2 and col2: ";
  cin>>row2>>col2;

  if (!(row1 == row2 && col1 == col2))  {
    cout<<"Matrix addition not possible!";
    return 0;
  };

  int matrix1[row1][col1];
  int matrix2[row2][col2];
  int matrix3[row1][col2];

  cout<<"Enter matrix1 elements"<<endl;

  for (int i = 0; i < row1; ++i) {
    for (int j = 0; j < col1; ++j) {
      cout<<"Enter element ("<<i<<" "<<j<<") : ";
      cin>>matrix1[i][j];
    }
  }

  cout<<"Enter matrix2 elements"<<endl;

  for (int i = 0; i < row2; ++i) {
    for (int j = 0; j < col2; ++j) {
      cout<<"Enter element ("<<i<<" "<<j<<") : ";
      cin>>matrix2[i][j];
    }
  }

  for (int i = 0; i < row2; ++i)
    for (int j = 0; j < col2; ++j)
      matrix3[i][j] = matrix1[i][j] + matrix2[i][j];

  cout<<"Matrix 1"<<endl;

  for (int i = 0; i < row1; ++i) {
    for (int j = 0; j < col1; ++j)
      cout<<matrix1[i][j]<<" ";
    cout<<endl;
  }

  cout<<"Matrix 2"<<endl;
  
  for (int i = 0; i < row2; ++i) {
    for (int j = 0; j < col2; ++j)
      cout<<matrix2[i][j]<<" ";
    cout<<endl;
  };

  cout<<"Matrix 3"<<endl;

  for (int i = 0; i < row2; ++i) {
    for (int j = 0; j < col2; ++j) {
      cout<<matrix3[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}