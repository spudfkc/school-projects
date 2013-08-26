/*
 * Begin.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef BEGIN_H_
#define BEGIN_H_
#include "../Expression.h"

namespace JazExpression {

class Begin : public Expression {
public:
	void interpret(Context*);
	Begin(std::string);
	virtual ~Begin();
};

} /* namespace JazExpression */
#endif /* BEGIN_H_ */
