/*
 * Gotrue.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef GOTRUE_H_
#define GOTRUE_H_
#include "../Expression.h"
namespace JazExpression {

class Gotrue : public Expression {
public:
	void interpret(Context*);
	Gotrue(std::string);
	virtual ~Gotrue();
};

} /* namespace JazExpression */
#endif /* GOTRUE_H_ */
