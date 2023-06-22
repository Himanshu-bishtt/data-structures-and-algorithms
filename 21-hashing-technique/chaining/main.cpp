#include <iostream>
#include "HashTable.h"

int main() {
  int A[] = {100, 16, 12, 25, 39, 6, 122, 5, 68, 75};

	int n = sizeof(A)/sizeof(A[0]);

	HashTable hashtable;

	for (int i=0; i<n; i++) hashtable.insert(A[i]);

  hashtable.display();

  Node *temp = hashtable.search(66);

  std::cout<<(temp ? "Successful search": "Unsuccessful search")<<std::endl;

  int removed = hashtable.remove(100);

  std::cout<<"Item deleted: "<<removed<<std::endl;

  hashtable.display();

  removed = hashtable.remove(75);

  std::cout<<"Item deleted: "<<removed<<std::endl;

  hashtable.display();

  return 0;
}