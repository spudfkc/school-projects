/*
 * End.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef END_H_
#define END_H_
#include "../Expression.h"

namespace JazExpression {

class End : public Expression {
public:
	void interpret(Context*);
	End(std::string);
	virtual ~End();
};

} /* namespace JazExpression */
#endif /* END_H_ */
