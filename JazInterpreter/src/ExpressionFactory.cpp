/*
 * ExpressionFactory.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: ncc
 */

#include "ExpressionFactory.h"
#include "expressions/Push.h"
#include "expressions/Pop.h"
#include "expressions/Rvalue.h"
#include "expressions/Lvalue.h"
#include "expressions/Assign.h"
#include "expressions/Label.h"
#include "expressions/Goto.h"
#include "expressions/Gofalse.h"
#include "expressions/Gotrue.h"
#include "expressions/Halt.h"
#include "expressions/Addition.h"
#include "expressions/Subtraction.h"
#include "expressions/Multiplication.h"
#include "expressions/Division.h"
#include "expressions/Modulo.h"
#include "expressions/And.h"
#include "expressions/Not.h"
#include "expressions/Or.h"
#include "expressions/NotEqual.h"
#include "expressions/LessEqual.h"
#include "expressions/GreaterEqual.h"
#include "expressions/Less.h"
#include "expressions/Greater.h"
#include "expressions/Equal.h"
#include "expressions/Print.h"
#include "expressions/Show.h"
#include "expressions/Begin.h"
#include "expressions/End.h"
#include "expressions/Call.h"
#include "expressions/Return.h"

namespace JazExpression {

Expression* ExpressionFactory::createPush(std::string args) {
	Push *push = new Push(args);
	return push;
}

Expression* ExpressionFactory::createRvalue(std::string args) {
	Rvalue *rvalue = new Rvalue(args);
	return rvalue;
}

Expression* ExpressionFactory::createLvalue(std::string args) {
	Lvalue *lvalue = new Lvalue(args);
	return lvalue;
}

Expression* ExpressionFactory::createPop(std::string args) {
	Pop *pop = new Pop(args);
	return pop;
}

Expression* ExpressionFactory::createAssign(std::string args) {
	Assign *assign = new Assign(args);
	return assign;
}

Expression* ExpressionFactory::createLabel(std::string args) {
	Label *label = new Label(args);
	return label;
}

Expression* ExpressionFactory::createGoto(std::string args) {
	Goto *g = new Goto(args);
	return g;
}

Expression* ExpressionFactory::createGofalse(std::string args) {
	Gofalse *gf = new Gofalse(args);
	return gf;
}

Expression* ExpressionFactory::createGotrue(std::string args) {
	Gotrue *gt = new Gotrue(args);
	return gt;
}

Expression* ExpressionFactory::createHalt(std::string args) {
	Halt *h = new Halt(args);
	return h;
}

Expression* ExpressionFactory::createAddition(std::string args) {
	Addition *add = new Addition(args);
	return add;
}

Expression* ExpressionFactory::createSubtraction(std::string args) {
	Subtraction *subtract = new Subtraction(args);
	return subtract;
}

Expression* ExpressionFactory::createMultiplication(std::string args) {
	Multiplication *mul = new Multiplication(args);
	return mul;
}

Expression* ExpressionFactory::createDivision(std::string args) {
	Division *d = new Division(args);
	return d;
}
Expression* ExpressionFactory::createModulo(std::string args) {
	Modulo *m = new Modulo(args);
	return m;
}

Expression* ExpressionFactory::createAnd(std::string args) {
	And *a = new And(args);
	return a;
}

Expression* ExpressionFactory::createNot(std::string args) {
	Not *n = new Not(args);
	return n;
}

Expression* ExpressionFactory::createOr(std::string args) {
	Or *o = new Or(args);
	return o;
}

Expression* ExpressionFactory::createNotEqual(std::string args) {
	NotEqual *ne = new NotEqual(args);
	return ne;
}

Expression* ExpressionFactory::createLessEqual(std::string args) {
	LessEqual *le = new LessEqual(args);
	return le;
}

Expression* ExpressionFactory::createGreaterEqual(std::string args) {
	GreaterEqual *ge = new GreaterEqual(args);
	return ge;
}

Expression* ExpressionFactory::createLess(std::string args) {
	Less *l = new Less(args);
	return l;
}

Expression* ExpressionFactory::createGreater(std::string args) {
	Greater *g = new Greater(args);
	return g;
}

Expression* ExpressionFactory::createEqual(std::string args) {
	Equal *e = new Equal(args);
	return e;
}


Expression* ExpressionFactory::createPrint(std::string args) {
	Print *p = new Print(args);
	return p;
}

Expression* ExpressionFactory::createShow(std::string args) {
	Show *s = new Show(args);
	return s;
}

Expression* ExpressionFactory::createBegin(std::string args) {
	Begin *b = new Begin(args);
	return b;
}

Expression* ExpressionFactory::createEnd(std::string args) {
	End *e = new End(args);
	return e;
}

Expression* ExpressionFactory::createReturn(std::string args) {
	Return *r = new Return(args);
	return r;
}

Expression* ExpressionFactory::createCall(std::string args) {
	Call *c = new Call(args);
	return c;
}

ExpressionFactory::ExpressionFactory() {
	// TODO Auto-generated constructor stub

}

ExpressionFactory::~ExpressionFactory() {
	// TODO Auto-generated destructor stub
}

} /* namespace JazExpression */
