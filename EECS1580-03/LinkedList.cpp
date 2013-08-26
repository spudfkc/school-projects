#include "StdAfx.h"
#include "LinkedList.h"


// this class hass all the methods for a LinkedList


LinkedList::LinkedList(void)
{
	head = new LLnode;
	tail = new LLnode;
	curr = new LLnode;
}

LinkedList::~LinkedList(void)
{
	// delete all mem allocations
	LLnode* tmp;

	curr = head; 
	while(curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		delete(tmp);
	}
	delete(curr);
	delete(tail);
	delete(head);
}


void LinkedList::insertFront(char c)
{
	LLnode *newnode = new LLnode;				// new node

	std::cout << "inserting at front: " << c << std::endl;

	newnode->data = c;							// set data of newnode
	newnode->next = head;						// set link of newnode
	head = newnode;								// point head to newnode

}

void LinkedList::insertBack(char c) 
{
	LLnode *newnode = new LLnode;				// newnode

	newnode->data = c;							// set data
	newnode->next = NULL;						// set link (should already be NULL tho)

	curr = head;								// goto end of list
	while(curr->next != NULL)
		curr = curr->next;

	curr->next = newnode;						// point end of list to newnode
}

void LinkedList::insertMid(char c, int place)
{
	LLnode *newnode = new LLnode;				// newnode

	newnode->data = c;							// set data

	curr = head;								// goto specified place
	for(int i = 0; i < place ; i++)
		curr = curr->next;
	
	newnode->next = curr->next;					// point newnode to next
	curr->next = newnode;						// point current to newnode
}

void LinkedList::insert(std::string id, int value) 
{ 
	SymbolTable *s = new SymbolTable(id, value);

	LLnode *temp;				  //create a temporary node 
	temp = new LLnode;			  //allocate space for node 

	temp->st = s;               // store data(first field)
	temp->next = head;			  // store the address of the pointer head(second field)
	head = temp;                  // transfer the address of 'temp' to 'head'
} 

void LinkedList::insert(std::string id, char op, int value) {

	curr = head; 
	// goto end of list
	while(curr->next != NULL)
		curr = curr->next;

	SymbolTable *s = new SymbolTable;
	LLnode *tmp = new LLnode;
	tmp->st = s;
	tmp->next = NULL;
	s->setValue(value);
	s->setID(id);
	tmp->data = op;
	curr->next = tmp;
}


void LinkedList::traverse(int start)
{
	curr = head;								// have to start at begining

	for(int i=0; i<start; i++)					// goto where we should 
		curr = curr->next;

	// traverse list and cout every data
	while(curr->next != NULL) 
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}

}

void LinkedList::traverse(void)
{
	curr = head;
	while(curr->next != NULL) 
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
	std::cout << curr->data << std::endl;
}


LinkedList::LLnode* LinkedList::getHead(void) 
{
	return head;
}


void LinkedList::find(std::string id, char op, int value)
{
	LLnode *curr;
	curr = head;
	SymbolTable *temp;

	while(curr != NULL)
	{
		if(curr->st->getID().compare(id) == 0) // if match..
		{
			//cout << "MATCH!" << endl;
			curr->st->performOp(op, value);
			break; // found, no need for anything else
		}
		else 
			curr = curr->next;
	}
}

void LinkedList::insertSorted(std::string id, int value) {
	curr = head;
	SymbolTable *s = new SymbolTable(id, value);
	LLnode *temp;				  //create a temporary node 
	temp = new LLnode;			  //allocate space for node 
	std::string curstring;
	std::string newstring;

	temp->st = s;               // store data(first field)
	//temp->next = head;			  // store the address of the pointer head(second field)
	//head = temp;                  // transfer the address of 'temp' to 'head'

	if(head = NULL) {
		// if there are no nodes, then this is the only one
		head = temp;
	} else {
		while(curr != NULL) {
			newstring = temp->st->getID();
			curstring = curr->st->getID();
			if(newstring.compare(curstring) > 0) {
				if(curr->next != NULL)
					curr = curr->next;
				else {
					// we're at the end of the list
					curr->next = temp;
					temp->next = NULL;
				}
			} else if(newstring.compare(curstring) < 0) {
				// then we must be at the front of the list
				temp->next = head;
				head = temp;
			} else if(newstring.compare(curstring) == 0) {
				// middle of list somewhere
				temp->next = curr->next;
				curr->next = temp;
			}
		}
	}
}

void LinkedList::sortAZ(void) {

	LinkedList sortedlist = LinkedList();
	curr = head;

	while(curr!=NULL) {
		std::cout << "sorted insert: " << curr->st->getID() << std::endl;
		sortedlist.insertSorted(curr->st->getID(), curr->st->getValue());
		curr = curr->next;
	}
	curr = head;
	head = sortedlist.head;

	// TODO: traverse list and delete all nodes
	delete curr;

}