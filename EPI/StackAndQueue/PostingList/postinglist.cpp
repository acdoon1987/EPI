#include<iostream>
#include <memory>
using namespace std;

struct NodePostingList {
    NodePostingList():order(-1),jump(nullptr),next(nullptr){}
    int order;
    shared_ptr<NodePostingList> jump;
    shared_ptr<NodePostingList> next;

}node;

void SetJumpFirstOrderHelper(const shared_ptr<NodePostingList>& list, int* order) {
    if(list && list.get()->order == -1) {
        list.get()->order = (*order)++;
        SetJumpFirstOrderHelper( list.get()->jump ,order);
        SetJumpFirstOrderHelper( list.get()->next ,order);
    }
}
void SetJumpFirstOrder( const shared_ptr<NodePostingList>& list) {
    int order =0;
    SetJumpFirstOrderHelper(list,&order);
}

shared_ptr<NodePostingList> CreateList(){

   shared_ptr<NodePostingList> node(new NodePostingList());

   NodePostingList* currNode = node.get();
   for(int i=0; i<5; i++) {
       shared_ptr<NodePostingList> nodeNew(new NodePostingList());
       currNode->next =nodeNew;
       currNode = nodeNew.get();
   }
  return node;
}
int main() {
SetJumpFirstOrder(CreateList());
}
