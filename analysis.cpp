#include <iostream>
#include "AVLTree.h"
#include <stdlib.h> 
#include <iomanip>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : A cpp file for the implemetnation of the general functions used for the assignment
*/


//fills the tree with random integers
int fillWithRandom(int size){
    AVLTree p = AVLTree();
    for (int i = 0; i < size; i++ ) {
        p.insert(rand());    
    }
    return p.getHeight();
}

//fills the tree with ascending integers 
int fillWithAscending(int size){
    AVLTree p = AVLTree();
    for (int i = 0; i < size; i++ ) {
        p.insert(i);    
    }
    return p.getHeight();
}

//fills the tree with descending integers
int fillWithDescending(int size){
    AVLTree p = AVLTree();
    for (int i = size; i > 0; i-- ) {
        p.insert(i);    
    }
    return p.getHeight();
}

//perform height analysis on different sizes of insertion on the tree
void heightAnalysis(){
     int diffSizes = 20;
     int sizes[20] = {1000, 2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
     int random, asc, desc;
     
     cout<< "Part e - Height Analysis of AVL Trees"<<endl;
     cout<< "------------------------------------------------------------------------------"<<endl;
     cout<< "Array Size"<<setw(20)<<"Random"<<setw(20)<<"Ascending"<<setw(20)<<"Descending"<<endl;
     cout<< "------------------------------------------------------------------------------"<<endl;
     
     for ( int i = 0; i < diffSizes; i++) {
         random =  fillWithRandom(sizes[i]);
         asc = fillWithAscending(sizes[i]);
         desc = fillWithDescending(sizes[i]);
         cout<<sizes[i]<<setw(20)<<random<<setw(20)<<asc<<setw(20)<<desc<<endl;
     }
}
