/*
 * Lvalue.h
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#ifndef LVALUE_H_
#define LVALUE_H_
#include "../Expression.h"

namespace JazExpression {

class Lvalue : public Expression {
public:
	void interpret(Context*);
	Lvalue(std::string);
	virtual ~Lvalue();
};

} /* namespace JazExpression */
#endif /* LVALUE_H_ */
