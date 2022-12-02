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

  //Push tests
  cout << "TESTING: push_back with 5000 coordinates" << endl;
  for (int i = 0; i < 5000; i++){
    dq.push_back(i);
  }
  cout << "Finished Push_back" << endl;
  cout << endl;

  cout << "TESTING: push_front with 5000 coordinates" << endl;
  for (int i = 5000; i < 0; i--){
    dq.push_front(i);
  }
  cout << "Finished Push_front" << endl;
  cout << endl;

  //Operator overload print test
  cout << "TESTING: [] Overload" << endl;;
  for (int i = 0; i < 5000; i+=100){
    cout << dq[i] << ' ';
  }
  cout << endl;

  //Pop Function Tests
  cout << "TESTING: pop_back 10 times" << endl;
  cout << "\tSize Before Pop: " << dq.getSize() << endl;
  cout << "\tPOPPING BACK..." << endl;
  for (int i = 0; i < 10; i++){
    dq.pop_back();
  }
  cout << "\tSize After Pop: " << dq.getSize() << endl;
  cout << endl;

  cout << "TESTING: pop_front 10 times" << endl;
  cout << "\tSize Before Pop: " << dq.getSize() << endl;
  cout << "\tPOPPING FRONT..." << endl;
  for (int i = 1; i < 10; i++){
    dq.pop_front();
  }
  cout << "\tSize after Pop: " << dq.getSize() << endl;
  cout << endl;
  
  return 0;
}

