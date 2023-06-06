#include <iostream>
#include <stdlib.h>
#include <mysql.h>
#include <sstream>
#include <string>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
using namespace std;

class Design {
public:

};
class Functionality {
public:
	char srv_name[20], db_name[20], db_user[20], db_pass[20];
	char t_name[20]; string datarows; string data;
	char datafield[20], datafield_data[20], where_field[20], where_data[20];
	short int choice, t_count, c_count;

	bool dbconnection() {
		
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);
		
		if (conn) {
			cout << "-----------------------------------\n";
			cout << "Database connectivity established.\n";
			cout << "-----------------------------------\n";
			return true;
		}
		else {
			cout << "\a-------------------------------------------\n";
			cout << "       Database connection failed!\n";
			cout << " Please restart the program and try again!\n";
			cout << "-------------------------------------------\n";
			return false;
		}	
	}

	void AddTable(string* column_names, string* column_types) {
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		int qstate = 0;
		stringstream ss;

		for (int i = 0; i < c_count; i++) {
			data += column_names[i] + " " + column_types[i] + ", ";
		}
		data.resize(data.length() - 2);
		ss << "CREATE TABLE `" << t_name << "` (" << data << ")";
		
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (qstate == 0) {
			cout << "---------------------------\n";
			cout << "Table creation successful.\n";
			cout << "---------------------------\n\n";
		}
		else { cout << "\aTable creation failed - please check your input and try again!\n\n"; }
	}

	void DeleteTable() {
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		int qstate = 0;
		stringstream ss;
		ss << "DROP TABLE `" << t_name << "`";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (qstate == 0) cout << "Table '" << t_name << "' successfully deleted.\n\n";
		else cout << "\aTable deletion unsuccessful. Are you sure this table exists in the database?\n\n";

	}

	void ShowTables() {
		MYSQL* conn; MYSQL_RES* result; MYSQL_RES* result1; MYSQL_ROW row;
		int num_fields, i=0;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		int qstate = 0;
		stringstream ss;
		ss << "SHOW TABLES";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
		result1 = mysql_store_result(conn);

		cout << "Tables currently in the database:\n";
		while ((row = mysql_fetch_row(result))) {
			for (i = 0; i < num_fields; i++) cout << row[i] << ", ";
		}
		cout << "\n\n";
		mysql_free_result(result); //Clears result set from memory
			
	}

	void ShowTableData() {
		MYSQL* conn; MYSQL_RES* result; MYSQL_ROW row;
		int num_fields, i, qstate = 0;
		stringstream ss, ss1; string query; const char* q;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		ss << "SELECT `COLUMN_NAME` FROM `INFORMATION_SCHEMA`.`COLUMNS` WHERE `TABLE_SCHEMA`='" << db_name <<
			"' AND `TABLE_NAME`='" << t_name << "'; ";
		query = ss.str();
		q = query.c_str();
		qstate = mysql_query(conn, q);
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
		//cout << qstate << "    " << query << "    " << q << "    " << result << "    " << num_fields << "    " << conn;
		while ((row = mysql_fetch_row(result))) {
			for (i = 0; i < num_fields; i++) cout << row[i] << "\t";
		}
		cout << "\n";
		mysql_free_result(result); //Clears result set from memory

		ss1 << "SELECT * FROM `" << t_name << "`";
		query = ss1.str();
		q = query.c_str();
		qstate = mysql_query(conn, q);
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
			
		while ((row = mysql_fetch_row(result))) {
			for (i = 0; i < num_fields; i++) cout << row[i] << "  \t";
			cout << endl;
		}
		cout << "\n\n";
		mysql_free_result(result); //Clears result set from memory
	}

	void InsertTableData(string* column_names, string* column_data) {
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		int qstate = 0;
		stringstream ss;

		for (int i = 0; i < c_count; i++) {
			datarows += "`" + column_names[i] + "`, ";
			data += "'" + column_data[i] + "', ";
		}
		datarows.resize(datarows.length() - 2);
		data.resize(data.length() - 2);

		ss << "INSERT INTO `" << t_name << "` (" << datarows << ") VALUES (" << data << ")";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (qstate == 0) {
			cout << "Data row inserted to table '" << t_name << "' successfully.\n\n";
		}
		else { cout << "\aData insertion failed - please check your input and try again!\n\n"; }
	}

	void ModifyTableData() {
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		int qstate = 0;
		stringstream ss;
		ss << "UPDATE `" << t_name << "` SET " << datafield << " = '" << datafield_data << "' WHERE `" << where_field << "` = '" <<
			where_data <<"'";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		
		if (qstate == 0) {
			cout << "\nData of column '" << datafield << "' from table '" << t_name << "'\nwhere '" << where_field << "' = '" <<
				where_data << "' successfully set to '" << datafield_data << "'\n\n";
		}
		else { cout << "\a\nData modification failed - please check your input and try again!\n\n"; }
	}

	void DeleteTableData() {
		MYSQL* conn;
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "localhost", "root", "password", db_name, 0, NULL, 0);

		//int br;
		/*for (int i = 0; i < c_count; i++) {
			cout << "Column name: "; cin >> datafield[i];
			cout << "Data: "; cin >> datafield_data[i];
		}*/
		int qstate = 0;
		stringstream ss;
		ss << "DELETE FROM `" << t_name << "` WHERE `" << datafield << "` = '" << datafield_data << "'";
		string query = ss.str();
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (qstate == 0) {
			cout << "Data row where '" << datafield << "' = '" << datafield_data << "' successfully deleted.\n\n";
		}
		else { cout << "\aData deletion failed - please check your input and try again!\n\n"; }
	}
};

