# Stack-Implementation-using-C++
This repository demonstrate how to implementatoin Stack function including push(), pop(), top(), clear(), beginTransaction(), rollback() and commit(). This code is done by C++, mainly using C++ STL.

The question background:
Implement a stack function including push(), pop(), top(), clear() and it should have transaction function including beginTransaction(), rollback() and commit(). If you begin transaction, you need to commit it in order to actually add numbers to stack. Transactions can be nested. Transaction has rollback method, then nothing is done. If transaction is not started, numbers are added immediately.

Task implementation:
The task is done using C++ STL container list, stack and queue.
main.cpp is a testing source file, it shows how to use class stackHelper and shows different warnings under certain senarios.
stackHelper.cpp and stackHelper.h are the class definiation implentating stack functions as required.
