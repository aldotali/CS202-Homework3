#include "MinHeap.h"
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
MinHeap::MinHeap() : size(0) {
             items = new int[2];
             maxSize = 2;
}

//checks if heap is empty
bool MinHeap::MinHeapIsEmpty() const {
	return (size == 0);
}

//reallcotaes the heap to twice its size
void MinHeap:: reallocateMinHeap(){
     maxSize = 2* maxSize;
     int *newItems = new int [maxSize];
     for (int i = 0; i < size; i++){
         newItems[i] = items[i];
     }
     delete[] items;
     items = newItems;
     newItems = NULL;
     
}

//inserts a new value to the heap
void MinHeap:: insert(int val){
   	if (size >= maxSize)
		reallocateMinHeap();

	items[size] = val;

	int place = size;
	int parent = (place - 1)/2;
	while ( (place >= 0) && (items[place] < items[parent]) ) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}


int MinHeap:: getMin(){
     return items[0];
}

int MinHeap:: removeMin(){
    int rootItem;
    if (MinHeapIsEmpty())
		cout<<"HeapException: Heap empty"<<endl;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		MinHeapRebuild(0);
	}
	return rootItem;
}

void MinHeap:: MinHeapRebuild(int root){
     int child = 2 * root + 1; 	
	if ( child < size ) {		
		
		int rightChild = child + 1; 	
	
		if ( (rightChild < size) &&
		     (items[rightChild] < items[child]) )
			child = rightChild; 	

		if ( items[root] > items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			MinHeapRebuild(child);
		}
  }
}


int MinHeap:: getSize(){
    return size;
}

void MinHeap::printMinHeap(){
     for (int i = 0; i < size; i++){
         cout<<items[i]<<" ";
     }
     cout<<endl;
}