int main() {
	Functionality myObj;

	cout << "-- ECHOSOFT --\n";
	cout << "-- Your first need tool for database manipulation --\n\n";

	Database_Section:
	//cout << "Server: "; cin >> myObj.srv_name;
	cout << "Database name: "; cin >> myObj.db_name;
	/*cout << "Database username: "; cin >> myObj.db_user;
	cout << "Database password: "; cin >> myObj.db_pass;*/

	if (myObj.dbconnection() == 1) {

	First_Section:
		cout << "0. Exit database\n";
		cout << "1. View data\n";
		cout << "2. Add, delete or change data | Input: "; cin >> myObj.choice;

		switch (myObj.choice) {
		case 0: { cout << endl; goto Database_Section; break; }
		case 1: {
		Second_Section_1:
			cout << "  1.0. Go back\n";
			cout << "  1.1. Show all tables in database\n";
			cout << "  1.2. Show all data in a table | Input: "; cin >> myObj.choice;

			switch (myObj.choice) {
			case 0: { goto First_Section; break; }
			case 1: { myObj.ShowTables(); goto Second_Section_1; break; }
			case 2: {
				cout << "Table name: "; cin >> myObj.t_name; cout << endl;
				myObj.ShowTableData();
				goto Second_Section_1;
				break;
			}
			default: {
				cout << "Error: Invalid choice\n\n";
				goto Second_Section_1;
				break;
			}
			}
			break;
		}
		case 2: {
		Second_Section_2:
			cout << "  2.0. Go back\n";
			cout << "  2.1. Insert table(s) into database\n";
			cout << "  2.2. Delete table(s) from database\n";
			cout << "  2.3. Insert data row(s) into table\n";
			cout << "  2.4. Delete data row(s) from table\n";
			cout << "  2.5. Modify data of a table | Input: "; cin >> myObj.choice;

			switch (myObj.choice) {
			case 0: { goto First_Section; break; }
			case 1: {
				cout << "\nHow many tables?: "; cin >> myObj.t_count;
				for (int i = 0; i < myObj.t_count; i++) {
					cout << "Table " << i + 1 << " name: "; cin >> myObj.t_name;
					cout << "How many columns?: "; cin >> myObj.c_count;
					string* column_names = new string[myObj.c_count];
					string* column_types = new string[myObj.c_count];

					for (int i = 0; i < myObj.c_count; i++) {
						cout << "Column " << i + 1 << " name: "; cin >> column_names[i];  
						cout << "Column " << i + 1 << " type: "; cin >> column_types[i];
					}
					myObj.AddTable(column_names, column_types);
					column_names->clear(); column_types->clear();
				}
				goto Second_Section_2;
				break;
			}
			case 2: {
				cout << "\nHow many tables?: "; cin >> myObj.t_count;
				for (int i = 0; i < myObj.t_count; i++) {
					cout << "Table " << i + 1 << " name: "; cin >> myObj.t_name;
					myObj.DeleteTable();
				}
				goto Second_Section_2;
				break;
			}
			case 3: {
				cout << "\nTable name: "; cin >> myObj.t_name;
				cout << "How many columns?: "; cin >> myObj.c_count;
				string* column_names = new string[myObj.c_count];
				string* column_data = new string[myObj.c_count];

				for (int i = 0; i < myObj.c_count; i++) {
					cout << "Column " << i + 1 << " name: "; cin >> column_names[i];
					cout << "Column " << i + 1 << " data: "; cin >> column_data[i];
				}

				myObj.InsertTableData(column_names, column_data);
				column_names->clear(); column_data->clear();
				goto Second_Section_2;
				break;
			}
			case 4: {
				cout << "\nTable name: "; cin >> myObj.t_name;
				cout << "How many columns?: "; cin >> myObj.c_count;
				for (int i = 0; i < myObj.c_count; i++) {
					cout << "Column name: "; cin >> myObj.datafield;
					cout << "Where: "; cin >> myObj.datafield_data;
					myObj.DeleteTableData();
				}
				goto Second_Section_2;
				break;
			}
			case 5: {
				cout << "\nTable name: "; cin >> myObj.t_name;
				cout << "How many columns?: "; cin >> myObj.c_count;
				for (int i = 0; i < myObj.c_count; i++) {
					cout << "Column name: "; cin >> myObj.datafield;
					cout << "New data: "; cin >> myObj.datafield_data;
					cout << "Where column: "; cin >> myObj.where_field; cout << "is = "; cin >> myObj.where_data;
					myObj.ModifyTableData();
				}
				goto Second_Section_2;
				break;
			}
			default: {
				cout << "Error: Invalid choice\n\n";
				goto Second_Section_2;
				break;
			}
			}
		}
		default: {
			cout << "Error: Invalid choice\n\n";
			goto First_Section;
			break;
		}
		}
	}
	return 0;
}