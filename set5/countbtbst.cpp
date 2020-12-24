#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<BinaryTree.h>

using namespace std;

long getFactorial(const int& input)
{
  if(!input)
    return(1);
  else
    return(input*getFactorial(input-1));
}

pair<long,long> getBTBSTCount(const int& input)
{
  long countBT=getFactorial(2*input)/(getFactorial(input+1));
  long countBST=countBT/getFactorial(input);
  pair<long, long> resultPair=make_pair<long, long>(static_cast<long>(countBT), static_cast<long>(countBST));
  return(resultPair);
}

int main(int argc, char* argv[])
{
  vector<int> testCases={0,1,2,3,4,5,6,7,8};
  for(const auto& testCase : testCases)
  {
    pair<long, long> resultPair=getBTBSTCount(testCase);
    cout<<"Total possible BST tree with "<<testCase<<" keys = "<<resultPair.second<<endl;
    cout<<"Total possible BT with "<<testCase<<" keys = "<<resultPair.first<<endl;
  }
  return(0);
}
