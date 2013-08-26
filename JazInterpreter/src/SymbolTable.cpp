/*
 * SymbolTable.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: ncc
 */

#include "SymbolTable.h"
#include <iostream>

namespace JazExpression {

int SymbolTable::resolve(std::string var) {
	if (afterCall == -1) {
		return variableMap[var];          // we are in a function, we only know of this scope
	}
	else if (afterCall) {
		return variableMap[var];          // we are returning from a function
	}
	else {
		if (hasVariable(var)) {
			return variableMap[var];
		}
		else {
			return parent->resolve(var);  // we are passing to a function
		}
	}
}

void SymbolTable::setVariable(std::string var, int value) {

	if (afterCall == -1) {
		variableMap[var] = value;        // in function
	}
	else if (afterCall) {
		parent->setVariable(var, value); // returning from function
	}
	else {
		variableMap[var] = value;        // passing to function
	}
}

bool SymbolTable::hasVariable(std::string var) {
	// TODO - clean this up/optimize
	bool result = false;
	std::map<std::string, int>::const_iterator iter = variableMap.find(var);
	if (iter == variableMap.end()) {
		result = false;
	}
	else {
		result = true;;
	}
	return result;
}

void SymbolTable::setParent(SymbolTable *newParent) {
	parent = newParent;
}

SymbolTable * SymbolTable::getParent(void) {
	return parent;
}

SymbolTable::SymbolTable() {
	parent = NULL;
	afterCall = 0;
}

SymbolTable::~SymbolTable() {
	parent = NULL;
	afterCall = 0;
}

} /* namespace JazExpression */
