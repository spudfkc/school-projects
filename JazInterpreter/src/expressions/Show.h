/*
 * Show.h
 *
 *  Created on: Jan 31, 2013
 *      Author: ncc
 */

#ifndef SHOW_H_
#define SHOW_H_
#include "../Expression.h"
#include <iostream>

namespace JazExpression {

class Show : public Expression {
public:
	void interpret(Context*);
	Show(std::string);
	virtual ~Show();
};

} /* namespace JazExpression */
#endif /* SHOW_H_ */
