/*
 * Push.h
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#ifndef PUSH_H_
#define PUSH_H_
#include <string>
#include "../Expression.h"

namespace JazExpression {

class Push : public Expression {
private:
	int stringToInt(std::string);
public:
//	Expression create(std::string);
	void interpret(Context*);
	Push(std::string);
	virtual ~Push();
};

} /* namespace JazExpression */
#endif /* PUSH_H_ */
