#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <chrono>
#include <thread>
#include <time.h>
using namespace std;

/////////////  STRUCTURES  /////////////
struct Student
{
	string name, roll, pass;
	int hours[9][100]{};
} s[115];

/////////////  PROTOTYPING  /////////////
void login();
void writeData();
void student();
void studentViewAttendance(string);
void findAttendanceLoop(int, string);
void teacher();
void markAttendance();
void teacherViewAttendance();
void editAttendance();
int checkIndex(int);
void addSpace(int, string);
void sleep(int);
void Date();

/////////////  GLOBAL VARIABLES  /////////////
string course[9] = {
	"",
	"APPLIED CALCULUS        ",
	"COMPUTER PROGRAMMING    ",
	"COMPUTER PROGRAMMING LAB",
	"FUNCTIONAL ENGLISH      ",
	"INTRODUCTION TO ICT     ",
	"INTRODUCTION TO ICT LAB ",
	"APPLIED PHYSICS         ",
	"APPLIED PHYSICS LAB     "
};

string date;

/////////////  MAIN  /////////////
int main()
{
	system("color 70");
	login();

	cout << endl << endl;
	return 0;
}

/////////////  LOGIN  /////////////
void login()
{
	//===========  VARIABLES  ===========//
	int ipt;

	//=============  BODY  =============//
	writeData();

	cout
		<< "\n\n\n"
		<< "\t\t\t\t\t  ----------------------------------\n"
		<< "\t\t\t\t\t----------                   ---------\n"
		<< "\t\t\t\t\t||         BAHRIA UNIVERSITY        ||\n"
		<< "\t\t\t\t\t----------                   ---------\n"
		<< "\t\t\t\t\t  ----------------------------------\n\n\n\n"
		<< "\t\t\t\t\tSIGN IN AS: \n\n"
		<< "\t\t\t\t\t1. STUDENT       ||       2. TEACHER\n\n\n\n\n"
		<< "\t\t\t\t\tSELECT AN OPTION: ";
	cin >> ipt;

	switch (ipt)
	{
	case 1:
	{
		system("cls");
		student();
		break;
	}
	case 2:
	{
		system("cls");
		teacher();
		break;
	}
	default:
	{
		cout << "\n\n\t\t\t\t\t----------INVALID INPUT----------";
		sleep(2);
		system("cls");
		login();
		break;
	}
	}
}

