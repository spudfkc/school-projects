/*
 * Context.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#include "Context.h"
#include <iostream>

int Context::getStackSize(void) {
	return thestack.size();
}

JazExpression::SymbolTable * Context::getScope() {
	return currentScope;
}

void Context::popScope(void) {
	currentScope = currentScope->getParent();
}

void Context::newScope(JazExpression::SymbolTable *scope) {
	if (currentScope != NULL) {
		scope->setParent(currentScope);
	}
	currentScope = scope;
}

int Context::nextInstruction() {
	int result = instructions.top();
	instructions.pop();
	return result;
}

int Context::getVariable(std::string var) {
	return currentScope->resolve(var);
}

void Context::assignVariable(std::string var, int value) {
	currentScope->setVariable(var, value);
}

int Context::getIndexForLabel(std::string label) {
	return labelMap[label];
}

void Context::setLabelMap(std::map<std::string, int> map) {
	labelMap = map;
}

std::string Context::top(void) {
	std::string result;
	if (thestack.size() > 0) {
		result = thestack.top();
	}
	else {
		result = "";
	}
	return result;
}

void Context::push(std::string arg) {
	thestack.push(arg);
}

std::string Context::pop(void) {
	std::string result = "";
	if (thestack.size() > 0) {
		result = thestack.top();
		thestack.pop();
	}
	return result;
}

Context::Context() {
	currentScope = new JazExpression::SymbolTable();
	instructions.push(-1); // This should indicate the end of intructions
	instructions.push(0);  // start at spot 0
}

Context::~Context() {
	// TODO Auto-generated destructor stub
}

