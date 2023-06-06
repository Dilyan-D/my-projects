#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

short int i, total = 0, index;

class cDelegate {
protected:
	string name, EGN, city;
	float expenses = 0.0;
	short int gender;
public:
	cDelegate() {
		name = "N/A";
		EGN = "N/A";
		city = "N/A";
		expenses = 0.0;
	}
	void setData();
	void getData();
};
void cDelegate::setData() {
	cout << "\n������ �����: "; getline(cin, name);
	cout << "������ ���: "; 
	while (getline(cin, EGN) && EGN.size() != 10) {
		cout << "���-�� ������ �� ���� 10 �������!\n";
		cout << "\n������ ���: ";
	}
	gender = stoi(EGN.substr(8, 1));
	if (gender % 2 == 0) gender = 0; //male
	else gender = 1; //female
	cout << "������ �������� �����: "; getline(cin, city);
	cout << "������ ����� ������� (� ����): "; cin >> expenses;
	cin.ignore();
}
void cDelegate::getData() {
	cout << "\n--\n�����: " << name;
	cout << "\n���: " << EGN;
	cout << "\n�������� �����: " << city;
	cout << "\n����� �������: "; printf("%0.2f", expenses); cout << " BGN";
}


class cHotel {
protected:
	string hotel, rnumber;
	float price = 0.0;
public:
	cHotel() {
		hotel = "N/A";
		rnumber = "N/A";
		price = 0.0;
	}
	void setData();
	void getData();
};
void cHotel::setData() {
	cout << "\n������ ��� �� �����: "; getline(cin, hotel);
	cout << "������ ����� �� ����: "; getline(cin, rnumber);
	cout << "������ ���� �� ������� (� ����): "; cin >> price;
	cin.ignore();
}
void cHotel::getData() {
	cout << "\n-\n�����: " << hotel;
	cout << "\n����� �� ����: " << rnumber;
	cout << "\n���� �� �������: "; printf("%0.2f", price); cout << " BGN";
}


class cDelegateCard : private cDelegate, private cHotel {
private: 
	string number, dateOfArrival, dateOfLeaving;
public:
	cDelegateCard() {
		number = "N/A";
		dateOfArrival = "N/A";
		dateOfLeaving = "N/A";
	}
	void setData();
	void getData();
	void getHotelData() {
		cHotel::getData();
	}
	void getSum(string, string);
	double calculateSum();
	void getDataByDate();
	string calculateDate(string, string);
	void newArray();
	short int getNewArraySize(string);
};
cDelegateCard Delegates[100];

