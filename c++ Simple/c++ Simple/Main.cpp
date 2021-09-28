#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

struct ExamResult
{
	int math;
	int programming;
	int history;
	int compLogic;

};

struct birthday
{
	int day;
	int month;
	int year;
};

struct studInfo
{
	birthday studBirth;
	ExamResult exams;
	char surname[255];
	char name[255];
	char state[255];
	char address[255];
	int phone;
	int curse;
	char group[255];
	char znakZodiak[255];


};

void zodiacGet(struct studInfo* student, int counter);
void FillStruct(struct studInfo* student, int size);
void RW(struct studInfo* student, string path, int size, int *check);
void RW(int &check);
void RD(struct studInfo* student, struct studInfo *student1, string path, int size, int curseCheck, string surCheck);
void RD();
void ShowStudents(struct studInfo* student, struct studInfo* student1, string path, int size);


int main()
{
	srand(time(NULL));
	string path = "INFO.DAT";
	string surCheck;
	int curseCheck;
	studInfo student[100];
	studInfo student1[100];
	int size = 0, check = 0;
	bool *NewStudent;
	cout << "If you want to add new student press \"0\", or press \"1\" if you want to show student ";
	cin >> check;
	while (check == 0)
	{
		cout << "Enter amount of student's, you want to add: ";
		cin >> size;
		FillStruct(student, size);
		RW(student, path, size, &check);
	}
	ShowStudents(student, student1, path, size);
	cout << "Enter curse and surname of the student which you want to see: ";
	cin >> curseCheck >> surCheck;
	RD(student, student1, path, size, curseCheck, surCheck);
	cout << "======================================" << endl;
	cout << "If you want to add new student, press \"0\", or press \"1\" if you want to show students ";
	cin >> check;
	while (check == 0)
	{
		RW(check);
	}
	RD();
	return 0;
}


