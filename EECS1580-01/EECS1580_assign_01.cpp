
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream> 
#include <algorithm>
#include "SymbolTable.h"
#include "LinkedList.h"

using namespace std;

//SymbolTable *root = NULL;

LinkedList mylist;

void parse(string line) 
{ 
	 int value;
	 string svalue;
	 string id;
	 char op;

	 cout << "Parsing..." << line << endl;

	 // remove all spaces 											  
	 for(int i=0; i<line.length(); )
		 if(line[i] == ' ')
			 line.erase(i,1);
		 else 
			 i++;

     int eqSpot = line.find('=');					          // find the = 
	 svalue = line.substr(eqSpot+1, line.length()-1);         // set value 
     switch(line.at(eqSpot-1)){								  // set op 
                      case '+':  op = '+';  eqSpot--; break; 
                      case '-':  op = '-';  eqSpot--; break; 
				      case '*':  op = '*';  eqSpot--; break; 
                      case '/':  op = '/';  eqSpot--; break;
                      default:   op = '=';  break;			
	 };

	 id = line.substr(0, eqSpot);							// set id

	 stringstream ss(svalue);								// convert std::string svalue to int value
	 ss >> value;

     if(op == '=')										    // if decleration.. 
     { 
		 // create new node in the LinkedList	   
				mylist.insert(id, value);							// insert s into LL
     } 
     else											        // else is operation 
     { 
			    mylist.find(id, op, value);
	 }
} 

/*// sorts the nodes in the LL
void sort()
{
	SymbolTable *temp1;
	SymbolTable *temp2;
	SymbolTable *temp;
 
	cout << "Sorting Nodes..." << endl;
	for( temp1 = root ; temp1!=NULL ; temp1 = temp1->getLink() )
	{
		  for( temp2 = temp1->getLink() ; temp2!=NULL ; temp2 = temp2->getLink() )
		  {
				if( temp1->getID() > temp2->getID() )
				{
					  temp = temp1->getLink();
					  temp1->setLink(temp2->getLink());
					  temp2->setLink(temp);
				}
		  }
	}
}
// should print out the toString for each node
void printNodes()
{
	SymbolTable *node = root;

	do
	{
		cout << node->toString() << endl;
	}while((node = node->getLink()) != NULL);
}
// Will traverse the string, comparing IDs and will return a pointer to that node or null if not found
SymbolTable* traverse(string id)
{
	 SymbolTable *temp1;                          // create tmp node 
     temp1 = root;

	 while(temp1 != NULL) 
     {  
		cout << temp1->toString() << endl;
		if(id.compare(temp1->getID()) == 0)
		{
			// Found!
			cout << "MATCH" << endl;
			return temp1;
		};
		cout << root->getLink() << endl;
		if(temp1 == temp1->getLink())
			temp1 = NULL;
		else
			temp1 = temp1->getLink();                // transfer address of temp->next to temp 
     };

	 cout << "NO MATCH FOUND" << endl;
	 return NULL;
	 
}
*/

// some test values

int _tmain(int argc, _TCHAR* argv[])
{
	// Read input
	mylist = LinkedList();
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

	mylist.sort();

	//myList.traverse();
	//exit 0;
    return 0;
    //return EXIT_SUCCESS; 
} 