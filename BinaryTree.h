#include<boost/circular_buffer.hpp>
#include<boost/iostreams/copy.hpp>
#include<boost/iostreams/filter/gzip.hpp>
#include<boost/iostreams/filtering_streambuf.hpp>
#include<boost/iostreams/filtering_stream.hpp>
#include<boost/tokenizer.hpp>
#include<cfloat>
#include<climits>
#include<cmath>
#include<fstream>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;
using namespace boost;
using namespace boost::iostreams;

#ifndef BinaryTree_H
#define BinaryTree_H

template<typename T> struct BinaryTreeNode
{
  T m_data;
  BinaryTreeNode<T>* m_leftChild;
  BinaryTreeNode<T>* m_rightChild;
  BinaryTreeNode(const T& data)
  {
    m_data=data;
    m_leftChild=m_rightChild=nullptr;
  }
};

template<typename T> constexpr T defaultVal = T(FLT_MIN);
template<> constexpr int defaultVal<int> = INT_MIN;
template<> constexpr float defaultVal<float> = FLT_MIN;
template<> constexpr long defaultVal<long> = LONG_MIN;
template<> constexpr char defaultVal<char> = '!';
template<> constexpr size_t defaultVal<size_t> = ULONG_MAX;
template<> constexpr const char* defaultVal<const char*> = "$%#$%#$";
template<> string defaultVal<string> = "$%#$%#$";

// A converter function that helps the serialization functions do proper data conversion while loading data stored on disk from string.
template<typename T> T converter(const string& ref)
{
  return(static_cast<T>(ref));
}
template<> int converter(const string& ref)
{
  return(stoi(ref));
}
template<> long converter(const string& ref)
{
  return(stol(ref));
}

template<> float converter(const string& ref)
{
  return(stof(ref));
}

template<> char converter(const string& ref)
{
  return(char(ref[0]));
}

template<> size_t converter(const string& ref)
{
  return(stoul(ref));
}

template<> const char* converter(const string& ref)
{
 return(ref.c_str()); 
}

template<> string converter(const string& ref)
{
  return(ref);
}

template<typename T> class BinaryTree
{
  private:
    BinaryTreeNode<T>* m_root=nullptr;
    bool m_initialized=false;
    T m_overrideVal=defaultVal<T>;
    bool m_isStrict=true;
    map<string, size_t> m_propertyCache;
    void deleteBinaryTree(BinaryTreeNode<T>*);
    void sizeInternal(BinaryTreeNode<T>*, size_t&);
    size_t heightInternal(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* clone(const BinaryTreeNode<T>*);
    BinaryTreeNode<T>* BSTFromSortedArrayInternal(const vector<T>&, const long&, const long&);
    void createFromLevelArrayInternal(const vector<size_t>&, const vector<T>&);

    void doInOrderTraversalInternal(const BinaryTreeNode<T>* node, vector<T>* ref=nullptr);
    void doPreOrderTraversalInternal(const BinaryTreeNode<T>* node, vector<T>* ref=nullptr);
    void doPostOrderTraversalInternal(const BinaryTreeNode<T>* node, vector<T>* ref=nullptr);

    void serializeInternal(const BinaryTreeNode<T>*, size_t&, vector<size_t>&, vector<T>&);
    BinaryTreeNode<T>* deserializeInternal(const vector<T>&, const T&, size_t&);
    bool areIdentical(const BinaryTreeNode<T>*, const BinaryTreeNode<T>*);
 
    void isPerfectInternal(const BinaryTreeNode<T>*, size_t& violation, unordered_set<size_t>& hashSet, size_t currentLevel=0);
    void isCompleteInternal(const BinaryTreeNode<T>* node, size_t& violation, unordered_set<size_t>& levelHash, size_t level=0);
    void isFullInternal(const BinaryTreeNode<T>*, size_t&);
    bool hasBothChildren(const BinaryTreeNode<T>*);
    long isBalancedInternal(const BinaryTreeNode<T>*, size_t&);
    void isDegenerateInternal(const BinaryTreeNode<T>*, size_t&, size_t&);
    void isBSTInternal(const BinaryTreeNode<T>*, circular_buffer<T>&, size_t&, size_t&, size_t&);

    string getSerializePath(const string&) const;

  public:
    // Key constructor, copy and assignment supported.The creation by pointer and reference are deep copy without using/owning the passed in parameter i.e pointer/reference.
    BinaryTree(const bool& isStrict=true);
    BinaryTree(const vector<T>& input, const bool& isStrict=true);
    BinaryTree(BinaryTreeNode<T>*, const bool& isStrict=true, const bool& cleanInput=false);
    BinaryTree(const BinaryTree<T>&);
    bool operator!=(const BinaryTree<T>&);
    BinaryTree<T>& operator=(const BinaryTree<T>&);

    // move constructor and assignment operators.
    BinaryTree(BinaryTree<T>&&);
    BinaryTree<T>& operator=(BinaryTree<T>&&);

    // provide equality comparison operator.
    bool operator==(const BinaryTree<T>&);

    // Key properties of the binary tree. size, height and level information.
    size_t size();
    size_t height();
    size_t levels();

    // This allows somebody to implement a puzzle solution where just the binary tree root node is required.
    BinaryTreeNode<T>* getRoot() const;
    void setRoot(BinaryTreeNode<T>*);

    // These are special methods to create binary tree from array [ both complete and not complete binaty trees ]. Also BST from a sorted array.
    void createFromArray(const vector<T>&, const T& nullItem=defaultVal<T>);  // This nullItem will be used to keep the node value null so that non-complete binary tree can be created.
    void createBSTFromSortedArray(const vector<T>&); // No check for sorted done to keep validation light and simple.
    void createFromLevelArray(const vector<size_t>& idxList,const vector<T>& valList);

    // Three standard traversals are provided.
    void doInOrderTraversal();
    void doPreOrderTraversal();
    void doPostOrderTraversal();

    // Standard traversals with results collected in vector [ below are overloaded ].
    void doInOrderTraversal(vector<T>*);
    void doPreOrderTraversal(vector<T>*);
    void doPostOrderTraversal(vector<T>*);

    // There are 6 type of BinaryTree checks available.
    bool isPerfect();
    bool isComplete();
    bool isFull();
    bool isHeightBalanced();
    bool isDegenerate();
    bool isBST();
    bool isEmpty();

    // Check if a given node is a leaf.
    bool isLeaf(const BinaryTreeNode<T>*);

    // A simple boost based serializer that saves binary tree as compressed gz file.Supports any shape of Binary Tree [ tested upto 100mil size BinaryTree ].
    const string serialize(const char*);
    const string deserialize(const char*);

    // A function to indicate which types this library build supports.
    static string getSupportedTypes();

    // Default destructor.
    ~BinaryTree();  // destructor that deletes the binary tree underneath.
};

#endif
