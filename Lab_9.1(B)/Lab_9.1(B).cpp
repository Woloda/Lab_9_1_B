#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { КН, ІФ, МЕ, ФІ, ТН };

string s_special[] = { "Комп’ютерні науки",
					   "Інформатика",
					   "Метематика та економіка",
					   "Фізика та інформатика",
					   "Трудове навчання" };

struct student
{
	string prizv;
	int kurs;
	Special specialization;
	int phisuka;
	int matematic;
	union
	{
		int programing;
		int chuslo_metod;
		int pedahohica;
	};
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int kil_student;
	cout << "Введіть кількість студентів: "; cin >> kil_student;
	cout << endl;
	student* s = new student[kil_student];

	Create(s, kil_student);
	cout << endl;
	Print(s, kil_student);
	cout << endl;

	cout << "Процент студентів, які вчаться без трійок (на “відмінно” і “добре”): " << setprecision(2) << find_prozent(s, kil_student) << "%" << endl << endl;

	cout << "Прізвища студентів, які отримали з фізики оцінки '5' або '4': " << endl;
	if (find_studend(s, kil_student));
	else
		cout << "Прізвища студентів, які отримали з фізики оцінки '5' або '4' не знайшлося: " << endl << endl;

	delete[] s;
}

void Create(student* s, const int kilkist)
{
	int kurs, special;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "студент № " << i + 1 << endl;

		cin.get();
		cin.sync();

		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Метематика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): "; cin >> special;
		s[i].specialization = (Special)special;
		cout << "  оцінка з фізики: "; cin >> s[i].phisuka;
		cout << "  оцінка з математики: "; cin >> s[i].matematic;
		switch (special)
		{
		case 0:
			cout << "  оцінка з програмування: "; cin >> s[i].programing;
			break;
		case 1:
			cout << "  оцінка з чисельних методів: "; cin >> s[i].chuslo_metod;
			break;
		case 2:
		case 3:
		case 4:
			cout << "  оцінка з педагогіки: "; cin >> s[i].pedahohica;
			break;
		default:
			cout << "Ви ввели помилкове значення! " << endl;
		}
		cout << endl;
	}
}

void Print(student* s, const int kilkist)
{
	cout << "============================================================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність           | Фізика | Математика  | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(23) << left << s_special[s[i].specialization] << " "
			<< "| " << setw(4) << right << s[i].phisuka << "   "
			<< "| " << setw(6) << right << s[i].matematic << "      ";
		switch (s[i].specialization)
		{
		case 0:
			cout << "| " << setw(7) << right << s[i].programing << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 1:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].chuslo_metod << "       |" << setw(13) << "|" << endl;
			break;
		case 2:
		case 3:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedahohica << "     |" << endl;
			break;
		}
	}
	cout << "============================================================================================================================" << endl;
}

double find_prozent(student* s, const int kilkist)
{
	int k = 0;
	for (int i = 0; i < kilkist; i++)
	{
		if (s[i].phisuka > 3 && s[i].matematic > 3 && s[i].programing > 3 && s[i].chuslo_metod > 3 && s[i].pedahohica > 3)
			k++;
	}
	return 100.0 * k / kilkist;
}

int find_studend(student* s, const int kilkist)
{
	int l = 0;
	for (int i = 0; i < kilkist; i++)
		if (s[i].phisuka > 3)
		{
			cout << "№ " << i + 1 << " " << s[i].prizv << " --- з фізики " << s[i].phisuka << endl;
			l = 1;
		}

	return l;
}