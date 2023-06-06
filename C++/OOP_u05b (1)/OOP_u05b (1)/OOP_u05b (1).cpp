#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

short int i, total = 0, br = 0;
float sum[30] = { 0 }, sum1 = 0;
bool if1 = false, if2 = false, if3 = false;

class CPerson {
protected:
	string name, EGN;
public:
	CPerson();
	CPerson(string, string);
	void setData(); //getData()
	void getData(); //display()
	void setDataBG();
	void getDataBG();
};
CPerson::CPerson() {
	name = "N/A";
	EGN = "N/A";
}
CPerson::CPerson(string name, string EGN) {
	this->name = name;
	this->EGN = EGN;
}
void CPerson::setData() {
	cin.ignore();
	cout << "\nEnter name: "; getline(cin, name);
	cout << "Enter EGN: "; getline(cin, EGN);
}
void CPerson::getData() {
	cout << "\n--\nName: " << name;
	cout << "\nEGN: " << EGN;
}
void CPerson::setDataBG() {
	cin.ignore();
	cout << "\nВъведи име: "; getline(cin, name);
	cout << "Въведи ЕГН: "; getline(cin, EGN);
}
void CPerson::getDataBG() {
	cout << "\n--\nИме: " << name;
	cout << "\nЕГН: " << EGN;
}

class CStudent : private CPerson {
private:
	string F_number;
	float marks[9];
public:
	CStudent();
	CStudent(string name, string EGN, string F_number, float marks[]);
	void setData(); //getData()
	void getData(); //display()
	void setDataBG();
	void getDataBG();

	void runCheck(string);
	void avgMarksOfGroup(string);
	void avgMarksOfStudent(string);
	void getDataByMarks();
	void getDataBGByMarks();
	void marksCheck(string);
	void marksCheckBG(string);
};
CStudent Students[100];
CStudent::CStudent() {
	name = "N/A";
	EGN = "N/A";
	F_number = "N/A";
	for (i = 0; i < 5; i++) marks[i] = 0.0;
}
CStudent::CStudent(string name, string EGN, string F_number, float marks[]){
	this->name = name;
	this->EGN = EGN;
	this->F_number = F_number;
	for (i = 0; i < 5; i++) this->marks[i] = marks[i];
}
void CStudent::setData() {
	float mark;
	CPerson::setData();
	cout << "Enter faculty number: "; getline(cin, F_number);
	for (int i = 0; i < 10; i++) {
	setMark:
		cout << "Enter mark " << i+1 << ": "; cin >> mark;
		if (mark >= 2 && mark <= 6) {
			marks[i] = mark;
		}
		else {
			cout << "Marks must be between 2 and 6!\n\n";
			goto setMark;
		}
	}
}
void CStudent::getData() {
	CPerson::getData();
	cout << "\nFaculty number: " << F_number;
	cout << "\nMarks: | "; for (int i = 0; i < 10; i++) { printf("%0.2f", marks[i]); cout << " | "; }
	cout << "\n--" << endl << endl;
}
void CStudent::setDataBG() {
	float mark;
	CPerson::setDataBG();
	cout << "Въведи факултетен номер: "; getline(cin, F_number);
	for (int i = 0; i < 10; i++) {
	setMark:
		cout << "Въведи оценка " << i + 1 << ": "; cin >> mark;
		if (mark >= 2 && mark <= 6) {
			marks[i] = mark;
		}
		else {
			cout << "Оценките трябва да бъдат между 2 и 6!\n\n";
			goto setMark;
		}
	}
}
void CStudent::getDataBG() {
	CPerson::getDataBG();
	cout << "\nФакултетен номер: " << F_number;
	cout << "\nОценки: | "; for (int i = 0; i < 10; i++) { printf("%0.2f", marks[i]); cout << " | "; }
	cout << "\n--" << endl << endl;
}

