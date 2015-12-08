/*
 * Customer.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: kaky
 */

#include "Customer.h"

#include <ctime>

Customer::Customer() :
		id(time(0)), name("test"), surname(""), age(0), purchase_amount(0.0) {
}

Customer::Customer( std::string n, std::string s, int a, float p) :
		id(time(0)), name(n), surname(s), age(a), purchase_amount(p) {
}

Customer::~Customer() {
	std::cout<<"customer is destroyed "<<this->name<<std::endl;
}

std::string Customer::getName() const {
	return this->name;
}
void Customer::setName(std::string n) {
	this->name = n;
}
long Customer::getId() const {
	return this->id;
}

std::ostream & operator<<(std::ostream &os, const Customer &cust) {
	return os << "Customer " << cust.id << " " << cust.name << " "
			<< cust.surname << " " << cust.purchase_amount << " " << cust.age;
}

