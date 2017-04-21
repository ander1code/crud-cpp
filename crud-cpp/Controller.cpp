#include <iostream>
#include <exception>
#include <sstream>
#include "sqlite3.h"
#include <exception>
#include "Controller.h"
#include "Connection.h"
#include "Date.h"

using namespace std;

	int Controller::BeginTrans()
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "BEGIN TRANSACTION";
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}

	int Controller::Commit()
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "COMMIT";
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}


	int Controller::Rollback()
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "ROLLBACK";
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}


	int Controller::InsertPerson(int id, std::string name, std::string email, double salary, Date birthday, std::string gender)
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "INSERT INTO PERSON(ID, NAME, EMAIL, BIRTHDAY, SALARY, GENDER) VALUES(" << id << ",'" << name << "','" << email << "','" << birthday.ToString() << "'," << salary << ",'" << gender << "');";
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}

	int Controller::InsertCustomer()
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "INSERT INTO CUSTOMER(ID, PERSON_ID) VALUES(" << this->cust.getID() << "," << this->cust.getID() << ");";
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}

	int Controller::EditPerson(int id, std::string name, std::string email, double salary, Date birthday, std::string gender)
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "UPDATE PERSON SET NAME='" << name << "',EMAIL='" << email << "',BIRTHDAY='" << birthday.ToString() << "',SALARY=" << salary << ",GENDER='" << gender << "' WHERE ID = " << id;
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}

	int Controller::EditCustomer()
	{
		return 1;
	}


	int Controller::DeletePerson(int id)
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "DELETE FROM PERSON WHERE ID = " << id;
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}


	int Controller::DeleteCustomer()
	{
		char *zErrMsg = 0;
		int rc;
		std::ostringstream sql;
		sql << "DELETE FROM CUSTOMER WHERE ID = " << this->cust.getID();
		string sqlstr = sql.str();

		rc = sqlite3_exec(this->conn, sqlstr.c_str(), 0, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			return -1;
		}
		else{
			return 1;
		}
	}

	Controller::Controller(Customer cust)
	{
		this->cust = cust;
		this->conn = Connection::Connect();
	}

	Controller::Controller()
	{
		this->conn = Connection::Connect();
	}

	Controller::~Controller()
	{
	}


	int Controller::Insert_Customer()
	{
		this->BeginTrans();
		this->cust.setID(123);

		if (this->InsertPerson(this->cust.getID(), this->cust.getName(), this->cust.getEmail(), this->cust.getSalary(), this->cust.getBirthday(), this->cust.getGender()) == 1)
		{
			if (this->InsertCustomer() == 1)
			{
				this->Commit();
				Connection::Close(this->conn);
				return 1;
			}
			else
			{
				this->Rollback();
				Connection::Close(this->conn);
				return -1;
			}
		}
		else
		{
			this->Rollback();
			Connection::Close(this->conn);
			return -1;
		}
	}


	int Controller::Edit_Customer()
	{
		this->BeginTrans();
		if (this->EditPerson(this->cust.getID(), this->cust.getName(), this->cust.getEmail(), this->cust.getSalary(), this->cust.getBirthday(), this->cust.getGender()) == 1)
		{
			if (this->EditCustomer() == 1)
			{
				this->Commit();
				Connection::Close(this->conn);
				return 1;
			}
			else
			{
				this->Rollback();
				Connection::Close(this->conn);
				return -1;
			}
		}
		else
		{
			this->Rollback();
			Connection::Close(this->conn);
			return -1;
		}
	}


	int Controller::Delete_Customer()
	{
		this->BeginTrans();
		if (this->DeleteCustomer() == 1)
		{
			if (this->DeletePerson(this->cust.getID()) == 1)
			{
				this->Commit();
				Connection::Close(this->conn);
				return 1;
			}
			else
			{
				this->Rollback();
				Connection::Close(this->conn);
				return -1;
			}
		}
		else
		{
			this->Rollback();
			Connection::Close(this->conn);
			return -1;
		}
	}

	int Controller::callbackGET(void *unused, int count, char **data, char **columns)
	{
		int i = 0;
		int l;

		for (l = 0; l < 30; l++)
		{
			cout << "-";
		}

		cout << "\n";

		while (i<count)
		{
			if ((i == 6) || (i == 7))
			{
				i++;
				continue;
			}

			cout << columns[i] << "= " << data[i] ? data[i] : "NULL";
			cout << "\n";
			i++;
		}
		return 0;
	}

	int Controller::GetPhysicalPersonByID()
	{
		sqlite3 *db = Connection::Connect();
		char *zErrMsg = 0;
		int rc;

		std::ostringstream sql;
		sql << "SELECT * FROM PERSON INNER JOIN CUSTOMER ON PERSON.ID = CUSTOMER.PERSON_ID WHERE PERSON.ID = " << this->cust.getID();
		string sqlstr = sql.str();
		rc = sqlite3_exec(this->conn, sqlstr.c_str(), callbackGET, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			Connection::Close(db);
			return -1;
		}
		else{
			Connection::Close(db);
			return 1;
		}
	}

	int Controller::GetPhysicalPersonByName()
	{
		sqlite3 *db = Connection::Connect();
		char *zErrMsg = 0;
		int rc;

		std::ostringstream sql;
		sql << "SELECT * FROM PERSON INNER JOIN CUSTOMER ON PERSON.ID = CUSTOMER.PERSON_ID WHERE PERSON.NAME LIKE '" << this->cust.getName() << "%'";
		string sqlstr = sql.str();
		rc = sqlite3_exec(this->conn, sqlstr.c_str(), callbackGET, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			sqlite3_free(zErrMsg);
			Connection::Close(db);
			return -1;
		}
		else{
			Connection::Close(db);
			return 1;
		}
	}