void RW(struct studInfo* student, string path, int size, int* check)
{
	ofstream fs(path, fstream::binary | fstream::app);

	for (int i = 0; i < size; i++)
	{
		fs.write((char*)&student[i], sizeof(student[i]));
	}
	fs.close();
	cout << "If you want to add new student press \"0\", or press \"1\" if you want to show student ";
	cin >> *check;
}
void RD(struct studInfo* student, struct studInfo* student1, string path, int size, int curseCheck, string surCheck)
{
	int counter = 0;
	ifstream fs2(path, fstream::binary);
	fs2.seekg(0, ios::end);      //переход в конец файла
	long i = (long)fs2.tellg();  //вы€снение кол-ва байтов в файле
	counter = i / sizeof(studInfo);
	fs2.clear();
	fs2.seekg(0);
	for (int i = 0; i < counter; i++)
	{
		fs2.read((char*)&student1[i], sizeof(student[i]));
	}
	fs2.close();
	for (int i = 0; i < counter; i++)
	{
		if ((student1[i].curse == curseCheck) && (student1[i].surname == surCheck))
		{
			if (student1[i].studBirth.month < 10)
			{
				cout << "The student you seek, is:" << endl;
				cout << student1[i].surname << " " << student1[i].name << endl;
				cout << student1[i].studBirth.day << " " << "0" << student1[i].studBirth.month << " " << student1[i].studBirth.year << endl;
				cout << "State: " << student1[i].state << endl;
				cout << "Address: " << student1[i].address << " " << "phone: " << student1[i].phone << endl;
				cout << "Curse: " << student1[i].curse<<" "<< "group: " << student1[i].group << endl;
				cout << "Math: " << student1[i].exams.math << endl << "History: " << student1[i].exams.history << endl << "Programming: " << student1[i].exams.programming << endl << "CompLogic: " << student1[i].exams.compLogic << endl;
				cout << "Znak: " << student1[i].znakZodiak << endl;
			}
			else
			{
				cout << "The student you seek, is:" << endl;
				cout << student1[i].surname << " " << student1[i].name << endl;
				cout << student1[i].studBirth.day << " " << "0" << student1[i].studBirth.month << " " << student1[i].studBirth.year << endl;
				cout << "State: " << student1[i].state << endl;
				cout << "Address: " << student1[i].address << " " << "phone: " << student1[i].phone << endl;
				cout << "Curse: " << student1[i].curse << " " << "group: " << student1[i].group << endl;
				cout << "Math: " << student1[i].exams.math << endl << "History: " << student1[i].exams.history << endl << "Programming: " << student1[i].exams.programming << endl << "CompLogic: " << student1[i].exams.compLogic << endl;
				cout << "Znak: " << student1[i].znakZodiak << endl;
			}
			return;
		}
		else if ((student1[i].curse == curseCheck) && (student1[i].surname != surCheck))
		{
			if (student1[i].studBirth.month < 10)
			{
				cout << "The student from the same curse:" << endl;
				cout << student1[i].surname << " " << student1[i].name << endl;
				cout << student1[i].studBirth.day << " " << "0" << student1[i].studBirth.month << " " << student1[i].studBirth.year << endl;
				cout << "State: " << student1[i].state << endl;
				cout << "Address: " << student1[i].address << " " << "phone: " << student1[i].phone << endl;
				cout << "Curse: " << student1[i].curse << " " << "group: " << student1[i].group << endl;
				cout << "Math: " << student1[i].exams.math << endl << "History: " << student1[i].exams.history << endl << "Programming: " << student1[i].exams.programming << endl << "CompLogic: " << student1[i].exams.compLogic << endl;
				cout << "Znak: " << student1[i].znakZodiak << endl;
			}
			else
			{
				cout << "The student from the same curse:" << endl;
				cout << student1[i].surname << " " << student1[i].name << endl;
				cout << student1[i].studBirth.day << " " << "0" << student1[i].studBirth.month << " " << student1[i].studBirth.year << endl;
				cout << "State: " << student1[i].state << endl;
				cout << "Address: " << student1[i].address << " " << "phone: " << student1[i].phone << endl;
				cout << "Curse: " << student1[i].curse << " " << "group: " << student1[i].group << endl;
				cout << "Math: " << student1[i].exams.math << endl << "History: " << student1[i].exams.history << endl << "Programming: " << student1[i].exams.programming << endl << "CompLogic: " << student1[i].exams.compLogic << endl;
				cout << "Znak: " << student1[i].znakZodiak << endl;
			}
		}

	}
}
void FillStruct(struct studInfo* student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter student's surname and name: ";
		cin >> student[i].surname >> student[i].name;
		cout << "Enter student's birthday (day, month, year) ";
		cin >> student[i].studBirth.day >> student[i].studBirth.month >> student[i].studBirth.year;
		cout << "Enter student's state: ";
		cin >> student[i].state;
		cout << "Enter student's address and phone: ";
		cin >> student[i].address >> student[i].phone;
		cout << "Enter student's curse and group: ";
		cin >> student[i].curse >> student[i].group;
		student[i].exams.compLogic = 1 + rand() % 5;
		student[i].exams.history = 1 + rand() % 5;
		student[i].exams.math = 1 + rand() % 5;
		student[i].exams.programming = 1+ rand() % 5;
		zodiacGet(student, i);
		

	}
}
void ShowStudents(struct studInfo* student, struct studInfo* student1, string path, int size)
{
	int counter = 0;
	ifstream fs2(path, fstream::binary);
	fs2.seekg(0, ios::end);      //переход в конец файла
	long i = (long)fs2.tellg();  //вы€снение кол-ва байтов в файле
	counter = i / sizeof(studInfo);
	fs2.clear();
	fs2.seekg(0); 
	for (int i = 0; i < counter; i++)
	{
		fs2.read((char*)&student1[i], sizeof(student[i]));
	}
	for (int i = 0; i < counter - 1; i++) {
		for (int j = 0; j < counter - i - 1; j++) {
			if (student1[j].curse < student1[j + 1].curse) {
				student[j] = student1[j];
				student1[j] = student1[j + 1];
				student1[j + 1] = student[j];
			}
		}
	}
	
	fs2.close();
	cout << "The students:" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << student1[i].surname << " " << student1[i].curse << endl;
	}
}
void RW(int &check)
{
	int N = 0, math, history, compLogic, programming, physics;
	string name;

	cout << "Enter amount of students: ";
	cin >> N;
	ofstream fs("Lab2.txt", fstream::app);
	/*fs.open("Lab2.txt");*/
	for (int i = 0; i < N; i++)
	{
		cout << "Enter name of the student: ";
		cin >> name;
		cout << "Enter marks from 5 subjects(math, history, programming, compLogic, physics): ";
		cout << "Math: ";  cin >> math;
		cout << "History: ";  cin >> history;
		cout << "Programming: ";  cin >> programming;
		cout << "CompLogic: ";  cin >> compLogic;
		cout << "Physics: ";  cin >> physics;
		fs << name <<" " << math<<" " << history <<" "<< programming <<" "<< compLogic<<" "<< physics << endl;
	}
	fs.close();
	cout << "If you want to add new student, press \"0\", or press \"1\" if you want to show students ";
	cin >> check;
}
void RD()
{
	int N = 0, math, history, compLogic, programming, physics;
	string name;
	ifstream fs;
	fs.open("Lab2.txt");
	while (!fs.eof())
	{
		fs >> name >> math >> history >> programming >> compLogic >> physics;
		if (!fs.eof() && ((math == 4) && (history == 4) && (programming == 4) && (compLogic == 4) && (physics == 4)))
		{
			cout <<"Name of the student: "<< name <<endl<< "Marks: " <<endl<<"Math: "<<math<<endl<<"History: "<<history<<endl<<"Programming: "<<programming<<endl<<"CompLogic: "<< compLogic<<endl<<"Physics: "<<physics<<endl;
		}
	}
	fs.close();
}
void zodiacGet(struct studInfo* student, int counter)
{
		if ((student[counter].studBirth.month == 1 && student[counter].studBirth.day >= 21) || (student[counter].studBirth.month == 2 && student[counter].studBirth.day <= 19))
		{
			strcpy(student[counter].znakZodiak, "Aquarius");
		}
		else if ((student[counter].studBirth.month == 2 && student[counter].studBirth.day >= 20) || (student[counter].studBirth.month == 3 && student[counter].studBirth.day <= 20))
		{
			strcpy(student[counter].znakZodiak, "Pisces");
		}
		else if ((student[counter].studBirth.month == 3) && (student[counter].studBirth.day >= 21) || (student[counter].studBirth.month == 4) && (student[counter].studBirth.day <= 20))
		{
			strcpy(student[counter].znakZodiak, "Oven");
		}
		else if ((student[counter].studBirth.month == 4 && student[counter].studBirth.day >= 21) || (student[counter].studBirth.month == 5 && student[counter].studBirth.day <= 20))
		{
			strcpy(student[counter].znakZodiak, "Taurus");
		}
		else if ((student[counter].studBirth.month == 5 && student[counter].studBirth.day >= 21) || (student[counter].studBirth.month == 6 && student[counter].studBirth.day <= 21))
		{
			strcpy(student[counter].znakZodiak, "Gemini");
		}
		else if ((student[counter].studBirth.month == 6 && student[counter].studBirth.day >= 22) || (student[counter].studBirth.month == 7 && student[counter].studBirth.day <= 22))
		{
			strcpy(student[counter].znakZodiak, "Cancer");
		}
		else if ((student[counter].studBirth.month == 7 && student[counter].studBirth.day >= 23) || (student[counter].studBirth.month == 8 && student[counter].studBirth.day <= 23))
		{
			strcpy(student[counter].znakZodiak, "Leo");
		}
		else if ((student[counter].studBirth.month == 8 && student[counter].studBirth.day >= 24) || (student[counter].studBirth.month == 9 && student[counter].studBirth.day <= 23))
		{
			strcpy(student[counter].znakZodiak, "Diva");
		}
		else if ((student[counter].studBirth.month == 9 && student[counter].studBirth.day >= 24) || (student[counter].studBirth.month == 10 && student[counter].studBirth.day <= 22))
		{
			strcpy(student[counter].znakZodiak, "Libra");
		}
		else if ((student[counter].studBirth.month == 10) && (student[counter].studBirth.day >= 23) || (student[counter].studBirth.month == 11 && student[counter].studBirth.day <= 22))
		{
			strcpy(student[counter].znakZodiak, "Scorpio");
		}
		else if ((student[counter].studBirth.month == 11 && student[counter].studBirth.day >= 23) || (student[counter].studBirth.month == 12 && student[counter].studBirth.day <= 21))
		{
			strcpy(student[counter].znakZodiak, "Saqittarius");
		}
		else if ((student[counter].studBirth.month == 12 && student[counter].studBirth.day >= 22) || (student[counter].studBirth.month == 1 && student[counter].studBirth.day <= 20))
		{
			strcpy(student[counter].znakZodiak, "Capricom");
		}
}
