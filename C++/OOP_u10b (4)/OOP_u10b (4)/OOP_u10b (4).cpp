#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

short int i, total = 0, tTotal = 0, rTotal = 0;

class cFigure {
protected:
	string color;
public:
	cFigure() {
		color = "N/A";
	}
	virtual void setData() = 0;
	virtual void getData() = 0;
	virtual bool type() = 0;
	virtual double getPerimeter() = 0;
	string getColor();
};
string cFigure::getColor() {
	return color;
}

class cTriangle : public cFigure {
private:
	float sides[3];
public:
	cTriangle() {
		for (int i = 0; i < 3; i++) sides[i] = 0.0;
	}
	void setData();
	void getData();
	bool type();
	double getPerimeter();
};
void cTriangle::setData() {
	cout << "\nВъведи цвят: "; getline(cin, color);
	cout << "Въведи страни:\n";
	cout << "a = "; cin >> sides[0];
	cout << "b = "; cin >> sides[1];
	cout << "c = "; cin >> sides[2];
	cin.ignore();
}
void cTriangle::getData() {
	cout << "\n--\nЦвят: "; cout << color;
	cout << "\nСтрани:\n" <<
		"\na: " << sides[0] <<
		"\nb: " << sides[1] <<
		"\nc: " << sides[2] <<
	"\n--\n\n";

}
bool cTriangle::type() {
	return true;
}
double cTriangle::getPerimeter() {
	return sides[0] + sides[1] + sides[2];
}

class cRectangle : public cFigure {
private:
	float sides[4];
public:
	cRectangle() {
		for (int i = 0; i < 4; i++) sides[i] = 0.0;
	}
	void setData();
	void getData();
	bool type();
	double getPerimeter();
};
void cRectangle::setData() {
	cout << "\nВъведи цвят: "; getline(cin, color);
	cout << "Въведи страни:\n";
	cout << "a = "; cin >> sides[0];
	cout << "b = "; cin >> sides[1];
	cout << "c = "; cin >> sides[2];
	cout << "d = "; cin >> sides[3];
}
void cRectangle::getData() {
	cout << "\n--\nЦвят: "; cout << color;
	cout << "\nСтрани:\n" <<
		"\na: " << sides[0] <<
		"\nb: " << sides[1] <<
		"\nc: " << sides[2] <<
		"\nd: " << sides[3] <<
	"\n--\n\n";
}
bool cRectangle::type() {
	return false;
}
double cRectangle::getPerimeter() {
	return sides[0] + sides[1] + sides[2] + sides[3];
}


cFigure* Figures[30];
cTriangle Triangles[30];
cRectangle Rectangles[30];

int main() {
	short int choice;
	system("chcp 1251");
	system("cls");

Menu:
	cout << "\n------------------------------------------------------------";
	cout << "\n\t\t\t  М Е Н Ю";
	cout << "\n------------------------------------------------------------";
	cout << "\n1. Добави фигура\t\t\t\tФИГУРИ: " << total << "/30";
	cout << "\n2. Изведи данните за всички фигури в БД";
	cout << "\n3. Изведи сумата от периметрите на вс. фигури в БД";
	cout << "\n4. Изведи списък с цветовете на вс. правоъгълници в БД | "; cin >> choice; cin.ignore();

	switch (choice) {
	case 1: {
	AddFigure:
		short int c;
		cout << "\n1. Триъгълник" << "\n2. Правоъгълник | "; cin >> c;

		switch (c) {
		case 1: {
			short int current;
			cout << "\nКолко триъгълници бихте искали да добавите? | "; cin >> current; cin.ignore();
			for (i = total; i < current + total; i++) {
				Figures[i] = &Triangles[tTotal++];
				Figures[i]->setData();
			}
			total += current;
			cout << endl << current << " триъгълник(а) беше/бяха успешно добавен(и).\n\n";
			goto Menu;
			break;
		}
		case 2: {
			short int current;
			cout << "\nКолко правоъгълници бихте искали да добавите? | "; cin >> current; cin.ignore();
			for (i = total; i < current + total; i++) {
				Figures[i] = &Rectangles[rTotal++];
				Figures[i]->setData();
			}
			total += current;
			cout << endl << current << " правоъгълник(а) беше/бяха успешно добавен(и).\n\n";
			goto Menu;
			break;
		}
		default: {
			cout << "\nНевалиден избор! Моля, опитайте отново.\n";
			goto AddFigure; break;
		}
		}
		goto Menu;
		break;
	}
	case 2: {
		if (total > 0) {
			cout << "\nОбщ брой фигури в базата данни: " << total << endl << endl;
			if (tTotal != 0) {
				cout << "\n\nТриъгълници (" << tTotal << "):\n";
				for (i = 0; i < total; i++) {
					if (Figures[i]->type() == true)
						Figures[i]->getData();
				}
			}
			if (rTotal != 0) {
				cout << "\n\nПравоъгълници (" << rTotal << "):\n";
				for (i = 0; i < total; i++) {
					if (Figures[i]->type() == false)
						Figures[i]->getData();
				}
			}
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете фигури.\n";
			goto Menu; break;
		}
	}
	case 3: {
		if (total > 0) {
			double sum = 0;
			cout << "\nСума от периметрите на всички фигури = ";
			for (i = 0; i < total; i++) 
				sum += Figures[i]->getPerimeter();
			cout << sum << endl;
			goto Menu;
			break;
		}
		else {
			cout << "\nБазата данни е празна! Моля, първо добавете фигури.\n";
			goto Menu; break;
		}
	}
	case 4: {
		if (rTotal > 0) {
			for (i = 0; i < total; i++) {
				if (Figures[i]->type() == false) {
					cout << "\nЦвят на правоъгълник " << i << ": " << 
						Figures[i]->getColor();
				}
			}
			goto Menu;
			break;
		}
		else {
			cout << "\nНяма правоъгълници в БД! Моля, първо добавете правоъгълник.\n";
			goto Menu; break;
		}
	}
	
	default: {
		cout << "\nНевалиден избор! Моля, опитайте отново.\n";
		goto Menu; break;
	}
	}
}