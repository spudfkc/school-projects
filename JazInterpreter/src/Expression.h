/*
 * Expression.h
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include "Context.h"
#include <string>
#include <iostream>

class Expression {
private:
public:
	int stringToInt(std::string);
	std::string intToString(int);
	std::string arguments;
	virtual void interpret(Context*);
	Expression(std::string);
	virtual ~Expression();
};

#endif /* EXPRESSION_H_ */
