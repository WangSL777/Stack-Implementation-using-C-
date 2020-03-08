#ifndef STACKHELPER_H
#define STACKHELPER_H

#include <stdio.h>
#include <list>
#include <stack>
#include <queue>

#define MAXCOUNT	10
#define PUSH		0
#define POP			1
#define TOP			2

struct action
{
	int myActionID; //0: push, 1: pop, 2: top
	int myActionValue;
};

struct transaction
{
	std::queue<action> myTransactionQueue;
};

class stackHelper
{
public:
    stackHelper();
    ~stackHelper();
	
	void push(int a);
	int pop();
	int top();
	void clear();
	
	void beginTransaction();
	void commit();
	void rollback();
		
	void display();
	
private:
	std::list<int> myStack;
	std::stack<transaction> myStackTransaction;
	int count;
	
	void mypush(int a);
	int mypop();
	int mytop();
	
};

#endif // STACKHELPER_H
