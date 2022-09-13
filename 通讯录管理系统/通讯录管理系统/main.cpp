#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct person {
	string name;
	string gen;
	int year;
	string phone;
	string address;
};

//定义最大容量为1000的数组
#define MAX 1000

struct contact {
	struct person arr[MAX];
	int maxsize;
};

void meun() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addperson(contact *p) {
	if (p->maxsize == MAX) {
		cout << "FULL" << endl;
	}
	else {
		string name;
		cout << "Name: ";
		cin >> name;
		p->arr[p->maxsize].name = name;
		string gen;
		cout << "Gender: ";
		cin >> gen;
		p->arr[p->maxsize].gen = gen;
		int year;
		cout << "How old: ";
		cin >> year;
		p->arr[p->maxsize].year = year;
		string phone;
		cout << "Phone #: ";
		cin >> phone;
		p->arr[p->maxsize].phone = phone;
		string address;
		cout << "Address: ";
		cin >> address;
		p->arr[p->maxsize].address = address;

		p->maxsize++;
		cout << "Success!" << endl;

		
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏操作
}

void showperson(contact* p) {
	if (p->maxsize == 0) {
		cout << "No contact in the menu." << endl;
	}
	else {
		for (int i = 0; i < p->maxsize; i++) {
			cout << "Name: " << p->arr[i].name 
				 << " Gender: " << p->arr[i].gen 
				 << " Year: " << p->arr[i].year 
				 << " Phone #: " << p->arr[i].phone 
				 << " Address: " << p->arr[i].address << endl;
		}
		
	}
	system("pause");
	system("cls");
}

int findperson(contact* p, string delectp) {

	for (int i = 0; i < p->maxsize; i++) {
		if (delectp == p->arr[i].name) {
			return i;
		}
	}
	return -1;
}

void de(contact *p, int num) {
	for (int i = num; i < p->maxsize; i++) {
		p->arr[i] = p->arr[i + 1];
	}
	p->maxsize--;
	cout << "Delect success." << endl;

	system("pause");
	system("cls");
}

void changeperson(contact* p, int numb) {
	cout << "Please enter the modified name: ";
	string name;
	cin >> name;
	cout << "Please enter the modified gender: ";
	string gen;
	cin >> gen;
	cout << "Please enter the modified year: ";
	int year;
	cin >> year;
	cout << "Please enter the modified phone#: ";
	string phone;
	cin >> phone;
	cout << "Please enter the modified address: ";
	string address;
	cin >> address;

	p->arr[numb].name = name;
	p->arr[numb].gen = gen;
	p->arr[numb].year = year;
	p->arr[numb].phone = phone;
	p->arr[numb].address = address;

	cout << "Modified success." << endl;

	system("pause");
	system("cls");

}

void delectall(contact* p) {
	p->maxsize = 0;
	cout << "Delect all success." << endl;
	system("pause");
	system("cls");
}

int main() {
	contact C;
	C.maxsize = 0;

	int choose;
	while (true) {
		meun();
		cin >> choose;
		switch (choose) {
		case 1:
			addperson(&C);
			break;
		case 2:
			showperson(&C);
			break;
		case 3:
		{
			cout << "Input the name that you want to delect: ";
			string delectp;
			cin >> delectp;
			int num=findperson(&C, delectp);
			if (num == -1) {
				cout << "Can't find that person." << endl;

				system("pause");
				system("cls");
			}
			else {
				de(&C,num);
			}
		}

			break;
		case 4: 
		{
			cout << "Input the name that you want to find: ";
			string findn;
			cin >> findn;
			int n = findperson(&C, findn);
			if (n == -1) {
				cout << "Can't find that person." << endl;

				system("pause");
				system("cls");
			}
			else {
				cout << "Name: " << C.arr[n].name
					<< " Gender: " << C.arr[n].gen
					<< " Year: " << C.arr[n].year
					<< " Phone #: " << C.arr[n].phone
					<< " Address: " << C.arr[n].address << endl;

				system("pause");
				system("cls");
			}
		}

			break;
		case 5:
		{
			cout << "Input the name that you want to change: ";
			string changen;
			cin >> changen;
			int numb = findperson(&C, changen);
			if (numb != -1) {
				changeperson(&C, numb);
			}
			else {
				cout << "Can't find that person." << endl;

				system("pause");
				system("cls");
			}
		}
			break;
		case 6:
			delectall(&C);
			break;
		case 0:
			exit(0);
		}

	}
}