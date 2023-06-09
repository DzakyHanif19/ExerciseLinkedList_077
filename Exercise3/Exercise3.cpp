#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int rollnumber;
	string name;
	node* next;
};

class CircularLinkedList {
private:
	node* last;
public:
	CircularLinkedList() {
		last = NULL;
	}
	void addnode();
	bool search(int rollno, node** annafi, node** dzaky);
	bool listempty();
	bool delnode(int rollnumber);
	void traverse();
};
void CircularLinkedList::addnode() { /*menambah sebuah node kedalam list*/
	int rollno;
	string name;
	cout << "masukan rollnumber: ";
	cin >> rollno;
	cout <<  "masukan nama: ";
	cin >> name;

	node* nodebaru = new node;
	nodebaru->rollnumber = rollno;
	nodebaru->name = name;

	if (last == NULL || rollno <= last->rollnumber)
	{
		if ((last != NULL) && (rollno == last->rollnumber))
		{
			cout << "\nduplikasi rollnumber tidak diijinkan\n";
			return;
		}
		nodebaru->next = last;
		last = nodebaru;
		return;
	}
	node* annafi, * dzaky;

	dzaky = last;
	annafi = last;

	while ((dzaky != NULL) && (rollno >= dzaky->rollnumber))
	{
		if (rollno == dzaky->rollnumber)
		{
			cout << "\nduplikasi rollnumber tidak diijinkan\n";
			return;
		}
		annafi = dzaky;
		dzaky = dzaky->next;
	}
	nodebaru->next = dzaky;
	annafi->next = nodebaru;
}
bool CircularLinkedList::search(int rollno, node** annafi, node** dzaky) {
	*annafi = last->next;
	*dzaky = last->next;
	while (*dzaky != last) {
		if (rollno == (*dzaky)->rollnumber) {
			return true;
		}
		*annafi = *dzaky;
		*dzaky = (*dzaky)->next;
	}
	if (rollno == last->rollnumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listempty() {
	return last == NULL;
}
bool CircularLinkedList::delnode(int rollnumber) 
{

	node* dzaky, * annafi;
	if (search(rollnumber, &annafi, &dzaky) == false)
		return false;
	annafi->next = dzaky->next;
	if (dzaky == last)
		last = last->next;

	delete dzaky;
	return true;
}
void CircularLinkedList::traverse() {
	if (listempty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		node* currentnode = last->next;
		while (currentnode != last) {
			cout << currentnode->rollnumber << " " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
		cout << last->rollnumber << " " << last->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}