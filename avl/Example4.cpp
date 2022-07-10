#include<AVLTree.h>

void percentTracker(const size_t& idx, const size_t& size)
{
  vector<float> tracker={0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
  for(const auto& iter : tracker)
  { 
    if(idx==iter*size)
      cout<<iter*100<<"% completed"<<endl;
  }
}

int main(int argc, char* argv[])
{
  AVLTree<int> avlTree(false);
  size_t size=1000;
  if(argc==2)
    size=atoi(argv[1]);
  else
    cout<<"defaulting the size of AVL Tree="<<size<<endl;
  for(size_t i=0;i<size;++i){
    avlTree.insertItem(i);
    percentTracker(i, size);
  }
  cout<<"size of the AVL BST is = "<<avlTree.size()<<endl;
  cout<<"height of the AVL BST is = "<<avlTree.height()<<endl;
  return(0);
}
