#include<iostream>

using namespace std;

int main() {
	int n;

	cout<<"Enter size: ";
	cin>>n;

	int array[n] = {10, 20};

	for (int x: array)
		cout<<x<<endl;

	return 0;
}
