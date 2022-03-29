#include <iostream>

bool firstRide = true;

class BusMaker {
public:
	std::string company = "A&S Transit";
	std::string model = "SMB354P";
	int amountOfSeats = 40;
	int freeSeats = 40;
	int ticketCost = 5;
	bool inService = true;
};

class walletMaker {
public:
	int depositedAmount = 500;
	std::string lastLocation = "Sentosa";
};

BusMaker Bus1;
BusMaker Bus2;
BusMaker Bus3;

walletMaker accountWallet;

void showOptions();
void goingToSentosa();
void goingToBukit();
void goingToTiong();
bool ticketPriceCalculator(int a);

void showOptions() {
	int chosenOption;
	std::cout << "Where would you like to go?\n";
	std::cout << "1. Sentosa\n";
	std::cout << "2. Bukit Timah\n";
	std::cout << "3. Tiong Bahru\n";
	std::cin >> chosenOption;
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
	bool samePlace = ticketPriceCalculator(1);
	if (samePlace) {
		int a;
		a = rand() % 1000 + 1;
		if (a == 1) {
			Bus1.inService = false;
		}
		int b;
		if (Bus1.freeSeats != 0 && Bus1.inService) {
			accountWallet.lastLocation = "Sentosa\n";
			std::cout << "You rode the bus\n";
			showOptions();
		}
		else {
			std::cout << "The bus is either full or broken\n";
			showOptions();
		}
		b = rand() % 40 + 1;
		Bus1.freeSeats -= b;
	}
	else {
		showOptions();
	}
}

void goingToBukit() {
	bool samePlace = ticketPriceCalculator(2);
	if (samePlace) {
		int a;
		a = rand() % 1000 + 1;
		if (a == 1) {
			Bus2.inService = false;
		}
		if (Bus2.inService) {
			accountWallet.lastLocation = "Bukit Timah";
		}

		if (Bus2.freeSeats != 0 && Bus2.inService) {
			accountWallet.lastLocation = "Bukit Timah";
			std::cout << "You rode the bus\n";
			showOptions();
		}
		else {
			std::cout << "The bus is either full or broken\n";
			showOptions();
		}
	}
	else {
		showOptions();
	}
}

void goingToTiong() {
	bool samePlace = ticketPriceCalculator(3);
	if (samePlace) {
		int a;
		a = rand() % 1000 + 1;
		if (a == 1) {
			Bus3.inService = false;
		}
		if (Bus3.inService) {
			accountWallet.lastLocation = "Tiong Bahru\n";
		}

		if (Bus3.freeSeats != 0 && Bus3.inService) {
			accountWallet.lastLocation = "Tiong Bahru";
			std::cout << "You rode the bus\n";
			showOptions();
		}
		else {
			std::cout << "The bus is either full or broken\n";
			showOptions();
		}
	}
	else {
		showOptions();
	}
}

bool ticketPriceCalculator(int a) {
	std::string placeLocation;
	
	switch (a) {
	case 1:
		placeLocation = "Sentosa";
		break;
	case 2:
		placeLocation = "Bukit Timah";
		break;
	case 3: 
		placeLocation = "Tiong Bahru";
	}

	if (accountWallet.lastLocation == placeLocation){
		std::cout << "You have to actually go somewhere\n";
		return false;
	}
	else {
		std::cout << "Tickets are $5\n";
		accountWallet.depositedAmount -= 5;
		std::cout << accountWallet.depositedAmount << " dollars left in your wallet.";
		return true;
	}
}

int main() {
	showOptions();
	return 0;
}