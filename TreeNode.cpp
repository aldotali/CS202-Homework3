#include "TreeNode.h"
#include <iostream>

/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The cpp file with the implementation of the functions of the 
              functions decleared in the header
*/

using namespace std;

TreeNode :: TreeNode (){
         leftChildPtr = NULL;
         rightChildPtr = NULL;
}

TreeNode :: TreeNode ( const int & anItem ){
         item = anItem;
         leftChildPtr = NULL;
         rightChildPtr = NULL;
}
TreeNode :: TreeNode ( const int & anItem ,
                    TreeNode * leftPtr ,
                    TreeNode * rightPtr ) {

         item = anItem;
         leftChildPtr = leftPtr;
         rightChildPtr = rightPtr;          
}
