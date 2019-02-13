///--------------------------------------------------------------------
///
///  Laboratory 11                                        HashTable.cpp
///
///  Hash table header file using array of binary trees
///
///--------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

using namespace std;

#include "BSTree.cpp"

template <typename DataType, typename KeyType>
class HashTable {
  public:
	  ///Constructor
    HashTable(int initTableSize);
	///copy constructor
    HashTable(const HashTable& other);
	///assignment operator overloading
    HashTable& operator=(const HashTable& other);

	///destructor
    ~HashTable();
	///insert item
	///Postcondition: Inserts item into hash table using hash function
    void insert(const DataType& newDataItem);
	///remove item
	///Postcondition: removes item with same key as delete key from hash
	///table and true if found, false otherwise
    bool remove(const KeyType& deleteKey);
	///retrieve item
	///Postcondition: returns item matching the search key and true if
	///found, false otherwise
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
	///clear
	///Postcondition: clears out the hash table
    void clear();
	///is empty
	///Postcondition: returns true if the table is empty, otherwise
	///false
    bool isEmpty() const;

    void showStructure() const;


  private:
	  ///copy table
	  ///Postcondition: copies one hash table to another
    void copyTable(const HashTable& source);

    int tableSize;
    BSTree<DataType, KeyType>* dataTable;
};

#endif	// ifndef HASHTABLE_H
