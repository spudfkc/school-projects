/*
 * Rvalue.h
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#ifndef RVALUE_H_
#define RVALUE_H_
#include "../Expression.h"

namespace JazExpression {

class Rvalue : public Expression {
public:
	void interpret(Context*);
	Rvalue(std::string);
	virtual ~Rvalue();
};

} /* namespace JazExpression */
#endif /* RVALUE_H_ */
