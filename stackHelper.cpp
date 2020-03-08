#include "stackHelper.h"

stackHelper::stackHelper()
{
	myStack.clear();
	while (!myStackTransaction.empty())
	{    
		myStackTransaction.pop();
	}
	count = 0;
}

stackHelper::~stackHelper()
{
}

void stackHelper::push(int a)
{
	if(myStackTransaction.size()>0)
	{
		action myAction;
		myAction.myActionID = PUSH;
		myAction.myActionValue = a;
		myStackTransaction.top().myTransactionQueue.push(myAction);
	}
	else
	{
		mypush(a);
	}
}

int stackHelper::pop()
{
	if(myStackTransaction.size()>0)
	{
		action myAction;
		myAction.myActionID = POP;
		myAction.myActionValue = 0;
		myStackTransaction.top().myTransactionQueue.push(myAction);
		return 0;
	}
	else
	{
		return mypop();
	}
}

int stackHelper::top()
{
	if(myStackTransaction.size()>0)
	{
		action myAction;
		myAction.myActionID = TOP;
		myAction.myActionValue = 0;
		myStackTransaction.top().myTransactionQueue.push(myAction);
		return 0;
	}
	else
	{
		return mytop();
	}
    
}

void stackHelper::clear()
{
	myStack.clear();
	while (!myStackTransaction.empty())
	{    
		myStackTransaction.pop();
	}
	count = 0;
}

void stackHelper::beginTransaction()
{
	transaction myTransaction;
	myStackTransaction.push(myTransaction);
}

void stackHelper::commit()
{
	if(myStackTransaction.size()>0)
	{
		action myAction;
		std::queue<action> transactionQueue = myStackTransaction.top().myTransactionQueue;
		while(transactionQueue.size()>0)
		{
			myAction = transactionQueue.front();
			switch(myAction.myActionID)
			{
				case PUSH: 
					mypush(myAction.myActionValue);
					break;
					
				case POP:
					mypop();
					break;
					
				case TOP:
					mytop();
					break;
					
				default:
					printf("Invalid commit action(%d)\n", myAction.myActionID);
					break;
			}
			transactionQueue.pop();
		}
	
		myStackTransaction.pop();
	}
	else
	{
		printf("There is no active transaction, commit transaction failed.\n");
	}
}

void stackHelper::rollback()
{
	if(myStackTransaction.size()>0)
	{
		myStackTransaction.pop();
	}
	else
	{
		printf("There is no active transaction, rollback transaction failed.\n");
	}
}

void stackHelper::mypush(int a)
{
	if(count<MAXCOUNT)
	{
		count++;
		myStack.push_back(a);
	}
	else
	{
		printf("Cannot push %d, stack already full\n", a);
	}
}

int stackHelper::mypop()
{
	if(count>0)
	{
		count--;
		int a = myStack.back();
		myStack.pop_back();
		return a;
	}
	else
	{
		printf("Cannot pop, stack already empty\n");
		return -1;
	}
}

int stackHelper::mytop()
{
	if(count>0)
	{
		int a = myStack.back();
		return a;
	}
	else
	{
		printf("Cannot top, stack already empty\n");
		return -1;
	}
}




void stackHelper::display()
{
	if(myStack.size() == 0)
	{
		printf("Current stack is empty\n");
		return;
	}
	
	printf("Current stack info:\n");
	for (std::list<int>::iterator it=myStack.begin(); it!=myStack.end() ; ++it)
	{
		printf("%d ",*it);
	}
	printf("\n");
	
}