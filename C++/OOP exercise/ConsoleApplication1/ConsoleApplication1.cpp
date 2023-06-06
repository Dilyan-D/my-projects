#include <iostream>
#include <string>
using namespace std;

short int i, total = 0, sTotal = 0, tTotal = 0;

class cPerson {
protected:
	string name, EGN;
public:
	cPerson() {
		name = "N/A"; EGN = "N/A";
	}
	virtual void setData();
	virtual void getData();
};
void cPerson::setData() {

}
void cPerson::getData() {

}

class cStudent : public cPerson {
private:
	string faculty;
public:
	cStudent() {
		faculty = "00";
	}
	void setData();
	void getData();
};
void cStudent::setData() {
	cout << "name: "; getline(cin, name);
	cout << "EGN: "; getline(cin, EGN);
	cout << "Faculty: "; getline(cin, faculty);
	cout << endl << endl;
}
void cStudent::getData() {
	cout << "name: " << name;
	cout << "EGN: " << EGN;
	cout << "Faculty: " << faculty;
	cout << endl << endl;
}

class cTeacher : public cPerson {
private:
	string job;
public:
	cTeacher() {
		job = "N/A";
	}
	void setData();
	void getData();
};
void cTeacher::setData() {
	cout << "name: "; getline(cin, name);
	cout << "EGN: "; getline(cin, EGN);
	cout << "Job: "; getline(cin, job);
	cout << endl << endl;
}
void cTeacher::getData() {
	cout << "name: " << name;
	cout << "EGN: " << EGN;
	cout << "Job: " << job;
	cout << endl << endl;
}

cPerson* People[50];
cStudent Students[50];
cTeacher Teachers[50];

int main() {
	short int c;
Menu:
	cout << "1. Add";
	cout << "\n2. Show\n";
	cin >> c;
	switch (c) {
	case 1: {
		short int choice;
		cout << "\n1. Student\n2. Teacher\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			short int current;
			cout << "\nHow many? "; cin >> current; cin.ignore();
			for (i = total; i < current + total; i++) {
				People[i] = &Students[sTotal++];
				People[i]->setData();
			}
			total += current;
			goto Menu;
			break;
		}
		case 2: {
			short int current;
			cout << "\nHow many? "; cin >> current; cin.ignore();
			for (i = total; i < current + total; i++) {
				People[i] = &Teachers[tTotal++];
				People[i]->setData();
			}
			total += current;
			goto Menu;
			break;
		}
		}
	case 2: {
		cout << endl << endl;
		for (i = 0; i < total; i++) {
			People[i]->getData();
		}
	}
	}
	}
}