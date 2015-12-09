/*
 * Customer.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: kaky
 */

#include "../include/Customer.h"


Customer::Customer() :
		id(0), name("test"), surname(""), age(0), purchase_amount(0.0) {
}

Customer::Customer(int i, std::string n, std::string s, int a, float p) :
		id(i), name(n), surname(s), age(a), purchase_amount(p) {
}

Customer::~Customer() {
	std::cout << "customer is destroyed " << this->name << std::endl;
}

std::string Customer::getName() const {
	return this->name;
}
void Customer::setName(std::string n) {
	this->name = n;
}

std::string Customer::getSurname() const {
	return this->surname;
}
void Customer::setSurname(std::string n) {
	this->surname = n;
}

long Customer::getId() const {
	return this->id;
}

int Customer::getAge() const {
	return this->age;
}
void Customer::setAge(int a){
	this->age=a;
}
float Customer::getPurchase_amount() const{
	return this->purchase_amount;
}
void Customer::setPurchase_amount(float pp){
	this->purchase_amount=pp;
}

std::ostream & operator<<(std::ostream &os, const Customer &cust) {
	return os << "Customer " << cust.id << " " << cust.name << " "
			<< cust.surname << " " << " " << cust.age << cust.purchase_amount;
}

bool Customer::operator==(const Customer &cust) {
	if ((this->age != cust.age) || (this->surname != cust.surname)
			|| (this->name != cust.name)
			|| (this->purchase_amount != cust.purchase_amount)) {
		return false;
	}
	return true;
}

