///--------------------------------------------------------------------
///
///  Laboratory 9                                         BSTree.cpp
///
///  Linked implementation of the showStructure operation for the
///  Binary Search Tree ADT
///
///--------------------------------------------------------------------
#include <iomanip>
#include "BSTree.h"
using namespace std;
///--------------------------------------------------------------------

/// Default constructor
template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree()
{
	root = NULL;
}

///copy constructor
template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree<DataType, KeyType>& other)
{
	if (other.root == NULL)
		root = NULL;
	else
		copyHelper(this->root, other.root);
	return *this;
}

/// Overloaded = operator
template<typename DataType, class KeyType>
BSTree<DataType, KeyType> & BSTree<DataType, KeyType>::operator=(const BSTree<DataType, KeyType>& other)
{
	if (this != other)
	{
		if (root != NULL)
			clear(root);
		if (other.root == NULL)
			root = NULL;
		else
			copyHelper(root, other.root);
	}
	return *this;
}


/// Destructor
template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree()
{
	clearHelper(root);
}

/// Binary search tree manipulation operations
/// Insert data item
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert(const DataType& newDataItem)
{
	insertHelper(newDataItem, root);
}

///retrieve data item
template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& searchDataItem) const
{
	return contains(searchKey, searchDataItem, root);
}

///remove data item
template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	return removeHelper(deleteKey, root);
}

///Output keys
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys() const
{
	writeKeysHelper(root);
}

///clear tree
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear()
{
	clearHelper(root);
	root = NULL;
}

///Tree is clear
template < typename DataType, class KeyType >								 // Binary search tree status operations
bool BSTree<DataType, KeyType>::isEmpty() const
{
	return(root == nullptr);
}
											
/// In-lab operations
/// height of tree
template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight() const
{
	return height(root);
}

/// Number of nodes
template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount() const
{
	return count(root);
}

/// Show Structure
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::showStructure() const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/// Helper Functions
/// Show Helper
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::showHelper(BSTreeNode *p,
	int level) const

	// Recursive helper for showStructure. 
	// Outputs the subtree whose root node is pointed to by p. 
	// Parameter level is the level of this node within the tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showHelper(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";
		cout << " " << p->dataItem.getKey();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showHelper(p->left, level + 1);          // Output left subtree
	}
}

/// Clear helper
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode *p) const
{
	if (p != nullptr)
	{
		clearHelper(p->left); ///clear left subtree
		clearHelper(p->right); ///clear right subtree
		delete p; ///delete the root
	}
}

///insert helper
template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insertHelper(const DataType &x, BSTreeNode * & p) const
{
	if (p == nullptr)
		p = new BSTreeNode(x, nullptr, nullptr); ///tree is empty create new node
	else if (x.getKey() < p->dataItem.getKey()) ///key is less than root key
		insertHelper(x, p->left); ///traverse left subtree
	else if (x.getKey() > p->dataItem.getKey()) ///key is more than root key
		insertHelper(x, p->right); ///traverse right subtree
	else
		; ///duplicate do nothing
}

/// Remove helper
template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelper(const KeyType & x, BSTreeNode *& p)
{
	if (p == nullptr) ///tree is empty
		return false;
	if (x < p->dataItem.getKey()) ///key is less than root
		removeHelper(x, p->left); ///traverse left subtree
	else if (x > p->dataItem.getKey()) ///key is right than root
		removeHelper(x, p->right); ///traverse right subtree
	else if (p->left != nullptr && p->right != nullptr) /// node has two children
	{
		BSTreeNode *current = p->right; ///set new node to right child
		while (current->left != NULL) 
			current = current->left; ///find last left child
		p->dataItem.setKey(current->dataItem.getKey()); ///set key to current key
		removeHelper(p->dataItem.getKey(), p->right);/// run again with right subtree
	}
	else
	{
		BSTreeNode *old = p; ///create new node
		p = (p->left != nullptr) ? p->left : p->right; ///set key to non null ptr
		delete old; 
		return true;
	}
}


///Contains (retrieve helper)
template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::contains(const KeyType & key, DataType & searchDataItem, BSTreeNode * p) const
{
	if (p == nullptr)
		return false;
	else if (key < p->dataItem.getKey()) ///key is less than root key
		return contains(key, searchDataItem, p->left); ///traverse left subtree
	else if (key > p->dataItem.getKey()) ///key is more than root key
		return contains(key, searchDataItem, p->right); ///traverse right subtree
	else ///key must equal one of the nodes
	{
		searchDataItem = p->dataItem; 
		return true;
	}
}

///copy helper
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyHelper(BSTreeNode * thisOne, BSTreeNode * otherOne)
{
	if (otherOne == nullptr) 
		thisOne = nullptr;
	else ///copy this one to other one
	{
		thisOne = new BSTreeNode;
		thisOne->dataItem = otherOne->dataItem;
		copyHelper(thisOne->left, otherOne->left);
		copyHelper(thisOne->right, otherOne->right);
	}
}

///Recursive functions to write keys
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode *p) const
{
	///Recursive function that writes the keys inorder
	if (p != NULL)
	{
		writeKeysHelper(p->left);
		cout << p->dataItem.getKey() << " ";
		writeKeysHelper(p->right);
	}
}

/// Height (getHeight helper)
template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::height(BSTreeNode * p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->left), height(p->right));
}

///Max
template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

///Count
template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::count(BSTreeNode * p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + count(p->left) + count(p->right);
}



