#include "MaxHeap.h"
#include <iostream>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The cpp file with the implementation of the functions of the 
              functions decleared in the header
*/

//constructor
MaxHeap::MaxHeap() : size(0) {
             items = new int[2];
             maxSize = 2;
}


//checks if heap is empty
bool MaxHeap::MaxHeapIsEmpty() const {
	return (size == 0);
}

// note that this implementation was taken from the slides given that 
// we were allowed to use it.
// however minor changes were made to the code to make it fit better into the assignment
void MaxHeap::maxHeapRebuild(int root){
     int child = 2 * root + 1; 	
	if ( child < size ) {		
		int rightChild = child + 1; 	
		if ( (rightChild< size) &&
		     (items[rightChild] >items[child]) )
			child = rightChild; 	

		if ( items[root] < items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			maxHeapRebuild(child);
		}
  }
}

//reallocates the heap by doubling its size
void MaxHeap:: reallocateMaxHeap(){
     maxSize = 2* maxSize;
     int *newItems = new int [maxSize];
     for (int i = 0; i < size; i++){
         newItems[i] = items[i];
     }
     delete[] items;
     items = newItems;
     newItems = NULL;
     
}

//inserts a new value into the heap
void MaxHeap:: insert(int val){
     
   	if (size >= maxSize)
		reallocateMaxHeap();

	items[size] = val;
	
	int place = size;
	int parent = (place - 1)/2;
	while ( (place >= 0) && (items[place] >items[parent]) ) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}


int MaxHeap:: getMax(){
    if (size > 0)
       return items[0];
    else
        return -27;
}


int MaxHeap:: removeMax(){
    int rootItem;
    if (MaxHeapIsEmpty())
		cout<<"HeapException: Heap empty"<<endl;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		maxHeapRebuild(0);
	}
	return rootItem;
}

//returns the size of the heap
int MaxHeap:: getSize(){
    return size;
}

void MaxHeap::printMaxHeap(){
     for (int i = 0; i < size; i++){
         cout<<items[i]<<" ";
     }
     cout<<endl;
}
