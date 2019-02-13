///--------------------------------------------------------------------
///
///  Laboratory 9                                    BSTree.h
///
/// Class declarations for the linked implementation of the Binary
///  Search Tree ADT -- including the recursive helpers of the
///  public member functions
///
///--------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    /// DataType : tree data item
class BSTree                                     /// KeyType : key field
{
  public:

    /// Constructor
    BSTree ();                         /// Default constructor
    BSTree ( const BSTree<DataType,KeyType>& other );   /// Copy constructor
    BSTree& operator= ( const BSTree<DataType,KeyType>& other );
						  /// Overloaded assignment operator

    /// Destructor
    ~BSTree ();

    /// Binary search tree manipulation operations
    void insert ( const DataType& newDataItem );
	/// Insert data item
	/// Postcondition: Inserts newDataItem into a new node
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const;
    /// Retrieve data item
	/// Postcondition: Returns true if searchKey is found
	///				   otherwise, returns false.
    bool remove ( const KeyType& deleteKey );  
	/// Remove data item
	/// Postcondiion: If a node is equal to deletekey it is deleted.
    void writeKeys () const; 
	/// Output keys
	/// Postcondition: Writes keys in ascending order
    void clear ();  
	/// Clear tree
	/// Postcondition: Clears the tree of all data items

    /// Binary search tree status operations
    bool isEmpty () const;                        /// Tree is empty
    /// Postcondition: Returns true if tree is empty
	///				   otherwise, returns false.

    /// Output the tree structure -- used in testing/debugging
    void showStructure () const;

    /// In-lab operations
    int getHeight () const; 
	/// Height of tree
	/// Postcondition: Returns height of the tree
    int getCount () const;			  
	/// Number of nodes in tree
	/// Postcondition: Returns node count

  protected:

    class BSTreeNode                  /// Inner class: facilitator for the BSTree class
    {
      public:
    
        /// Constructor
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr );

        /// Data members
        DataType dataItem;         /// Binary search tree data item
        BSTreeNode *left,    /// Pointer to the left child
                   *right;   /// Pointer to the right child
    };

    /// Recursive helpers for the public member functions -- insert
    /// prototypes of these functions here.
    void showHelper      ( BSTreeNode *p, int level ) const;
	/// Recursive helper for show structure
	/// Postcondition: Outputs the tree to user
	void clearHelper(BSTreeNode *p) const;
	/// Recursive helper for clear
	/// Postcondition: Clears the tree of all data items
	void insertHelper(const DataType &x, BSTreeNode * & p)const;
	/// Recursive helper for insert
	/// Postcondition: If no node is found in the tree with DataType x
	///				   a node with x is created and inserted in the tree
	bool removeHelper(const KeyType &x, BSTreeNode * & p);
	/// Recursive helper for remove
	/// Postcondition: If a node is found with KeyType x, removes the 
	///				   node and returns true, otherwise return false
	bool contains(const KeyType & key, DataType & searchDataItem, BSTreeNode *p)const;
	/// Recursive helper for retrieve
	/// Postcondition: If a node is equal to key, changes searchDataItem to the dataItem
	///				   and returns true, otherwise returns false
	void copyHelper(BSTreeNode *thisOne, BSTreeNode *otherOne);
	/// Recurisive helper for copy constructor
	/// Postcondition: Copys thisOne node to otherOne node
	void writeKeysHelper(BSTreeNode *p) const;
	/// Recursive helper for writeKeys
	/// Postcondition: Writes keys to console in ascending order
	int height(BSTreeNode *p) const;
	/// Recursive helper for getHeight
	/// Postcondition: Returns height of tree
	int max(int x, int y) const;
	/// Finds max value
	/// Postcondition: Returns max value between two intergers
	int count(BSTreeNode *p) const;
	/// Counts the nodes
	/// Postcondition: Returns the number of nodes in the tree


    /// Data member
    BSTreeNode *root;   /// Pointer to the root node
};


#endif	/// define BSTREE_H

template<typename DataType, class KeyType>
///Constructor for BSTreeNode
inline BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType & nodeDataItem, BSTreeNode * leftPtr, BSTreeNode * rightPtr)
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}
