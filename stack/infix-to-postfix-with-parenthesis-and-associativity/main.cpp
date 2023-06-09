#include <iostream>
#include <string.h>

struct Stack {
  int SIZE;
  int TOP;
  char *s;
} st;

void push(char ch) {
  if (st.TOP == st.SIZE - 1) {
    std::cout<<"Stack overflow"<<std::endl;
    return;
  };
  st.s[++st.TOP] = ch;
};

char pop() {
  char ch;
  if (st.TOP == -1) {
    std::cout<<"Stack underflow"<<std::endl;
    return '\0';
  };
  ch = st.s[st.TOP];
  st.s[st.TOP--] = '\0';
  return ch;
};

char stackTop() {
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
    default: return 0;
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

int main() {
  char expression[] = "((a+b)*c)-d^e^f";

  printf("Infix: %s\n", expression);

  printf("Postfix: %s\n", convert(expression));
  
  return 0;
}