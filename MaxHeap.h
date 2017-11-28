/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The header file for the Max Heap Implementation
*/

class MaxHeap {
          
    public:
    	MaxHeap();				
    	bool MaxHeapIsEmpty() const;
    
    	
        void insert(int val); 
        int getMax(); 
        int removeMax();
        int getSize(); 
        void printMaxHeap();
    
    
    protected:
    	void maxHeapRebuild(int root);	
    	void reallocateMaxHeap();
    					
    private:
    	int          *items;	
    	int          size;            
    	int          maxSize;
};
