/*
 * GreaterEqual.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef GREATEREQUAL_H_
#define GREATEREQUAL_H_
#include "../Expression.h"
namespace JazExpression {

class GreaterEqual : public Expression {
public:
	void interpret(Context*);
	GreaterEqual(std::string);
	virtual ~GreaterEqual();
};

} /* namespace JazExpression */
#endif /* GREATEREQUAL_H_ */
