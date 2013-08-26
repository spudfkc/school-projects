#include "StdAfx.h"
#include "HeapSort.h"

// Constructor
// Will set the size of the array for later use
HeapSort::HeapSort(int arraysize)
{
	HeapSize = 0;
	arrayCount = arraysize;
}

// Deconstructor
HeapSort::~HeapSort(void)
{
}

// return the parent of the current element (index of)
int HeapSort::HeapParent(int i) {
	return (i/2);
}

// return left element (index of)
int HeapSort::HeapLeft(int i) {
	return (2*i);
}

// return right element (index of)
int HeapSort::HeapRight(int i) {
	return (2*i + 1);
}

// Main function to call to sort an array. Just pass it an array and it will sort it.
// Note that a new HeapSort 'object' will need to be created for each DIFFERENT SIZED array you would like to sort.
void HeapSort::HeapSortArray(SymbolTable a[]) {
	SymbolTable tmp;
	BuildMaxHeap(a);
	for(int i=arrayCount; i>=2; i--) {
		tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;
		HeapSize = HeapSize-1;
		MaxHeapify(a, 1);
	}

}

// Builds the max heap.
void HeapSort::BuildMaxHeap(SymbolTable a[]) { 
	HeapSize = arrayCount;
	for(int i=(HeapSize/2); i>=1; i--) {	// THIS WAS sizeof(a)/2
		MaxHeapify(a, i);
	}
}	
	
// Max Heapify
void HeapSort::MaxHeapify(SymbolTable tosort[], int i) {
	int l, r, largest;
	SymbolTable tmp;
	l = HeapLeft(i);
	r = HeapRight(i);
	if ((l <= HeapSize) && (tosort[l].getID() > tosort[i].getID())) 
		largest = l;
	else largest = i;
	if((r <= HeapSize) && (tosort[r].getID() > tosort[largest].getID())) 
		largest = r;
	if(largest != i) {
		tmp = tosort[i];
		tosort[i] = tosort[largest];
		tosort[largest] = tmp;
		MaxHeapify(tosort, largest);
	}
}

// Extract the max element from the heap. This will return the index of the max
int HeapSort::HeapExtractMax(SymbolTable a[]) {
	int max;
	if(HeapSize < 1)
		std::cout << " ERROR! HEAP UNDERFLOW " << std::endl;
	max = a[1].getValue();
	a[1] = a[HeapSize];
	HeapSize = HeapSize - 1;
	MaxHeapify(a, 1);
	return max;
}