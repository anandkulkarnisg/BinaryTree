#include<AVLTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  AVLTree<int> avlTree(false);
  vector<int> insertItems={10, 27, 15, 12, 27};
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  for(const auto& insertItem : insertItems)
  {
    pair<bool, BinaryTreeNode<int>*> insertStatus=avlTree.insertItem(insertItem);
    if(insertStatus.first)
    {
      cout<<"The insert status of the item = true"<<endl;
      cout<<"The item inserted was = "<<insertStatus.second->m_data<<endl;
    }
    else
    {
      cout<<"The insert status of the item = false"<<endl;
      if(!insertStatus.second)
        cout<<"The inserted item is null"<<endl;
      else
        cout<<"The inserted item is = "<<insertStatus.second->m_data<<endl;
    }
  }
  // Demonstrate the search functionality which also returns a pair.
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  vector<int> searchItems={10, 12, 32, 15, 27, 53};
  for(const auto& searchItem : searchItems)
  {
    pair<bool, BinaryTreeNode<int>*> searchStatus=avlTree.searchItem(searchItem);
    if(searchStatus.first)
    {
      cout<<"The search status of the item = "<<searchItem<<" is true"<<endl;
      cout<<"The item searched was = "<<searchStatus.second->m_data<<endl;
    }
    else
    {
      cout<<"The item searched for = "<<searchItem<<" was not found"<<endl;
      if(!searchStatus.second)
        cout<<"The searched item status is null"<<endl;
      else
        cout<<"The searched item is = "<<searchStatus.second->m_data<<endl;
    }
  }
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  return(0);
}
