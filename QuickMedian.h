#include "MaxHeap.h"
#include "MinHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The header file for QuickMedian
*/
class QuickMedian {
    public:
    	QuickMedian();
        void insert(int val);
        double getMedian();	
        int size;			
    private:   
        MaxHeap maxHeap;
        MinHeap minHeap;
        int quickSize;
		
};
