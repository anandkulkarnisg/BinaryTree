#include<iostream>
#include<AVLTree.h>

using namespace std;

// Here we test search and insert functionality. 
// We test if insert functionality returns the node inserted and a proper boolean status.
// We test if the find functionality returns the proper boolean status if found along with node details.

int main(int argc, char* argv[])
{
  AVLTree<int> avlTree(false);
  for(const auto& insertItem : {30, 5, 12, 7, 10}){
    avlTree.insertItem(insertItem);
  }
  pair<bool, BinaryTreeNode<int>*> insertStatus=avlTree.insertItem(50);
  cout<<"insert status = "<<insertStatus.first<<endl;
  cout<<"node inserted with value = "<<insertStatus.second->m_data<<" at address = "<<&insertStatus.second<<endl;
  // Identify if the item can be found.
  pair<bool, BinaryTreeNode<int>*> searchStatus=avlTree.searchItem(10);
  cout<<"search status = "<<searchStatus.first<<endl;
  cout<<"search node status = "<<searchStatus.second->m_data<<endl;  
  // Search something that doesnt exist.
  pair<bool, BinaryTreeNode<int>*> searchStatus2=avlTree.searchItem(20);
  cout<<"search status for non existent 20 = "<<searchStatus2.first<<endl;
  if(!searchStatus2.second)
    cout<<"The searched node for non existent 20 = is null"<<endl;
  return(0);
}
