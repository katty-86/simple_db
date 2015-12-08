#include <iostream>
#include <memory>
#include "Simpledb.h"
#include "Customer.h"

using namespace std;

int main() {

	SimpleDB sim_db("write");
	cout << sim_db.getFilename() << endl;

	shared_ptr<Customer> bs0 (new Customer("imie1", "nazwisko1", 1, 1.0));
	shared_ptr<Customer> bs1 (new Customer("imie2", "nazwisko2", 1, 1.0));
	//cout<<*bs0<<endl;
	//cout<<*bs1<<endl;
	sim_db.db_insert(*bs0);
	sim_db.db_insert(*bs1);
	cout<<sim_db<<endl;
	cout<<"writing"<<endl;
	sim_db.save_data(sim_db);
//
cout<<"reading"<<endl;
//
	SimpleDB sim_db1("read");
	sim_db1.read_data(sim_db1);
	cout<<sim_db1<<endl;

	cout << "cleaning"<<endl;
	return 0;
}
