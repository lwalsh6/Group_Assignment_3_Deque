/**
 * @file main.cpp
 * @author Logan Walsh/Zachary Rose
 * @date 2022-11-29
 * @brief Deque Main
 * 
 * The main file for the program, used to run tests
 */

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

