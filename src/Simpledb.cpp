/*
 * Simpledb.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: kaky
 */

#include "../include/Simpledb.h"

#include <algorithm>

SimpleDB::SimpleDB() :
		filename("/home/kaky/test/db.file") {
}

SimpleDB::SimpleDB(std::string n) :
		filename("/home/kaky/test/db.file"), name(n) {
}
//SimpleDB::SimpleDB(std:string file ): filename(file){}

void SimpleDB::db_insert(Customer c) {

	database.insert(database.end(), c);
}

SimpleDB::~SimpleDB() {
	std::cout << "db is destroyed " << this->name << std::endl;
}

void SimpleDB::save_data(const SimpleDB &s) {
	std::ofstream ofs((s.getFilename()).c_str());
	boost::archive::text_oarchive oa(ofs);
	oa << s;
}

void SimpleDB::read_data(SimpleDB &s) {

	std::ifstream ifs((s.getFilename()).c_str());
	boost::archive::text_iarchive ia(ifs);
	ia >> s;
}

std::string SimpleDB::getFilename() const {
	return this->filename;
}
void SimpleDB::setFilename(std::string file) {
	this->filename = file;
}

std::list<Customer> SimpleDB::getDatabase() const {
	return this->database;
}
void SimpleDB::setDatabase(std::list<Customer> &v) {
	this->database = v;
}

int SimpleDB::db_select_count_if(std::string n, std::string type) {

	if(type=="name"){
		return std::count_if(this->database.begin(), this->database.end(),[&n](const Customer &c){return c.getName()==n ;});
	}
	else if (type=="surname"){
		return std::count_if(this->database.begin(), this->database.end(),[&n](const Customer &c){return c.getSurname()==n ;});
	}
	else{
		return -1;
	}
}

int SimpleDB::db_select_count_if(int n, std::string type) {

	return std::count_if(this->database.begin(), this->database.end(),[&n](const Customer &c){return c.getAge()==n ;});

}

int SimpleDB::db_select_count_if(float n, std::string type) {

	return std::count_if(this->database.begin(), this->database.end(),[&n](const Customer &c){return c.getPurchase_amount()()==n ;});

}

int SimpleDB::db_select_count(Customer &c) {

	return std::count(this->database.begin(), this->database.end(), c);
}
std::ostream & operator<<(std::ostream &os, const SimpleDB & s) {

	std::list<Customer>::const_iterator it;
	for (it = s.database.begin(); it != s.database.end(); it++) {
		os << '\n' << *it;
	}
	return os;
}