/////////////  writeData  /////////////
void writeData()
{
	//===========  VARIABLES  ===========//
	int n = 0;
	string zero[3] = { "", "0", "00" };
	string names[56] = {
	"",
	"Abdullah Danish Siddiqui",
	"Abdullah Iqbal          ",
	"Abdul Manan             ",
	"Adnan Musa              ",
	"Agha Mubeen Khan        ",
	"Aleeha Fatima           ",
	"Ali Arif                ",
	"Ali Hasan               ",
	"Amatul Musawir Tooba    ",
	"Annas Bin Khalil        ",
	"Arham Butt              ",
	"Arslan                  ",
	"Asad Ali                ",
	"Danish Riaz             ",
	"Daniyal Amir            ",
	"Daniyal Sajid           ",
	"Gulfam Asghar           ",
	"Hafsa Umer              ",
	"Hamid Naveed Choudhary  ",
	"Hamza Ghafran           ",
	"Hamza Shahid            ",
	"Hamza Zahid             ",
	"Haris Ali Safder        ",
	"Haris Rehman            ",
	"Hasan Umair             ",
	"Haseeb Arshad           ",
	"Hassaan Rasool          ",
	"Jawad Abdullah          ",
	"Mahaz Asif              ",
	"Mashood ur Rehman Rana  ",
	"Mohsin Hussain Mirza    ",
	"Moiz Aftab              ",
	"Mudassir Ahmed          ",
	"Muhammad Abdul Qadeer   ",
	"Muhammad Abdullah Javed ",
	"Muhammad Abu Huraira    ",
	"Muhammad Abubaker       ",
	"Muhammad Ahmad          ",
	"Muhammad Ali            ",
	"Muhammad Ali Butt       ",
	"Muhammad Ali Khan       ",
	"Muhammad Ali Riasat     ",
	"Zarar Ahmed Nagra       ",
	"Zuhaa Binte Jawad       ",
	"Ahmad Azeem             ",
	"Asad Farooq             ",
	"Khadija Zahoor          ",
	"Ameer Hamza             ",
	"Mubeen Khalil           ",
	"Abdul Sami Mochi        ",
	"Bushra Masood           ",
	"Hammad Aftab            ",
	"Abdullah Hassan         ",
	"Minahil                 ",
	"Fizah                   "
	};

	//=============  BODY  =============//
	for (int i = 1; i < 115; i++)
	{
		s[i].name = names[i];
		s[i].roll = "03-134202-" + zero[2] + to_string(i);
		s[i].pass = "abc" + zero[2] + to_string(i);
		if (i >= 10)
		{
			s[i].roll = "03-134202-" + zero[1] + to_string(i);
			s[i].pass = "abc" + zero[1] + to_string(i);
		}

		switch (i)
		{
		case 42:
		{
			for (i = 93; i < 100; i++)
			{
				n = checkIndex(i);
				s[i].name = names[n];
				s[i].roll = "03-134202-" + zero[1] + to_string(i);
				s[i].pass = "abc" + zero[1] + to_string(i);
			}
		}
		case 99:
		{
			for (i = 106; i < 109; i++)
			{
				n = checkIndex(i);
				s[i].name = names[n];
				s[i].roll = "03-134202-" + zero[0] + to_string(i);
				s[i].pass = "abc" + zero[0] + to_string(i);
			}
		}
		case 108:
		{
			for (i = 112; i < 115; i++)
			{
				n = checkIndex(i);
				s[i].name = names[n];
				s[i].roll = "03-134202-" + zero[0] + to_string(i);
				s[i].pass = "abc" + zero[0] + to_string(i);
			}
		}
		}
	}
}

