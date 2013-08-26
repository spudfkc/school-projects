#include "StdAfx.h"
#include "SymbolTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> 

using namespace std;

	void SymbolTable::setID(string s)
	{
		id = s;
	}

	void SymbolTable::setValue(int a) 
	{
		value = a;
	}

	// Will perform the requested operation on the node
	int SymbolTable::performOp(char op, int val)
	{
		//cout << "performing op: " << op << endl;
	// final value to return
	int final = 0;
	// determine which op to use, then exec it
		switch (op) {
			case '+':
				value += val; break;
			case '-':
				value -= val; break;
			case '*':
				value *= val; break;
			case '/':
				value /= val; break;
			case '%':
				value %= val; break;
			default:
				// no operation performed
				cout << "noOp" << endl;
				break;
		}

		cout << id << " New Value: " << value << endl;

		// return the new value
		return value;
}

	// returns a string with info about the node
	std::string SymbolTable::toString(void)
	{
		// create new string to return
		string mString;
		// append id and = to the string
		mString.append(id).append("=");

		// append in to string
		stringstream ss;//create a stringstream
	    ss << value;//add number to the stream
        mString.append(ss.str());//return a string with the contents of the stream
		return mString;
		// return the final string
	}

	// return Id 
	const string SymbolTable::getID(void)
	{
			return id;
	}

	const int SymbolTable::getValue(void)
	{
		return value;
	}

	// return the link that this obj points to
	//SymbolTable* SymbolTable::getLink()
	//{
	//	return link;
	//}

	// set link
	//void SymbolTable::setLink(SymbolTable *s)
	//{
	//	link = s;
	//}

	// Constructor
	SymbolTable::SymbolTable(string a, int v)
	{

		// initialize the id
		id = a;
		//cout << getID() << endl;
		// initialize the value
		value = v;
		//cout << getValue() << endl;
		final = 0;
	}

	SymbolTable::SymbolTable()
	{
		id = "";
		value = 0;
	}

	// deConstructor
	SymbolTable::~SymbolTable(void)
	{
		// clear the string
		id = "";
		// set value to 0
		value = 0;
	}