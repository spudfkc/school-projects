/*
 * NotEqual.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef NOTEQUAL_H_
#define NOTEQUAL_H_
#include "../Expression.h"
namespace JazExpression {

class NotEqual : public Expression {
public:
	void interpret(Context*);
	NotEqual(std::string);
	virtual ~NotEqual();
};

} /* namespace JazExpression */
#endif /* NOTEQUAL_H_ */
