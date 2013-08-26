#pragma once
#include <iostream>
#include <string>
#include "SymbolTable.h"

class HeapSort
{
public:	
	int HeapSize;
	HeapSort(int);
	~HeapSort(void);
	void HeapSortArray(SymbolTable[]);
private:
	int arrayCount;
	int HeapParent(int);
	int HeapLeft(int);
	int HeapRight(int);
	void BuildMaxHeap(SymbolTable[]);
	void MaxHeapify(SymbolTable[], int);
	int HeapExtractMax(SymbolTable[]);
};

