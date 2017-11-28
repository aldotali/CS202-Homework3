/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The header file for a Min heap Implementation
*
*/

class MinHeap {
public:
	MinHeap();				
	bool MinHeapIsEmpty() const;

	
    void insert(int val); 
    int getMin(); 
    int removeMin(); 
    int getSize(); 
    void printMinHeap();


protected:
	void MinHeapRebuild(int root);		
	void reallocateMinHeap();
					
private:
	int          *items;	
	int          size;            		
	int          maxSize;
};
