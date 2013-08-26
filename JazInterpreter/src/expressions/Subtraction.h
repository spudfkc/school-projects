/*
 * Subtraction.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_
#include "../Expression.h"
namespace JazExpression {

class Subtraction : public Expression {
public:
	void interpret(Context*);
	Subtraction(std::string);
	virtual ~Subtraction();
};

} /* namespace JazExpression */
#endif /* SUBTRACTION_H_ */
