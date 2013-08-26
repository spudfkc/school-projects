/*
 * Division.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef DIVISION_H_
#define DIVISION_H_
#include "../Expression.h"
namespace JazExpression {

class Division : public Expression {
public:
	void interpret(Context*);
	Division(std::string);
	virtual ~Division();
};

} /* namespace JazExpression */
#endif /* DIVISION_H_ */
