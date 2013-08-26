/*
 * Multiplication.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_
#include "../Expression.h"
namespace JazExpression {

class Multiplication : public Expression {
public:
	void interpret(Context*);
	Multiplication(std::string);
	virtual ~Multiplication();
};

} /* namespace JazExpression */
#endif /* MULTIPLICATION_H_ */
