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
* Description : The cpp file with the implementation of the functions of the 
              functions decleared in the header
*/

//constructor
AVLTree :: AVLTree(){
        root = NULL;
}
//inserts a value to the Tree
//makes use of a helper functio that takes root as parameter and value
void AVLTree:: insert(int val){
     helperInsert(root,val);
}

// Helper function for inserting a value to the avl tree starting from root
// the algorithm tries to go recursively until it finds a null node in the BST
// whenever it reaches a null node that means we have found our insertion point.
//  The recursion goes back up and checks the heights at each level up to the root
//  when the difference in heights is greater than one a rotation is applied.
//  To make this easier some helper function based on the rotations in the slides 
//  were applied
void AVLTree:: helperInsert(TreeNode* &root,int val){
     if ( root != NULL) {
        if (root->item < val){
           helperInsert(root->rightChildPtr,val);          //search tfor insertion point first
           int left = getHeightHelper(root->leftChildPtr);
           int right = getHeightHelper(root->rightChildPtr);       //check for the height difference at each node
           int balanceNo = abs(left-right);
               if (balanceNo > 1 && root->rightChildPtr != NULL && root->rightChildPtr->item > val)
                             doubleRightLeftRotation(root);
               else {
                if (balanceNo > 1 && root->rightChildPtr != NULL && root->rightChildPtr->item < val)
                              singleLeftRotation(root);
                }
                            
        } else {
               helperInsert(root->leftChildPtr,val);
               int left = getHeightHelper(root->leftChildPtr);
               int right = getHeightHelper(root->rightChildPtr);
               int balanceNo = abs(left-right);
               if (balanceNo > 1 && root->leftChildPtr != NULL && root->leftChildPtr->item > val) 
                             singleRightRotation(root);
               else {
                    if (balanceNo > 1 && root->leftChildPtr != NULL && root->leftChildPtr->item < val)
                                doubleLeftRightRotation(root);
               }
        }
     } else {
       root = new TreeNode(val);
     }
}
//returns the height of the AVL Tree. Makes use of a helper function
int AVLTree :: getHeight(){
    return getHeightHelper(root);
}

//finds the height of the tree starting from root
int AVLTree :: getHeightHelper(TreeNode* &root){
    if (root == NULL){
             return 0;
    } else {
      int left = getHeightHelper(root->leftChildPtr);
      int right = getHeightHelper(root->rightChildPtr);
      if (left > right)
         return left + 1 ;
      else
          return right + 1; 
    }
}

// Performs single left rotation at point k1
// Note that the rotation follows the same case as in the slides
void AVLTree:: singleLeftRotation(TreeNode* &k1){
     TreeNode *k2 = k1->rightChildPtr;
     TreeNode *B = k2->leftChildPtr;
     
     k2->leftChildPtr = k1;
     k1->rightChildPtr = B;
     k1 = k2;
}

// Performs single right rotation at point k2
// Note that the rotation follows the same case as in the slides
void AVLTree:: singleRightRotation(TreeNode* &k2){
     TreeNode *k1 = k2->leftChildPtr;
     TreeNode *B = k1->rightChildPtr;
     
     k2->leftChildPtr = B;
     k1->rightChildPtr = k2;
     k2 = k1;
}

// Performs double right-left rotation at point k1
// Note that the rotation follows the same case as in the slides
void AVLTree :: doubleRightLeftRotation (TreeNode* &k1){
     singleRightRotation(k1->rightChildPtr);
     singleLeftRotation(k1);
}

// Performs double left-right rotation at point k1
// Note that the rotation follows the same case as in the slides
void AVLTree :: doubleLeftRightRotation (TreeNode* &k3){
     singleLeftRotation(k3->leftChildPtr);
     singleRightRotation(k3);
}

void AVLTree :: displayInorder (){
     displayTreeInorder(root);
}

void AVLTree :: displayTreeInorder(TreeNode *root){
    if (root != NULL){
        //cout<<"Going left of : "<<root->item<<endl;
        displayTreeInorder(root->leftChildPtr);
        //cout<<"Root : "<<root->item<<endl;
        cout <<root->item<<endl;
        //cout<<"Going right of : "<<root->item<<endl;
        displayTreeInorder(root->rightChildPtr);
    }
}
