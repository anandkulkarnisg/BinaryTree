#include<AVLTree.h>

const char* boolToString(const bool& b){
  if(b)
    return("true");
  return("false");
}

int main(int argc, char* argv[])
{
  AVLTree<int> avlTree(false);
  // Generated random numbers using `$-1_raze {(,/)(string x,",")}each 0N?100 / thx to kdb+
  vector<int> randItems={39,29,13,77,58,78,83,43,59,3,69,23,64,53,91,37,82,61,99,85,98,63,92,9,31,5,80,0,
  84,75,95,26,54,15,49,40,22,25,19,38,73,36,18,50,27,14,47,20,55,32,74,42,94,12,57,88,89,65,34,6,97,16,71,
  46,72,90,41,52,24,67,93,76,62,51,86,66,21,30,70,60,4,11,45,2,81,35,44,17,10,28,7,33,56,68,79,87,96,48,1,8
  };
  for(const auto& singleRandItem : randItems)
    avlTree.insertItem(singleRandItem);
  avlTree.doInOrderTraversal(); 
  cout<<"AVL Tree size="<<avlTree.size()<<endl;
  cout<<"AVL Tree height="<<avlTree.height()<<endl;
  cout<<"AVL Tree root item ="<<avlTree.getRoot()->m_data<<endl;
  cout<<"AVL Tree height balanced status="<<boolToString(avlTree.isHeightBalanced())<<endl;
  cout<<"AVL Tree perfect status="<<boolToString(avlTree.isPerfect())<<endl;
  cout<<"AVL Tree full status="<<boolToString(avlTree.isFull())<<endl;
  cout<<"AVL tree degenerate status="<<boolToString(avlTree.isDegenerate())<<endl;
  cout<<"AVL tree isBST status="<<boolToString(avlTree.isBST())<<endl;
  cout<<"AVL tree isEmpty status="<<boolToString(avlTree.isEmpty())<<endl;
  return(0);
}
