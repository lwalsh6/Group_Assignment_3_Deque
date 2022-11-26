#include <iostream>
#include "deque.h"

using namespace std;

deque::deque(){
  block_size = 1024;
  first_element = 40;
  first_block = 3;
  size = 0;
  rowCount = 10;
  blockmap = new int*[rowCount];
  // allocate first block only
  blockmap[first_block] = new int[block_size];
}

deque::~deque(){
  // final row in use that needs to be deallocated
  int final_used_row;
  // FIX THIS memory leak for now
}

void deque::push_front(int element){
  // column of the current first element
  int col = first_element % block_size;
  int row = first_block + (first_element / block_size);
  // if there is room in the current block
  if (col > 0){
    blockmap[row][col - 1] = element;
    size++;
    first_element--;
  }
  // if there is no more room in the current block, check if a new block must be allocated
  //  else{
    // if a new block is not yet needed
    // if (row > first_block){
    //   // put element at the last position in the previous block
    //   row--;
    //   col = block_size - 1;
      
    //   blockmap[row][col] = element;
    //   size++;
    //   first_element = block_size - 1;
  //    }
  
  // if a new block is needed
  else{
    // if there is still an unused block in the blockmap
    if (row - 1 > 0){
      blockmap[row - 1] = new int[block_size];

      row--;
      col = block_size - 1;

      blockmap[row][col] = element;
      
      first_block--;
      size++;
      first_element = block_size - 1;
    }
    // if there is no more room in the blockmap, add 3 more pointers
    else{
      int **newerBlockMap = new int*[rowCount + 3];
      // allocate new row
      newerBlockMap[2] = new int[block_size];
      first_block = 2;
      col = block_size - 1;
	
      // grab all block pointers from previous map
      for (int i = 0; i < rowCount; i++){
	newerBlockMap[i + 3] = blockmap[i];
      }
	
      rowCount += 3;
      blockmap = newerBlockMap;

      blockmap[row][col] = element;
      size++;
      first_element = block_size - 1;
    }
  }
}

void deque::pop_front(){
  // potential problem with still having a valid block?
  size--;
  first_element++;
}

void deque::push_back(int element){

}
void deque::pop_back(){

}

int deque::front(){
  return this->operator[](0);
}

int deque::back(){
  return this->operator[](size - 1);
}

bool deque::empty(){
  // boolean, returns true if greater than 0
  return size;
}

int deque::getSize(){
  return size;
}

int& deque::operator[](int index){
  // int division
  int row = first_block + (first_element + index) / block_size;
  int col = (index + first_element) % block_size;

  return blockmap[row][col];
}
