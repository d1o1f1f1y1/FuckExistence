#include <iostream>

using namespace std;

struct dishesWithNuts // Створюємо структуру
{
	int valueOfNuts;
	int numberOfDish;
	bool isEmpty;
	bool selected;
};

void func(); // Створюємо прототип функції

void main() {


	setlocale(0, "");
	func();


};

void func() { // Створюємо функцію
	int valueOfDishes, nuts;


	cout << "Enter number of plates : "; 
	cin >> valueOfDishes;



	if (valueOfDishes <= 0) {
		cout << "Your number must be positive!" << endl;
	}
	else {
		dishesWithNuts* newYearParty = new dishesWithNuts[valueOfDishes];

		for (int i = 0; i < valueOfDishes; i++) {
			newYearParty[i].numberOfDish = i + 1;

			int b = -1;
			while (b < 0) {
				cout << "Enter how many nuts are in the plate №" << newYearParty[i].numberOfDish << "  : ";
				cin >> newYearParty[i].valueOfNuts;
				b = newYearParty[i].valueOfNuts;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					b = -1;
				}
			}

			if (newYearParty[i].valueOfNuts > 0) {
				newYearParty[i].isEmpty = false;
			}
			else {
				newYearParty[i].isEmpty = true;
			}
			newYearParty[i].selected = false;
		}
		int num;

		int  petrikTime = 0;
		bool dishesAreEmpty = false;

		while (!dishesAreEmpty) {
			int selectedCounter = 0;
			int minNuts = 9999999999999999;
			int counterOfEmptyDishes = 0;

			cout << endl;
			for (int i = 0; i < valueOfDishes; i++) {
				cout << "In a plate №" << newYearParty[i].numberOfDish << " - " << newYearParty[i].valueOfNuts << " nuts. " << endl;
			}

			cout << endl << "Enter (1) if you want to choose a plate and (0) if you don't. Plates with nuts: " << endl;

			for (int i = 0; i < valueOfDishes; i++) {
				if (newYearParty[i].isEmpty == false) {
					cout << "Plate №" << newYearParty[i].numberOfDish << " : ";
					cin >> num;
					if (num == 1) {
						newYearParty[i].selected = true;
						cout << "Plate №" << newYearParty[i].numberOfDish << " selected" << endl;
						selectedCounter++;
					}
					else {
						cout << "Plate №" << newYearParty[i].numberOfDish << " not selected" << endl;
					}
				}
			}

			if (selectedCounter == 0) {
				continue;
			}

			for (int i = 0; i < valueOfDishes; i++) {
				if (newYearParty[i].selected == true) {
					if (newYearParty[i].isEmpty == false) {
						if (minNuts > newYearParty[i].valueOfNuts) {
							minNuts = newYearParty[i].valueOfNuts;
						}
					}
				}
			}


			cout << endl << "(" << minNuts << ") is the maximum amount of nuts Petrik can take." << endl;
			cout << "How many nuts will Petrik take from each plate in a minute: ";
			cin >> nuts;

			if (nuts > minNuts) {
				cout << endl << "Exceeded nuts limit!" << endl;
			}
			else {
				for (int i = 0; i < valueOfDishes; i++) {
					if (newYearParty[i].selected == true) {
						if (newYearParty[i].isEmpty == false) {
							newYearParty[i].valueOfNuts -= nuts;
						}
					}
				}
				petrikTime++;
			}

			for (int i = 0; i < valueOfDishes; i++) {
				if (newYearParty[i].valueOfNuts == 0) {
					newYearParty[i].isEmpty = true;
					counterOfEmptyDishes++;
				}
				newYearParty[i].selected = false;
			}

			if (counterOfEmptyDishes == valueOfDishes) {
				dishesAreEmpty = true;
			}
		}

		cout << endl << "Minimum time : " << petrikTime << " min." << endl;



	}

}