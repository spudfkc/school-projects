/*
 * Greater.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef GREATER_H_
#define GREATER_H_
#include "../Expression.h"
namespace JazExpression {

class Greater : public Expression {
public:
	void interpret(Context*);
	Greater(std::string);
	virtual ~Greater();
};

} /* namespace JazExpression */
#endif /* GREATER_H_ */
