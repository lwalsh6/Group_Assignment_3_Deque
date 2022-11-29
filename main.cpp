
#include <iostream>
#include "deque.h"

using namespace std;

int main() {
  deque test;
  for (int i = 0; i < 10000; i++){
    test.push_back(i);
  }

  for (int i = 0; i < 10000; i++){
    cout << test[i] << ' ';
  }
 
  cout << endl;
  return 0;
}

