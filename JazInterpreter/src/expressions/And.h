/*
 * And.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef AND_H_
#define AND_H_
#include "../Expression.h"
namespace JazExpression {

class And : public Expression {
public:
	void interpret(Context*);
	And(std::string);
	virtual ~And();
};

} /* namespace JazExpression */
#endif /* AND_H_ */
