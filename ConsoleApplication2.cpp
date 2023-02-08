#include <iostream>
#include <string>
#include <fstream>
#include<iomanip> 
#include<algorithm>
#include<windows.h>
using namespace std;
int flag2 = 0;
int count2 = 1;
int incre = 0;
int decre = 0;
int num_of_vip = 0;
int num_of_normal = 0;
void openacc();
void save_into_file(string id, string phn, string accnum, string name, string type);

struct csutomer {
	string id;
	string phn;
	string accnum;
	string name;
	string type;
};

struct node {
	csutomer info;
	node* next;
};


node* current = NULL;
node* Rear = NULL;
node* Front = NULL;

node* c1;
node* current2 = NULL;
node* Rear2;
node* Front2 = NULL;


node* current3 = NULL;
node* Rear3 = NULL;
node* Front3 = NULL;


node* current4 = NULL;
node* Rear4 = NULL;
node* Front4 = NULL;


node* current5 = NULL;
node* Rear5 = NULL;
node* Front5 = NULL;

node* current6 = NULL;
node* Rear6 = NULL;
node* Front6 = NULL;



void enqueue1(string id, string phn, string accnum, string name, string type);
void enqueue2(string id, string phn, string accnum, string name, string type);
void enqueue3(string id, string phn, string accnum, string name, string type);
void enqueue4(string id, string phn, string accnum, string name, string type);
void enqueue5(string id, string phn, string accnum, string name, string type);
void enqueue6(string id, string phn, string accnum, string name, string type);
void dequeue();
void display();
void display2();
void display3();
void display4();
void display5();
void print_vip();
void print_All_cus();
void search_in_current_queue();
void menu();
void Update();
void func(int data);








int main() {
	menu();
}
void menu() {
	int cho;
	do {
		cout << "\t\t\t****MENU****" << endl;
		cout << "1- Enqueue " << endl;
		cout << "\n";
		cout << "2- Dequeue " << endl;
		cout << "\n";
		cout << "3- Print All Clients  " << endl;
		cout << "\n";
		cout << "4- Print VIP Clients  " << endl;
		cout << "\n";
		cout << "5- Search  " << endl;
		cout << "\n";
		cout << "6- update the system  " << endl;
		cout << "\n";
		cout << "7- Exit " << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Enter your option:" << endl;
		cin >> cho;
		cout << "---------------------------------------------" << endl;
		switch (cho)
		{
		case 1:
			int count;
			cout << "Enter Number of customers to be enqueue:" << endl;
			cin >> count;
			count2 = count;
			system("CLS");
			for (int i = 1; i <= count; i++) {
				cout << "---------------------------------------------" << endl;
				cout << "Customer Number:" << i << endl;
				cout << "---------------------------------------------" << endl;
				openacc();
				system("CLS");
			}
			break;
		case 2:
			for (int i = 1; i <= count2; i++) {

				dequeue();
			}
			system("CLS");
			break;
		case 3:
			print_All_cus();

			break;

		case 4:
			print_vip();

			break;
		case 5:
			search_in_current_queue();

			break;
		case 6:
			Update();
			break;


		case 7:


			break;









		}

	} while (cho != 6);
}

