////////////////////////////////////////////////////////////////////////////////////////////////////////
//	SingletonPattern.cpp : C++ program to demonstrate Singleton design pattern
//
//	Auther :- Kunal Gore
//	Date :- 11 Jun 2023
//	
//	Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object. 
//	This is useful when exactly one object is needed to coordinate actions across the system. 
//	For example, if you are using a logger, that writes logs to a file, you can use a singleton class to create such a logger.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include<iostream>
using namespace std;

class Singleton{
private:
	Singleton(){}						// private constructor, so no one can initialize it
	static Singleton * Instance;		// static instance for maitaining single sintance throughout the execution of a program
public:	
	static Singleton* GetInstance();		
	void PrintLog(){					// printing logs
		cout << "printing... " << endl;
	}
};

Singleton *Singleton::Instance = nullptr;	// initializing instance with nullptr

//	GetInstance() is a static method that returns an instance when it is invoked. It returns the same
//  instance if it is invoked more than once as an instance  of Singleton class is already created. 
//	It is static because we have to invoke this method without any object of Singleton class and 
//	static method can be invoked without object of class
//	As constructor is private so we cannot create object of Singleton class without a static method 
//	as they can be called without objects. We have to create an instance of
//  this Singleton class by using GetInstance() method.
Singleton * Singleton:: GetInstance(){
	if (Instance == nullptr)
		Instance = new Singleton();
	return Instance;
}

int main(){
	Singleton *ptr = Singleton:: GetInstance();	// creating instance, whenever we call GetInstance next time it will return same instance
	ptr->PrintLog();		
	//Singleton *ptr1 = new Singleton();	// gives error , error C2248: 'Singleton::Singleton' : cannot access private member declared in class 'Singleton'
	return 0;
}

