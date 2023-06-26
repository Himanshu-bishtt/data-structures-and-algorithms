#include <iostream>
#define SIZE 10

int hash(int key) {
  return key%SIZE;
};

int probe(int H[], int key) {
  int index = hash(key);
  for (int i = 0; i < SIZE; ++i) {
    if (H[index] == 0) return index;
    index++;
  };
  return index;
};

// int probe(int H[], int key) {
//   int index = hash(key);
//   int i = 0;
//   while(H[(index+1)%SIZE] != 0) i++;
//   return (index+i)%SIZE;
// };

int length(int H[]) {
  int length = 1;
  for (int i = 0; i < SIZE; ++i) {
    if (H[i] != 0) length++;
  };
  return length;
};

void insert(int H[], int key) {
  int hashIndex = hash(key);
  int l = length(H);
  double lf = (float)l/SIZE;

  if (lf > 0.5) {
    printf("%d cannot be inserted\n", key);
    return;
  }; 

  if (H[hashIndex] != 0)
    hashIndex = probe(H, key);
  H[hashIndex] = key;
};

void display(int H[]) {
  std::cout<<"*****************Displaying hashtable******************"<<std::endl;
  for (int i = 0; i < SIZE; ++i) {
    printf("Index: %d, Data: %d\n", i, H[i]);
  };
  printf("\n");
};

int search(int H[], int key) {
  int i = 0;
  while(H[i] != key || H[i] == 0)
    i++;
  return i >= SIZE ? -1 : i;
};

// int search(int H[], int key) {
//   int index = hash(key);
//   int i = 0;
//   while(H[(index+1)%SIZE] != key) 
//     i++;
//   return (index+i)%SIZE;
// };

int main() {
  int HT[SIZE] = {0};

  insert(HT, 12);
  insert(HT, 15);
  insert(HT, 22);
  insert(HT, 52);
  insert(HT, 92);
  insert(HT, 19);

  display(HT);

  std::cout<<"Search: "<<search(HT, 12)<<std::endl;
  std::cout<<"Search: "<<search(HT, 92)<<std::endl;
  std::cout<<"Search: "<<search(HT, 15)<<std::endl;
  std::cout<<"Search: "<<search(HT, 100)<<std::endl;

  return 0;
}