void CStudent::runCheck(string group) {
	if (F_number.substr(2, 2) == group) if3 = true;
}
void CStudent::avgMarksOfGroup(string group) {
	if (F_number.substr(2, 2) == group) {
		for (int j = 0; j < 10; j++)
			sum[i] += marks[j];
		sum[i] /= 10;
		br++;
	}
}
void CStudent::avgMarksOfStudent(string F_number) {
	if (this->F_number == F_number) {
		if2 = true;
		for (int i = 0; i < 10; i++)
			sum1 += marks[i];
	}
}
void CStudent::getDataByMarks() {
	short int br = 0;
	for (int i = 0; i < 10; i++)
		if (marks[i] < 3.00 && marks[i] > 1.99) br++;

	if (br >= 2) {
		Students[i].getData();
		if1 = true;
	}
}
void CStudent::getDataBGByMarks() {
	short int br = 0;
	for (int i = 0; i < 10; i++)
		if (marks[i] < 3.00 && marks[i] > 1.99) br++;

	if (br >= 2) {
		Students[i].getDataBG();
		if1 = true;
	}
}
void CStudent::marksCheck(string F_number) {

	if (this->F_number == F_number) {
		if2 = true;
		bool bad = false;
		for (int i = 0; i < 10; i++)
			if (marks[i] < 3.00 && marks[i] > 1.99) {
				bad = true;
				break;
			}
		if (bad == true) {
			cout << "\nThis student has a bad mark!\n";
			if1 = true;
		}
	}
}
void CStudent::marksCheckBG(string F_number) {

	if (this->F_number == F_number) {
		if2 = true;
		bool bad = false;
		for (int i = 0; i < 10; i++)
			if (marks[i] < 3.00 && marks[i] > 1.99) {
				bad = true;
				break;
			}
		if (bad == true) {
			cout << "\nТози студент има лоша оценка!\n";
			if1 = true;
		}
	}
}

