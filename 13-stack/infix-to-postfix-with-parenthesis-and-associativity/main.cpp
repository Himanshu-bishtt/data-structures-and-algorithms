#include <iostream>
#include <string.h>
#include <stdlib.h>

struct Stack {
  int SIZE;
  int TOP;
  int *s;
} st;

void push(int ch) {
  if (st.TOP == st.SIZE - 1) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  st.s[++st.TOP] = ch;
};

int pop() {
  int ch;
  if (st.TOP == -1) {
    std::cout<<"Stack underflow"<<std::endl;
    return '\0';
  };
  ch = st.s[st.TOP];
  st.s[st.TOP--] = '\0';
  return ch;
};

int stackTop() {
  return st.s[st.TOP];
};

bool isEmpty() {
  return st.TOP == -1;
};

bool isOperand(char ch) {
  switch(ch) {
    case '+': case '-': case '*': case '/': case '^': case '(': case ')': return false;
    default: return true;
  };
};

int outPre(char ch) {
  switch(ch) {
    case '+': case '-': return 1;
    case '*': case '/': return 3;
    case '^': return 6;
    case '(': return 7;
    case ')': return 0;
    default: return -1;
  };
};

int inPre(char ch) {
  switch(ch) {
    case '+': case '-': return 2;
    case '*': case '/': return 4;
    case '^': return 5;
    case '(': return 0;
    default: return -1;
  };
};

/*
  char * convert(char * infix) {
    int length = strlen(infix);
    st.SIZE = length;
    st.TOP = -1;
    st.s = (char *)malloc(st.SIZE * sizeof(char));

    char *postfix = (char *)malloc(st.SIZE * sizeof(char));

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
      if (isOperand(infix[i])) 
        postfix[j++] = infix[i++];
      else {
        if (isEmpty() || outPre(infix[i]) > inPre(st.s[st.TOP]))
          push(infix[i++]);
        else {
          if (outPre(infix[i]) == inPre(st.s[st.TOP])) {
            pop();
            i++;
          } else {
            postfix[j++] = pop();
          };
        };
      };
    };

    while(!isEmpty()) postfix[j++] = pop();

    return postfix;
  };
*/

int operation(int x1, int x2, char op) {
  switch(op) {
    case '+':
      return x1+x2;
    case '-':
      return x1-x2;
    case '*':
      return x1*x2;
    case '/':
      return x1/x2;
    default:
      return -999;
  };
};

// only valid for single digit operand
int evaluate(char *postfix) {
  int length = strlen(postfix);
  st.SIZE = length;
  st.TOP = -1;
  st.s = (int *)malloc(length * sizeof(int));
  
  int i, x1, x2, r;
  i = 0;

  while(postfix[i] != '\0') {
    if (isOperand(postfix[i]))  
      push(postfix[i++] - '0');
    else {
      x2 = pop(); x1 = pop();
      r = operation(x1, x2, postfix[i]);
      push(r);
      i++;
    };
  };
  return pop();
};

int main() {
  // char expression[] = "3*5+6/2-4";

  // printf("Infix: %s\n", expression);

  // char *postfix = convert(expression);

  // printf("Postfix: %s\n", postfix);

  char postfix[] = "234*+82/-";

  printf("Result: %d\n", evaluate(postfix));

  return 0;
}