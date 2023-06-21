#include<string>
#include<iostream>

using namespace std;

struct Student {
  int id;
  char name[20];
};

struct Card {
  int face;
  string shape;
};

int main() {
  struct Card deck[52];
  int count = 0;
  int faces = 13;
  int shapes = 4;

  for (int i = 1; i <= faces; ++i) {
    for (int j = 1; j <= shapes; ++j) {
      switch(j) {
        case 1:
          deck[count].shape = "HEARTS";
          break;

        case 2:
          deck[count].shape = "SPADES";
          break;

        case 3:
          deck[count].shape = "DIAMONDS";
          break;

        case 4:
          deck[count].shape = "CLUBS";
          break;
      }
      deck[count].face = i;
      count++;
    }
  };

  count = 0;

  for (int i = 1; i <= faces; ++i) {
    for (int j = 1; j <= shapes; ++j) {
      if (deck[count].shape == "DIAMONDS")
        cout<<"Face: "<<deck[count].face<<", Shape: "<<deck[count].shape<<endl;
      count++;
    }
  }

  return 0;
}