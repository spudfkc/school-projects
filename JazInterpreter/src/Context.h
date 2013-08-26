/*
 * Context.h
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_
#include <stack>
#include <vector>
#include <string>
#include <map>
#include "SymbolTable.h"

class Context {
private:
	std::map<std::string, int> labelMap;
	std::map<std::string, int> variableMap;
	std::stack<std::string,std::vector<std::string> > thestack;
	JazExpression::SymbolTable *currentScope;
public:
//	int inCall;
	int nextInstruction(void);

	int getStackSize(void);
	std::stack<int> instructions;

	JazExpression::SymbolTable * getScope(void);
	void popScope(void);
	void newScope(JazExpression::SymbolTable *);

	int getVariable(std::string);
	void assignVariable(std::string, int);

	void setLabelMap(std::map<std::string, int>);
	int getIndexForLabel(std::string);

	void push(std::string);
	std::string pop(void);
	std::string top(void);

	Context();
	virtual ~Context();
};

#endif /* CONTEXT_H_ */



