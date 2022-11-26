
#include <iostream>
#include "deque.h"

using namespace std;

int main() {
  deque test;
  for (int i = 0; i < 100; i++){
    test.push_front(i);
  }

  for (int i = 0; i < 100; i++){
    cout << test[i] << ' ';
  }
  cout << endl;
  return 0;
}

