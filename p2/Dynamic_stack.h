/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  z353yang@uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Fall 2018
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    - null
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    - null
 *****************************************/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>
using namespace std;


class Dynamic_stack {

	private:
		int *array;
		int count;		
		int array_size;
		int initial_size;
	
	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
			
		void push( int const & );
		int pop();
		void clear();		
};

Dynamic_stack::Dynamic_stack( int n ):
count( 0 ),
array_size( n ),
initial_size(n)
{
	array_size = (n < 1) ? 1 : n;	// reassign size to 1 if less than 1
	initial_size = array_size;
	array = new int[array_size];
}


Dynamic_stack::~Dynamic_stack() {
	delete[] array;
}


int Dynamic_stack::top() const {
	if (count == 0)
		throw underflow();
	return array[count-1];
}


int Dynamic_stack::size() const {
	return count;
}


bool Dynamic_stack::empty() const {
	return (count == 0);
}


int Dynamic_stack::capacity() const {
	return array_size;
}


void Dynamic_stack::push( int const &obj ) {
	// reallocate if stack is full
	if (count == array_size) {
		int *newstack = new int[2 * array_size];
		array_size += array_size;
		for (int i = 0; i < count; i++)
			newstack[i] = array[i];
		delete[] array;		// delete original stack
		array = newstack;
	}
	array[count++] = obj;		// push in new element
}


int Dynamic_stack::pop() {
	if (count == 0)
		throw underflow();
	return array[--count];	// pop out element and return it
}

void Dynamic_stack::clear() {
	count = 0;	// clear the stack
	if (array_size != initial_size) {	// reallocate if not size changed
		delete[] array;
		array = new int[initial_size];
		array_size = initial_size;
	}
}
#endif
