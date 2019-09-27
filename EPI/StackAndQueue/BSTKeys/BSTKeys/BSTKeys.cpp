#include <iostream>
#include <vector>
#include<stack>

using namespace std;

template<typename T>
struct BSTNode
{
    BSTNode(T _d):data(_d){ left =nullptr; right = nullptr; }
    BSTNode* left;
    BSTNode* right;
    T data;
};

vector<int> BSTinSortedOrder( const BSTNode<int> & tree){
    stack<const BSTNode<int>*> stk;
    vector<int> result;
    const auto* currNode =  &tree;

    while(!stk.empty() || currNode ) {
        if(currNode) {
        stk.push(currNode);
        currNode = currNode->left;
        }
        else {
          currNode = stk.top();
                    stk.pop();
          result.push_back(currNode->data);
          currNode = currNode->right;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
     BSTNode<int>* node = new BSTNode<int>(7);
     BSTNode<int>* node2 = new BSTNode<int>(3);
     BSTNode<int>* node3 = new BSTNode<int>(9);
     BSTNode<int>* node4 = new BSTNode<int>(1);
     BSTNode<int>* node5 = new BSTNode<int>(5);
     BSTNode<int>* node6 = new BSTNode<int>(8);
     BSTNode<int>* node7 = new BSTNode<int>(15);
     node->left = node2;
     node->right = node3;
     node2->left = node4;
     node2->right = node5;
     node3->left = node6;
     node3->right = node7;


     vector<int> result;
     result = BSTinSortedOrder(*node);

     for(auto a: result)
     {
         cout<< a <<endl;
     }
    return 0;
}
