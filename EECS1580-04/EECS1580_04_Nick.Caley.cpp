// EECS1580_03_Nick.Caley.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include "SymbolTable.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "HeapSort.h"

using namespace std;

SymbolTable heapArray[101];
int arrayCount = 1;
int heapArrayLength = sizeof(heapArray)/sizeof(SymbolTable);

// Parse the input string
void parse(string line) 
{ 
	 int value;
	 string svalue;
	 string id;
	 char op;

	 cout << "Parsing: " << line << endl;

	 // remove all spaces 											  
	 for(int i=0; i<line.length(); )
		 if(line[i] == ' ')
			 line.erase(i,1);
		 else 
			 i++;

     int eqSpot = line.find('=');					           // find the = 
	 svalue = line.substr(eqSpot+1, line.length()-1);          // set value 
     switch(line.at(eqSpot-1)){								   // set op 
                      case '+':  op = '+';  eqSpot--; break; 
                      case '-':  op = '-';  eqSpot--; break; 
				      case '*':  op = '*';  eqSpot--; break; 
                      case '/':  op = '/';  eqSpot--; break;
                      default:   op = '=';  break;			
	 };

	 id = line.substr(0, eqSpot);								// set id

	 stringstream ss(svalue);									// convert std::string svalue to int value
	 ss >> value;
	 //cout << "op:" << op << ":"<< endl;
	 if(op == '=')											    // if decleration.. 
     { 
		 //st = new SymbolTable(id, value);
		 heapArray[arrayCount] = SymbolTable(id, value);
		 arrayCount++;
     } 
     else												        // else is operation 
     {		
		 //cout << "performing op";
		 //mytree.search(id, mytree.getRoot())->st->performOp(op, value);
		 // search from start to end of array for the same id
		 for(int i=1; i<arrayCount; i++) {
			 if( heapArray[i].getID().compare(id) == 0 ) {
				 heapArray[i].performOp(op, value);
				 break;
			 }
		 }
	 }
} 

// Write the SORTED output to output.txt
void outputToFile(SymbolTable oa[], int arraySize, string file) {
	// outputfile stream
	std::ofstream outfile(file);
	// gothrough the array and print all elements
	for (int i=2; i<arraySize+1; i++) {
		outfile << oa[i].getID() << " = " << oa[i].getValue() << endl;
	} 
	outfile.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Read input
	//char a;
	//cin >> a;
	//mytree = BinaryTree();
	string line;
	ifstream myfile ("input.txt");				// input file
	if (myfile.is_open())
	{
		cout << "Reading file..." << endl;
		while ( myfile.good() )					// read file line by line
		{
			getline(myfile,line);
			if(line.compare("</end/>") == 0)	// end of file
				break;
			else
				parse(line);					// parse the line
		}
		myfile.close();
		cout << "done reading.." << endl;
	}
	else cout << "Unable to open file"; 
	
	cout << endl << endl;
	cout << " Array unsorted. As is from the input file " << endl;
	// print out the unsorted array
	for (int i=1; i<arrayCount; i++) {
		cout << heapArray[i].getID() << "  =  " << heapArray[i].getValue() << endl;
	}

	cout << endl << endl;

	// Sort the array
	HeapSort heap = HeapSort::HeapSort(arrayCount); // need new heapSort object to sort the array. Need a new one for each array
	heap.HeapSortArray(heapArray);					// sort the array from A-Z by identifiers of the SymbolTables

	// for some reason you need to change the bounds?
	// I'm not sure why, but it works
	// Print out the sorted array
	cout << " Array Sorted via HeapSort " << endl;
	for (int i=2; i<arrayCount+1; i++) {
		cout << heapArray[i].getID() << "  =  " << heapArray[i].getValue() << endl;
	}
	
	// write the sorted array to a file (output.txt)
	// Can change the parameter to change the filename
	outputToFile(heapArray, arrayCount, "output4.txt");

    return EXIT_SUCCESS; 
}

