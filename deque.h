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
 * Class for the Double Ended Queue
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
 * basic constructor for the program
 *
 * @pre 
 * @post Any private variables are initialized
 * 
 */
  deque();

/**
 * basic destructor for the program
 *
 * @pre used once the program is finished
 * @post dimensions of the deque have been deleted
 * 
 */
  ~deque();

/**
 * pushes an element to the front end of the queue
 *
 * @param int element the element being pushed
 * @pre called in main
 * @return void returns nothing
 * @post element has been pushed to the front
 * 
 */
  void push_front(int element);

/**
 * pops an element at the front of the queue
 *
 * @pre called in main
 * @return void returns nothing
 * @post front element has been popped
 * 
 */
  void pop_front();

/**
 * pushes an element to the back of the queue
 *
 * @param int element the element being pushed
 * @pre called in main
 * @return void returns nothing
 * @post the element has been pushed to the back of the queue
 * 
 */
  void push_back(int element);

/**
 * pops the element in the back of the queue
 *
 * @pre called in main
 * @return void returns nothing
 * @post the back element has been popped
 * 
 */
  void pop_back();

/**
 * returns the element at the front of the queue
 *
 * @pre called in main
 * @return int returns an integer
 * @post the front element can be used when called
 * 
 */
  int front();
/**
 * returns the element at the back of the queue
 *
 * @pre
 * @return int returns an integer
 * @post the back element can be used when called
 *
 */
  int back();

/**
 * returns a boolean that tells that the queue is empty
 *
 * @pre 
 * @return bool returns a boolean
 * @post can be used in places that will check if the queue is empty
 * 
 */
  bool empty();

/**
 * returns the size of the queue
 *
 * @pre 
 * @return int returns an integer
 * @post the size can be used when called
 * 
 */
  int getSize();

/**
 * operator overload for []
 *
 * @param int index the element in the program
 * @pre 
 * @return int& 
 * @post 
 * 
 */
  int& operator[](int index);
};

#endif //DEQUE_H
