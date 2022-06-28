#include<iostream>
#include<BinarySearchTree.h>
#include<magic_enum.hpp>

using namespace std;

// Test deleteItem facility in the BST.
int main(int argc, char* argv[])
{
  BinarySearchTree<int> bstTree(false);
  for(const auto& item : {15,10,20,8,12,18,16,19,30})
    bstTree.insertItem(item);
  bstTree.doInOrderTraversal();
  vector<bstRebalancePolicy> policyVec={bstRebalancePolicy::successor,
    bstRebalancePolicy::predecessor,
    bstRebalancePolicy::height,
    bstRebalancePolicy::size
  };
  vector<int> itemsToBeDeleted={15, 16, 12, 18};
  for(size_t i=0;i<itemsToBeDeleted.size();++i){
    bstTree.setBSTRebalancePolicy(policyVec[i]);
    cout<<"Case "<<i<<" : Aiming for a root node deletion ("<<itemsToBeDeleted[i]<<") with ";
    cout<<magic_enum::enum_name(bstTree.getBSTRebalancePolicy())<<" policy"<<endl;
    bstTree.deleteItem(itemsToBeDeleted[i]);
    bstTree.doInOrderTraversal();
    cout<<"After the root removal new root is = "<<bstTree.getRoot()->m_data<<endl;
  }
  return(0);
}
