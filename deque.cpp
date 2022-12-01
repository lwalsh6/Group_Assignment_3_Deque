#include <iostream>
#include "deque.h"

using namespace std;

deque::deque(){
  block_size = 1024;
  first_element = 40;
  first_block = 3;
  size = 0;
  rowCount = 5;
  
  blockmap = new int*[rowCount];
  // allocate first block only
  blockmap[first_block] = new int[block_size];
  first_allocated = first_block;
  last_allocated = first_block;
}

deque::~deque(){
  // deallocate rows between first_allocated and last_allocated
  for (int i = first_allocated; i <= last_allocated; i++){
    delete[] blockmap[i];
    cout << "deleting block: " << i << endl;
  }

}

void deque::push_front(int element){
  // column and row of the current first element
  int col = first_element % block_size;
  int row = first_block + (first_element / block_size);
  // if there is room in the current block
  if (col > 0){
    blockmap[row][col - 1] = element;
    size++;
    first_element--;
  }  
  // if a new block is needed
  else{
    // if there is still an unused and unallocated block in the blockmap
    if (row > 0 && first_allocated == row){
      blockmap[row - 1] = new int[block_size];

      row--;
      col = block_size - 1;

      blockmap[row][col] = element;
      
      first_block--;
      first_allocated = first_block;
      size++;
      first_element = col;
    }
    // if there is an unused but previously allocated block in the blockmap
    else if (row > 0 && first_allocated < row){
      row--;
      col = block_size - 1;

      blockmap[row][col] = element;

      first_block--;
      size++;
      first_element = col;
    }
    // if there is no more room in the blockmap, add another row
    else{
      int **newerBlockMap = new int*[rowCount + 1];
      // allocate new row
      newerBlockMap[0] = new int[block_size];
      first_block = 0;
      first_allocated = 0;
      col = block_size - 1;
	
      // grab all block pointers from previous map, from i + 1 to the end
      for (int i = 0; i < rowCount; i++){
       	newerBlockMap[i + 1] = blockmap[i];
      }
      
      // couldn't get this pointer nonsense to work, had to do less efficient loop above
      // newerBlockMap[1] = blockmap[0];
      
      rowCount++;
      blockmap = newerBlockMap;

      // row set to new allocated block
      row = 0;
      blockmap[row][col] = element;
      size++;
      first_element = col;

      // last allocated block has moved up one relative to beginning
      last_allocated++;
    }
  }
}

void deque::pop_front(){
  // if empty, don't worry about valid data and simply return
  if (size == 0)
    return;
  
  size--;
  first_element++;
  
  // if popping the front moves the first element up a block
  if (first_element >= block_size){
    first_element = 0;
    first_block++;
  }
}

void deque::push_back(int element){
  // if nothing has been added yet, add first element
  if (size == 0){
    blockmap[first_block][first_element] = element;
    size++;
    return;
  }
  
  // column and row of the current last element
  int row = first_block + (first_element + size - 1) / block_size;
  int col = (size - 1 + first_element) % block_size;
  // if there is room in the current block
  if (col < block_size - 1){
    blockmap[row][col + 1] = element;
    size++;
  }  
  // if a new block is needed
  else{
    // if there is still an unused and unallocated block in the blockmap
    if (row < rowCount - 1 && row == last_allocated){
      blockmap[row + 1] = new int[block_size];

      row++;
      col = 0;
      last_allocated = row;
      
      blockmap[row][col] = element;
      size++;
    }
    // if there is an unused but previously allocated block in the blockmap
    else if (row < rowCount - 1 && row < last_allocated){
      row++;
      col = 0;
      
      blockmap[row][col] = element;
      size++;
    }
    // if there is no more room in the blockmap, add another row
    else{
      int **newerBlockMap = new int*[rowCount + 1];
      // allocate new row at the last block in the blockmap
      newerBlockMap[rowCount] = new int[block_size];
      last_allocated = rowCount;
      
      // grab all block pointers from previous map
      for (int i = 0; i < rowCount; i++){
       	newerBlockMap[i] = blockmap[i];
      }
      
      rowCount++;
      blockmap = newerBlockMap;

      // add new element in first position of newest block
      row++;
      col = 0;
      blockmap[row][col] = element;
      size++;
    }
  }
}
void deque::pop_back(){
  // if empty, don't worry about valid data and simply return
  if (size == 0)
    return;
  
  size--;
}

int deque::front(){
  return this->operator[](0);
}

int deque::back(){
  return this->operator[](size - 1);
}

bool deque::empty(){
  return size == 0;
}

int deque::getSize(){
  return size;
}

int& deque::operator[](int index){
  // row and column of index
  int row = first_block + (first_element + index) / block_size;
  int col = (index + first_element) % block_size;
  
  // invalid index, return an index from the first used block
  if (index >= size){
    return blockmap[first_block][col];
  }

  
  return blockmap[row][col];
}
