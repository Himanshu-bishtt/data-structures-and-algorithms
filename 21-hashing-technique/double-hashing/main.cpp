#include <iostream>
#define SIZE 10
#define PRIME 7

int hash(int key) {
  return key % SIZE;
};

int prime_hash(int key) {
  return PRIME - (key % PRIME);
};

int double_hash(int H[], int key) {
  int i1 = hash(key);
  int i2 = prime_hash(key);
  int i = 0;
  while (H[(i1 + i * i2) % SIZE] != 0) 
    i++;
  return (i1 + i * i2) % SIZE;
};

int length(int H[]) {
  int l = 1;
  for (int i = 0; i < SIZE; ++i)
    if (H[i] != 0) l++;
  return l;
};

void display(int H[]) {
  std::cout<<"*****************Displaying hashtable******************"<<std::endl;
  for (int i = 0; i < SIZE; ++i) {
    printf("Index: %d, Data: %d\n", i, H[i]);
  };
  printf("\n");
};


void insert(int H[], int key) {
  int index = hash(key);
  double lf = (float)length(H)/SIZE;

  if (lf > 0.5) {
    printf("Cannot insert %d\n", key);
    return;
  };

  if (H[index] != 0)
    index = double_hash(H, key);
  H[index] = key;
};

int search(int H[], int key) {
  int i1 = hash(key);
  int i2 = prime_hash(key);
  int i = 0;

  while(H[(i1 + i * i2) % SIZE] != key && H[(i1 + i * i2) % SIZE] != 0) 
    i++;

  if (H[(i1 + i * i2) % SIZE] != key) return -1;
  return (i1 + i * i2) % SIZE;
};

int main() {
  int HT[SIZE] = {0};

  insert(HT, 5);
  insert(HT, 25);
  insert(HT, 35);
  insert(HT, 45);

  display(HT);

  std::cout<<"Search: "<<search(HT, 25)<<std::endl;
  std::cout<<"Search: "<<search(HT, 55)<<std::endl;
  std::cout<<"Search: "<<search(HT, 5)<<std::endl;
};