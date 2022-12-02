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
  deque dq;
  cout << "TESTING: push_back" << endl;
  for (int i = 0; i < 5000; i++){
    dq.push_back(i);
  }
  cout << endl;

  cout << "TESTING: push_front" << endl;
  for (int i = 5000; i < 0; i--){
    dq.push_front(i);
  }
  cout << endl;

  cout << "TESTING: [] Overload" << endl;;
  for (int i = 0; i < 5000; i+=100){
    cout << dq[i] << ' ';
  }
  cout << endl;
  
  cout << "TESTING: pop_back" << endl;
  for (int i = 0; i < 5000; i++){
    dq.pop_back();
  }
  cout << endl;

  cout << "TESTING: pop_front" << endl;
  for (int i = 1; i < 5000; i++){
    dq.pop_front();
  }
  cout << endl;

  

  /*for (int i = 0; i < 100; i++){
    test.push_back(i);
  }

  // for (int i = 0; i < 10000; i++){
  //   cout << test[i] << ' ';
  // }
  for (int i = 0; i < 10; i++){
    cout << test.back() << " ";
    test.pop_back();
  }
  for (int i = 0; i < 20000; i++){
    test.push_front(i);
  }
  cout << endl;
  
  for (int i = 0; i < 20000; i+= 1000){
  cout << test[i] << " ";
}
  cout << endl;
  return 0;*/
}

