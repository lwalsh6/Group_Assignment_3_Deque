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
  // number of elements to push to front AND back of deque
  int STRESS_TEST;
  
  deque dq;
  cout << "Enter number of elements to push to the front AND back of the deque (20 - 1000000): ";
  cin >> STRESS_TEST;
  
  // enforces bounds on the number of cases
  STRESS_TEST %= 1000001;
  if (STRESS_TEST < 0)
    STRESS_TEST *= -1;
  if (STRESS_TEST < 20)
    STRESS_TEST += 20;

  
  //Push tests
  cout << "TESTING: push_back with elements 0 -> " << STRESS_TEST << endl;
  for (int i = 0; i <= STRESS_TEST; i++){
    dq.push_back(i);
  }
  cout << "Finished push_back" << endl;
  cout << endl;

  cout << "TESTING: push_front with elements " << STRESS_TEST << " -> 0" << endl;
  for (int i = STRESS_TEST; i >= 0; i--){
    dq.push_front(i);
  }
  cout << "Finished push_front" << endl;
  cout << endl;
  
  cout << "For reference, the deque currently looks like this: 0, 1, ... " << STRESS_TEST << ", 0, 1, ... " << STRESS_TEST << endl << endl;
  
  //Operator overload print test
  cout << "TESTING: [] Overload. Printing every " << STRESS_TEST / 20 << "th index from 0 to " << STRESS_TEST << endl;
  for (int i = 0; i <= STRESS_TEST; i += STRESS_TEST / 20){
    cout << dq[i] << ' ';
  }
  cout << endl;
  cout << "Printing every " << STRESS_TEST / 20 << "th index from " << 1 + STRESS_TEST << " to the end" << endl;
  for (int i = STRESS_TEST + 1; i <= STRESS_TEST * 2 + 1; i += STRESS_TEST / 20){
    cout << dq[i] << ' ';
  }
  cout << endl << endl;

  //Popping Tests, pops a fourth of the elements from the front and back, and shows size before and after
  cout << "TESTING: pop_back " << STRESS_TEST / 4 << " times" << endl;
  cout << "\tSize Before Pop: " << dq.getSize() << endl;
  cout << "\tPOPPING BACK..." << endl;
  for (int i = 0; i < STRESS_TEST / 4; i++){
    dq.pop_back();
  }
  cout << "\tSize After Pop: " << dq.getSize() << endl;
  cout << endl;

  cout << "TESTING: pop_front " << STRESS_TEST / 4 << " times" << endl;
  cout << "\tSize Before Pop: " << dq.getSize() << endl;
  cout << "\tPOPPING FRONT..." << endl;
  for (int i = 0; i < STRESS_TEST / 4; i++){
    dq.pop_front();
  }
  cout << "\tSize after Pop: " << dq.getSize() << endl;
  cout << endl;

  // front() and back() test
  cout << "TESTING: front() and back()" << endl;
  cout << "\tCurrent front element: " << dq.front() << endl;
  cout << "\tPOPPING FRONT..." << endl;
  dq.pop_front();
  cout << "\tCurrent front element: " << dq.front() << endl;
  
  cout << "\tCurrent back element: " << dq.back() << endl;
  cout << "\tPOPPING BACK..." << endl;
  dq.pop_back();
  cout << "\tCurrent back element: " << dq.back() << endl;
  return 0;
}

