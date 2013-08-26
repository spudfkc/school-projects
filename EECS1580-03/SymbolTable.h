#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> 

class SymbolTable
{
	std::string id;
	int value;
	int final;

public:
	int performOp(char, int);
	std::string toString(void);
	const std::string getID(void);
	void setValue(int);
	void setID(std::string);
	const int getValue();
	SymbolTable(std::string, int);
	SymbolTable();
	~SymbolTable(void);
};

