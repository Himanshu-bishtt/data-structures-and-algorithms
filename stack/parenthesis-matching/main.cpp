#include <iostream>

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
  st.TOP++;
  st.s[st.TOP] = ch;
};

char pop() {
  char ch;
  if (st.TOP == -1) {
    std::cout<<"Stack underflow"<<std::endl;
    return 'x';
  };
  ch = st.s[st.TOP];
  st.s[st.TOP] = '\0';
  st.TOP--;
  return ch;
};

bool isEmpty() {
  return st.TOP == -1;
}

bool isBalance(char *expression, int length) {
  st.SIZE = length;
  st.TOP = -1;
  st.s = new char[st.SIZE];

  for (int i = 0; expression[i] != '\0'; ++i) {
    if (expression[i] == '(')
      push(expression[i]);
    else if (expression[i] == ')') {
      // checking if the stack is empty but the expression still contains closing parenthesis
      if (isEmpty()) return false;
      pop();
    };
  };
  // at this point if the stack is empty, then parenthesis are matching
  return isEmpty();
};

char stackTop() {
  return st.s[st.TOP];
};

bool isBalanced(char *expression, int length) {
  st.SIZE = length;
  st.TOP = -1;
  st.s = new char[st.SIZE];

  for (int i = 0; expression[i] != '\0'; ++i) {
    if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
      push(expression[i]);
    } else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')') {
      if (isEmpty()) return false;
      if (expression[i] == '}' && stackTop() == '{') pop();
      if (expression[i] == ']' && stackTop() == '[') pop();
      if (expression[i] == ')' && stackTop() == '(') pop();
    };
  };
  return isEmpty();
};

int main() {
  char expression[] = {'(','(','a','+','b',')','*','(','c','-','d',')',')'};

  char expr[] = "{(a+b)*[(c+d)*(a+d)]}";

  int length = sizeof(expr)/sizeof(expr[0]);

  bool v = isBalanced(expr, length);

  std::cout<<"Parenthesis matching: "<<(v ? "True" : "False")<<std::endl;

  // int length = sizeof(expression)/sizeof(expression[0]);

  // std::cout<<"Parenthesis matching: "<<(isBalance(expression, length) ? "True" : "False")<<std::endl;

  // printf("\n");

  return 0;
}