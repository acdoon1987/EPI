#include "cbinarytree.h"
#include <stdexcept>
#include <tuple>
CBinaryTree::CBinaryTree():root(nullptr)
{

}

template<typename T>
void CBinaryTree<T>::insert(T data)
{
    if(root == nullptr){
        root =  new  BinaryTreeNode<T>(data);
    }

    if(root->data > data){
        root->left = insert(root->left,data);
    }
    else if (root->data < data) {
        root->right = insert(root->right,data);
    }
}

template<typename T>
bool CBinaryTree::IsBalanced()
{
    return checkBalanced(root).first;
}

template<typename T>
void CBinaryTree<T>::remove(T data)
{
    if(root == nullptr)
        throw std::length_error("Empty Binary Tree");

    if(root->data > data)
    {
        root->left = removeNode(root->left,data);
    }
    else if(root->data < data) {
        root->right =  removeNode(root->right,data);
    }
    else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {

             BinaryTreeNode<T>* tmp = root;
             root = root->right;
             delete tmp;
        }
        else if(root->right == nullptr) {
            BinaryTreeNode<T>* tmp = root;
            root = root->left;
            delete tmp;
        }//Two children//
        else{
            BinaryTreeNode<T>* node = findMinNode(root->right);
            root->data = node->data;
            root->right = removeNode(root->right,node->data);
        }
    }
}

template<typename T>
CBinaryTree::BinaryTreeNode* CBinaryTree<T>::removeNode(BinaryTreeNode<T> *node, T data)
{
   if(node->data > data)
       node->left = removeNode(node->left,data);
   else if (node->data < data) {
       node->right = removeNode(node->right,data);
   }
   else {//Node is a leaf Node
       if(node->left == nullptr && node->right == nullptr) {
           delete node;
           node = nullptr;
       }
       else if (node->left == nullptr) {
           BinaryTreeNode<T>* tmp = node;
           node =  node->right;
           delete tmp;
       }
       else if(node->right == nullptr) {
           BinaryTreeNode<T>* tmp = node;
           node = node->left;
           delete tmp;
       }// 2 children
       else {
           BinaryTreeNode<T>* tmp = findMinNode(node->right);
           node->data = tmp->data;
           node->right = removeNode(node->right,tmp->data);
       }
   }
   return node;
}

template<typename T>
CBinaryTree::BinaryTreeNode* CBinaryTree<T>::findMinNode(BinaryTreeNode<T> * node)
{
   if(node ==  nullptr)
       throw std::length_error(" node is null");

    BinaryTreeNode<T>* minNode;

    while (node != nullptr) {

        minNode = node;
        if(node->left != nullptr)
        {
            node = node->left;
        }
        else{
            break;
        }
    }
    return minNode;
}

template<typename T>
std::pair<bool,int> CBinaryTree::checkBalanced(BinaryTreeNode<T> * node)
{
    if(node == nullptr)
        return {true,-1};
    bool isleftBalanced , isRightBalanced;
    int leftHeight , rightHeight;
    std::tie(isleftBalanced,leftHeight) = checkBalanced(node->left);
     if(!isleftBalanced){
         return {false ,0};
     }
     std::tie(isRightBalanced,rightHeight) = checkBalanced(node->right);
     if(!isRightBalanced)
         return {false,0};
     bool is_balanced = abs(leftHeight - rightHeight) <=1;

     int height = std::max(leftHeight,rightHeight);
     return {is_balanced,height};


}




template<typename T>
CBinaryTree::BinaryTreeNode<T>* CBinaryTree<T>::insert(BinaryTreeNode<T> *node, T data)
{
      if(node == nullptr)
        node =  new BinaryTreeNode<T>(data);

      if(node->data > data) {
          node->left = insert(node->left,data);
      }else if (node->data < data) {
          node->right = insert(node->right,data);
      }
      return node;
}


