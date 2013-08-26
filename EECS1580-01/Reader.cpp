// EECS1580_assign_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> 
#include <list> 
#include <algorithm>
#include "Reader.h"
#include "SymbolTable.h"
#include <cstring>

using namespace std;
/*
std::list<SymbolTable> myList; 
SymbolTable *root = NULL;




SymbolTable* traverse(string id)
{
	 SymbolTable *temp1;                          // create tmp node 
     temp1 = root;                                // transfer address of head to temp1 
      
	 while(temp1->getLink() != NULL) 
     {  
		if(temp1->getID() == id)
		{
			cout << temp1->getID();
			return temp1;
		}
         temp1 = temp1->getLink();                // transfer address of temp->next to temp   
          
     };

	 cout << "NO MATCH FOUND" << endl;
	 return NULL;
	 
}

void parse(string line) 
{ 
	 int value;
	 string svalue;
	 string id;
	 char op;

	 cout << "Parsing..." << line << endl;

      //substring stuff 
      //input e.x.    var_10 = 12 
      //              id_22+=3 

	 // remove all spaces 											  
	 for(int i=0; i<line.length(); i++)
		 if(line[i] == ' ')
			 line.erase(i,1);
     int eqSpot = line.find('=');     
     svalue = line.substr(eqSpot, line.length()-1);         // set value 
     switch(eqSpot-1){										// set op 
                      case '+':  op = '+';  eqSpot--; break; 
                      case '-':  op = '-';  eqSpot--; break; 
				      case '*':  op = '*';  eqSpot--; break; 
                      case '/':  op = '/';  eqSpot--; break;
                      default:  op = '=';  break; 
	 };
     id = line.substr(0, eqSpot);					   // set id 
     value = atoi( svalue.c_str() );
     if(op == '=')                                     // if decleration.. 
     { 
		 // need to create new node in the LinkedList
		   if(root == NULL) // if empty list
		   {
			   cout << "id is: " << id << endl;//
			   cout << "value is: " << value << endl;//
				SymbolTable s(id, value); // new SymbolTable
				root = &s;				  // root points to new SymbolTable
		   }
		   else // else, there's already stuff in the list
		   {
			   cout << "id is: " << id << endl;//
			   cout << "value is: " << value << endl;//
			   SymbolTable s(id, value);
			   s.setLink(root);
			   root = &s;
			   cout << "s.LINK" << s.getLink() << endl;
			   cout << "root.LINK" << root << endl;
		   }

     } 
     else                                              // else is operation 
     { 
           SymbolTable *n = traverse(id);              // find and point to node we need 
           n->performOp(value, op);                    // perform the op on that node 
     } 
	 
} 

void readFile()
{
	// read file
	string line;
	ifstream myfile("input.txt");				// input file
	if(myfile.is_open())
	{
		cout << "Reading file...";
		while (myfile.good())	// read file line by line, until we hit end mark
		{
			getline(myfile,line);
			if(line.compare("</end/>") == 0)	// end of file
				break;
			else
				parse(line);					// parse the line
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
}
*/

Reader::Reader()
{
	string s = "id_2 = 34";
	//parse(s);

	//readFile();
    
} 

Reader::~Reader()
{
}