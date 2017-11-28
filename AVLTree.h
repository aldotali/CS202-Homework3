#include "TreeNode.h"
/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : A header file for including the AVL Tree functions
*/

class AVLTree{
      private :
              TreeNode *root;
       protected:
              void helperInsert(TreeNode* &root,int val);
              int  getHeightHelper(TreeNode* &root);
              void singleLeftRotation(TreeNode* &k1);
              void singleRightRotation(TreeNode* &k2);
              void doubleRightLeftRotation (TreeNode* &k1);
              void doubleLeftRightRotation (TreeNode* &k3);
              void displayTreeInorder(TreeNode *root);
         
      public :
             AVLTree();
             void insert(int val); 
             int getHeight();
             void displayInorder();
};
