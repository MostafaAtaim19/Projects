// Bank Mangement System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class bank {
	char name[100], father[100], addr[100], type[10];
	float balance;
public:
	void open_account();
	void deposit_money();
	void withdraw_money();
	void dispaly_account();
};
void bank::open_account() {
	cout << "\nEnter your name" << endl;
	cin.ignore();
	cin.getline(name,100);
	cout << "\nEnter your father Name " << endl;
	cin.ignore();
	cin.getline(father, 100);
	cout << "\nEnter your address" << endl;
	cin.ignore();
	cin.getline(addr, 100);
	cout << "\nType of account you want to open saving(s) or current(c)" << endl;
	cin.ignore();
	cin.getline(type, 100);
	cout << "\nEnter your first deposit amount" << endl;
	cin >> balance;

	cout << "\nyour account is created successfully" << endl;

}

void bank::deposit_money() {
	int d;
	cout << "\nEnter amount you want to deposit" << endl;
	cin >> d;
	balance = balance + d;
	cout << "\nYour current/Total balance is" << balance << endl;
}
void bank::withdraw_money() {

	float c;
	cout << "\nEnter The amount you want to Withdraw" << endl;
	cin >> c;
	balance = balance - c;
	cout << "\nYour remaining balance is" << balance << endl;
}

void bank::dispaly_account() {
	cout << "\nYour Name is" <<name<< endl;
	cout << "\nYour father name is" <<father<<endl;
	cout << "\nYour address" <<addr<<endl;
	cout << "\nYour account type is"<<type<< endl;
	cout << "\ncurrent/Total balance is" << balance << endl;
}









int main() {

	bank obj;
	int ch;
	cout << "\n-----------------------------------------------------------------------------" << endl;
	cout << "\n------------------------------Maka Bank Welcomes you-------------------------" << endl;
	cout << "\n-----------------------------------------------------------------------------" << endl;


	cout << "\n1.) Open account" << endl;
	cout << "\n2.) Deposit Money" << endl;
	cout << "\n3.) Withdraw Money" << endl;
	cout << "\n4.) Display account" << endl;
	cout << "\n5.) Exit" << endl;
	return 0;

	switch (ch) {

	case 1:
		cout << "\n1.) Open account" << endl;
		obj.open_account();
		break;
	case 2:
		cout << "\n2.) Deposit Money" << endl;
		obj.deposit_money();
		break;
	case 3:
		cout << "\n3.) Withdraw Money" << endl;
		obj.withdraw_money();
		break;
	case 4:
		cout << "\n4.) Display account" << endl;
		obj.dispaly_account();













	}





}
