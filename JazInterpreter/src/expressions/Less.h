/*
 * Less.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef LESS_H_
#define LESS_H_
#include "../Expression.h"
namespace JazExpression {

class Less : public Expression {
public:
	void interpret(Context*);
	Less(std::string);
	virtual ~Less();
};

} /* namespace JazExpression */
#endif /* LESS_H_ */
