#include <iostream>
#include <string>
#include <chrono>
#include <ctime> 
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main();
void add();
void search();
void view(int);
void viewDel();
void viewAll();
void edit();
void sort();
void remove();
void dashboard();
void login();




struct Tutor {
	struct Tutor* previous;
	int TutorID;
	string Name;
	string DateJoined;
	string DateTerminated;
	double HourlyPay;
	string Phone;
	string Address;
	int TCCode;
	string TCName;
	int SubjectCode;
	string SubjectName;
	int Rating;
	struct Tutor* next;

}*list, *newnode, *current, *previous, *last, *temp;

void CreateList() {
	list = NULL;
}

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);


	return buf;
}
void remove(){}
void search(){
	newnode = list;
	string opt;
	string Rate;
	int TutorId, find = 0;
	system("CLS");
	cout << "1. Search Tutor by ID" << endl << "2. Search Tutor by Rating" << endl;
	cout << "Enter your option (Ex : 1): ";
	cin >> opt;
	if (opt == "1") {
		cout << "Search Tutor by ID" << endl;
		cout << "Enter Tutor Id: ";
		cin >> TutorId;
		while (list != NULL){
			if (list->TutorID=TutorId){
				system("CLS");
				/*cout << "\n\n-----" << temp1 << order[temp2] << " tutor-----" << endl;*/
				cout << "Tutor ID: " << list->TutorID << endl;
				cout << "Tutor name: " << list->Name << endl;
				cout << "Tutor date joined: " << list->DateJoined << endl;
				cout << "Tutor date terminated: " << list->DateTerminated << endl;
				cout << "Hourly pay: RM" << list->HourlyPay << endl;
				cout << "Tutor phone: " << list->Phone << endl;
				cout << "Tutor address: " << list->Address << endl;
				cout << "TC code: " << list->TCCode << endl;
				cout << "TC name: " << list->TCName << endl;
				cout << "Tutor subject code: " << list->SubjectCode << endl;
				cout << "Tutor subject name: " << list->SubjectName << endl;
				cout << "Tutor rating: " << list->Rating << endl;

				system("PAUSE");
				dashboard();
			}
			else {
				cout << "Tutor ID not EXist" << endl << endl;
			2
			}
			list = list->next;
		}
	}


	
	else if (opt == "2") {
		cout << "Search Tutor by Rating" << endl;
		cout << "Enter Tutor Rating: ";
		cin >> Rate;
	}
	else {
		cout << "Sorry wrong input" << endl;
		system("PAUSE"); search();
	}
}

void view(){
	system("CLS");
	/*cout << "\n\n-----" << temp1 << order[temp2] << " tutor-----" << endl;*/
	cout << "Tutor ID: " <<list->TutorID << endl;
	cout << "Tutor name: " << list->Name << endl;
	cout << "Tutor date joined: " << list->DateJoined << endl;
	cout << "Tutor date terminated: " << list->DateTerminated << endl;
	cout << "Hourly pay: RM" << list->HourlyPay << endl;
	cout << "Tutor phone: " << list->Phone << endl;
	cout << "Tutor address: " << list->Address << endl;
	cout << "TC code: " << list->TCCode << endl;
	cout << "TC name: " << list->TCName << endl;
	cout << "Tutor subject code: " << list->SubjectCode << endl;
	cout << "Tutor subject name: " << list->SubjectName << endl;
	cout << "Tutor rating: " << list->Rating << endl;

	system("PAUSE");
	dashboard();

}
void viewAll(){
	newnode = list;
	while (list != NULL) {
		cout << "Tutor ID: " << list->TutorID << endl;
		cout << "Tutor name: " << list->Name << endl;
		cout << "Tutor date joined: " << list->DateJoined << endl;
		cout << "Tutor date terminated: "<< list->DateTerminated << endl;
		cout << "Hourly pay: RM" << list->HourlyPay << endl;
		cout << "Tutor phone: " << list->Phone << endl;
		cout << "Tutor address: " << list->Address << endl;
		cout << "TC code: " << list->TCCode << endl;
		cout << "TC name: " << list->TCName << endl;
		cout << "Tutor subject code: " << list->SubjectCode << endl;
		cout << "Tutor subject name: " << list->SubjectName << endl;
		cout << "Tutor rating: " << list->Rating << endl<< endl;
		list = list-> next;
	}
	system("PAUSE"); system("CLS");
		dashboard();
}
void edit() {}
void sort() {}

