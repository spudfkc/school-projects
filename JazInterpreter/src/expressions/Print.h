/*
 * Print.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef PRINT_H_
#define PRINT_H_
#include "../Expression.h"

namespace JazExpression {

class Print : public Expression {
public:
	bool isNumber(std::string&);
	void interpret(Context*);
	Print(std::string);
	virtual ~Print();
};

} /* namespace JazExpression */
#endif /* PRINT_H_ */
