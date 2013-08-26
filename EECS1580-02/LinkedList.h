#pragma once
#include <iostream>

class LinkedList
{
public:
	typedef struct LLnode {
		LLnode *next;
		char data;
		LLnode() {
			next = NULL;
			data = 'X';
		}
	};
	LinkedList(void);
	~LinkedList(void);
	void insertFront(char);
	void traverse(int);
	void traverse(void);
	void insertBack(char);
	void insertMid(char, int);
	LLnode* getHead(void);

private:
	LLnode *head, *tail, *curr;

};

