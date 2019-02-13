///--------------------------------------------------------------------
///
///  Laboratory 11                                        HashTable.cpp
///
///  Hash table implementation file using array of binary trees
///
///--------------------------------------------------------------------
#include<iomanip>
#include<iostream>
#include "HashTable.h"

template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable & other)
{
	*this = other;
}

template<typename DataType, typename KeyType>
HashTable <DataType, KeyType> & HashTable<DataType, KeyType>::operator=(const HashTable & other)
{
	if (this == &other)
		return this;
	if (!isEmpty())
		clear();
	copyTable(other);
	return *this;

}

template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	clear();
}

template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType & newDataItem)
{
	int i = newDataItem.hash(newDataItem.getKey()) % tableSize;
	dataTable[i].insert(newDataItem);
}

template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType & deleteKey)
{
	DataType temp;

	int i = temp.hash(deleteKey) % tableSize;

	return dataTable[i].remove(deleteKey);
}

template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType & searchKey, DataType & returnItem) const
{
	int i = returnItem.hash(searchKey) % tableSize;

	return dataTable[i].retrieve(searchKey, returnItem);
}

template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int i = 0; i < tableSize; i++)
		dataTable[i].clear();
}

template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (dataTable[i].isEmpty() == false)
			return false;
	}
	return true;
}

template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable & source)
{
	delete dataTable;
	dataTable = new BSTree<DataType, KeyType>[source.tableSize];

	for (int i = 0; i < tableSize; i++)
		dataTable[i] = source.dataTable[i];
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
	for (int i = 0; i < tableSize; ++i) {
		cout << i << ": ";
		dataTable[i].writeKeys();
	}
}

