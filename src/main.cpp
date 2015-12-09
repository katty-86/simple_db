#include <iostream>
/*#include <memory>

#include "../include/Customer.h"
#include "../include/Simpledb.h"

using namespace std;

int main() {

	SimpleDB sim_db("write");
	cout << sim_db.getFilename() << endl;

	shared_ptr<Customer> bs0 =make_shared <Customer> (1,"imie1", "nazwisko1", 1, 1.0);
	shared_ptr<Customer> bs1 =make_shared <Customer> (2, "imie2", "nazwisko2", 1, 1.0);
	shared_ptr<Customer> bs2 =make_shared <Customer> (5,"imie1", "nazwisko1", 1, 1.0);
	//cout<<*bs0<<endl;
	//cout<<*bs1<<endl;
	sim_db.db_insert(*bs0);
	sim_db.db_insert(*bs1);
	sim_db.db_insert(*bs2);
	cout<<sim_db<<endl;
	cout<<"writing"<<endl;
	sim_db.save_data(sim_db);
//

cout<<"reading"<<endl;
//
	SimpleDB sim_db1("read");
	sim_db1.read_data(sim_db1);
	shared_ptr<Customer> bs11 =make_shared <Customer> (3,"imie2", "nazwisko2", 1, 1.0);
	cout<<"ilosc "<<sim_db1.db_select_count(*bs11)<<endl;
	cout<<"imie "<<sim_db1.db_select_count_if("imie1", "name")<<endl;
	cout<<"nazwisko "<<sim_db1.db_select_count_if(1.0 )<<endl;
	cout<<sim_db1<<endl;
	cout << "cleaning"<<endl;
	return 0;
}*/
