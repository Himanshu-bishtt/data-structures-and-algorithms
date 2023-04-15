#include<string>
#include<iostream>

using namespace std;

struct Student {
  int id;
  char name[20];
};

enum FACE {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum SHAPE {HEART, SPADE, CLUB, DIAMOND};
enum COLOR {BLACK, WHITE};

struct Card {
  int face;
  int shape;
  int color;
};

int main() {
  struct Card deck[52];
  int count = 0;

  for (int i = ACE; i <= KING; ++i) {
    for (int j = HEART; j <= DIAMOND; ++j) {
      for (int k = BLACK; k <= WHITE; ++k) {
        deck[count].face = i;
        deck[count].shape = j;
        deck[count].color = k;
      }
    count++;  
    }
  };

  count = 0;

  for (int i = ACE; i <= KING; ++i) {
    for (int j = HEART; j <= DIAMOND; ++j) {
      for (int k = BLACK; k <= WHITE; ++k) {
        cout<<"Face: "<<deck[count].face<<", Shape: "<<deck[count].shape<<", Color: "<<deck[count].color<<endl;
      }
  count++; 
    }
  };

  cout<<"Count: "<<count<<endl;

  return 0;
}