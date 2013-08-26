/*
 * Equal.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef EQUAL_H_
#define EQUAL_H_
#include "../Expression.h"
namespace JazExpression {

class Equal : public Expression {
public:
	void interpret(Context*);
	Equal(std::string);
	virtual ~Equal();
};

} /* namespace JazExpression */
#endif /* EQUAL_H_ */