void openacc() {
	string id, phn, accnum;
	string name, type;
	cout << "Enter The Name of The account Holder : ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < name.length(); i++) {
		if (isdigit(name[i]) || name == ".")
		{

			cout << "\nPlease enter valid name,containing letters only " << "\n" << endl;
			cout << "Name of The account Holder:" << "\n";
			cin.ignore();
			getline(cin, name);

		}
	}



	cout << "\nEnter Type of The account vip or not : ";
	cin >> type;


	for (int i = 0; i <= type.length(); i++) {
		if (isdigit(type[i]) || (type != "vip" && type != "not"))

		{

			cout << "\nPlease enter valid name,containing letters only " << "\n" << endl;
			cout << "Type " << "\n";
			cin >> type;

		}

	}
	cout << "\nEnter The Customer NUmber :";
	cin >> accnum;
	for (int i = 0; i <= accnum.length(); i++) {
		if (isalpha(accnum[i]))
		{
			`


				cout << "\nPlease enter valid number" << "\n" << endl;
			cout << "Number:" << "\n";
			cin >> accnum;

		}
	}

	cout << "\nEnter id: ";
	cin >> id;
	for (int i = 0; i <= id.length(); i++) {
		if (isalpha(id[i]))
		{

			cout << "\nPlease enter valid id,not contain letters " << "\n" << endl;
			cout << "id" << "\n";
			cin >> id;

		}
	}
	cout << "\nEnter phone number: ";
	cin >> phn;
	for (int i = 0; i <= phn.length(); i++) {
		if (isalpha(phn[i]))
		{

			cout << "\nPlease enter valid phone number,not contain letters " << "\n" << endl;
			cout << "phone number:" << "\n";
			cin >> phn;

		}
	}
	if (phn.length() > 11 || phn.length() < 11) {
		cout << "\nPlease enter valid phone number,11 digit only " << "\n" << endl;
		cout << "Phone number:" << "\n";
		cin >> phn;


	}

	cout << "\n\n\nAccount Created.." << "\n";


	save_into_file(id, phn, accnum, name, type);

	enqueue1(id, phn, accnum, name, type);
}
void save_into_file(string id, string phn, string accnum, string name, string type) {

	fstream file1;
	file1.open("customersdata.txt", ios::app);
	if (file1.is_open()) {
		file1 << "\n" << "id:" << id << "\n";
		file1 << "phone number:" << phn << "\n";
		file1 << "account Number:" << accnum << "\n";
		file1 << "Name of The account Holder:" << name << "\n";
		file1 << "vip or not : " << type << "\n";
		file1 << "..............................................." << "\n";
		file1.close();

	}



}

void enqueue1(string id, string phn, string accnum, string name, string type) {
	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear != NULL)
	{
		Rear->next = customer;
		Rear = customer;
	}
	else
	{
		Front = customer;
		Rear = customer;
	}
	Rear->next = NULL;
	incre++;
}

void dequeue() {

	if (Front != NULL)
	{
		current = Front;
		string id, phn, accnum;
		string name, type;
		int c;
		id = current->info.id;
		phn = current->info.phn;
		name = current->info.name;
		accnum = current->info.accnum;
		type = current->info.type;
		cout << "Hello:" << "\t" << current->info.name << "\n";
		cout << "\n" << "Enter Your Choice, for Customer Services(1) or (2) for teller" << "\n";
		cin >> c;
		if (c != 1 && c != 2) {

			cout << "Please enter number between 1 or 2" << endl;
			cin >> c;
		}
		if (c == 1) {
			if (current->info.type == "vip") {
				enqueue2(id, phn, accnum, name, type);
				enqueue6(id, phn, accnum, name, type);
			}
			else {

				enqueue4(id, phn, accnum, name, type);
				enqueue6(id, phn, accnum, name, type);
			}
		}
		else if (c == 2) {
			if (current->info.type == "vip") {
				enqueue3(id, phn, accnum, name, type);
				enqueue6(id, phn, accnum, name, type);
			}
			else {
				enqueue5(id, phn, accnum, name, type);
				enqueue6(id, phn, accnum, name, type);
			}
		}

		Front = Front->next;
		delete current;
	}
	else
	{
		cout << "No element Found to be dequeued" << endl;
	}
	decre++;
}
void enqueue2(string id, string phn, string accnum, string name, string type) {
	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear2 != NULL)
	{
		Rear2->next = customer;
		Rear2 = customer;
	}
	else
	{
		Front2 = customer;
		Rear2 = customer;
	}
	num_of_vip++;


}

void enqueue3(string id, string phn, string accnum, string name, string type) {

	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear3 != NULL)
	{
		Rear3->next = customer;
		Rear3 = customer;
	}
	else
	{
		Front3 = customer;
		Rear3 = customer;
	}
	Rear3->next = NULL;
	num_of_vip++;
}


void enqueue4(string id, string phn, string accnum, string name, string type) {
	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear4 != NULL)
	{
		Rear4->next = customer;
		Rear4 = customer;
	}
	else
	{
		Front4 = customer;
		Rear4 = customer;
	}

	num_of_normal++;

}
void enqueue5(string id, string phn, string accnum, string name, string type) {
	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear5 != NULL)
	{
		Rear5->next = customer;
		Rear5 = customer;
	}
	else
	{
		Front5 = customer;
		Rear5 = customer;
	}
	Rear5->next = NULL;
	num_of_normal++;

}
void enqueue6(string id, string phn, string accnum, string name, string type) {

	node* customer = new node();
	customer->info.id = id;
	customer->info.phn = phn;
	customer->info.accnum = accnum;
	customer->info.name = name;
	customer->info.type = type;
	if (Rear6 != NULL)
	{
		Rear6->next = customer;
		Rear6 = customer;
	}
	else
	{
		Front6 = customer;
		Rear6 = customer;
	}
	Rear6->next = NULL;






}
void display()
{
	if (Front != NULL)
	{
		current = Front;
		while (current != NULL)
		{
			cout << "id:" << current->info.id << "\n";
			cout << "\n";
			cout << "phone NUmber:" << current->info.phn << "\n";
			cout << "\n";
			cout << "Name:" << current->info.name << "\n";
			cout << "\n";
			cout << "Account Number :" << current->info.accnum << "\n";
			cout << "\n";
			cout << "Type:" << current->info.type << "\n";
			current = current->next;
		}
		cout << "\n";
	}
	else { cout << "There is no data in the queue\n"; }

}
void display2()
{
	if (Front2 != NULL)
	{
		current2 = Front2;
		while (current2 != NULL)
		{
			cout << "id:" << current2->info.id << "\n";
			cout << "\n";
			cout << "phone NUmber:" << current2->info.phn << "\n";
			cout << "\n";
			cout << "Name:" << current2->info.name << "\n";
			cout << "\n";
			cout << "Account Number :" << current2->info.accnum << "\n";
			cout << "\n";
			cout << "Type:" << current2->info.type << "\n";
			current2 = current2->next;
		}
		cout << "\n";
	}
	else { cout << "There is no data in the queue\n"; }

}
void display3() {
	if (Front3 != NULL)
	{
		current3 = Front3;
		while (current3 != NULL)
		{
			cout << "id:" << current3->info.id << "\n";
			cout << "\n";
			cout << "phone NUmber:" << current3->info.phn << "\n";
			cout << "\n";
			cout << "Name:" << current3->info.name << "\n";
			cout << "\n";
			cout << "Account Number :" << current3->info.accnum << "\n";
			cout << "\n";
			cout << "Type:" << current3->info.type << "\n";
			current3 = current3->next;
		}
		cout << "\n";
	}
	else { cout << "There is no data in the queue\n"; }

}


void display4()
{
	if (Front4 != NULL)
	{
		current4 = Front4;
		while (current4 != NULL)
		{
			cout << "id:" << current4->info.id << "\n";
			cout << "\n";
			cout << "phone NUmber:" << current4->info.phn << "\n";
			cout << "\n";
			cout << "Name:" << current4->info.name << "\n";
			cout << "\n";
			cout << "Account Number :" << current4->info.accnum << "\n";
			cout << "\n";
			cout << "Type:" << current4->info.type << "\n";
			current4 = current4->next;
		}
		cout << "\n";
	}
	else { cout << "There is no data in the queue\n"; }

}
void display5()
{
	if (Front5 != NULL)
	{
		current5 = Front5;
		while (current5 != NULL)
		{
			cout << "id:" << current5->info.id << "\n";
			cout << "\n";
			cout << "phone NUmber:" << current5->info.phn << "\n";
			cout << "\n";
			cout << "Name:" << current5->info.name << "\n";
			cout << "\n";
			cout << "Account Number :" << current5->info.accnum << "\n";
			cout << "\n";
			cout << "Type:" << current5->info.type << "\n";
			current5 = current5->next;
		}
		cout << "\n";
	}
	else { cout << "There is no data in the queue\n"; }

}
void print_vip() {


	cout << "\n";
	display2();
	cout << "\n";
	display3();
	cout << "\n";
	Sleep(15000);
	system("CLS");
}


void print_All_cus() {
	cout << "All clints Enterd The Customer Services Dapartment";
	cout << "\n";
	display2();
	cout << "\n";
	display4();
	cout << "\n";
	cout << "All clints Enterd The Teller Dapartment";
	cout << "\n";
	display3();
	cout << "\n";
	display5();
	cout << "\n";
	Sleep(15000);
	system("CLS");
}

void search_in_current_queue() {
	string x;
	int flag = 0;
	string y;
	cout << "Enter Id:";
	cin >> x;
	c1 = Front6;

	while (flag != 1) {

		for (int i = 0; i <= count2; i++) {
			if (i == count2) {
				flag += 1;
				break;
			}
			if (c1->info.id == x) {
				cout << "we are found the data about:" << c1->info.name << "\t" << "With id:" << c1->info.id << endl;
				flag += 1;
				y = "found";
				break;

			}
			else {
				c1 = c1->next;

			}

		}

	}
	if (y == "found") { return; }
	else { func(flag2); }
	Sleep(15000);
	system("CLS");
}
void func(int data) {
	if (flag2 == 0) {
		cout << "No data found about this id" << endl;
	}
}



void Update() {

	cout << "Numeber of customers entered the Bank:" << incre << endl;
	cout << "\n";
	cout << "Numeber of vip customers entered the Bank:" << num_of_vip << endl;
	cout << "\n";
	cout << "Numeber of normal customers entered the Bank:" << num_of_normal << endl;
	cout << "\n";
	cout << "Numeber of customers they were distributed to the windows:" << decre << endl;



	Sleep(15000);
	system("CLS");

}