int BG_version();
int EN_version() {
	short int choice;
	system("cls");

Menu:
	cout << "\n---------------------------------------------------------------------";
	cout << "\n\t\t\t\tM E N U";
	cout << "\n---------------------------------------------------------------------";
	cout << "\n0. Change language to bulgarian\t\t\tSTUDENTS: " << total << "/100";
	cout << "\n1. Add new student(s) to list";
	cout << "\n2. Print all students' data from list";
	cout << "\n3. Calculate average mark of all students in specific specialty";
	cout << "\n4. Calculate average mark of specific student";
	cout << "\n5. Print students' data with more than one bad mark (2)";
	cout << "\n6. Check if a specific student has a bad mark | "; cin >> choice;

	switch (choice) {
	case 0: {
		return BG_version();
		break;
	}
	case 1: {
	AddStudent:
		int current;
		cout << "\nHow many students would you like to add? | "; cin >> current;
		for (i = total; i < current + total; i++) Students[i].setData();
		total += current;
		cout << endl << current << " student(s) has/have been successfully added.\n\n";
		goto Menu;
		break;
	}
	case 2: {
		if (total > 0) {
			cout << "\nTotal students in database: "; cout << total << endl;
			for (i = 0; i < total; i++) Students[i].getData();
			goto Menu;
			break;
		}
		else {
			cout << "\nDatabase is empty! Please, add some students first.\n";
			goto AddStudent; break;
		}
	}
	case 3: {
		if (total > 0) {
			string group;
			float sum2 = 0; cin.ignore();
			cout << "\nSpecialty number: "; getline(cin, group); if3 = false;
			for (i = 0; i < total; i++) Students[i].runCheck(group);
			if (if3 == true) {
				for (i = 0; i < total; i++) Students[i].avgMarksOfGroup(group);
				for (i = 0; i < br; i++) sum2 += sum[i];
				cout << "\nAverage mark of specialty: "; printf("%0.2f", sum2 / br); cout << endl;
				for (i = 0; i < br; i++) sum[i] = 0;
				sum2, br = 0;
				goto Menu;
				break;
			}
			else {
				cout << "\nNo students in specialty are registered.\n";
				goto Menu;
				break;
			}
			
		}
		else {
			cout << "\nDatabase is empty! Please, add some students first.\n";
			goto AddStudent; break;
		}
	}
	case 4: {
		if (total > 0) {
			string f_number;
			cin.ignore();
			cout << "\nFaculty number: "; getline(cin, f_number);
			for (i = 0; i < total; i++) Students[i].avgMarksOfStudent(f_number);
			if (if2 == false) cout << "\nNo student with faculty number is registered.\n";
			else {
				cout << "\nAverage mark of student: "; printf("%0.2f", sum1 / 10); cout << endl;
			}
			sum1 = 0;
			if2 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nDatabase is empty! Please, add some students first.\n";
			goto AddStudent; break;
		}
	}
	case 5: {
		if (total > 0) {
			for (i = 0; i < total; i++) Students[i].getDataByMarks();
			if (if1 == false) cout << "\nNo students matching criteria were found.\n";
			if1 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nDatabase is empty! Please, add some students first.\n";
			goto AddStudent; break;
		}
	}
	case 6: {
		if (total > 0) {
			string f_number; cin.ignore();
			cout << "\nFaculty number: "; getline(cin, f_number);
			for (i = 0; i < total; i++) Students[i].marksCheck(f_number);
			if (if2 == false) cout << "\nNo student with faculty number is registered.\n";
			else {
				if (if1 == false) cout << "\nThis student doesn't have a bad mark!\n";
				if1 = false;
			}
			if2 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nDatabase is empty! Please, add some students first.\n";
			goto AddStudent; break;
		}
	}
	default: {
		cout << "\nInvalid choice! Please, try again.\n";
		goto Menu; break;
	}
	}
	return 0;
}
int BG_version() {
	short int choice;
	system("chcp 1251");
	system("cls");

Menu:
	cout << "\n---------------------------------------------------------------------";
	cout << "\n\t\t\t\tМ Е Н Ю";
	cout << "\n---------------------------------------------------------------------";
	cout << "\n0. Промяна на езика на английски\t\t      СТУДЕНТИ: " << total << "/100";
	cout << "\n1. Добави нов(и) студент(и) в списъка";
	cout << "\n2. Изведи информацията на студентите от списъка";
	cout << "\n3. Изчисли средна оценка на всички студенти от определена специалност";
	cout << "\n4. Изчисли средна оценка на определен студент";
	cout << "\n5. Изведи информацията на студентите с повече от една слаба оценка (2)";
	cout << "\n6. Провери определен студент за слаба оценка | "; cin >> choice;

	switch (choice) {
	case 0: {
		return EN_version();
		break;
	}
	case 1: {
	AddStudent:
		int current;
		cout << "\nКолко студенти бихте искали да добавите? | "; cin >> current;
		for (i = total; i < current + total; i++) Students[i].setDataBG();
		total += current;
		cout << endl << current << " студент(и) беше/бяха успешно добавен(и).\n\n";
		goto Menu;
		break;
	}
	case 2: {
		if (total > 0) {
			cout << "\nОбщ брой студенти в базата данни: "; cout << total << endl;
			for (i = 0; i < total; i++) Students[i].getDataBG();
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете добавете студенти.\n";
			goto AddStudent; break;
		}
	}
	case 3: {
		if (total > 0) {
			string group;
			float sum2 = 0; cin.ignore();
			cout << "\nНомер на специалност: "; getline(cin, group); if3 = false;
			for (i = 0; i < total; i++) Students[i].runCheck(group);
			if (if3 == true) {
				for (i = 0; i < total; i++) Students[i].avgMarksOfGroup(group);
				for (i = 0; i < br; i++) sum2 += sum[i];
				cout << "\nСредна оценка на специалността: "; printf("%0.2f", sum2 / br); cout << endl;
				for (i = 0; i < br; i++) sum[i] = 0;
				sum2, br = 0;
				goto Menu;
				break;
			}
			else {
				cout << "\nНяма регистрирани студенти в специалността.\n";
				goto Menu;
				break;
			}

		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете добавете студенти.\n";
			goto AddStudent; break;
		}
	}
	case 4: {
		if (total > 0) {
			string f_number;
			cin.ignore();
			cout << "\nФакултетен номер: "; getline(cin, f_number);
			for (i = 0; i < total; i++) Students[i].avgMarksOfStudent(f_number);
			if (if2 == false) cout << "\nНяма регистрирани студенти с този факултетен номер.\n";
			else {
				cout << "\nСредна оценка на студента: "; printf("%0.2f", sum1 / 10); cout << endl;
			}
			sum1 = 0;
			if2 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете добавете студенти.\n";
			goto AddStudent; break;
		}
	}
	case 5: {
		if (total > 0) {
			for (i = 0; i < total; i++) Students[i].getDataBGByMarks();
			if (if1 == false) cout << "\nНяма регистрирани студенти, отговарящи на критерия.\n";
			if1 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете добавете студенти.\n";
			goto AddStudent; break;
		}
	}
	case 6: {
		if (total > 0) {
			string f_number; cin.ignore();
			cout << "\nФакултетен номер: "; getline(cin, f_number);
			for (i = 0; i < total; i++) Students[i].marksCheckBG(f_number);
			if (if2 == false) cout << "\nНяма регистрирани студенти с този факултетен номер.\n";
			else {
				if (if1 == false) cout << "\nТози студент няма лоша оценка!\n";
				if1 = false;
			}
			if2 = false;
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете добавете студенти.\n";
			goto AddStudent; break;
		}
	}
	default: {
		cout << "\nНевалиден избор! Моля, опитайте отново.\n";
		goto Menu; break;
	}
	}
	return 0;
}
int main() {
	string lang;
	cout << "EN/BG? : "; cin >> lang;
	if (lang == "EN" || lang == "en") {
		cout << endl << endl;
		EN_version();
	}
	if (lang == "BG" || lang == "bg") BG_version();
	if (lang != "EN" || lang != "BG") return main();
}