void cDelegateCard::setData() {
	short int d, m, y;
	cDelegate::setData(); cHotel::setData();
	cout << "\n������ ���������� �����: ";
	while (getline(cin, number) && number.size() != 6) {
		cout << "������� ������ �� ���� 6 ������!\n";
		cout << "\n������ ���������� �����: ";
	}
	cout << "������ ���� �� ���������� (��/��/����): "; getline(cin, dateOfArrival);
	cout << "������ ���� �� ���������� (��/��/����): "; getline(cin, dateOfLeaving); cout << endl;
	
}
void cDelegateCard::getData() {
	cDelegate::getData(); cHotel::getData();
	cout << "\n-\n���������� �����: " << number;
	cout << "\n���� �� ���������� (��/��/����): " << dateOfArrival;
	cout << "\n���� �� ���������� (��/��/����): " << dateOfLeaving;
	cout << "\n--" << endl;
}
void cDelegateCard::getSum(string hotel, string city) {
	bool exists = false;
	for (i = 0; i < total; i++)
		if (hotel == Delegates[i].hotel && city == Delegates[i].city) {
			exists = true;
			for (int i = 0; i < total; i++) {
				if (hotel == Delegates[i].hotel && city == Delegates[i].city) {
					cout << "����������, ��������� � ����� " << hotel << ", � �������� ����� " << city << " ������: ";
					printf("%0.2f", Delegates[i].calculateSum()); cout << " BGN\n";
				}
			}
		}
	if (exists == false) cout << "���� ������� � �� �� ���������� ����� �/��� �������� �����.\n";
	
}
double cDelegateCard::calculateSum() {
	const int secondsPerDay = 60 * 60 * 24;
	short int d, m, y;
	tm timestruct;

	d = stoi(dateOfArrival.substr(0, 2));
	m = stoi(dateOfArrival.substr(3, 2));
	y = stoi(dateOfArrival.substr(6, 4));

	timestruct = { 0 };
	timestruct.tm_mday = d;
	timestruct.tm_mon = m - 1;
	timestruct.tm_year = y - 1900;
	tm Arrival = timestruct;

	d = stoi(dateOfLeaving.substr(0, 2));
	m = stoi(dateOfLeaving.substr(3, 2));
	y = stoi(dateOfLeaving.substr(6, 4));

	timestruct = { 0 };
	timestruct.tm_mday = d;
	timestruct.tm_mon = m - 1;
	timestruct.tm_year = y - 1900;
	tm Leaving = timestruct;

	time_t a_time = mktime(&Arrival);
	time_t l_time = mktime(&Leaving);

	double margin = difftime(a_time, l_time) / secondsPerDay;
	return abs(margin * price);
}
void cDelegateCard::getDataByDate() {
	short int index = 0;
	string minDate = Delegates[0].dateOfArrival;
	
	for (i = 0; i < total; i++) {
		if (Delegates[i].gender == 0) {
			minDate = calculateDate(minDate, Delegates[i].dateOfArrival);
			index = i+1;
		}
	}
	if (index != 0) {
		cout << "\n�������: " << Delegates[index-1].name;
		Delegates[index-1].getHotelData(); cout << endl << endl;
	}
	else {
		cout << "\n\n���� ��������, ���������� �� ���������.\n";
	}
	
}
string cDelegateCard::calculateDate(string min, string date) {
	const int secondsPerDay = 60 * 60 * 24;
	short int d, m, y;
	tm timestruct;

	d = stoi(min.substr(0, 2));
	m = stoi(min.substr(3, 2));
	y = stoi(min.substr(6, 4));

	timestruct = { 0 };
	timestruct.tm_mday = d;
	timestruct.tm_mon = m - 1;
	timestruct.tm_year = y - 1900;
	tm minArrival = timestruct;


	d = stoi(date.substr(0, 2));
	m = stoi(date.substr(3, 2));
	y = stoi(date.substr(6, 4));
	
	timestruct = { 0 };
	timestruct.tm_mday = d;
	timestruct.tm_mon = m - 1;
	timestruct.tm_year = y - 1900;
	tm ifArrival = timestruct;

	time_t min_time = mktime(&minArrival);
	time_t if_time = mktime(&ifArrival);

	double margin = difftime(if_time, min_time) / secondsPerDay;

	if (margin <= 0) return date;
	else return min;
}
void cDelegateCard::newArray() {
	string city; bool exists = false;
	cout << "\n�������� �����: "; getline(cin, city); cout << endl;
	for (i = 0; i < total; i++)
		if (city == Delegates[i].city) {
			exists = true;
			short int k = 0, n = getNewArraySize(city);
			cDelegate* newDelegates = new cDelegate[n];
			for (int i = 0; i < total; i++) {
				if (city == Delegates[i].city) {
					newDelegates[k] = Delegates[i];
					k++;
				}
			}

			for (int i = 0; i < n; i++) newDelegates[i].getData();
			cout << endl << endl;
		}
	if (exists == false) cout << "���� ������� � �� �� ���������� �������� �����.\n";
}
short int cDelegateCard::getNewArraySize(string city) {
	short int n = 0;
	for (i = 0; i < total; i++) {
		if (city == Delegates[i].city) n++;
	}
	return n;
}

int main() {
	short int choice;
	system("chcp 1251");
	system("cls");

Menu:
	cout << "\n-------------------------------------------------------------------------------";
	cout << "\n\t\t\t\t     � � � �";
	cout << "\n-------------------------------------------------------------------------------";
	cout << "\n1. ������ �������\t\t\t\t\t\t��������: " << total << "/100";
	cout << "\n2. ������ ������������ �� ���������� �� ��";
	cout << "\n3. ������� ������� �� ������� ����� ���� �� �������� �� �������� �������� �����";
	cout << "\n4. ������ ���. �� ������ � ����� �� ���-���� ������������ ������� ���";
	cout << "\n5. ������ � ������ ����� � ����� �� �������� �� �������� �������� ����� | "; cin >> choice; cin.ignore();

	switch (choice) {
	case 1: {
		short int current;
		cout << "\n����� �������� ����� ������ �� ��������? | "; cin >> current; cin.ignore();
		for (i = total; i < current + total; i++) Delegates[i].setData();
		total += current;
		cout << endl << current << " �������(�) ����/���� ������� �������(�).\n\n";
		goto Menu;
		break;
	}
	case 2: {
		if (total > 0) {
			cout << "\n��� ���� �������� � ������ �����: " << total << endl;
			for (i = 0; i < total; i++) Delegates[i].getData();
			goto Menu;
			break;
		}
		else {
			cout << "\n������ ����� � ������! ����, ����� �������� ��������.\n";
			goto Menu; break;
		}
	}
	case 3: {
		if (total > 0) {
			string hotel, city;
			cout << "\n�����: "; getline(cin, hotel);
			cout << "�������� �����: "; getline(cin, city); cout << endl;
			Delegates->getSum(hotel, city);
			goto Menu;
			break;
		}
		else {
			cout << "\n������ ����� � ������! ����, ����� �������� ��������.\n";
			goto Menu; break;
		}
	}
	case 4: {
		if (total > 0) {
			Delegates->getDataByDate();
			goto Menu;
			break;
		}
		else {
			cout << "\n������ ����� � ������! ����, ����� �������� ��������.\n";
			goto Menu; break;
		}
	}
	case 5: {
		if (total > 0) {
			Delegates->newArray();
			goto Menu;
			break;
		}
		else {
			cout << "\n������ ����� � ������! ����, ����� �������� ��������.\n";
			goto Menu; break;
		}
	}
	default: {
		cout << "\n��������� �����! ����, �������� ������.\n";
		goto Menu; break;
	}
	}
}