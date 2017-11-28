#include "analysis.h"
#include <iostream>
#include "QuickMedian.h"
using namespace std;

int main(){
    MaxHeap *k = new MaxHeap();
    k->insert(40);
    k->insert(50);
    k->insert(45);
    k->insert(30);
    k->insert(60);
    k->insert(55);
    k->insert(20);
    k->insert(35);
    k->insert(10);
    k->insert(25);
   
    int max = k->getMax();
    int size = k->getSize();
    cout<<"The max is : "<<max<<" and the size is: "<<size<<endl;
    
    MinHeap *p = new MinHeap();
    p->insert(40);
    p->insert(50);
    p->insert(45);
    p->insert(30);
    p->insert(60);
    p->insert(55);
    p->insert(20);
    p->insert(35);
    p->insert(10);
    p->insert(25);
   
    int min = p->getMin();
    size = p->getSize();
    cout<<"The min is : "<<min<<" and the size is: "<<size<<endl;
    
    QuickMedian *l = new QuickMedian();
    l->insert(40);
    l->insert(50);
    l->insert(45);
    l->insert(30);
    l->insert(60);
    l->insert(55);
    l->insert(20);
    l->insert(35);
    l->insert(10);
    l->insert(25);
   
    double median = l->getMedian();
    cout<<"The median is : "<<median<<endl<<endl<<endl;
    
     heightAnalysis();
    
    return 0;
}