/////////////  STUDENT  /////////////
void student()
{
	//===========  VARIABLES  ===========//
	string
		s_roll, s_pass;
	bool check = false;

	//=============  BODY  =============//

	cout
		<< "\n\n\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t-------------------                ---------------------\n"
		<< "\t\t\t\t||                  STUDENT'S MENU                    ||\n"
		<< "\t\t\t\t-------------------                ---------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n\n\n\n"

		<< "\t\t\t\tENROLLMENT NUMBER: ";
	cin >> s_roll;
	cout << "\n\t\t\t\tPASSWORD         : ";

	char ch;
	ch = _getch();
	while (ch != 13)
	{
		s_pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	for (int i = 1; i < 115; i++)
	{
		if (s_roll == s[i].roll)
		{
			check = true;
			if (s_pass != s[i].pass)
			{
				cout << "\n\n\n\t\t\t\t----------PASSWORD IS INCORRECT----------";
				sleep(2);
				system("cls");
				student();
				break;
			}
		}
	}

	string roll = s_roll.substr(10, 3);

	if (check == true)
	{
		system("cls");
		studentViewAttendance(roll);
	}
	else if (check == false)
	{
		cout << "\n\n\n\t\t\t\t----------NO ACCOUNT WITH SUCH CREDENTIALS----------";
		sleep(2);
		system("cls");
		student();
	}
}

/////////////  STUDENT VIEW ATTENDANCE  /////////////
void studentViewAttendance(string roll)
{
	int ipt;

	cout
		<< "\n\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t||                   SUBJECT LIST                     ||\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n\n";

	for (int i = 1; i < 9; i++)
	{
		cout << "\t\t\t\t" << i << ". " << course[i] << endl;
	}
	cout
		<< "\n\n\t\t\t\t" << "9. BACK"
		<< " \t || \t  10. LOGIN PAGE"
		<< "\n\n\n\t\t\t\tYOUR CHOICE: ";
	cin >> ipt;


	if (ipt == 1 || ipt == 2 || ipt == 3 || ipt == 4 ||
		ipt == 5 || ipt == 6 || ipt == 7 || ipt == 8)
	{
		system("cls");
		findAttendanceLoop(ipt, roll);
	}
	else if (ipt == 9)
	{
		system("cls");
		student();
	}
	else if (ipt == 10)
	{
		system("cls");
		login();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t----------INVALID INPUT----------";
		sleep(2);
		system("cls");
		studentViewAttendance(roll);
	}
}

/////////////  ATTENDANCE LOOP  /////////////
void findAttendanceLoop(int n, string roll)
{
	int class_number;
	int hour;

	ifstream getClassNumber;
	getClassNumber.open("class" + to_string(n) + ".txt");
	getClassNumber >> class_number;

	class_number -= 1;

	cout
		<< "\n\n"
		<< "\t\t\t\t  --------------------------------------------------\n"
		<< "\t\t\t\t-------------------              ---------------------\n"
		<< "\t\t\t\t||                   ATTENDANCE                     ||\n"
		<< "\t\t\t\t-------------------              ---------------------\n"
		<< "\t\t\t\t  --------------------------------------------------\n\n\n"
		<< "\t\t\tDATE\t\tWEEKS\t\tTOTAL HOURS\t\tPRESENT HOURS\n\n";

	for (int i = 0; i < class_number; i++)
	{
		ifstream get_date;
		ifstream get_data;
		get_data.open("data" + roll + "_" + to_string(n) + "_" + to_string(i + 1) + ".txt");
		get_date.open("data" + roll + "_" + to_string(n) + "_" + to_string(i + 1) + "_date" + ".txt");

		get_date >> date;
		cout << "\t\t     " << date << "\t\t" << "WEEK" << i + 1 << "\t\t     " << "3" << "\t\t\t       ";
		get_data >> hour;
		cout << hour << endl;
		get_data.close();
		get_date.close();
	}

	cout << "\n\n\n\n";
	int choice;

	do
	{
		cout
			<< "\n\n\t\t\t\t" << "1. BACK"
			<< " \t || \t  2. LOGIN PAGE"
			<< "\n\n\n\t\t\t\tYOUR CHOICE: ";
		cin >> choice;

		if (choice != 1 && choice != 2)
		{
			cout << "\t\t     INVALID INPUT\n\n";
		}

	} while (choice != 1 && choice != 2);

	if (choice == 1)
	{
		system("cls");
		studentViewAttendance(roll);
	}
	else if (choice == 2)
	{
		system("cls");
		login();
	}
}

/////////////  TEACHER  /////////////
void teacher()
{
	cout
		<< "\n\n\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t-------------------                ---------------------\n"
		<< "\t\t\t\t||                  TEACHER'S MENU                    ||\n"
		<< "\t\t\t\t-------------------                ---------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n\n\n\n\n\n";

	int ipt;
	cout
		<< "\t\t\t\t1. MARK ATTENDANCE         ||        2. VIEW ATTENDANCE\n\n"
		<< "\t\t\t\t3. EDIT ATTENDANCE         ||        4. BACK\n\n\n\n"
		<< "\t\t\t\tEnter An Option: ";
	cin >> ipt;

	switch (ipt)
	{
	case 1:
	{
		system("cls");
		markAttendance();
		break;
	}
	case 2:
	{
		system("cls");
		teacherViewAttendance();
		break;
	}
	case 3:
	{
		system("cls");
		editAttendance();
		break;
	}
	case 4:
	{
		system("cls");
		login();
		break;
	}
	default:
	{
		cout << "\n\n\t\t\t\t\t----------INVALID INPUT----------";
		sleep(2);
		system("cls");
		teacher();
		break;
	}
	}
}

/////////////  MARK ATTENDANCE  /////////////
void markAttendance()
{
	string s_roll = "";
	string space = "";
	int num = 0, class_number = 1;
	string hours;

	cout
		<< "\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t||                   SUBJECT LIST                     ||\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n\n";

	for (int i = 1; i < 9; i++)
	{
		cout << "\t\t\t\t" << i << ". " << course[i] << endl;
	}

	cout
		<< "\n\n\t\t\t\t" << "9. BACK"
		<< " \t || \t  10. LOGIN PAGE"
		<< "\n\n\n\t\t\t\tYOUR CHOICE: ";
	cin >> num;

	if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8)
	{
		system("cls");

		cout
			<< "\n\t\t\t\t  ----------------------------------------------------\n"
			<< "\t\t\t\t--------------------               ---------------------\n"
			<< "\t\t\t\t||                  Mark Attendance                    ||\n"
			<< "\t\t\t\t--------------------               ---------------------\n"
			<< "\t\t\t\t  ----------------------------------------------------\n\n"
			<< "\t\t\t\t   YOU CAN ENTER (0 - 3)\n\n\n";

		ofstream classNumber;
		ifstream getClassNumber;

		getClassNumber.open("class" + to_string(num) + ".txt");
		getClassNumber >> class_number;
		classNumber.open("class" + to_string(num) + ".txt");

		int c_number = class_number;

		for (int i = 1; i < 115; i++)
		{
			int n = 0;
			string zero[3] = { "", "0", "00" };
			string add_zero;

			if (!s[i].name.empty())
			{
				for (int j = c_number; j < c_number + 1; j++)
				{
					if (i < 10)
					{
						add_zero = zero[2];
					}
					if (i > 9 && i < 100)
					{
						add_zero = zero[1];
					}
					if (i > 99)
					{
						add_zero = zero[0];
					}

					ofstream write_date;
					ofstream write_data;
					write_data.open("data" + add_zero + to_string(i) + "_" + to_string(num) + "_" + to_string(c_number) + ".txt");
					cout
						<< "\n\n\t\t\t\t   " << s[i].name << " ("
						<< s[i].roll << ") =" << "\t";
					do
					{
						cin >> s[i].hours[num][c_number];
					} while (s[i].hours[num][c_number] < 0 || s[i].hours[num][c_number] > 3);
					write_data << s[i].hours[num][c_number];
					write_data.close();

					Date();

					write_date.open("data" + add_zero + to_string(i) + "_" + to_string(num) + "_" + to_string(c_number) + "_date" + ".txt");
					write_date << date;
					write_date.close();
				}
			}

			class_number += 1;
			classNumber << class_number;
			getClassNumber.close();
			classNumber.close();
		}

		cout << "\n\n\n\n";
		int choice;

		do
		{
			cout
				<< "\n\n\t\t\t\t" << "1. BACK"
				<< " \t || \t  2. LOGIN PAGE"
				<< "\n\n\n\t\t\t\tYOUR CHOICE: ";
			cin >> choice;

			if (choice != 1 && choice != 2)
			{
				cout << "\n\t\t\t\t   INVALID INPUT\n\n";
			}

		} while (choice != 1 && choice != 2);

		if (choice == 1)
		{
			system("cls");
			teacher();
		}
		else if (choice == 2)
		{
			system("cls");
			login();
		}
	}
	else if (num == 9)
	{
		system("cls");
		teacher();
	}
	else if (num == 10)
	{
		system("cls");
		login();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t----------INVALID INPUT----------";
		sleep(2);
		system("cls");
		markAttendance();
	}
}

