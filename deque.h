/**
 * @file deque.h
 * @author Logan Walsh/Zachary Rose
 * @date 2022-11-29
 * @brief Deque Header
 * 
 * Contains the function prototypes for the deque 
 */

#ifndef DEQUE_H
#define DEQUE_H

class deque{
 private:
  int **blockmap;
  // number of elements in each block
  int block_size;
  // index of first used element in first used block in blockmap
  int first_element;
  // index of first used block in blockmap
  int first_block;
  // number of elements
  int size;
  // total number of blocks in blockmap, both used and unused
  int rowCount;

 public:
  deque();
  ~deque();
  void push_front(int element);
  void pop_front();
  void push_back(int element);
  void pop_back();
  int front();
  int back();
  bool empty();
  int getSize();
  int& operator[](int index);
};

#endif //DEQUE_H