void add() {
	int Tid,pay,Tccode,Subcode,rate;
	string name, phone, adress, TCname, Subname;
	newnode = new Tutor;
	int i;
	string YN;
	system("CLS");
	cout << "Enter your tutor ID: ";
	cin >> Tid;
	newnode->TutorID = Tid;
	
	
	if (newnode->TutorID == 0) {
		cout << "Data entered must be numeric type and cannot be set to zero. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}
	/*while (i >= 0) {
		if (newnode->TutorID == temp->TutorID) {
			cout << "Tutor with tutor ID '" << newnode->TutorID << "' already exists. Consider using another tutor ID." << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore(10000, '\n');
			add();
		}
		i--;*/
	
	cout << "\nEnter tutor full name: ";
	cin.ignore();
	getline(cin, name);
	newnode->Name = name;
	
	
	if (newnode->Name == "") {
		cout << "Name cannot be blank. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nDate Joined: " << currentDateTime() << endl;
	newnode->DateJoined = currentDateTime();

	cout << "\nEnter the hourly pay (RM40.00 - RM80.00): RM";
	cin >> pay;
	newnode->HourlyPay = pay;
	
	
	if ((newnode->HourlyPay < 40.00) || (newnode->HourlyPay > 80.00)) {
		cout << "Amount entered is too low or too high, please try again." << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(10000, '\n');
		add();
	}
	if (newnode->HourlyPay == 0) {
		cout << "Data entered must be numeric type and cannot be set to zero. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tutor phone number: ";

	cin >> phone;
		newnode->Phone=phone;
	
	
	if (newnode->Phone == "") {
		cout << "Phone number cannot be blank. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tutor address: ";
	cin.ignore();
	getline(cin, adress);
	newnode->Address = adress;
	
	
	if (newnode->Address == "") {
		cout << "Address cannot be blank. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tuition center code: ";

	cin >> Tccode;
		newnode->TCCode=Tccode;
	
	
	if (newnode->TCCode == 0) {
		cout << "Data entered must be numeric type and cannot be set to zero. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tuition center name: ";

	cin >> TCname;
		newnode->TCName=TCname;
	
	
	if (newnode->TCName == "") {
		cout << "Tuition center name cannot be blank. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tutor subject code: ";

	cin >> Subcode;
		newnode->SubjectCode=Subcode;
	
	
	if (newnode->SubjectCode == 0) {
		cout << "Data entered must be numeric type and cannot be set to zero. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tutor subject name: ";
	cin.ignore();
	getline(cin, Subname);
	newnode->SubjectName = Subname;
	
	
	if (newnode->SubjectName == "") {
		cout << "Phone number cannot be blank. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}

	cout << "\nEnter tutor rating (1-5): ";
	cin >> rate;
		newnode->Rating=rate;
	
	
	if (newnode->Rating == 0) {
		cout << "Data entered must be numeric type and cannot be set to zero. Please try again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		system("PAUSE");
		add();
	}
	if (newnode->Rating < 1 || newnode->Rating > 5) {
		cout << "Rating entered is too low or too high, please try again." << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(10000, '\n');
		add();
	}

	cout << "\n\n\n-----SUMMARY-----" << endl;
	cout << "Tutor ID: " << newnode->TutorID << endl;
	cout << "Tutor name: " << newnode->Name << endl;
	cout << "Tutor date joined: " << newnode->DateJoined << endl;
	//cout << "Tutor date terminated: "<< tutor[Tcounter].DateTerminated << endl;
	cout << "Hourly pay: RM" << newnode->HourlyPay << endl;
	cout << "Tutor phone: " << newnode->Phone << endl;
	cout << "Tutor address: " << newnode->Address << endl;
	cout << "TC code: " << newnode->TCCode << endl;
	cout << "TC name: " << newnode->TCName << endl;
	cout << "Tutor subject code: " << newnode->SubjectCode << endl;
	cout << "Tutor subject name: " << newnode->SubjectName << endl;
	cout << "Tutor rating: " << newnode->Rating << endl;
	cout << "\nAre you sure to add " << newnode->Name << "? (Y/N) ";
	cin >> YN;

	if (YN == "Y" || YN == "y") {
		newnode->next = NULL;
		if (list == NULL) {
			list = newnode;
		}
		else if (Tid < list->TutorID) {
			newnode->next = list;
			list = newnode
		}
		else  {
			temp = list;
			while (temp != NULL) {
				previous = temp;
				temp = temp->next;
			}
			previous->next = newnode;
		}
		cout << "\n\nTutor added!" << endl;
		system("pause");
		dashboard();
	}
	else if (YN == "N" || YN == "y") {
		cout << "\nRedirecting to dashboard..." << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(10000, '\n');
		dashboard();
	}
	else {
		cout << "Invalid input, please try again." << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(10000, '\n');
		add();
	}

}

void dashboard()
{
	string menu;
	system("CLS");
	cout << "\t\t\t\t\t\t*****DASHBOARD*****" << endl << endl;
	cout << "1. Add New Tutor" << endl << "2. Display All Tutor" << endl << "3. Search Tutor" << endl << "4. Sort and Display Tutor" << endl << "5. Modify Tutor Records" << endl << "6. Delete Tutor Records" << endl << "7. Logout" << endl;
	cout << "Enter your choice (Ex : 1)  :  ";
	cin >> menu;
	if (menu == "1") {
		cout << endl << "Redirecting to Add New Tutor..." << endl; system("pause"); system("CLS"); add();
	}
	else if (menu == "2") {
		cout << endl << "Redirecting to Display All Tutor..." << endl; system("pause"); system("CLS"); viewAll();

	}
	else if (menu == "3") {
		cout << endl << "Redirecting to Search Tutor..." << endl; system("pause"); system("CLS"); search();
	}
	else if (menu == "4") {
		cout << endl << "Redirecting to Sort and Display..." << endl; system("pause"); system("CLS"); sort();
	}
	else if (menu == "5") {
		cout << endl << "Redirecting to Modify Tutor..." << endl; system("pause"); system("CLS"); edit();
	}
	else if (menu == "6") {
		cout << endl << "Redirecting to Delete Tutor..." << endl; system("pause"); system("CLS"); remove();
	}
	else if (menu == "7") {
		cout << endl << "Logout success." << endl; system("pause"); login();
	}
	else {
		cout << endl << endl << "Wrong input\n\nPlease Try Again" << endl; system("pause"); system("CLS"); dashboard();
	}

}

void login()
{
	system("CLS");
	string uname, pass;

	cout << "\t\t\t\t\tWelcome to eXcel Tuition Centre !\t\t\t" << currentDateTime() << endl;
	cout << "\t\t\t\t\t\t*****LOGIN*****" << endl << endl;
	cout << "Username : ";
	cin >> uname;
	cout << "\nPassword : ";
	cin >> pass;

	if (uname == "admin" && pass == "admin") {
		cout << "\n\nLogin Success" << endl;
		system("pause");
		dashboard();

	}
	else {
		cout << "Sorry, wrong username or password" << endl; system("PAUSE");
		login();
	}

}

int main() {

	

	login();

	return 0;
}
