#include <iostream>
#define SIZE 10

int hash(int key) {
  return key%SIZE;
};

int probe(int H[], int key) {
  int index = hash(key);
  int i = 0;
  while((H[(index+i*i)%SIZE]) != 0) i++;
  return (index+i*i)%SIZE;
};

int length(int H[]) {
  int total = 1;
  for (int i = 0; i < SIZE; ++i)
    if (H[i] != 0) 
      total++;
  return total;
};

void insert(int H[], int key) {
  int index = hash(key);
  double lf = (float)length(H)/SIZE;

  if (lf > 0.5) {
    printf("Cannot insert %d\n", key);
    return;
  };

  if (H[index] != 0)
    index = probe(H, key);
  H[index] = key;
};

int search(int H[], int key) {
  int index = hash(key);
  int i = 0;
  while(H[(index+i*i)%SIZE] != key && H[(index+i*i)%SIZE] != 0) i++;
  if (H[(index+i*i)%SIZE] != key) return -1;
  return (index+i*i)%SIZE;
};

void display(int H[]) {
  std::cout<<"*****************Displaying hashtable******************"<<std::endl;
  for (int i = 0; i < SIZE; ++i) {
    printf("Index: %d, Data: %d\n", i, H[i]);
  };
  printf("\n");
};

int main() {
  int HT[SIZE] = {0};

  insert(HT, 10);
  insert(HT, 20);
  insert(HT, 30);
  insert(HT, 45);
  insert(HT, 19);

  display(HT);

  std::cout<<"Search: "<<search(HT, 19)<<std::endl;
  std::cout<<"Search: "<<search(HT, 22)<<std::endl;
  std::cout<<"Search: "<<search(HT, 20)<<std::endl;
  std::cout<<"Search: "<<search(HT, 10)<<std::endl;
  std::cout<<"Search: "<<search(HT, 45)<<std::endl;

  return 0;
};