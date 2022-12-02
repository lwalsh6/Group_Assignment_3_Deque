# Group-Assignment-3-Deque-Toolkit
Names: Logan Walsh, Zachary Rose  
Date: 12/2/2022

An implementation for a double ended queue, and a driver that displays the deque functionality in console through print statements and comments.

## Required Files
* main.cpp --> The main driver, used to display functionality and stress test the deque.
* deque.h --> The header file for the deque class.
* deque.cpp --> Contains the deque class implementation, a simple double ended queue that allows for pushing and popping from both sides, as well as indexed access to internal array elements.
* Makefile --> Used to compile all of the files.
* README.md --> A mythical file that is speculated to explain what a program is for.

## Compilation instructions

Type "make" to compile the program.

## Program usage

* To launch the program, type "./deque"
* User inputs the number of elements to add to the deque, and the tests run on their own and print to console

## Design Decisions
* blocksize was set to 1024 to match with the STL.
* first_element was set to 40 by default to allow for some push_front before starting a new block.
* private members first_allocated and last_allocated prevent needing to delete after popping out of a block.
* Due to difficulties with pointer magic, pointer engineering was used instead.
  * When a brand new block (row) is added to the blockmap, each row pointer is copied over directly. No efficiency loss was seen up to 2000000 elements.
* operator[] returns some element in the first block if an out of bound index is attempted, simply to avoid throwing an exception, but the behavior should be considered undesirable.
  * A large negative index will likely cause a fault, but that should be avoided during implementation.
* A relatively low number of rows is included in the blockmap by default to make it easier to test both:
  *  allocating existing but unallocated blocks.
  *  adding brand new rows to the blockmap when pushing.
## Challenges
* Figuring out how the deque would work with a 2D Array was hard due to a lack of a solid in-class example.  
* Some of the initial drafts of the functions could lead to memory leaks, ways to prevent these had to be found.
* Working with the pointers and keeping track of all the internal private variables was difficult.
* Got some great practice debugging with GDB, especially concerning printing out variables and stepping/nextlining large amounts to skip forward partially through a large loop.

## Work Distribution
Logan wrote the initial structure for the class as well as most of the documentation, while Zachary finished off most of the implementation. We worked together to finish any remaining functions, the test cases and made any changes we felt were necessary. 
