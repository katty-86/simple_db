/*
 * SimpleDB.h
 *
 *  Created on: Dec 7, 2015
 *      Author: kaky
 */
#include <fstream>
#include <iostream>
#include <boost/serialization/list.hpp>

#include "../include/Customer.h"

#ifndef INCLUDE_SIMPLEDB_H_
#define INCLUDE_SIMPLEDB_H_

class SimpleDB {
	std::string filename;
	std::string name;
	friend class boost::serialization::access;
	friend std::ostream & operator<<(std::ostream &os, const SimpleDB &s);

	//std::list<Customer> database;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version) {

		ar & this->database;
	}

public:
	std::list<Customer> database;
	SimpleDB();
	//SimpleDB(std:string file );
	SimpleDB(std::string n);
	~SimpleDB();

	void db_insert(Customer c);
	//select_count
	int db_select_count(Customer &c);
	int db_select_count_if(std::string n, std::string type);
	int db_select_count_if(int n, std::string type);
	int db_select_count_if(float n, std::string type);
	//select

	std::string getFilename() const;
	void setFilename(std::string file);
	std::list<Customer> getDatabase() const;
	void setDatabase(std::list<Customer>& v);
	void read_data(SimpleDB &s);
	void save_data(const SimpleDB &s);

	int delete_row();

};

#endif /* INCLUDE_SIMPLEDB_H_ */
