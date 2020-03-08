#include <stdio.h>
#include "stackHelper.h"

int main(int argc, char **argv)
{
	printf("Welcome to stack testing by Shuliang\n");
	stackHelper myStackHelper;
	myStackHelper.display();
	
	printf("\nNow testing immediate push, pop, top...\n");
	myStackHelper.pop();		//do nothing and show warning, because stack is empty 
	myStackHelper.top();		//do nothing and show warning, because stack is empty 
	myStackHelper.push(10); 	//immediate push success
	myStackHelper.rollback(); 	//do nothing and show warning, because there is no active transaction
	myStackHelper.commit(); 	//do nothing and show warning, because there is no active transaction
	for(int i = 1; i <= MAXCOUNT; i++)
		myStackHelper.push(i);	//immediate push 10 fail, due to stack full
	myStackHelper.display();	//current stack should have 10, 1, 2, 3, 4, 5, 6, 7, 8, 9
	printf("pop one node(%d) from stack\n", myStackHelper.pop());
	myStackHelper.display();	//current stack should have 10, 1, 2, 3, 4, 5, 6, 7, 8
	printf("top one node(%d) from stack\n", myStackHelper.top());
	myStackHelper.display();	//current stack should have 10, 1, 2, 3, 4, 5, 6, 7, 8
	
	printf("\nNow testing transaction...\n");
	myStackHelper.clear();
	myStackHelper.beginTransaction();	//create a active transaction
	myStackHelper.push(1);
	myStackHelper.push(2);
	myStackHelper.push(3);				//transaction push 1, 2, 3
	myStackHelper.pop();				//transaction pop
	
	myStackHelper.beginTransaction();	//create another active transaction
	myStackHelper.push(5);
	myStackHelper.push(6);				//transaction push 5, 6
	myStackHelper.commit();				//commit second transactoin
	myStackHelper.display(); 			//current stack should have 5, 6
	
	myStackHelper.beginTransaction();	//create another active transaction
	myStackHelper.push(7);
	myStackHelper.push(8);				//transaction push 5, 6
	myStackHelper.rollback();			//cancel second transactoin
	myStackHelper.display(); 			//current stack should still have 5, 6
	
	myStackHelper.commit();				//commit first transactoin
	myStackHelper.display();			//current stack should have 5, 6, 1, 2
		
	return 0;
}
