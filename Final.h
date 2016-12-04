//
//  main.h
//  ATM
//
#ifndef main_h
#define main_h

#include <vector>
using namespace std;

class ATM {
private:
	//need to initialize allCustomers
	vector<Customer> allCustomers;
	Person currentCustomer;
	int findCustomer(int cardNumber){
		//iterates through allCustomers comparing cardNumbers until it finds a match
		for (int i = 0; i < allCustomers.size(); i++) {
			if (allCustomers[i].compareCardNumber(cardNumber)){
				return i;
			}
		}

		//returns -1 if no match is found
		return -1;
	}

public:
	bool addNewCustomer();

	//finish method below
	bool setCurrentCustomer(int cardNumber){
		//makes sure cardNumber is that of valid Customer
		x = findCustomer(cardNumber);
		if (x < 0) {
			return false;
		}

		int PIN;

		//Gaurd for entering a PIN
    int counter;
    int attempts;
    attempts = 3;
    while(counter < 1 ){
      cout << "Please enter your PIN"
      cin >> PIN;
    // checks that user input is an integer
      while(std::cin.fail()) {
              cout << "Error, please input a valid pin number" << std::endl;
              cin.clear();
              cin.ignore(256,'\n');
              cin >> PIN;
          }
      // Checks for correct PIN number
        if(comparePIN(PIN)){
          counter++;
        } else{
          // decrements one attempt and asks user to try again
               if(attempts == 0){
                 //If PIN number is false and user ran out of tries program is exited
               cout << "You have ran out of tries, please login again"
               exit(0);
                }
          attempts--;
          cout << "Incorret input, please input your PIN. You have " << attempts << " attempts remaining" << endl;
        }
      }
      attempts = 3;
		//add possible loops for missed trys
		//checks that user knows PIN for cardNumber
		if (allCustomers[x].comparePIN(PIN)){
			currentCustomer = allCustomers[x];
			return true;
		}

		return false;
	}

	Customer getCustomer(int cardNumber){
		x = findCustomer(cardNumber);

		//if x is within the size of allCustomers returns the customer at that location
		if (x > -1) {
			return allCustomers[x];
		}

		//otherwise returns nullptr reference (NULL)
		return nullptr;
	}

};



class Customer {

private:
	string name;
	string address;
	string DOB;
	int cardNumber;
	int PIN;
	int balance;

public:
	Customer(string name, string address, string DOB, int cardNumber, double startingBalance, int PIN) {
		this->name = name;
		this->address = address;
		this->DOB = DOB;
		this->cardNumber = cardNumber;
		this->balance = (int)(startingBalance * 100);
		this->PIN = PIN;
	}

	bool changePIN() {
		int enteredPIN = -1;

		while (enteredPIN != 0) {
        int i;
        while(i<0){

			cout << "Enter your current PIN (enter 0 to cancel): ";
			cin >> enteredPIN;
      while(std::cin.fail()) {
              cout << "Error, please input a valid pin number" << std::endl;
              cin.clear();
              cin.ignore(256,'\n');
              cin >> enteredPIN;
          }
			if (comparePIN(enteredPIN)) {

				//cin needs a guard against invalid input

				//accepts 2 user inputed PIN's to make sure new PIN is desired PIN
				cout << "Please enter new PIN: ";
				cin >> enteredPIN;
        while(std::cin.fail()) {
                cout << "Error, please input a number" << std::endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> enteredPIN;
            }
				int newPIN;
				cout << "Please re-enter new PIN: ";
				cin >> newPIN;
        while(std::cin.fail()) {
                cout << "Error, please input a number" << std::endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> newPIN;
            }
				//if 2 entered PIN's are same, set new PIN
				if (newPIN == enteredPIN) {
					this->PIN = newPIN;
					return true;
          i++
				}

				//possibly add a loop
				else {
					cout << "Entered PINS do not match. Please try again";

				}
			}


		}

  }

	}

	bool comparePIN(int PIN) {
		if (this->PIN = PIN) {
			return true;
		}
		return false;
	}

	bool compareCardNumber(int cardNumber) {
		if (this->cardNumber = cardNumber) {
			return true;
		}
		return false;
	}

	bool makeDeposit(double x) {
		this->balance += (int)(x * 100);
		return true;
	}

	bool makeWithdrawal(double x) {
		int withdrawalAmount = (int)(x * 100);
		//checks to make sure user has sufficient funds to make a withdrawal
		if (this->balance >= withdrawalAmount) {
			balance -= withdrawalAmount;
			return true;
		}

		cout << "Insufficient funds." << endl;
		return false;
	}

	double getBalance() {
		cout << "Your current balance is: " << ((double) this->balance) / 100 << endl;
		return this->balance;
	}

	bool transfer(int cardNumber, double x, ATM atm){

		Customer transferTo = atm.getCustomer(cardNumber);

		//attempts to make withdrawal, if there are sufficient funds, makes deposit in other account, returns true
		if (makeWithdrawal(x) && transferTo != nullptr){
			transferTo.makeDeposit(x);
			return true;
		}

		//customer is unable to transfer the funds, returns false
		cout << "Unable to transfer funds." << endl;
		return false;
	}
};

#endif /* main_h */
