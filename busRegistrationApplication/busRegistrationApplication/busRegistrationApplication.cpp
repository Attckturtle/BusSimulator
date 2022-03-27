#include <iostream>

bool firstRide = true;
std::string lastLocation = "sentosa";
int chosenOption;

void showOptions();
void processChosenOption();
void goingToSentosa();
void goingToBukit();
void goingToTiong();
void ticketPriceCalculator(int a);

class BusMaker {
public:
	std::string company = "A&S Transit";
	std::string model = "SMB354P";
	int amountOfSeats = 40;
	int freeSeats = 40;
	int ticketCost = 5;
	bool inService = true;
};

BusMaker Bus1;
BusMaker Bus2;
BusMaker Bus3;

int main() {
	showOptions();
	return 0;
}

void showOptions() {
	std::cout << "Where would you like to go?\n";
	std::cout << "1. Sentosa\n";
	std::cout << "2. Bukit Timah\n";
	std::cout << "3. Tiong Bahru\n";
	std::cin >> chosenOption;
	processChosenOption();
}

void processChosenOption() {
	switch (chosenOption) {
	case 1:
		goingToSentosa();
		break;
	case 2:
		goingToBukit();
		break;
	case 3:
		goingToTiong();
	}
}

void goingToSentosa() {
	int a;
	a = rand() % 1000 + 1;
	if (a == 1) {
		Bus1.inService = false;
	}
	
	int b;
	b = rand() % 40 + 1;
	Bus1.freeSeats -= b;

	if (Bus1.freeSeats != 0 && Bus1.inService) {
		lastLocation = "Sentosa\n";
		std::cout << "You rode the bus\n";
		showOptions();
	}
	else {
		std::cout << "The bus is either full or broken\n";
		showOptions();
	}
}

void goingToBukit() {
	int a;
	a = rand() % 1000 + 1;
	if (a == 1) {
		Bus2.inService = false;
	}
	if (Bus2.inService) {
		lastLocation = "Bukit Timah\n";
	}
}

void goingToTiong() {
	int a;
	a = rand() % 1000 + 1;
	if (a == 1) {
		Bus3.inService = false;
	}
	if (Bus3.inService) {
		lastLocation = "Tiong Bahru\n";
	}
}

void ticketPriceCalculator(int a) {
	std::string placeLocation;
	
	switch (a) {
	case 1:
		placeLocation = "Sentosa\n";
		break;
	case 2:
		placeLocation = "Bukit Timah\n";
		break;
	case 3: 
		placeLocation = "Tiong Bahru\n";
	}

	if (lastLocation == placeLocation){
		std::cout << "You have to actually go somewhere\n";
	}
	else {
		std::cout << "Tickets are $5\n";
	}
}
