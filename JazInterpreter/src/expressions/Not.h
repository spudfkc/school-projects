/*
 * Not.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef NOT_H_
#define NOT_H_
#include "../Expression.h"
namespace JazExpression {

class Not : public Expression {
public:
	void interpret(Context*);
	Not(std::string);
	virtual ~Not();
};

} /* namespace JazExpression */
#endif /* NOT_H_ */
