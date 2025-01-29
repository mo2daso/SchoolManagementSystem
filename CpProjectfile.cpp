#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int  i = 0;
struct stud {
	int id;
	string name;
	string f_name;
	string l_name;
	string email;
	string p_num;
	int yob;
}stdt[20];
struct marks {
	int eng;
	int urdu;
	int maths;
	int science;
	int computer;
	long int tot;
	float perce;
	char grade;
}obj[20];
//for copied variables
struct temp {
	int id2;
	string name2;
	string f_name2;
	string l_name2;
	string email2;
	float marks2;
	float percent2;
	string p_num2;
	int yob2;
	int eng2;
	int urdu2;
	int maths2;
	int science2;
	int computer2;
	char grade2;
}obj1[20];
int insertDetails();
int insertMarks();
int displayDetails();
int updateDetails();
int searchDetails();
int delDetails();
int filing();
int teacher();
int student();
int filing2();
void main()
{
	char c;
	int choice1;
	do {
		cout << "\t\t\t------Student Information Management System------" << endl;
		cout << "\t\tPress 1 (For Teachers) " << endl;
		cout << "\t\tPress 2 (For Students) " << endl;
		cout << "\t\tEnter Your Choice: ";
		cin >> choice1;
		if (choice1 == 1)
		{
			teacher();
		}
		else if (choice1 == 2)
		{
			student();
		}
		else
		{
			cout << "\t\tInvalid Input" << endl;
		}
		cout << "\t\tPress y to continue or any key to exit: ";
		cin >> c;
	} while (c == 'y' || c == 'Y');
	system("cls");
	system("pause");
}
int teacher()
{
	system("Cls");
	int choice;
	char cont;
	do {
		cout << "\t\t\t------Student Information Management System------" << endl;
		cout << "\t\t\t\t------Teacher------" << endl;
		cout << "\t\t\tPress 1 to Enter Student Details" << endl;
		cout << "\t\t\tPress 2 to Update Student Details" << endl;
		cout << "\t\t\tPress 3 to Delete Student Details" << endl;
		cout << "\t\t\tPress 4 to Search Student Details" << endl;
		cout << "\t\t\tPress 5 to Display Student Details" << endl;
		cout << "\t\t\tPress 6 to Exit" << endl;
		cout << "\t\t\tEnter Your Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			system("Cls");
			int choice2;
			cout << "\t\t\t------Student Information Management System------" << endl;
			cout << "\t\t\tPress 1 to insert Student Details " << endl;
			cout << "\t\t\tPress 2 to insert Student Marks" << endl;
			cout << "\t\t\tEnter Your Choice: ";
			cin >> choice2;
			if (choice2 == 1)
			{
				system("Cls");
				insertDetails();
			}
			else if (choice2 == 2)
			{
				system("Cls");
				insertMarks();
			}
		}
		else if (choice == 2)
		{
			system("Cls");
			updateDetails();
		}
		else if (choice == 3)
		{
			system("cls");
			delDetails();
		}
		else if (choice == 4)
		{
			system("cls");
			searchDetails();
		}
		else if (choice == 5)
		{
			system("cls");
			displayDetails();
		}
		else if (choice == 6)
		{
			break;
		}
		cout << "\t\t\tDo You Want To Continue:";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
	system("cls");
	return 0;
}
int student()
{
	char c;
	int choice3;
	do {
		cout << "\t\t\t\t------Student------" << endl;
		cout << "\t\t\tViewing Your Details " << endl;
			system("cls");
			searchDetails();
		cout << "\t\t\tPress y to contniue: ";
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return 0;
}
int insertDetails()
{
	cout << "\t\t\t------Student Information Management System------" << endl;
	cout << "\t\t\t\tEnter Student Details" << endl;
	cout << "\t\t\tEnter student Id :";
	cin >> stdt[i].id;
	cout << "\t\t\tEnter student name: ";
	getline(cin >> ws, stdt[i].name);
	cout << "\t\t\tEnter student's Last Name: ";
	getline(cin >> ws, stdt[i].l_name);
	cout << "\t\t\tEnter student's Father Name: ";
	getline(cin >> ws, stdt[i].f_name);
	cout << "\t\t\tEnter student email: ";
	getline(cin >> ws, stdt[i].email);
	cout << "\t\t\tEnter student phone number: ";
	getline(cin >> ws, stdt[i].p_num);
	cout << "\t\t\tEnter student Year Of Birth: ";
	cin >> stdt[i].yob;
	i++;
	filing();
	filing2();
	
	return 0;
}
int filing2() {
	ofstream out2("shortlisted.txt", ios::out);
	for (int j = 0; j < i; j++)
	{
		out2 << stdt[j].id << endl;
		out2 << stdt[j].name << endl;
		out2 << stdt[j].l_name << endl;
		out2 << stdt[j].f_name << endl;
		out2 << stdt[j].email << endl;
		out2 << stdt[j].p_num << endl;
		out2 << stdt[j].yob << endl;
		out2 << obj[j].eng << endl;
		out2 << obj[j].urdu << endl;
		out2 << obj[j].maths << endl;
		out2 << obj[j].science << endl;
		out2 << obj[j].computer << endl;
		out2 << obj[j].tot << endl;
		out2 << obj[j].perce << endl;
		out2 << obj[j].grade << endl;
	}
	return 0;
}
int filing()
{
	ofstream out("studentData.txt", ios::out);
	for (int j = 0; j < i; j++)
	{
		out << "\t\t\tStudent Id :" << stdt[j].id << endl;
		out << "\t\t\tStudent name: " << stdt[j].name << endl;
		out << "\t\t\tStudent Last Name: " << stdt[j].l_name << endl;
		out << "\t\t\tStudent's Father Name: " << stdt[j].f_name << endl;
		out << "\t\t\tstudent email: " << stdt[j].email << endl;
		out << "\t\t\tStudent phone number: " << stdt[j].p_num << endl;
		out << "\t\t\tStudent Year Of Birth: " << stdt[j].yob << endl;
		out << "\t\t\tEnglish Marks: " << obj[j].eng << endl;
		out << "\t\t\tUrdu Marks: " << obj[j].urdu << endl;
		out << "\t\t\tMaths Marks: " << obj[j].maths << endl;
		out << "\t\t\tScience Marks: " << obj[j].science << endl;
		out << "\t\t\tComputer Marks: " << obj[j].computer << endl;
		/*obj[j].tot = obj[j].eng + obj[j].urdu + obj[j].maths + obj[j].science + obj[j].computer;
		obj[j].perce = (obj[j].tot * 100) / 250;*/
		out << "\t\t\tTOTAL MARKS : " << obj[j].tot << " /250 " << endl;
		out << "\t\t\tPERCENTAGE: " << obj[j].perce << endl;
		out << "\t\t\tGRADE: " << obj[j].grade << endl;
	}
	return 0;
}

int insertMarks()
{
	cout << "\t\t\t------Student Information Management System------" << endl;
	int search_id;
	cout << "\t\t\tEnter Student Id To Insert Marks: ";
	cin >> search_id;
	cout << "\t\t\t\tEnter Student's Marks" << endl;

	for (int j = 0; j < i; j++)
	{
		if (search_id == stdt[j].id)
		{
			cout << "\t\t\tEnter Student's English Marks: ";
			cin >> obj[j].eng;
			cout << "\t\t\tEnter Student's Urdu Marks:  ";
			cin >> obj[j].urdu;
			cout << "\t\t\tEnter Student's Maths Marks: ";
			cin >> obj[j].maths;
			cout << "\t\t\tEnter Student's Science Marks:  ";
			cin >> obj[j].science;
			cout << "\t\t\tEnter Student's Computer Marks:  ";
			cin >> obj[j].computer;
			obj[j].tot = obj[j].eng + obj[j].urdu + obj[j].maths + obj[j].science + obj[j].computer;
			obj[j].perce = (obj[j].tot * 100) / 250;
			if (obj[j].perce < 50)
			{
				obj[j].grade = 'F';
			}
			if (obj[j].perce > 50 && obj[j].perce < 60)
			{
				obj[j].grade = 'D';
			}
			if (obj[j].perce > 60 && obj[j].perce > 70)
			{
				obj[j].grade = 'C';
			}
			if (obj[j].perce > 70 && obj[j].perce >= 80)
			{
				obj[j].grade = 'B';
			}
			if (obj[j].perce > 80 && obj[j].perce > 100)
			{
				obj[j].grade = 'A';
			}
		}
	}
	filing();
	filing2();
	return 0;
}
int displayDetails()
{
	ifstream in2("studentData.txt", ios::in);
	string l;
	while (in2.eof() == 0)
	{
		getline(in2, l);
		cout << l << endl;
	}
	
	return 0;
}
int updateDetails()
{
	cout << "\t\t\t------Student Information Management System------" << endl;

	int id2;
	cout << "\t\t\tEnter the id you want to update details of: ";
	cin >> id2;
	for (int k = 0; k < i; k++)
	{
		if (id2 == stdt[k].id)
		{
			cout << "\t\t\tStudent Id :" << stdt[k].id << endl;
			cout << "\t\t\tStudent name: " << stdt[k].name << endl;
			cout << "\t\t\tStudent Last Name: " << stdt[k].l_name << endl;
			cout << "\t\t\tStudent's Father Name: " << stdt[k].f_name << endl;
			cout << "\t\t\tstudent email: " << stdt[k].email << endl;
			cout << "\t\t\tStudent phone number: " << stdt[k].p_num << endl;
			cout << "\t\t\tStudent Year Of Birth: " << stdt[k].yob << endl;
			cout << "\t\t\tEnglish Marks: " << obj[k].eng << " /50 " << endl;
			cout << "\t\t\tUrdu Marks: " << obj[k].urdu << " /50 " << endl;
			cout << "\t\t\tMaths Marks: " << obj[k].maths << " /50 " << endl;
			cout << "\t\t\tScience Marks: " << obj[k].science << " /50 " << endl;
			cout << "\t\t\tComputer Marks: " << obj[k].computer << " /50 " << endl;
			cout << "\t\t\tTOTAL MARKS : " << obj[k].tot << " /250 " << endl;
			cout << "\t\t\tPERCENTAGE: " << obj[k].perce << endl;
			cout << "\t\t\tGRADE: " << obj[k].grade << endl;
			
			int choice3;
			cout << "\t\t\t------Student Information Management System------" << endl;
			cout << "\t\t\tPress 1 for updating students details " << endl;
			cout << "\t\t\tPress 2 for updating marks " << endl;
			cout << "\t\t\tPress 3 for updating all details and marks " << endl;
			cout << "\t\t\tEnter Your Choice: ";
			cin >> choice3;
			if (choice3 == 1)
			{
				system("cls");
				cout << "\t\t\t------Student Information Management System------" << endl;
				cout << "\t\t\t\tUpdating students details" << endl;
				cout << "\t\t\tEnter new id: ";
				cin >> stdt[k].id;
				cout << "\t\t\tEnter new name: ";
				cin >> stdt[k].name;
				cout << "\t\t\tEnter new last name: ";
				cin >> stdt[k].l_name;
				cout << "\t\t\tEnter new Father name: ";
				cin >> stdt[k].f_name;
				cout << "\t\t\tEnter new Email: ";
				cin >> stdt[k].email;
				cout << "\t\t\tEnter new Phone number: ";
				cin >> stdt[k].p_num;
				cout << "\t\t\tEnter year of birth: ";
				cin >> stdt[k].yob;
				filing();
				filing2();
				system("cls");
			}
			if (choice3 == 2)
			{
				system("cls");
				cout << "\t\t\t------Student Information Management System------" << endl;
				cout << "\t\t\t\tUpdating students marks " << endl;
				cout << "\t\t\tEnter the marks for English: ";
				cin >> obj[k].eng;
				cout << "\t\t\tEnter the marks for Urdu: ";
				cin >> obj[k].urdu;
				cout << "\t\t\tEnter the marks for Maths: ";
				cin >> obj[k].maths;
				cout << "\t\t\tEnter the marks for Science: ";
				cin >> obj[k].science;
				cout << "\t\t\tEnter the marks for Computer: ";
				cin >> obj[k].computer;
				obj[k].tot = obj[k].eng + obj[k].urdu + obj[k].maths + obj[k].science + obj[k].computer;
				obj[k].perce = (obj[k].tot * 100) / 250;
				cout << "\t\t\tTOTAL MARKS : " << obj[k].tot << " /250 " << endl;
				cout << "\t\t\tPERCENTAGE: " << obj[k].perce << endl;
				if (obj[k].perce > 50 && obj[k].perce < 60)
				{
					obj[k].grade = 'D';
				}
				if (obj[k].perce > 60 && obj[k].perce > 70)
				{
					obj[k].grade = 'C';
				}
				if (obj[k].perce > 70 && obj[k].perce >= 80)
				{
					obj[k].grade = 'B';
				}
				if (obj[k].perce > 80 && obj[k].perce > 100)
				{
					obj[k].grade = 'A';
				}
				cout << "\t\t\tPERCENTAGE: " << obj[k].grade << endl;
				filing();
				filing2();
				system("cls");
			}
			if (choice3 == 3)
			{
				system("cls");
				cout << "\t\t\t------Student Information Management System------" << endl;
				cout << "\t\t\tEnter new id: ";
				cin >> stdt[k].id;
				cout << "\t\t\tEnter new name: ";
				cin >> stdt[k].name;
				cout << "\t\t\tEnter new last name: ";
				cin >> stdt[k].l_name;
				cout << "\t\t\tEnter new Father name: ";
				cin >> stdt[k].f_name;
				cout << "\t\t\tEnter new Email: ";
				cin >> stdt[k].email;
				cout << "\t\t\tEnter new Phone number: ";
				cin >> stdt[k].p_num;
				cout << "\t\t\tEnter year of birth: ";
				cin >> stdt[k].yob;
				cout << "\t\t\t\tUpdating students marks" << endl;
				cout << "\t\t\tEnter the marks for English: ";
				cin >> obj[k].eng;
				cout << "\t\t\tEnter the marks for Urdu: ";
				cin >> obj[k].urdu;
				cout << "\t\t\tEnter the marks for Maths: ";
				cin >> obj[k].maths;
				cout << "\t\t\tEnter the marks for Science: ";
				cin >> obj[k].science;
				cout << "\t\t\tEnter the marks for Computer: ";
				cin >> obj[k].computer;
				obj[k].tot = obj[k].eng + obj[k].urdu + obj[k].maths + obj[k].science + obj[k].computer;
				obj[k].perce = (obj[k].tot * 100) / 250;
				cout << "\t\t\tTOTAL MARKS : " << obj[k].tot << " /250 " << endl;
				cout << "\t\t\tPERCENTAGE: " << obj[k].perce << endl;
				filing();
				filing2();
				
			}
		}
	}
	return 0;
}
int searchDetails()
{
	cout << "\t\t\t------Student Information Management System------" << endl;
	int f = 0;
	ifstream in("shortlisted.txt", ios::in);
	while (in >> obj1[f].id2, in >> obj1[f].name2, in >> obj1[f].f_name2, in >> obj1[f].l_name2, in >> obj1[f].email2, in >> obj1[f].p_num2, in >> obj1[f].yob2, in >> obj1[f].eng2, in >> obj1[f].urdu2, in >> obj1[f].maths2, in >> obj1[f].science2, in >> obj1[f].computer2, in >> obj1[f].marks2, in >> obj1[f].percent2, in >> obj1[f].grade2)
	{
		f++;
	}
	for (int i = 0; i < f; i++)
	{
		cout << obj1[i].id2;
		cout << obj1[i].name2;
	}
	int search_id;
	cout << "\t\t\tEnter Id: ";
	cin >> search_id;
	for (int i = 0; i < f; i++)
	{
		if (search_id == obj1[i].id2)
		{
			cout << "\t\t\tStudent's Id is: " << obj1[i].id2 << endl;
			cout << "\t\t\tStudent's  First Name is:  " << obj1[i].name2 << endl;
			cout << "\t\t\tStudent's Last Name is :  " << obj1[i].f_name2 << endl;
			cout << "\t\t\tStudent's Father Name is :  " << obj1[i].l_name2 << endl;
			cout << "\t\t\tStudent's Email Address  is :  " << obj1[i].email2 << endl;
			cout << "\t\t\tStudent's  Phone Number is :  " << obj1[i].p_num2 << endl;
			cout << "\t\t\tStudent's Year Of Birth  is :  " << obj1[i].yob2 << endl;
			cout << "\t\t\tStudent's Marks of English are :  " << obj1[i].eng2 << endl;
			cout << "\t\t\tStudent's Marks of Urdu are :  " << obj1[i].urdu2 << endl;
			cout << "\t\t\tStudent's Marks of Maths are :  " << obj1[i].maths2 << endl;
			cout << "\t\t\tStudent's Marks of Science are :  " << obj1[i].science2 << endl;
			cout << "\t\t\tStudent's Marks of Computer are :  " << obj1[i].computer2 << endl;
			cout << "\t\t\tTOTAL MARKS : " << obj1[i].marks2 << " /250 " << endl;
			cout << "\t\t\tPERCENTAGE: " << obj1[i].percent2 << endl;
			cout << "\t\t\tGRADE: " << obj1[i].grade2 << endl;
			break;
		}
		else
		{
			cout << "\t\t\tInvalid Input";
		}
	}
	return 0;
}
int delDetails()
{
	cout << "\t\t\t------Student Information Management System------" << endl;
	int temp;
	cout << "\n\t\t\tEnter Id To Delete ";
	cin >> temp;
	for (int k = 0; k < i; k++)
	{
		if (temp == stdt[k].id)
		{
			cout << "\t\t\tStudent Id :" << stdt[k].id << endl;
			cout << "\t\t\tStudent name: " << stdt[k].name << endl;
			cout << "\t\t\tStudent Last Name: " << stdt[k].l_name << endl;
			cout << "\t\t\tStudent's Father Name: " << stdt[k].f_name << endl;
			cout << "\t\t\tStudent email: " << stdt[k].email << endl;
			cout << "\t\t\tStudent phone number: " << stdt[k].p_num << endl;
			cout << "\t\t\tStudent Year Of Birth: " << stdt[k].yob << endl;
			cout << "\t\t\tEnglish Marks: " << obj[k].eng << endl;
			cout << "\t\t\tUrdu Marks: " << obj[k].urdu << endl;
			cout << "\t\t\tMaths Marks: " << obj[k].maths << endl;
			cout << "\t\t\tScience Marks: " << obj[k].science << endl;
			cout << "\t\t\tComputer Marks: " << obj[k].computer << endl;
			cout << "\t\t\tTOTAL MARKS : " << obj[k].tot << " /250 " << endl;
			cout << "\t\t\tPERCENTAGE: " << obj[k].perce << endl;
			cout << "\t\t\tGRADE : " << obj[k].perce << endl;
			int choice3;
			cout << "\t\t\tPress 1 for deleting students details" << endl;
			cout << "\t\t\tPress 2 to return to menu " << endl;
			cout << "\t\t\tEnter Your Choice: ";
			cin >> choice3;
			if (choice3 == 1)
			{
				int  found = 0;
				for (int j = 0; j < i; j++)
				{
					if (temp == stdt[j].id) {
						for (int k = j; k < i - 1; k++)
						{
							cout << "\t\t\tStudent Name Is: " << stdt[j].name;
							stdt[k].id = stdt[k + 1].id;
							stdt[k].name = stdt[k + 1].name;
							stdt[k].l_name = stdt[k + 1].l_name;
							stdt[k].f_name = stdt[k + 1].f_name;
							stdt[k].email = stdt[k + 1].email;
							stdt[k].f_name = stdt[k + 1].f_name;
							stdt[k].email = stdt[k + 1].email;
							stdt[k].p_num = stdt[k + 1].p_num;
							stdt[k].yob = stdt[k + 1].yob;
							obj[k].eng = obj[k + 1].eng;
							obj[k].urdu = obj[k + 1].urdu;
							obj[k].maths = obj[k + 1].maths;
							obj[k].science = obj[k + 1].science;
							obj[k].computer = obj[k + 1].computer;
							obj[k].perce = obj[k + 1].tot;
							obj[k].tot = obj[k + 1].perce;
							obj[k].grade = obj[k + 1].grade;
						}
						i--;
						filing();
						filing2();
						cout << "\t\t\tDeleted"<< endl;
						found++;
						break;
					}
				}
				if (found == 0)
				{
					cout << endl << "\t\t\tInvalid" << endl;
				}
			}
			if (choice3 == 2)
			{
				break;
			}
		}
	}
	return 0;
}