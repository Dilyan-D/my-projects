#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

short int i, cTotal = 0, tTotal = 0;
float ifChair, ifTable = 0.0;

class cFurniture {
protected:
	string name;
	float price;
public:
	cFurniture() {
		name = "N/A";
		price = 0.0;
	}
	void setData();
	void getData();
};

void cFurniture::setData() {
	cout << "\nВъведи наименование: "; getline(cin, name);
	cout << "Въведи цена: "; cin >> price;
	cin.ignore();
}
void cFurniture::getData() {
	cout << "\n--\nИме: " << name;
	cout << "\nЦена: "; printf("%0.2f", price); cout << " BGN";
}


class cChair : private cFurniture {
private:
	string color;
public:
	cChair() {
		name = "N/A"; color = "N/A";
		price = 0.0;
	}
	void setData();
	void getData();
	void getDataByPrice();
	void runCheck();
	float getPrice() {
		return price;
	}
};
cChair Chairs[100];
void cChair::setData() {
	cFurniture::setData();
	cout << "Въведи цвят: "; getline(cin, color);
}
void cChair::getData() {
	cFurniture::getData();
	cout << "\nЦвят: " << color;
	cout << "\n--" << endl;
}
void cChair::runCheck() {
	if (price < ifChair)
		ifChair = price;
}
void cChair::getDataByPrice() {
	if (price == ifChair)
		getData();
}


class cTable : private cFurniture {
private:
	short int brplaces;
public:
	cTable() {
		name = "N/A";
		price = 0.0; brplaces = 0;
	}
	void setData();
	void getData();
	void getDataByPrice();
	void runCheck();
};
cTable Tables[100];
void cTable::setData() {
	cFurniture::setData();
	cout << "Въведи брой места: "; cin >> brplaces;
	cin.ignore();
}
void cTable::getData() {
	cFurniture::getData();
	cout << "\nБрой места: " << brplaces;
	cout << "\n--" << endl;
}
void cTable::runCheck() {
	if (price > ifTable)
		ifTable = price;
}
void cTable::getDataByPrice() {
	if (price == ifTable)
		getData();
}


int main() {
	short int choice;
	system("chcp 1251");
	system("cls");

Menu:
	cout << "\n-----------------------------------------------------";
	cout << "\n\t\t      М Е Н Ю";
	cout << "\n-----------------------------------------------------";
	cout << "\n1. Добави нов(и) стол(ове) в БД\t\tМЕБЕЛИ: " << cTotal + tTotal << "/200";
	cout << "\n2. Добави нова/и маса/и в БД";
	cout << "\n3. Изведи информацията на мебелите от БД";
	cout << "\n4. Изведи информацията на най-евтиния стол";
	cout << "\n5. Изведи информацията на най-скъпата маса | "; cin >> choice;

	switch (choice) {
	case 1: {
	AddChair:
		short int current;
		cout << "\nКолко столове бихте искали да добавите? | "; cin >> current; cin.ignore();
		for (i = cTotal; i < current + cTotal; i++) Chairs[i].setData();
		cTotal += current;
		cout << endl << current << " стол(a) беше/бяха успешно добавен(и).\n\n";
		goto Menu;
		break;
	}
	case 2: {
	AddTable:
		int current;
		cout << "\nКолко маси бихте искали да добавите? | "; cin >> current; cin.ignore();
		for (i = tTotal; i < current + tTotal; i++) Tables[i].setData();
		tTotal += current;
		cout << endl << current << " маса/и беше/бяха успешно добавена/и.\n\n";
		goto Menu;
		break;
	}
	case 3: {
		if ((cTotal + tTotal) > 0) {
			cout << "\nОбщ брой мебели в базата данни: " << cTotal + tTotal;
			cout << "\n\nСтолове (" << cTotal << "): ";
			for (i = 0; i < cTotal; i++) Chairs[i].getData();
			cout << "\n\nМаси (" << tTotal << "): ";
			for (i = 0; i < tTotal; i++) Tables[i].getData();
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете мебели.\n";
			goto Menu; break;
		}
	}
	case 4: {
		if (cTotal > 0) {
			ifChair = Chairs[0].getPrice();
			for (i = 0; i < cTotal; i++) Chairs[i].runCheck();
			for (i = 0; i < cTotal; i++) Chairs[i].getDataByPrice();
			ifChair = Chairs[0].getPrice();
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете столове.\n";
			goto AddChair; break;
		}
	}
	case 5: {
		if (tTotal > 0) {
			for (i = 0; i < tTotal; i++) Tables[i].runCheck();
			for (i = 0; i < tTotal; i++) Tables[i].getDataByPrice();
			ifTable = 0.0;
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете маси.\n";
			goto AddTable; break;
		}
	}
	default: {
		cout << "\nНевалиден избор! Моля, опитайте отново.\n";
		goto Menu; break;
	}
	}
}