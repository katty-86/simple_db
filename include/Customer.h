/*
 * Customer.h
 *
 *  Created on: Dec 7, 2015
 *      Author: kaky
 */
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#ifndef SRC_CUSTOMER_H_
#define SRC_CUSTOMER_H_

class Customer {
	int id;
	std::string name;
	std::string surname;
	int age;
	float purchase_amount;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & id;
		ar & name;
		ar & surname;
		ar & age;
		ar & purchase_amount;
	}
	friend std::ostream & operator<<(std::ostream &os, const Customer &cust);

public:
	Customer();
	Customer( int i, std::string n, std::string s, int a, float p);
	~Customer();
	std::string getName() const ;
	void setName(std::string name);
	std::string getSurname() const ;
	void setSurname(std::string name);
	int getAge() const ;
	void setAge(int a);
	float getPurchase_amount() const;
	void setPurchase_amount(float pp);

	long getId() const ;
	bool operator==( const Customer &cust);

};

#endif /* SRC_CUSTOMER_H_ */
