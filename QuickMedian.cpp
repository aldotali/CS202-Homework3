#include "QuickMedian.h"
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
QuickMedian :: QuickMedian() : quickSize(0){
            minHeap = MinHeap();
            maxHeap = MaxHeap();
}

// insert to quickmedian. Here the half of the numbers are kept in max heap half are kept on the min heap
// the first half is a max heap the second a min heap. The median is either one of the numbers in top of
// the heaps or their average
void QuickMedian :: insert(int val){
     if (quickSize % 2 == 0){
        quickSize++;
        minHeap.insert(val);
     } else {
        if ( minHeap.getSize() > maxHeap.getSize()){
           maxHeap.insert(val);
        }  else
           maxHeap.insert(val);
        quickSize++;
     }
}

//calculate median
// even numebr of inserted items means we take the average of the middle two numbers
double QuickMedian :: getMedian(){
       if ( quickSize % 2 == 0) {
          return (minHeap.getMin() + maxHeap.getMax())/2.0;
       } else {
         if ( minHeap.getSize() > maxHeap.getSize()){
            return (double)minHeap.getMin();
         } else{
           return (double)maxHeap.getMax();
         }
       }
}
