// EECS1580_02_Nick.Caley.cpp : Defines the entry point for the console application.

// EECS 1580 
// PROJECT 2 - POSTFIX WITH BINARY TREES
// 
// Author: Nicholas Caley
//  Will take in an input file called input.txt in same directory and convert the inflix to postfix, store it in a binary treee, and compute the output
//  format should be: i.e.    (((1+2)*3)-4)   ,   ((1+2)*(3+4))    ,    etc

#include "stdafx.h"

#include "BinaryTree.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


LinkedList input  = LinkedList();
LinkedList output = LinkedList();

LinkedStack ops   = LinkedStack();

// determines if it is an operator
bool isOp(char c)
{
	switch(c) {
		case '+' : { return true;  }
		case '-' : { return true;  }
		case '/' : { return true;  }
		case '*' : { return true;  }
		default  : { return false; }
	};
}

void whatDo(char t)
{
	switch(t) {
		case '(' : ops.push(t); break;
		case '+' : ops.push(t); break;
		case '-' : ops.push(t); break;
		case '/' : ops.push(t); break;
		case '*' : ops.push(t); break;
		case ')' : output.insertFront(ops.pop()); ops.pop(); break;
			// default should be number
		default : output.insertFront(t); break;
	};
}

// Will convert the linked list in inflix notation to a linkedlist in postfix notation
// NO ERROR CHECKING! if the data is not a ),(,+,-,/,* then it is assumed to be a numer!!
void parseList()
{
	char t;
	LinkedList::LLnode *curr = input.getHead();

	while(curr->next != NULL)
	{
		t = curr->data;

		switch(t) {
		case '(' : ops.push(t); break;
		case '+' : ops.push(t); break;
		case '-' : ops.push(t); break;
		case '/' : ops.push(t); break;
		case '*' : ops.push(t); break;
		case ')' : output.insertFront(ops.pop()); ops.pop(); break;
			// default should be number
		default : output.insertFront(t); break;
		};

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	string line;						// will hold read line

	ifstream myfile("input.txt");		// input.txt is the file to be read

	if(myfile.is_open())
	{
		cout << "Reading file..." << endl;
		if(myfile.good())
		{
			getline(myfile,line);
			cout << "line: " << line << endl;
			for(int i=0; i<line.length(); i++)
			{
				cout << "current char: " << line[i] << endl;
				whatDo(line[i]);
			}
		}
		myfile.close();

		//output.traverse();

		BinaryTree mt(output.getHead());
		//cout << "ABOUT TO COMPUTE..." << endl;
		cout << "COMPUTED RESULT: " << mt.compute(mt.getRoot()) << endl;
		//mt.traverse(mt.getRoot());

		//mt.branch(output.getHead());


	    //input.traverse();

		// convert to postfix

	}

	exit(0);

	return 0;
}

