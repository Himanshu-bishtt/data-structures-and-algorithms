#include <iostream>
#include "queue.h"

int main() {
  struct Queue q1, q2, q3;

  create(&q1, 10);
  create(&q2, 10);
  create(&q3, 10);

  insert(&q1, &q2, &q3, {100, 1});
  insert(&q1, &q2, &q3, {100, 2});
  insert(&q1, &q2, &q3, {100, 3});
  insert(&q1, &q2, &q3, {111, 1});
  insert(&q1, &q2, &q3, {111, 2});
  insert(&q1, &q2, &q3, {99, 1});
  insert(&q1, &q2, &q3, {25, 1});

  display(q1);
  display(q2);
  display(q3);
};