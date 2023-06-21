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

bool isOperand(char ch) {
  switch(ch) {
    case '+': case '-': case '*': case '/': return false;
    default: return true;
  };
};

int precedence(char ch) {
  switch(ch) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    default: return 0;
  };
};

char * convert(char *infix) {
  int length = strlen(infix);

  st.SIZE = length;
  st.TOP = -1;
  st.s = (char *)malloc((length + 1)* sizeof(char));

  char *postfix = (char *)malloc((length + 1)*sizeof(char));

  int i, j;
  i = j = 0;

  while (infix[i] != '\0') {
    if (isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else {
      if (precedence(stackTop()) < precedence(infix[i]))
        push(infix[i++]);
      else
        postfix[j++] = pop();
    };
  };

  for (int i = st.TOP; i >= 0; --i)
    postfix[j++] = pop();

  return postfix;
};

int main() {
  char expr[] = "a+b*c-d/e";

  printf("Infix: %s\n", expr);

  printf("Postfix: %s\n", convert(expr));

  return 0;
}