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


/**
 * a simple double ended queue that allows for pushing and popping from both sides, as well as indexed access to internal array elements.
 *
 * @class deque{ deque.h "GHW03/deque.h"
 * @brief DEQUE
 *
 */
class deque{
 private:
  int **blockmap;
  // number of elements in each block
  int block_size;
  // index of first used element in first used block in blockmap
  int first_element;
  // index of first used block in blockmap
  int first_block;
  // index of first allocated block, used to avoid the need to delete after a pop
  int first_allocated;
  // index of last allocated block, used to avoid the need to delete after a pop
  int last_allocated;
  // number of elements
  int size;
  // total number of blocks in blockmap, both used and unused
  int rowCount;

 public:

/**
 * default constructor, initializes blocksize to 1024 and allocates only the starting block
 *
 * @pre 
 * @post private members given default values, first block is allocated
 * 
 */
  deque();

/**
 * deallocates any allocated blocks
 *
 * @post dynamic memory has been deallocated
 * 
 */
  ~deque();

/**
 * pushes an element to the front end of the deque
 *
 * @param int element the element to add
 * @pre 
 * @return void
 * @post element has been pushed to the front, and size increased by 1
 * 
 */
  void push_front(int element);

/**
 * pops the element at the front of the deque
 *
 * @pre 
 * @return void 
 * @post front element has been popped, and size decreased by 1
 * 
 */
  void pop_front();

/**
 * pushes an element to the back of the deque
 *
 * @param int element the element to add
 * @pre 
 * @return void 
 * @post the element has been added to the back of the deque, and size increased by 1
 * 
 */
  void push_back(int element);

/**
 * pops the element in the back of the deque
 *
 * @pre 
 * @return void 
 * @post the back element has been popped, and size decreased by 1
 * 
 */
  void pop_back();

/**
 * returns a copy of the element at the front of the deque
 *
 * @pre 
 * @return int a copy of the first element in the deque
 * @post 
 * 
 */
  int front();
/**
 * returns a copy of the element at the back of the deque
 *
 * @pre
 * @return int a copy of the last element in the deque
 * @post 
 *
 */
  int back();

/**
 * checks if the deque is empty
 *
 * @pre 
 * @return bool returns true if the deque contains no elements
 * @post 
 * 
 */
  bool empty();

/**
 * returns the size of the deque
 *
 * @pre 
 * @return int number of elements in deque
 * @post 
 * 
 */
  int getSize();

/**
 * operator overload for []
 *
 * @param int index the requested index of an element
 * @pre index should be less than number of elements in deque (size)
 * @return int& reference to element at index in deque
 * @post 
 * 
 */
  int& operator[](int index);
};

#endif //DEQUE_H
