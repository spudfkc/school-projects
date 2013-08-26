/*
 * Parser.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: ncc
 */

#include "Parser.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include "ExpressionFactory.h"

void Parser::trim(std::string& str) {
	std::string::size_type start2 = str.find_first_not_of("\t");
	std::string::size_type end2   = str.find_last_not_of("\t");
	str = str.substr(start2 == std::string::npos ? 0 : start2,
		end2 == std::string::npos ? str.length() - 1 : end2 - start2 + 1);

	std::string::size_type start = str.find_first_not_of(' ');
	std::string::size_type end   = str.find_last_not_of(' ');
	str = str.substr(start == std::string::npos ? 0 : start,
		end == std::string::npos ? str.length() - 1 : end - start + 1);
	str.erase(remove(str.begin(), str.end(), '\t'), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
	str.erase(remove(str.begin(), str.end(), '\r'), str.end());
}

std::vector<Expression*> Parser::parse(std::string inputFilePath) {
	std::vector<Expression*> result;
	bool isValid = true;
	char *inputFileCharArray = new char[inputFilePath.size() + 1];
	inputFileCharArray[inputFilePath.size()] = 0;
	std::memcpy(inputFileCharArray, inputFilePath.c_str(), inputFilePath.size());

	std::ifstream input;
	input.open(inputFileCharArray);

	if (!input.is_open()) {
		std::cout << "Could not open file: " << inputFilePath << std::endl;
		std::exit(1);
	}

	// Parsing start
	int i = 1;
	for (std::string line; std::getline (input, line); ) {
		trim(line);
		if (line.size() != 0) {
			std::map<std::string, Expression>::const_iterator expIterator;
			Expression *expression = new Expression("");

			bool isNoArgExpression = false;
			std::string::size_type whitespace = line.find(' ', 0);
			if (whitespace == std::string::npos) {
				isNoArgExpression = true;
			}

			std::string expString;
			std::string argString;

			if (!isNoArgExpression) {
				expString = line.substr(0, whitespace);
				argString = line.substr(whitespace, line.size()-1);
			}
			else {
				expString = line;
				argString = "";
			}

			std::map<std::string, exp_method_t>::const_iterator iter = createMap.find(expString);
			if (iter == createMap.end()) {
				std::cout << "Bad expression found on line: " << i << std::endl;
				std::cout << "\t" << expString << std::endl;
				isValid = false;
			}
			else {
				exp_method_t func = iter->second;
				expression = (factory.*func)(argString);
				result.push_back(expression);

				// we need to check to see if the expression is a label because
				// we need to know where the labels are before we interpret
				if (expString.compare("label") == 0) {
					labelMap[argString] = i;
				}
				i++;
			}
			//std::cout << "Line " << i++ << ": " << line << std::endl << std::endl;
		}
	}

	if (input.is_open()) {
		input.close();
	}

	if (!isValid) {
		std::cout << std::endl << "======== Bad Jaz ========" << std::endl;
		exit(1);
	}
	// Parsing end

	return result;
}

std::map<std::string, int> Parser::getLabelMap(void) {
	return labelMap;
}

Parser::Parser() {


	createMap["push"] = &JazExpression::ExpressionFactory::createPush;
	createMap["rvalue"] = &JazExpression::ExpressionFactory::createRvalue;
	createMap["lvalue"] = &JazExpression::ExpressionFactory::createLvalue;
	createMap["pop"] = &JazExpression::ExpressionFactory::createPop;
	createMap[":="] = &JazExpression::ExpressionFactory::createAssign;

	createMap["label"] = &JazExpression::ExpressionFactory::createLabel;
	createMap["goto"] = &JazExpression::ExpressionFactory::createGoto;
	createMap["gofalse"] = &JazExpression::ExpressionFactory::createGofalse;
	createMap["gotrue"] = &JazExpression::ExpressionFactory::createGotrue;
	createMap["halt"] = &JazExpression::ExpressionFactory::createHalt;

	createMap["+"] = &JazExpression::ExpressionFactory::createAddition;
	createMap["-"] = &JazExpression::ExpressionFactory::createSubtraction;
	createMap["*"] = &JazExpression::ExpressionFactory::createMultiplication;
	createMap["/"] = &JazExpression::ExpressionFactory::createDivision;
	createMap["div"] = &JazExpression::ExpressionFactory::createModulo;

	createMap["&"] = &JazExpression::ExpressionFactory::createAnd;
	createMap["!"] = &JazExpression::ExpressionFactory::createNot;
	createMap["|"] = &JazExpression::ExpressionFactory::createOr;

	createMap["<>"] = &JazExpression::ExpressionFactory::createNotEqual;
	createMap["<="] = &JazExpression::ExpressionFactory::createLessEqual;
	createMap[">="] = &JazExpression::ExpressionFactory::createGreaterEqual;
	createMap["<"] = &JazExpression::ExpressionFactory::createLess;
	createMap[">"] = &JazExpression::ExpressionFactory::createGreater;
	createMap["="] = &JazExpression::ExpressionFactory::createEqual;

	createMap["print"] = &JazExpression::ExpressionFactory::createPrint;
	createMap["show"] = &JazExpression::ExpressionFactory::createShow;

	createMap["begin"] = &JazExpression::ExpressionFactory::createBegin;
	createMap["end"] = &JazExpression::ExpressionFactory::createEnd;
	createMap["return"] = &JazExpression::ExpressionFactory::createReturn;
	createMap["call"] = &JazExpression::ExpressionFactory::createCall;
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

