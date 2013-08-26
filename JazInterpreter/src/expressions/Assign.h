/*
 * Assign.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef ASSIGN_H_
#define ASSIGN_H_
#include "../Expression.h"

namespace JazExpression {

class Assign : public Expression {
public:
	void interpret(Context*);
	Assign(std::string);
	virtual ~Assign();
};

} /* namespace JazExpression */
#endif /* ASSIGN_H_ */
