#include "StdAfx.h"
#include "LinkedList.h"
#include <iostream> 
#include <string>
#include "SymbolTable.h"

using namespace std;
    
LinkedList::LinkedList() 
{
	head = new node;
	tail = new node;
	curr = new node;
} 

LinkedList::~LinkedList() 
{ 
   node *q; 
   if( head == NULL ) 
        return; 
  
   while( head != NULL ) 
   { 
      q = head->next; 
      delete head; 
      head = q; 
   }                     
} 

  
// insert node at front of LinkedList
void LinkedList::insert(string id, int value) 

{ 
	SymbolTable *s = new SymbolTable(id, value);

	node *temp;					  //create a temporary node 
	temp = new node;			  //allocate space for node 

	temp->data = s;               // store data(first field)
	temp->next = head;			  // store the address of the pointer head(second field)
	head = temp;                  // transfer the address of 'temp' to 'head'
} 

void LinkedList::display() 
{ 
     node *q; 
     cout << endl; 
      
     for(q = head; q != NULL; q = q->next) 
           cout << q->data->toString() << endl;
}  

void LinkedList::find(string id, char op, int value)
{
	node *curr;
	curr = head;
	SymbolTable *temp;

	while(curr != NULL)
	{
		if(curr->data->getID().compare(id) == 0) // if match..
		{
			//cout << "MATCH!" << endl;
			curr->data->performOp(op, value);
			break; // found, no need for anything else
		}
		else 
			curr = curr->next;
	}
}

void LinkedList::traverse() 
{ 
      
	node *curr;
	curr = head;
	SymbolTable *temp;

	if(head == NULL)
	cout << "End of list.\n";
	else	
	{
		while(curr != NULL) {
		//cout << temp->data.toString() << " ";
			temp->setID(curr->data->getID());
			temp->setValue(curr->data->getValue());
			cout << temp->toString() << endl;
			curr = curr->next;
		}
	}
} 


void LinkedList::sort() 
{ 
	node *temp1, *temp2, *curr;

	for(temp1 = head; temp1 != NULL; temp1 = temp1->next)
		for(temp2 = head; temp2 != NULL; temp2 = temp2->next)
			if(temp1->data->getValue() < temp2->data->getValue())
			{
				curr  = temp1;
				temp1 = temp2;
				temp2 = curr;
			}

	node *t = head;
	while(t != NULL)
	{
		cout << t->data->toString() << endl;
		t = t->next;
	}

} 
