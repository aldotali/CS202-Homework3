/**
* Title : Heaps and AVL Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 02
* Assignment : 3
* Description : The header file to implement a TreeNode
*/
class TreeNode
{
    private :
        int item ; 
        TreeNode * leftChildPtr ; 
        TreeNode * rightChildPtr ;
        
    public :
        TreeNode () ;
        TreeNode ( const int & anItem ) ;
        TreeNode ( const int & anItem ,
                    TreeNode * leftPtr ,
                    TreeNode * rightPtr ) ;
        friend class AVLTree;
};
