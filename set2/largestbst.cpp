#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<climits>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

tuple<bool, size_t, int, int> largestBSTInternal(const BinaryTreeNode<int>* node, pair<const BinaryTreeNode<int>*, size_t>& solution)
{
  if(!node)
    return(make_tuple<bool, size_t, int, int>(false,0,0,0));
  if(isLeaf(node))
    return(make_tuple<bool, size_t, int, int>(true,1, static_cast<int>(node->m_data), static_cast<int>(node->m_data)));
  tuple<bool, size_t, int, int> leftSubTreeSolution=largestBSTInternal(node->m_leftChild, solution);
  tuple<bool, size_t, int, int> rightSubTreeSolution=largestBSTInternal(node->m_rightChild, solution);
  tuple<bool, size_t, int, int> result=make_tuple<bool, size_t, int, int>(false, 1, static_cast<int>(node->m_data), static_cast<int>(node->m_data));
  bool leftStatus=true, rightStatus=true;
  if(node->m_leftChild)
  {
    if(!(get<0>(leftSubTreeSolution)&&get<3>(leftSubTreeSolution)<node->m_data))
      leftStatus=false;
  }
  if(node->m_rightChild)
  {
    if(!(get<0>(rightSubTreeSolution)&&get<2>(rightSubTreeSolution)>node->m_data))
      rightStatus=false;
  }
  if(leftStatus)
  {
    if(node->m_leftChild)
    {
      get<1>(result)+=get<1>(leftSubTreeSolution);
      get<2>(result)=min(get<2>(leftSubTreeSolution), node->m_data);
    }
    else
      get<2>(result)=node->m_data;
  }
  if(rightStatus)
  {
    if(node->m_rightChild)
    {
      get<1>(result)+=get<1>(rightSubTreeSolution);
      get<3>(result)=max(get<3>(rightSubTreeSolution), node->m_data);
    }
    else
      get<3>(result)=node->m_data;
  }
  get<0>(result)=leftStatus&&rightStatus;
  //cout<<"for node : "<<node->m_data<<" The results are : "<<get<0>(result)<<","<<get<1>(result)<<","<<get<2>(result)<<","<<get<3>(result)<<endl;
  if(get<0>(result)&&get<1>(result)>solution.second)
  {
    solution.first=node;
    solution.second=get<1>(result);
  }
  return(result);
}

pair<const BinaryTreeNode<int>*, size_t> findLargestBST(const BinaryTreeNode<int>* node)
{
  pair<const BinaryTreeNode<int>*, size_t> solution=make_pair<const BinaryTreeNode<int>*, size_t>(nullptr, 0);
  largestBSTInternal(node, solution);
  return(solution);
}

int main(int argc, char* argv[])
{
  //vector<int> vec={7,5,8,3,9,6,10,2,4,99,99,99,99,99,99};
  //vector<int> vec={4,3,5,2,99,99,6};
  //vector<int> vec={5,2,4,1,3,99,99};
  vector<int> vec={50,30,60,5,20,45,70,99,99,99,99,99,99,65,80};
  BinaryTree<int> tree;
  tree.createFromArray(vec,99);

  // Identify the largest size binary search tree inside this tree. If nothing found return 1 since each node in itself is a BST.
  pair<const BinaryTreeNode<int>*,size_t> solution=findLargestBST(tree.getRoot());
  if(solution.first)
    cout<<"The largest BST is found starting at node : "<<solution.first->m_data<< " with size of BST = " << solution.second<<endl;
  else
    cout<<"There is no BST found inside the given tree."<<endl;
  return(0);
}
