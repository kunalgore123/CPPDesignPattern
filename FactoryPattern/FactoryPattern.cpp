//////////////////////////////////////////////////////////////////////////
//	FactoryPattern.cpp : C++ program to demonstrate factory method design pattern
//
//	Auther :- Kunal Gore
//	Date :- 10 Jun 2023
//		
//	The factory method is a creational design pattern, i.e., related to object creation. 
//	The Factory Method pattern is used to create objects without specifying the exact class of object that will be created. 
//	This pattern is useful when you need to decouple the creation of an object from its implementation.
//	The idea is to create a factory class with a single responsibility to create objects, hiding the details of class modules from the user.
//	A factory pattern is one of the core design principles to create an object, 
//	allowing clients to create objects of a library(explained below) in a way such that it doesn’t have a tight coupling with 
//	the class hierarchy of the library.
//	What is meant when we talk about libraries and clients? 
//	A library is something that is provided by some third party that exposes some public APIs and 
//	clients make calls to those public APIs to complete their tasks. A very simple example can be different kinds of Views provided by Android OS. 
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
using namespace std;

enum VehicleType {
	VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler
};

// Library classes
class Vehicle {
public:
	virtual void printVehicle() = 0;
	static Vehicle* Create(VehicleType type);
	virtual ~Vehicle(){}
};

class TwoWheeler : public Vehicle {
public:
	void printVehicle() {
		cout << "I am two wheeler" << endl;
	}
};

class ThreeWheeler : public Vehicle {
public:
	void printVehicle() {
		cout << "I am three wheeler" << endl;
	}
};

class FourWheeler : public Vehicle {
	public:
	void printVehicle() {
		cout << "I am four wheeler" << endl;
	}
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Vehicle* Vehicle::Create(VehicleType type) {
	if (type == VT_TwoWheeler)
		return new TwoWheeler();
	else if (type == VT_ThreeWheeler)
		return new ThreeWheeler();
	else if (type == VT_FourWheeler)
		return new FourWheeler();
	else return NULL;
}

// Client class
class Client {
public:
	// Client doesn't explicitly create objects but passes type to factory method "Create()"
	Client(VehicleType type = VT_ThreeWheeler);		/// by default ThreeWheeler considered
	~Client() {
		if (pVehicle) {
			delete pVehicle;
			pVehicle = NULL;
		}
	}
	Vehicle* getVehicle() {
		return pVehicle;
	}
private:
	Vehicle *pVehicle;
};

Client :: Client(VehicleType type){
		pVehicle = Vehicle::Create(type);
}

// Driver program
int main() {
	Client *pClient3 = new Client();
	Vehicle * pVehicle3 = pClient3->getVehicle();
	pVehicle3->printVehicle();

	Client *pClient2 = new Client(VT_TwoWheeler);
	Vehicle * pVehicle2 = pClient2->getVehicle();
	pVehicle2->printVehicle();

	delete pClient3;
	delete pClient2;
	return 0;
}