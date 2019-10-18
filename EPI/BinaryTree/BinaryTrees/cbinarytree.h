#ifndef CBINARYTREE_H
#define CBINARYTREE_H
#include <algorithm>
template<typename T>
class CBinaryTree
{
public:
    CBinaryTree();
  void  insert(T data);
  bool  IsBalanced();
  void remove(T data);

private:
    template<typename T>
    class BinaryTreeNode
    {
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    public:
        BinaryTreeNode(T data):data(data),left(nullptr),right(nullptr) {}

    };
   BinaryTreeNode<T>* root;

  std::pair<bool,int>  checkBalanced(BinaryTreeNode<T>*);
   BinaryTreeNode*  insert(BinaryTreeNode<T>* , T);
   BinaryTreeNode* removeNode(BinaryTreeNode<T>*,T );
   BinaryTreeNode* findMinNode(BinaryTreeNode<T>*);

};
#include<cbinarytree.cpp>
#endif // CBINARYTREE_H
