#include <iostream>
#include "hanoi.h"

void print(Stack<int>** s)
{
  s[0]->hanoiPrint();
  s[1]->hanoiPrint();
  s[2]->hanoiPrint();
  std::cout << '\n';
}

void hanoi(int len, int i, int k, Stack<int>** s)
{
  if(len == 1) {
    s[k]->Push(s[i]->Pop());
    print(s);
  } else {
    int tmp = 3 - i - k;
    hanoi(len - 1, i, tmp, s);
    s[k]->Push(s[i]->Pop());
    print(s);
    hanoi(len - 1, tmp, k, s);
  }
}