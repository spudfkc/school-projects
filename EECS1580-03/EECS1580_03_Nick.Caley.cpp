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

using namespace std;

BinaryTree mytree;
LinkedList mylist;
LinkedList opslist;
int sizeofVarsList = 0;

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
		 BinaryTree::BTnode* tmp = new BinaryTree::BTnode;
		 tmp->right = NULL;
		 tmp->left = NULL;
		 tmp->p = NULL;
		 tmp->st = new SymbolTable(id, value);
		 mytree.insert(tmp);	
		 	//mytree.traverse(mytree.getRoot());// insert into tree
		 mytree.traverse(mytree.getRoot());
     } 
     else												        // else is operation 
     {		
		 //cout << "performing op";
		 mytree.search(id, mytree.getRoot())->st->performOp(op, value);
	 }
} 


int _tmain(int argc, _TCHAR* argv[])
{
	// Read input
	//char a;
	//cin >> a;
	mytree = BinaryTree();
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
	mytree.traverse(mytree.getRoot());
	mytree.outputToFile();
	

	//exit 0;
    //return 0;
    return EXIT_SUCCESS; 
}