/////////////  TEACHER VIEW ATTENDANCE  /////////////
void teacherViewAttendance()
{
	int num = 0, class_number = 0;
	int hour = 0, t_hours = 0, p_hours = 0;
	double percent = 0;
	string zero[3] = { "", "0", "00" };
	string add_zero;

	string below_75_names[115] = {};
	int total_hours[115] = {};
	int total_present_hours[115] = {};
	double percentage[115] = {};

	ifstream getClassNumber;

	cout
		<< "\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t||                   SUBJECT LIST                     ||\n"
		<< "\t\t\t\t--------------------              ----------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n";

	for (int i = 1; i < 9; i++)
	{
		cout << "\t\t\t\t" << i << ". " << course[i] << endl;
	}
	cout
		<< "\n\n\t\t\t\t" << "9. BACK"
		<< " \t || \t  10. LOGIN PAGE"
		<< "\n\n\n\t\t\t\tYOUR CHOICE: ";
	cin >> num;

	if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8)
	{
		system("cls");

		cout
			<< "\n"
			<< "\t\t\t\t  ----------------------------------------------------\n"
			<< "\t\t\t\t--------------------              ----------------------\n"
			<< "\t\t\t\t||                    ATTENDANCE                      ||\n"
			<< "\t\t\t\t--------------------              ----------------------\n"
			<< "\t\t\t\t  ----------------------------------------------------\n\n\n"
			<< "\t\t    NAME OF STUDENTS\t\t    TOTAL PRESENT HOURS\t\t    TOTAL HOURS\n"
			<< "\t\t  ______________________\t   _____________________\t  _______________\n\n";

		getClassNumber.open("class" + to_string(num) + ".txt");
		getClassNumber >> class_number;

		int c_number = class_number;

		for (int i = 1; i < 115; i++)
		{
			if (!s[i].name.empty())
			{
				for (int j = 0; j < 1; j++)
				{
					for (int k = 1; k < class_number; k++)
					{
						if (i < 10)
						{
							add_zero = zero[2];
						}
						if (i > 9 && i < 100)
						{
							add_zero = zero[1];
						}
						if (i > 99)
						{
							add_zero = zero[0];
						}

						p_hours = 0;

						for (int m = 1; m < class_number; m++)
						{
							ifstream get_data;
							get_data.open("data" + add_zero + to_string(i) + "_" + to_string(num) + "_" + to_string(m) + ".txt");
							get_data >> hour;
							p_hours += hour;
							get_data.close();
							t_hours = 3 * (class_number - 1);
						}
					}

					cout << "\t\t  " << s[i].name << "\t\t     " << p_hours << "\t\t\t\t " << t_hours << endl;

					percent = ((double)p_hours / (double)t_hours) * 100;

					if (percent < 75)
					{
						percentage[i] = percent;
						total_present_hours[i] = p_hours;
						total_hours[i] = t_hours;
						below_75_names[i] = s[i].name;
					}
				}
			}
		}

		cout << "\n\n\n\n";
		int choice;

		do
		{
			cout
				<< "\t\t  1. LIST OF STUDENTS WITH BELOW 75% ATTENDANCE\n"
				<< "\t\t  2. BACK\n"
				<< "\t\t  3. LOGIN PAGE\n"
				<< "\t\t  YOUR CHOICE: ";
			cin >> choice;

			if (choice != 1 && choice != 2 && choice != 3)
			{
				cout << "\t\t  INVALID INPUT\n\n";
			}

		} while (choice != 1 && choice != 2 && choice != 3);

		if (choice == 1)
		{
			system("cls");

			cout
				<< "\n"
				<< "\t\t\t\t  -------------------------------------------------------------\n"
				<< "\t\t\t\t--------------------                       ----------------------\n"
				<< "\t\t\t\t||                    BELOW 75% ATTENDANCE                      ||\n"
				<< "\t\t\t\t--------------------                       ----------------------\n"
				<< "\t\t\t\t  -------------------------------------------------------------\n\n\n"
				<< "\t\t\t         NAME OF STUDENTS\t\t\t    TOTAL PERCENTAGE\n"
				<< "\t\t\t        __________________\t\t\t   __________________\n\n";

			for (int i = 1; i < 115; i++)
			{
				if (!below_75_names[i].empty())
				{
					cout << "\t\t\t\t" << below_75_names[i] << "\t\t\t  " << fixed << setprecision(2) << percentage[i] << endl;
				}
			}

			cout << "\n\n\n\n";
			int option;

			do
			{
				cout
					<< "\t\t\t\t1. BACK\n"
					<< "\t\t\t\t2. LOGIN PAGE\n"
					<< "\t\t\t\tYOUR CHOICE: ";
				cin >> option;

				if (option != 1 && option != 2)
				{
					cout << "\t\t\t\tINVALID INPUT\n\n";
				}

			} while (option != 1 && option != 2);

			if (option == 1)
			{
				system("cls");
				teacherViewAttendance();
			}
			else if (option == 2)
			{
				system("cls");
				login();
			}
		}
		else if (choice == 2)
		{
			system("cls");
			teacher();
		}
		else if (choice == 3)
		{
			system("cls");
			login();
		}
	}
	else if (num == 9)
	{
		system("cls");
		teacher();
	}
	else if (num == 10)
	{
		system("cls");
		login();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t----------INVALID INPUT----------";
		sleep(2);
		system("cls");
		teacherViewAttendance();
	}
}
/////////////  EDIT ATTENDANCE  /////////////
void editAttendance()
{
	int num, class_number, hours;
	string student;
	char opt;

	cout
		<< "\n"
		<< "\t\t\t\t  ----------------------------------------------------\n"
		<< "\t\t\t\t--------------------                --------------------\n"
		<< "\t\t\t\t||                   EDIT ATTENDANCE                   ||\n"
		<< "\t\t\t\t--------------------                --------------------\n"
		<< "\t\t\t\t  ----------------------------------------------------\n\n\n";

	for (int i = 1; i < 9; i++)
	{
		cout << "\t\t\t\t" << i << ". " << course[i] << endl;
	}

	do
	{
		cout << "\n\t\t\t\tSUBJECT: ";
		cin >> num;

		cout << "\n\t\t\t\tENTER WEEK NUMBER: ";
		cin >> class_number;

		cout << "\n\t\t\t\tENTER STUDENT ENROLLMENT NUMBER: ";
		cin >> student;

		string roll = student.substr(10, 3);

		do
		{
			cout << "\n\t\t\t\tUPDATE ATTENDANCE: ";
			cin >> hours;

			if (hours < 0 || hours > 3)
			{
				cout << "\t\t\t\tINVALID INPUT\n";
			}
		} while (hours < 0 || hours > 3);

		ofstream update_attendance;
		update_attendance.open("data" + roll + "_" + to_string(num) + "_" + to_string(class_number) + ".txt", ios::trunc);
		update_attendance << hours;
		update_attendance.close();

		cout << "\n\t\t\t\tDO YOU WANT TO UPDATE ANOTHER ATTENDANCE? (Y / n)\n\t\t\t\t";
		cin >> opt;
	} while (opt == 'Y' || opt == 'y');

	cout << "\n\n\t\t\t\tATTENDANCE UPDATED";
}

/////////////  CHECK INDEX FOR NAMES  /////////////
int checkIndex(int loop_int)
{
	int return_int = 0;

	if (loop_int >= 93 && loop_int <= 99)
	{
		return_int = loop_int - 50;
	}
	if (loop_int >= 106 && loop_int <= 108)
	{
		return_int = loop_int - 56;
	}
	if (loop_int >= 112 && loop_int <= 114)
	{
		return_int = loop_int - 59;
	}

	return return_int;
}

/////////////  ADD SPACE  /////////////
void addSpace(int n, string str)
{
	if (n == 2)
	{
		str = "\t";
	}
	else if (n == 6)
	{
		str = "\t\t\t";
	}
	else
	{
		str = "\t\t";
	}
	cout << str;
}

/////////////  SLEEP  /////////////
void sleep(int sec)
{
	this_thread::sleep_for(std::chrono::seconds(sec));
}

void Date()
{
	int day, month, year;

	time_t now;
	time(&now);
	struct tm* local = localtime(&now);

	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	string _day = to_string(day);
	string _month = to_string(month);
	string _year = to_string(year);

	if (month < 10)
	{
		date = _day + "/0" + _month + "/" + _year;
	}
	else
	{
		date = _day + "/" + _month + "/" + _year;
	}
}