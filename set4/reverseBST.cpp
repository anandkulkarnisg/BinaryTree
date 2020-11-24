#include<algorithm>
#include<climits>
#include<iostream>
#include<string>
#include<thread>
#include<utility>
#include<vector>

#include<BinaryTree.h>
#include<CyclicBarrier.h>

using namespace std;

void inOrderTraversal(BinaryTreeNode<int>* node, const size_t& iterations, size_t& currIterations, 
    const bool& mode, tuple<int*, int*>& swapPair, CyclicBarrier& preBarrier, CyclicBarrier& postBarrier
    )
{
  if(!node||currIterations>=iterations)
    return;
  if(mode)
    inOrderTraversal(node->m_leftChild, iterations, currIterations, mode, swapPair, preBarrier, postBarrier);
  else
    inOrderTraversal(node->m_rightChild, iterations, currIterations, mode, swapPair, preBarrier, postBarrier);
  preBarrier.await();
  if(mode)
    get<0>(swapPair)=&node->m_data;
  else
    get<1>(swapPair)=&node->m_data;
  postBarrier.await();
  if(mode)
  {
    int temp=*get<0>(swapPair);
    *get<0>(swapPair)=*get<1>(swapPair);
    *get<1>(swapPair)=temp;
    ++currIterations;
  }
  if(mode)
    inOrderTraversal(node->m_rightChild, iterations, currIterations, mode, swapPair, preBarrier, postBarrier);
  else
    inOrderTraversal(node->m_leftChild, iterations, currIterations, mode, swapPair, preBarrier, postBarrier);
}

void reverseBST(BinaryTree<int>& tree)
{
  BinaryTreeNode<int>* node=tree.getRoot();
  if(!node)
    return;
  if(tree.isDegenerate()) // A degenerate BST, Ex: linked list BST, below algorithm wont work.It will only work for height balanced BST.
  {
    cout<<"Degenerate BST not supported!!"<<endl;
    return;
  }
  const size_t iterations=tree.size()/2;
  tuple<int*, int*> swapPair=make_tuple<int*, int*>(&node->m_data, &node->m_data);
  constexpr short barrierPair=2;
  size_t currIter=0;
  CyclicBarrier preBarrier(barrierPair), postBarrier(barrierPair);
  thread t1(&inOrderTraversal, node, std::cref(iterations), std::ref(currIter), true,  std::ref(swapPair), std::ref(preBarrier), std::ref(postBarrier));
  thread t2(&inOrderTraversal, node, std::cref(iterations), std::ref(currIter), false, std::ref(swapPair), std::ref(preBarrier), std::ref(postBarrier));
  t1.join();
  t2.join();
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{4,2,6,1,3,5,7},{4,3,5,2,99,99,6},{},
                                 {6,4,8,3,5,7,11,2,99,99,99,99,99,10,12,1,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
                                 {1,2,99,3,99,99,99}
                                };
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    reverseBST(tree);
    cout<<"After : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
