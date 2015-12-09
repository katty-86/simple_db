#include "gtest/gtest.h"
#include "../include/Customer.h"
#include "../include/Simpledb.h"
#include <memory>
#include <iostream>

using namespace std;

class SimpledbTest: public ::testing::Test {
protected:
	SimpleDB *sim_db;
	shared_ptr<Customer> c1;
	shared_ptr<Customer> c2;
	shared_ptr<Customer> c3;
	shared_ptr<Customer> ct1;
	shared_ptr<Customer> ct3;

	virtual void SetUp() {
	}
	virtual void TearDown() {
	}
	SimpledbTest(){

		sim_db=new SimpleDB("write");
		c1 = make_shared<Customer>(1, "Ola", "Kot", 1, 5.2);
		c2 = make_shared<Customer>(2, "Mis", "Pies", 1, 4.4);
		c3 = make_shared<Customer>(3, "Jas", "Pies", 1, 3.2);
		ct1 = make_shared<Customer>(9, "Ola", "Pies", 1, 1.3);
		ct3 = make_shared<Customer>(3, "Jas", "Pies", 1, 3.2);
		sim_db->db_insert(*c1);
		sim_db->db_insert(*c2);
		sim_db->db_insert(*c3);
	}
	~SimpledbTest(){
		delete sim_db;
	}
};

TEST_F(SimpledbTest, select_count) {
	EXPECT_EQ(0, sim_db->db_select_count(*ct1));
	EXPECT_EQ(1, sim_db->db_select_count(*ct3));
	EXPECT_NE(sim_db->db_select_count(*ct1), 3);
	EXPECT_NE(sim_db->db_select_count(*ct3), 7);
}


TEST_F(SimpledbTest, select_count_if) {
	EXPECT_EQ(1, sim_db->db_select_count_if("Ola", "name"));
	EXPECT_EQ(2, sim_db->db_select_count_if("Pies", "surname"));
	EXPECT_EQ(3, sim_db->db_select_count_if(1));
	EXPECT_EQ(1, sim_db->db_select_count_if(3.2f));
	EXPECT_NE(sim_db->db_select_count_if(1), 9);
	EXPECT_NE(sim_db->db_select_count_if(1.0f), 7.0);
}



