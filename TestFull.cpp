#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <regex>
#include <ctime>
#include <fstream>
#include <set>
#define COUNTRY 11
#define GROUP 10
using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

FILE* pf_country;
FILE* pf_gr;
FILE* pf_art;
FILE* pf;
FILE* pf_file;

struct Login
{
	char log[17];
	char pass[10];
};
struct Data {
	char article[8];
	int am;
	int otv_countrys;
	time_t dat1;
	float pr;
	
};
struct Data_article {
	char article[8];
	int otv;
	char name[12];
};

void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);
void Pause();
void Loading();
void VvodCountry(const char* file_country);
size_t CountRecCountry(const char* file_country);
void VvodGr(const char* file_gr);
size_t CountRecGr(const char* file_gr);
void VyvodCountry(const char* file_country);
void VyvodGr(const char* file_gr);
bool IdentArt(const char* file_art, Data_article b);
void vvodart(const char* file_gr, const char* file_art);
void vyvodart(const char* file_art, const char* file_gr);
size_t CountRecArt(const char* file_art);
size_t CountRecFull(const char* file_full);
void vyvod(const char* file_art, const char* file_full, const char* file_country, const char* file_gr);
int vvodcountry(const char* file_coutnry);
void vvod(const char* file_gr, const char* file_art, const char* file_full, const char* file_country);
bool IdentCountry(const char* file_country,char b[COUNTRY]);
bool IdentGr(const char* file_gr, char b[GROUP]);
bool IdentFull(const char* file_full, Data a);
int CheckFile(const char* file_full);
void Check(const char* file_country, const char* file_art, const char* file_gr,const char*file_name);
void line_art();
void shapka_art();
void EditRecField(const char* file_full, const char* file_art, const char* file_country, const char* file_gr);
void shapka_edit();
void line_edit();
void EditRecCountry(const char* file_country);
void EditRecGroup(const char* file_gr);
void EditRecArt(const char* file_art,const char*file_gr);
void MainMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
size_t CountRecLog(const char* file_name);
void AdminMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void UserMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void VvodMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void VyvodMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void EditMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void DelMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void SortMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void RequestMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name);
void DeleteRecGroup(const char* file_gr, const char* file_full,const char*file_art,const char*file_country);
void DeleteRec(const char* file_full, const char* file_art, const char*file_gr, const char*country);
void SortGr(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void SortCountry(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void vart(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void searchgroup(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void top_prices(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void kiltovar(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void searchcountry(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void searchmonth(const char* file_full, const char* file_art, const char* file_gr, const char* file_country);
void createCSV(const char* file_art, const char* file_full, const char* file_gr, const char* file_country);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* file_country = "Country.dat";
	const char* file_gr = "Group.dat";
	const char* file_art = "Art.dat";
	const char* file_full = "MusicShop.dat";
	const char* file_name = "Login.dat";
	if (!CheckFile(file_full)) {
		return 0;
	}
	Check(file_country, file_art, file_gr,file_name);
	MainMenu(file_country, file_gr, file_art, file_full, file_name);
}
void Pause() {
	cout << "Для продовження натисніть будь-яку клавішу";
	_getch();
}
void Loading() {
	system("COLOR 0e");
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t";
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;
	for (size_t i = 0; i < 25; i++)
	{
		cout << (char)bar1;
	}
	cout << "\r";
	cout << "\t\t\t\t\t\t\t";
	for (size_t i = 0; i < 25; i++)
	{
		cout << (char)bar2;
		Sleep(150);
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void ConsoleCursorVisible(bool show, short size) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void GoToXY(short x, short y) {
	SetConsoleCursorPosition(hStdOut, { x, y });
}
int CheckFile(const char* file_full)
{
	bool flag_1;
	regex reg_num("[0,1]");
	cmatch result;
	int ot = -1;
	fopen_s(&pf, file_full, "rb");
	if (!pf) {
		do {
			flag_1 = false;
			cout << "Немає файлу! Чи хочете Ви його створити (так - 1, ні - 0): ";
			string ot_1 = to_string(ot);
			getline(cin, ot_1);
			if (regex_match(ot_1.c_str(), result, reg_num))
			{
				ot = stoi(ot_1);
				flag_1 = true;
			}
			else {
				cout << "Введіть коректно запис\n";
			}
		} while (!flag_1);
		if (ot) {
			fopen_s(&pf, file_full, "wb");
			Loading();
			fclose(pf);
			ConsoleCursorVisible(false, 100);
		}
		else {
			cout << "Дуже шкода, що Ви не хочете створювати файл. Бажаємо Вам успіхів!" << endl;
		}
	}
	else
	{
		fclose(pf);
	}
	return ot;
}
void Check(const char* file_country, const char*file_art, const char*file_gr,const char*file_name)
{
	fopen_s(&pf_country, file_country, "rb");
	fopen_s(&pf_gr, file_gr, "rb");
	fopen_s(&pf_art, file_art, "rb");
	fopen_s(&pf_file, file_name, "rb");
	if (!pf_country) {
		fopen_s(&pf_country, file_country, "wb");
		fclose(pf_country);
	}
	else {
		fclose(pf_country);
	}
	if (!pf_gr) {
		fopen_s(&pf_gr, file_gr, "wb");
		fclose(pf_gr);
	}
	else {
		fclose(pf_gr);
	}
	if (!pf_art) {
		fopen_s(&pf_art, file_art, "wb");
		fclose(pf_art);
	}
	else {
		fclose(pf_art);
	}
	if(!pf_file) {
		fopen_s(&pf_file, file_name, "wb");
		fclose(pf_file);
	}
	else {
	fclose(pf_file);
	}
}
bool IdentCountry(const char* file_country,char b[COUNTRY]) {
	char c[COUNTRY];
	bool fl = false;
	fopen_s(&pf_country, file_country, "a+b");
	while (fread(&c, COUNTRY, 1, pf_country))
	{
		if (strcmp(b, c) == 0)
		{
			cout << "Таку країну Ви вже вводити, введіть нову" << endl;
			fl = true;
			break;
		}
	}
	fclose(pf_country);
	return fl;
}
bool IdentGr(const char* file_gr, char b[GROUP]) {
	char c[GROUP];
	bool fl = false;
	fopen_s(&pf_gr, file_gr, "a+b");
	while (fread(&c, GROUP, 1, pf_gr))
	{
		if (strcmp(b, c) == 0)
		{
			cout << "Таку групу Ви вже вводити, введіть нову" << endl;
			fl = true;
			break;
		}
	}
	fclose(pf_gr);
	return fl;
}
bool days(int year, int mon, string day_1) {
	int numDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool flag = false;
	regex regular("([1-9]|1[0-9]|2[0-9]|3[0-1])");
	cmatch result;
	if (!regex_match(day_1.c_str(), result, regular))
	{
		cout << "Введіть коректний день" << endl;
	}
	else
	{
		int d = atoi(day_1.c_str());
		if (year % 4 == 0 && mon == 2) {
			if (d <= (numDays[mon - 1] + 1))
			{
				flag = true;
			}
			else {
				cout << "У високосному році у лютому 29 днів\n";
			}
		}
		else
		{
			if (d <= numDays[mon - 1])
			{
				flag = true;
			}
			else {
				cout << "У не високосному році у лютому 28 днів\n";
			}
		}
	}
	return flag;
}
time_t func_vvod_date() {
	regex regular_mon("([1-9]|1[0-2])");
	regex regular_year("(202[0-3])");
	cmatch result;
	bool flag;
	time_t ts_data;
	struct tm t_data;
	string day_1, mon_1, year_1;
	ts_data = time(NULL);
	localtime_s(&t_data, &ts_data);
	do {
		flag = false;
		cout << "\nВведіть рік: (з 2020 по 2023): ";
		getline(cin, year_1);
		if (regex_match(year_1.c_str(), result, regular_year))
		{
			flag = true;
		}
		else {
			cout << "Введіть рік з 2020 по 2023\n";
		}
	} while (!flag);
	int year = stoi(year_1, 0, GROUP);
	do {
		flag = false;
		cout << "\nВведіть місяць: ";
		getline(cin, mon_1);
		if (regex_match(mon_1.c_str(), result, regular_mon))
		{
			flag = true;
		}
		else {
			cout << "Введіть коректний місяць\n";
		}
	} while (!flag);
	int mon = stoi(mon_1, 0, GROUP);
	do {
		flag = false;
		cout << "\nВведіть день: ";
		getline(cin, day_1);
		flag = days(year, mon, day_1);
	} while (!flag);
	int day = stoi(day_1, 0, GROUP);
	t_data.tm_mday = day;
	t_data.tm_mon = mon - 1;
	t_data.tm_year = year - 1900;
	ts_data = mktime(&t_data);
	return ts_data;
}
void line() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void shapka() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3       \xB3            \xB3           \xB3          \xB3            \xB3\n";
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  №  ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Артикул ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "    Назва    ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Група   ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Кіль- ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Країна   ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Дата    ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Ціна   ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  Вартість  ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " кість ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  виробник  ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " закупівлі ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3          \xB3            \xB3\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3       \xB3            \xB3           \xB3          \xB3            \xB3\n";
	cout << "\xC3\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n";
}
void VvodCountry(const char* file_country) {
	bool flag_1;
	char d;
	char b[COUNTRY];
	regex reg_country("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,10}");
	regex reg_d("[н,т]");
	cmatch result;
	do {
			do {
				flag_1 = false;
				string country_1;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nКраїна-виробник: (можна вводити тільки українські букви - максимальна кількість символів 10) ";
				getline(cin, country_1);
				if (regex_match(country_1.c_str(), result, reg_country))
				{
					strcpy_s(b, country_1.c_str());
					flag_1 = true;
				}
				else
				{
					cout << "Можна вводити тільки українські букви (максимальна кількість символів 10)";
				}
			} while (!flag_1);
			if (!IdentCountry(file_country,b))
			{
				fopen_s(&pf_country, file_country, "a+b");
				fwrite(&b, COUNTRY, 1, pf_country);
				fclose(pf_country);
			}
			bool flag;
			do {
				flag = false;
				cout << "Хочете продовжити? (т/н) ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
			} while (!flag);
	} while (d == 'т');
}
bool IdentFull(const char* file_full,Data a) {
	tm dat_1;
	char str[9];
	localtime_s(&dat_1, &a.dat1);
	strftime(str, 9, "%d.%m.%y", &dat_1);
	Data c;
	bool fl = false;
	fopen_s(&pf, file_full, "a+b");
	while (fread(&c, sizeof(Data), 1, pf))
	{
		tm dat_1;
		char str_1[9];
		localtime_s(&dat_1, &c.dat1);
		strftime(str_1, 9, "%d.%m.%y", &dat_1);
		if (strcmp(a.article, c.article) == 0 && a.am == c.am && a.otv_countrys == c.otv_countrys && strcmp(str_1,str)==0 && a.pr == c.pr)
		{
			cout << "Такий інструмент Ви вже вводили, введіть новий" << endl;
			fl = true;
			Pause();
			break;
		}
	}
	fclose(pf);
	return fl;
}
void VvodGr(const char* file_gr) {
	bool flag_1;
	char d;
	char b[GROUP];
	regex reg_gr("[а-щ-ьюяїієґ]{1,9}");
	regex reg_d("[н,т]");
	regex reg_otv("[1-9]{1}|[1][0]");
	cmatch result;
	cout << "Всього можна ввести 10 груп";
	do {
		int k = CountRecGr(file_gr);
		if (k != 10) {
			do {
				flag_1 = false;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nГрупа інструментів: (можна вводити тільки українські букви - максимальна кількість символів 9) ";
				string gr_1;
				getline(cin, gr_1);
				if (regex_match(gr_1.c_str(), result, reg_gr))
				{
					strcpy_s(b, gr_1.c_str());
					flag_1 = true;
				}
				else {
					cout << "Можна вводити тільки маленькі українські букви (максимальна кількість символів 9)";
				}
			} while (!flag_1);
			if (!IdentGr(file_gr, b))
			{
				fopen_s(&pf_gr, file_gr, "a+b");
				fwrite(&b, GROUP, 1, pf_gr);
				fclose(pf_gr);
			}
			bool flag;
			do {
				flag = false;
				cout << "Хочете продовжити? (т/н) ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
			} while (!flag);
		}
		else {
			cout << "\nВибачте, Ви вже ввели 10 груп\n";
			break;
		}
	} while (d == 'т');
}
size_t CountRecCountry(const char* file_country) {
	fopen_s(&pf_country, file_country, "rb");
	fseek(pf_country, 0, SEEK_END);
	size_t k = ftell(pf_country) / 11;
	fclose(pf_country);
	return k;
}
size_t CountRecGr(const char* file_gr) {
	fopen_s(&pf_gr, file_gr, "rb");
	fseek(pf_gr, 0, SEEK_END);
	size_t k = ftell(pf_gr) / 10;
	fclose(pf_gr);
	return k;
}
size_t CountRecArt(const char* file_art) {
	fopen_s(&pf_art, file_art, "rb");
	fseek(pf_art, 0, SEEK_END);
	size_t k = ftell(pf_art) / sizeof(Data_article);
	fclose(pf_art);
	return k;
}
size_t CountRecFull(const char* file_full) {
	fopen_s(&pf, file_full, "rb");
	fseek(pf, 0, SEEK_END);
	size_t k = ftell(pf) / sizeof(Data);
	fclose(pf);
	return k;
}
void VyvodCountry(const char* file_country) {
	char b[COUNTRY];
	int i = 0;
	cout << "Список всіх введених країн: \n";
	fopen_s(&pf_country, file_country, "rb");
	while (fread(&b,11, 1, pf_country))
	{
		cout << i + 1 << " " << b << endl;
		cout << "<-------------------------------------->\n";
		i++;
	}
	fclose(pf_country);
}
void VyvodGr(const char* file_gr) {
	char b[GROUP];
	int i = 0;
	cout << "Список всіх введених груп: \n";
	fopen_s(&pf_gr, file_gr, "rb");
	while (fread(&b, GROUP, 1, pf_gr))
	{
		cout << i + 1 << " " << b << endl;
		cout << "<-------------------------------------->\n";
		i++;
	}
	fclose(pf_gr);
}
void vvodart(const char* file_gr, const char* file_art) {
	system("color 0F");
	regex reg_d("[н,т]");
	regex reg_otv("[1-9]+|[1-9]+[0]+");;
	cmatch result;
	Data_article b, c,a;
	char d;
	bool flag_1;
	system("CLS");
	regex reg_name("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,11}");
	regex reg_gr("[1-9]|[1][0]");
	do {
		do {
			flag_1 = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nНазва інструменту: (можна вводити тільки українські букви - максимальна кількість символів 11) ";
			string name_1;
			getline(cin, name_1);
			if (regex_match(name_1.c_str(), result, reg_name))
			{
				strcpy_s(b.name, name_1.c_str());
				flag_1 = true;
			}
			else {
				cout << "Можна вводити тільки українські букви (максимальна кількість символів 11)";
			}

		} while (!flag_1);
		bool ident_1 = false;
		if (IdentArt(file_art, b)) {
			ident_1 = true;
		}
		if (!ident_1) 
		{
			int otv_art;
			int i = 0;
			char cc[GROUP];
			size_t k = CountRecGr(file_gr);
			cout << "Група:\n";
			fopen_s(&pf_gr, file_gr, "rb");
			while (fread(&cc, GROUP, 1, pf_gr)) {
				cout << ++i << " " << cc << "\n";
			}
			fclose(pf_gr);
			do {
				flag_1 = false;
				string otv_1;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Номер (можна вводити від 1 до " << k << "): ";
				getline(cin, otv_1);
				otv_art = atoi(otv_1.c_str());
				if (regex_match(otv_1.c_str(), result, reg_otv))
				{
					if (otv_art >= 1 && otv_art <= k)
					{
						flag_1 = true;
					}
					else
					{
						cout << "Можна вводити тільки цифри від 1 до " << k << "\n";
					}
				}
				else
				{
					cout << "Можна вводити тільки цифри від 1 до "<<k<<"\n";
				}
			} while (!flag_1);
			size_t k_2 = CountRecArt(file_art);
			string article_1, article_a, article_c;
			int art_2 = 1;
			fopen_s(&pf_art, file_art, "r+b");
			bool f = true;
			int p;
			while (f)
			{
				f = false;
				p = 1;
				fread(&a, sizeof(Data_article), 1, pf_art);
				article_a = a.article;
				int jj = article_a.find("-");
				article_a = article_a.substr(jj + 1, 2);
				int newnum_a = atoi(article_a.c_str());
				while(fread(&c, sizeof(Data_article), 1, pf_art))
				{
					p++;
						article_c = c.article;
						int jj = article_c.find("-");
						article_c = article_c.substr(jj + 1, 2);
						int newnum_c = stoi(article_c);
						if (newnum_a > newnum_c)
							{
						fseek(pf_art, (p - 2) * sizeof(Data_article), SEEK_SET);
						fwrite(&c, sizeof(Data_article), 1, pf_art);
						fseek(pf_art, (p-1) * sizeof(Data_article), SEEK_SET);
						fwrite(&a, sizeof(Data_article), 1, pf_art);
						f = true;
							}
						else
						{
							a = c;
							newnum_a = newnum_c;
						}
					fseek(pf_art, p * sizeof(Data_article), SEEK_SET);
				}
				rewind(pf_art);
			}
			fclose(pf_art);
			bool fl = false;
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&c, sizeof(Data_article), 1, pf_art))
			{
				if (otv_art == c.otv)
				{
					article_1 = c.article;
					fl = true;
				}
			}
			fclose(pf_art);
			int newnum;
			if (fl)
			{
				int j = article_1.find("-");
				article_1 = article_1.substr(j + 1, 2);
				newnum = stoi(article_1);
				newnum++;
			}
			else
				newnum = 1;
			string art_3 = to_string(newnum);
			string otv_1 = to_string(otv_art);
			article_1 = otv_1 + "-" + art_3;
			strcpy_s(b.article, article_1.c_str());
			b.otv = otv_art;
			fopen_s(&pf_art, file_art, "a+b");
			fwrite(&b, sizeof(Data_article), 1, pf_art);
			fclose(pf_art);
		}
		bool flag;
		do {
			flag = false;
			cout << "Хочете продовжити? (т/н) ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (d=='т');
}
int vvodcountry(const char* file_country) {
	system("color 0F");
	regex reg_d("[н,т]");
	regex reg_otv("[1-9]+|[1-9]+[0]+");
	cmatch result;
	char c[COUNTRY];
	Data a;
	char d;
	bool flag_1;
	int otv_country;
	int i = 0;
	size_t k = CountRecCountry(file_country);
	cout << "Країни:\n";
	fopen_s(&pf_country, file_country, "rb");
	while (fread(&c, COUNTRY, 1, pf_country)) {
		cout << i + 1 << " " << c << "\n";
		i++;
	}
	fclose(pf_country);
	do {
		int k = CountRecCountry(file_country);
		flag_1 = false;
		string otv_1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Номер (можна вводити від 1 до "<<k<<": ";
		getline(cin, otv_1);
		otv_country = atoi(otv_1.c_str());
		if (regex_match(otv_1.c_str(), result, reg_otv))
		{
			if (otv_country >= 1 && otv_country <= k)
			{
				flag_1 = true;
			}
			else
			{
				cout << "Немає такого запису\n";
			}
		}
		else
		{
			cout << "Можна вводити тільки цифри від 1 до "<<k<<"\n";
		}
	} while (!flag_1);
	return otv_country;
}
bool IdentArt(const char* file_art, Data_article b) {
	Data_article c;
	bool fl = false;
	fopen_s(&pf_art, file_art, "a+b");
	while (fread(&c, sizeof(Data_article), 1, pf_art))
	{
		if (strcmp(b.name, c.name) == 0)
		{
			cout << "Такий інструмент Ви вже вводили" << endl;
			fl = true;
			break;
		}
	}
	fclose(pf_art);
	return fl;
}
void vyvodart(const char* file_art, const char* file_gr) {
	Data_article b;
	char c[GROUP];
	int i=1;
	fopen_s(&pf_art, file_art, "rb");
	while (fread(&b, sizeof(Data_article), 1, pf_art))
	{
		fopen_s(&pf_gr, file_gr, "rb");
		fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
		fread(&c, GROUP, 1, pf_gr);
		fclose(pf_gr);
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout << "\xB3 " << setw(3) << right << i++ << " \xB3 " << setw(7) << right;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << b.article;
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout << " \xB3 " << setw(11) << left;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << b.name;
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout << " \xB3" << " " << setw(9) << left;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << c;
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout<<" \xB3\n";
	}
	fclose(pf_art);
}
void vvod(const char* file_gr, const char* file_art, const char* file_full, const char* file_country) {
	Data a;
	char d;
	bool flag_1;
	int k = CountRecArt(file_art);
	int k_1 = CountRecCountry(file_country);
	do {
		system("CLS");
		regex reg_am("[1-9]{1}|[1-9]{1}[0-9]{1}|[1]{1}[0]{2}");
		regex reg_pr_1("[1-9][0-9]{3}|[1-4][0-9]{4}|[5][0]{4}");
		regex reg_pr_2("[1-9][0-9]{3}[.]([0-9]){1,2}|[1-4][0-9]{4}[.]([0-9]){1,2}");
		regex reg_d("[н,т]");
		regex reg_otv("[1-9]+|[1-9]+[0]+");
		cmatch result;
		Data_article b;
		int num;
		do {
			flag_1 = false;
			string num_1;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			int i = 0;
			fopen_s(&pf_art, file_art, "rb");
			cout << "\n";
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				cout << ++i << " - " << b.name << "\n";
			}
			cout << "Введіть номер інструменту (можна вводити від 1 до " << k << "): ";
			getline(cin, num_1);
			num = atoi(num_1.c_str());
			if (regex_match(num_1.c_str(), result, reg_otv))
			{
				if (num >= 1 && num <= k)
				{
					flag_1 = true;
				}
				else
				{
					cout << "Можна вводити тільки цифри від 1 до " << k << "\n";
				}
			}
			else
			{
				cout << "Можна вводити тільки цифри від 1 до " << k << "\n";
			}
		} while (!flag_1);
		rewind(pf_art);
		fseek(pf_art, (num - 1) * sizeof(Data_article), SEEK_SET);
		fread(&b, sizeof(Data_article), 1, pf_art);		
		strcpy_s(a.article, 6, b.article);
		fclose(pf_art);
		char c[COUNTRY];
		int num_country;
		do {
			int i = 0;
			flag_1 = false;
			string num_1;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			fopen_s(&pf_country, file_country, "rb");
			cout << "\n";
			while (fread(&c, COUNTRY, 1, pf_country))
			{
				cout << ++i << " - " << c << "\n";
			}
			fclose(pf_art);
			cout << "Введіть номер країни (можна вводити від 1 до " << k_1 << "): ";
			getline(cin, num_1);
			num_country = atoi(num_1.c_str());
			if (regex_match(num_1.c_str(), result, reg_otv))
			{
				if (num_country >= 1 && num_country <= k_1)
				{
					flag_1 = true;
				}
				else
				{
					cout << "Можна вводити тільки цифри від 1 до " << k_1 << "\n";
				}
			}
			else
			{
				cout << "Можна вводити тільки цифри від 1 до " << k_1 << "\n";
			}
		} while (!flag_1);
		do {
			flag_1 = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			string am_1;
			cout << "\nКількіть: (можна вводити з 1 до 100) ";
			getline(cin, am_1);
			if (regex_match(am_1.c_str(), result, reg_am))
			{
				a.am = stoi(am_1);
				flag_1 = true;
			}
			else {
				cout << "Можна вводити тільки цифри (діапазон: 1-100)\n";
			}
		} while (!flag_1);
			a.otv_countrys = num_country;
			a.dat1 = func_vvod_date();
			do {
				flag_1 = false;
				string pr_1;
				cout << "\nЦіна: (можна вводити з 1000-50000 як ціле, так і неціле) ";
				getline(cin, pr_1);
				if (regex_match(pr_1.c_str(), result, reg_pr_1) || regex_match(pr_1.c_str(), result, reg_pr_2))
				{
					a.pr = strtof(pr_1.c_str(), nullptr);
					flag_1 = true;
				}
				else {
					cout << "Можна вводити тільки цифри (діапазон: 1000-50000, приклад: 1000.99 або 1000)\n";
				}
			} while (!flag_1);
			if (!IdentFull(file_full, a)) {
				fopen_s(&pf, file_full, "a+b");
				fwrite(&a, sizeof(Data), 1, pf);
				fclose(pf);
			}
		bool flag;
		do {
			flag = false;
			cout << "Хочете продовжити? (т/н) ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (d == 'т');
}
void vyvod(const char* file_art, const char* file_full, const char* file_country, const char* file_gr) {
	Data a;
	Data_article b;
	int i = 1;
	fopen_s(&pf, file_full, "rb");
	char country_name[COUNTRY];
	while (fread(&a, sizeof(Data), 1, pf)) {
		tm dat_1;
		char str[9];
		localtime_s(&dat_1, &a.dat1);
		strftime(str, 9, "%d.%m.%y", &dat_1);
		fopen_s(&pf_art, file_art, "rb");
		while (fread(&b, sizeof(Data_article), 1, pf_art))
		{
			if (strcmp(a.article, b.article) == 0)
			{
				char c[GROUP], d[COUNTRY];
				fopen_s(&pf_gr, file_gr, "rb");
				fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
				fread(&c, GROUP, 1, pf_gr);
				fclose(pf_gr);
				fopen_s(&pf_country, file_country, "rb");
				fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
				fread(&d, COUNTRY, 1, pf_country);
				fclose(pf_country);
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << a.article;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3 " << setw(11) << left;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << b.name;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3" << " " << setw(9) << left;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << c;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3  " << setw(3) << right;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << (int)a.am;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "  \xB3 " << setw(10) << left;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout <<d;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3  " << setw(8) << right;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << str;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3 " << setw(8) << right;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << fixed << setprecision(2) << (float)a.pr;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3 " << setw(10) << right;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << (float)a.pr * a.am;
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << " \xB3\n";
				i++;
				break;
			}
		}
		fclose(pf_art);
	}
	fclose(pf);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void line_art() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void shapka_art() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	system("color 0F");
	cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3\n";
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  №  ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Артикул ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "    Назва    ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Група   ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3\n";
	cout << "\xB3     \xB3         \xB3             \xB3           \xB3\n";
	cout << "\xC3\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n";
}
void EditRecField(const char* file_full, const char* file_art, const char* file_country, const char* file_gr)
{
	regex reg_d("[н,т]");
	regex reg_otv("[1-9]+|[1-9]+[0]+");
	regex reg_name("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,11}");
	regex reg_gr("[1-9]|[1][0]");
	regex reg_am("[1-9]{1}|[1-9]{1}[0-9]{1}|[1]{1}[0]{2}");
	regex reg_pr_1("[1-9][0-9]{3}|[1-4][0-9]{4}|[5][0]{4}");
	regex reg_pr_2("[1-9][0-9]{3}[.]([0-9]){1,2}|[1-4][0-9]{4}[.]([0-9]){1,2}|[5][0]{4}[.]([0-9]{1,2})");
	cmatch result;
	Data a;
	Data_article b;
	int otv;
	bool flag;
	char d;
	size_t k = CountRecFull(file_full);
	do {
		system("cls");
		shapka();
		vyvod(file_art, file_full, file_country, file_gr);
		line();
			do {
				do {
					flag = false;
					cin.ignore(cin.rdbuf()->in_avail());
					cout << endl << "Який запис Ви хочете відредагувати: (можна ввести від 1 до "<<k<<"): ";
					string num_1;
					getline(cin, num_1);
					if (regex_match(num_1.c_str(), result, reg_otv))
					{
						otv = atoi(num_1.c_str());
						flag = true;
					}
					else
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Можна вводити тільки цифри від 1 до "<<k<<")" << "\n";
					}
					cin.ignore(cin.rdbuf()->in_avail());
				} while (!flag);
				if (1 <= otv && otv <= k)
					break;
				else
					cout << "\nНема такого запису";
			} while (1);
			system("cls");
			shapka();
			fopen_s(&pf, file_full, "rb");
			fseek(pf, (otv - 1) * sizeof(Data), SEEK_SET);
			fread(&a, sizeof(Data), 1, pf);
			fclose(pf);
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, b.article) == 0)
				{
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << otv << " \xB3 " << setw(7) << right;
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << b.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
					break;
				}
			}
			fclose(pf_art);
			line();
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете редагувати цей запис? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т') {
				shapka_edit();
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "\xB3 " << setw(3) << right << "#";
				cout << " \xB3  " << setw(3) << right << (int)a.am << "  \xB3  " << setw(8) << right << str << " \xB3 " << setw(8) << right << fixed << setprecision(2) << (float)a.pr << " \xB3";
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				cout << "\n";
				line_edit();
				int otv_field;
				do {
					do {
						flag = false;
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "\nВиберіть поле, яке необхідно редагувати(від 1 до 3): ";
						string otv_filed_1;
						getline(cin, otv_filed_1);
						if (regex_match(otv_filed_1.c_str(), result, reg_otv))
						{
							otv_field = atoi(otv_filed_1.c_str());
							flag = true;
						}
						else
						{
							cin.ignore(cin.rdbuf()->in_avail());
							cout << "Можна вводити тільки цифри від 1 до 3\n";
						}
						cin.ignore(cin.rdbuf()->in_avail());
					} while (!flag);
					if (1 <= otv_field && otv_field <= 3)
						break;
					else
						cout << "\nНема такого поля";
				} while (1);
				switch (otv_field)
				{
				case 1: {
					do {
						flag = false;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						string am_1;
						cout << "\nКількіть: (можна вводити тільки цифри; діапазон: від 1 до 100) ";
						getline(cin, am_1);
						if (regex_match(am_1.c_str(), result, reg_am))
						{
							a.am = stoi(am_1);
							flag = true;
						}
						else {
							cout << "Можна вводити тільки цифри (діапазон: 1-100)";
						}
					} while (!flag);
					break;
				}
				case 2: {
					a.dat1 = func_vvod_date();
					break;
				}
				case 3: {
					do {
						system("CLS");
						flag = false;
						string pr_1;
						cout << "\nЦіна: (можна вводити тільки цифри; діапазон: 1000-50000) ";
						getline(cin, pr_1);
						if (regex_match(pr_1.c_str(), result, reg_pr_1) || regex_match(pr_1.c_str(), result, reg_pr_2))
						{
							a.pr = strtof(pr_1.c_str(), nullptr);
							flag = true;
						}
						else {
							cout << "Можна вводити тільки цифри (діапазон: 1000-50000, приклад: 1000.99 або 1000)\n";
							Pause();
						}
					} while (!flag);
					break;
				}
				}
				if (!IdentFull(file_full, a)) {
					fopen_s(&pf, file_full, "r+b");
					fseek(pf, (otv - 1) * sizeof(Data), 1);
					fwrite(&a, sizeof(Data), 1, pf);
					fclose(pf);
				}
			}
			do {
				flag = false;
				cout << "\nХочете продовжити? ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
			} while (!flag);
	} while (d == 'т');
}
void shapka_edit() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n";
	cout << "\xB3     \xB3       \xB3           \xB3          \xB3\n";
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "  №  ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Кіль- ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Дата    ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "   Ціна   ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3\n";
	cout << "\xB3     \xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " кість ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xB3";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " закупівлі ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout <<"\xB3          \xB3\n";
	cout << "\xB3     \xB3       \xB3           \xB3          \xB3\n";
	cout<<"\xC3\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n";
}
void line_edit() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void EditRecCountry(const char* file_country) {
	char b[COUNTRY];
	size_t num;
	char d;
	bool flag, flag_1;
	regex reg_country("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,10}");
	regex reg_d("[н,т]");
	regex reg_num("[1-9]|[1-9][0-9]+?");
	cmatch result;
	size_t	k = CountRecCountry(file_country);
	do {
			system("cls");
			VyvodCountry(file_country);
			do {
				do {
					flag = false;
					cin.ignore(cin.rdbuf()->in_avail());
					cout << endl << "Який запис Ви хочете редагувати: ";
					string num_1;
					getline(cin, num_1);
					if (regex_match(num_1.c_str(), result, reg_num))
					{
						num = atoi(num_1.c_str());
						flag = true;
					}
					else
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
					}
					cin.ignore(cin.rdbuf()->in_avail());
				} while (!flag);
				if (1 <= num && num <= k)
					break;
				else
					cout << "\nНема такого запису";
			} while (1);
			system("cls");
			fopen_s(&pf_country, file_country, "rb");
			fseek(pf_country, (num - 1) * COUNTRY, SEEK_SET);
			fread(&b, COUNTRY, 1, pf_country);
			fclose(pf_country);
			cout << num << " " << b << endl;
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете відредагувати цей запис? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т')
			{
				do {
					flag_1 = false;
					string country_1;
					cout << "\nКраїна-виробник: ";
					getline(cin, country_1);
					if (regex_match(country_1.c_str(), result, reg_country))
					{
						strcpy_s(b, country_1.c_str());
						flag_1 = true;
					}
					else {
						cout << "Можна вводити тільки українські букви (максимальна кількість символів 10)";
					}
				} while (!flag_1);
				if (!IdentCountry(file_country, b))
				{
					fopen_s(&pf_country, file_country, "r+b");
					fseek(pf_country, (num - 1) * 11, SEEK_SET);
					fwrite(&b, 11, 1, pf_country);
					fclose(pf_country);
				}
			}
		bool flag;
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (d=='т');
}
void EditRecGroup(const char* file_gr) {
	char b[GROUP];
	size_t num;
	char d;
	bool flag, flag_1;
	regex reg_gr("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,9}");
	regex reg_d("[н,т]");
	regex reg_num("[1-9]|[1-9][0-9]+?");
	cmatch result;
	size_t	k = CountRecGr(file_gr);
	do {
			system("cls");
			VyvodGr(file_gr);
			do {
				do {
					flag = false;
					cin.ignore(cin.rdbuf()->in_avail());
					cout << endl << "Який запис Ви хочете редагувати: ";
					string num_1;
					getline(cin, num_1);
					if (regex_match(num_1.c_str(), result, reg_num))
					{
						num = atoi(num_1.c_str());
						flag = true;
					}
					else
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
					}
					cin.ignore(cin.rdbuf()->in_avail());
				} while (!flag);
				if (1 <= num && num <= k)
					break;
				else
					cout << "\nНема такого запису";
			} while (1);
			system("cls");
			fopen_s(&pf_gr, file_gr, "rb");
			fseek(pf_gr, (num - 1) * GROUP, SEEK_SET);
			fread(&b, GROUP, 1, pf_gr);
			fclose(pf_gr);
			cout << num << " " << b << endl;
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете відредагувати цей запис? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т')
			{
				do {
					flag_1 = false;
					string gr_1;
					cout << "\nГрупа інстрментів: ";
					getline(cin, gr_1);
					if (regex_match(gr_1.c_str(), result, reg_gr))
					{
						strcpy_s(b, gr_1.c_str());
						flag_1 = true;
					}
					else {
						cout << "Можна вводити тільки українські букви (максимальна кількість символів 9)";
					}
				} while (!flag_1);
				if (!IdentGr(file_gr, b))
				{
					fopen_s(&pf_gr, file_gr, "r+b");
					fseek(pf_gr, (num - 1) * GROUP, SEEK_SET);
					fwrite(&b, GROUP, 1, pf_gr);
					fclose(pf_gr);
				}
			}
		bool flag;
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (d == 'т');
}
void EditRecArt(const char* file_art,const char*file_gr) {
	size_t num;
	Data_article a,b, c;
	char d;
	char g[GROUP];
	bool flag, flag_1;
	regex reg_name("[а-щА-ЩЬьЮюЯяЇїІіЄєҐґ]{1,11}");
	regex reg_d("[н,т]");
	regex reg_gr("[1-9]|[1][0]");
	regex reg_num("[1-9]|[1-9][0-9]+?");
	regex reg_otv("[1-9]+|[1-9]+[0]+");
	cmatch result;
	size_t	k = CountRecArt(file_art);
	do {
			system("cls");
			shapka_art();
			vyvodart(file_art,file_gr);
			line_art();
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			do {
				do {
					flag = false;
					cin.ignore(cin.rdbuf()->in_avail());
					cout << endl << "Який запис Ви хочете редагувати: ";
					string num_1;
					getline(cin, num_1);
					if (regex_match(num_1.c_str(), result, reg_num))
					{
						num = atoi(num_1.c_str());
						flag = true;
					}
					else
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
					}
					cin.ignore(cin.rdbuf()->in_avail());
				} while (!flag);
				if (1 <= num && num <= k)
					break;
				else
					cout << "\nНема такого запису";
			} while (1);
			system("cls");
			fopen_s(&pf_art, file_art, "rb");
			fseek(pf_art, (num - 1) * sizeof(Data_article), SEEK_SET);
			fread(&b, sizeof(Data_article), 1, pf_art);
			fclose(pf_art);
			fopen_s(&pf_gr, file_gr, "rb");
			fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
			fread(&g, GROUP, 1, pf_gr);
			fclose(pf_gr);
			cout << num << " " << b.article<<" "<<b.name<<" "<< g << endl;
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете відредагувати цей запис? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т')
			{
				do {
					flag_1 = false;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "\nНазва інструменту: ";
					string name_1;
					getline(cin, name_1);
					if (regex_match(name_1.c_str(), result, reg_name))
					{
						strcpy_s(b.name, name_1.c_str());
						flag_1 = true;
					}
					else {
						cout << "Можна вводити тільки українські букви (максимальна кількість символів 11)";
					}

				} while (!flag_1);
				bool ident_1 = false;
				if (IdentArt(file_art, b)) {
					ident_1 = true;
				}
				if (!ident_1) {
					int otv_art;
					int i = 0;
					char cc[GROUP];
					size_t k_1 = CountRecGr(file_gr);
					cout << "Група:\n";
					fopen_s(&pf_gr, file_gr, "rb");
					while (fread(&cc, GROUP, 1, pf_gr)) {
						cout << ++i << " " << cc << "\n";
					}
					fclose(pf_gr);
					do {
						flag_1 = false;
						string otv_1;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Номер (можна вводити від 1 до " << k_1 << "): ";
						getline(cin, otv_1);
						otv_art = atoi(otv_1.c_str());
						if (regex_match(otv_1.c_str(), result, reg_otv))
						{
							if (otv_art >= 1 && otv_art <= k_1)
							{
								flag_1 = true;
							}
							else
							{
								cout << "Можна вводити тільки цифри від 1 до " << k_1 << "\n";
							}
						}
						else
						{
							cout << "Можна вводити тільки цифри від 1 до " << k_1 << "\n";
						}
					} while (!flag_1);
					int art_2 = 1;
					size_t k_2 = CountRecArt(file_art);
					string article_1, article_a, article_c;
					fopen_s(&pf_art, file_art, "r+b");
					bool f;
					int p;
					f = true;
					while (f)
					{
						f = false;
						p = 1;
						fread(&a, sizeof(Data_article), 1, pf_art);
						article_a = a.article;
						int jj = article_a.find("-");
						article_a = article_a.substr(jj + 1, 2);
						int newnum_a = stoi(article_a);
						while (fread(&c, sizeof(Data_article), 1, pf_art))
						{
							p++;
							article_c = c.article;
							int jj = article_c.find("-");
							article_c = article_c.substr(jj + 1, 2);
							int newnum_c = stoi(article_c);
							if (newnum_a > newnum_c)
							{
								fseek(pf_art, (p - 2) * sizeof(Data_article), SEEK_SET);
								fwrite(&c, sizeof(Data_article), 1, pf_art);
								fseek(pf_art, (p - 1) * sizeof(Data_article), SEEK_SET);
								fwrite(&a, sizeof(Data_article), 1, pf_art);
								f = true;
							}
							else
							{
								a = c;
								newnum_a = newnum_c;
								
							}
							fseek(pf_art, p * sizeof(Data_article), SEEK_SET);
						}
						rewind(pf_art);
					}
					fclose(pf_art);
					bool fl = false;
					fopen_s(&pf_art, file_art, "rb");
					while (fread(&c, sizeof(Data_article), 1, pf_art))
					{
						if (otv_art == c.otv)
						{
							article_1 = c.article;
							fl = true;
						}
					}
					fclose(pf_art);
					int newnum;
					if (fl)
					{
						int j = article_1.find("-");
						article_1 = article_1.substr(j + 1, 2);
						newnum = stoi(article_1);
						newnum++;

					}
					else
						newnum = 1;
						string art_3 = to_string(newnum);
						string otv_1 = to_string(otv_art);
						article_1 = otv_1 + "-" + art_3;
						strcpy_s(b.article, article_1.c_str());
						b.otv = otv_art;
						fopen_s(&pf_art, file_art, "r+b");
						fseek(pf_art, (num - 1) * sizeof(Data_article), SEEK_SET);
						fwrite(&b, sizeof(Data_article), 1, pf_art);
						fclose(pf_art);
				}
			}
		bool flag;
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (d == 'т');
}
void MainMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full,const char*file_name)
{
	int active_menu = 1;
	char ch;
	Login a;
	bool f = 0;
	string Menu[] = { "\t МЕНЮ","Зайти як адміністратор", "Зайти як користувач", "Зареєструватися", "Вихід" };
	string Menu_1[] = { "\t МЕНЮ","Зайти як адміністратор", "Зайти як користувач", "Вихід" };
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;

		if (!CountRecLog(file_name)) {
			for (size_t i = 0; i < size(Menu); i++)
			{
				if (i == active_menu)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				}
				GoToXY(x, y++);
				cout << Menu[i] << endl;
			}
		}
		else {
			for (size_t i = 0; i < size(Menu_1); i++)
			{
				if (i == active_menu)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				}
				GoToXY(x, y++);
				cout << Menu_1[i] << endl;
			}
			f = 1;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (!f) {
				if (active_menu < size(Menu) - 1)
				{
					++active_menu;
				}
			}
			else {
				if (active_menu < size(Menu_1) - 1)
				{
					++active_menu;
				}
			}
			break;
		}
		case 13: {
			if (f && active_menu == 3)
			{
				active_menu++;
			}
			ConsoleCursorVisible(true, 100);
			int r_1;
			switch (active_menu) {
			case 1: {
				system("CLS");
				system("color 0F");
				if (CountRecLog(file_name)) {
					char name[17];
					char password[10];
					bool flg;
					do {
						system("cls");
						flg = true;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "\nВведіте Ваше ім'я: ";
						cin.getline(name, 17);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Введіть Ваш пароль: ";
						int i = 0;
						while (true) {
							char ch = _getch();
							if (ch == '\r' && i > 0) {
								break;
							}
							else if (ch == '\b' && i > 0) {
								cout << "\b \b";
								i--;
							}
							else if (isprint(ch) && i < 8) {
								cout << "*";
								password[i] = ch;
								i++;
							}
						}
						password[i] = '\0';
						for (size_t i = 0; i < strlen(password); i++) {
							char ch = ((password[i] - 'a' + 2) % 26) + 'a';
							password[i] = ch;
						}
						password[strlen(password)] = '\0';
						bool fld = 0;
						fopen_s(&pf_file, file_name, "rb");
						while (fread(&a, sizeof(Login), 1, pf_file)) {
							if (strcmp(name, a.log) == 0 && strcmp(password, a.pass) == 0)
							{
								fld = 1;
							}
						}
						if (fld)
						{
							AdminMenu(file_country, file_gr, file_art, file_full, file_name);
						}
						else
						{
							cout << "\nНевірні дані, спробуйте ще раз\n";
							flg = false;
							Pause();
						}
						fclose(pf_file);
					} while (!flg);
				}
				else {
					system("CLS");
					cout << "Немає користувачів, зареєструйтесь, будь ласка\n";
				}
				Pause();
				break;
			}
			case 2: {
				UserMenu(file_country, file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}

			case 3: {
				system("CLS");
				system("color 0F");
				Login a;
				regex regular_l("([a-z]{1,15})");
				regex regular_n("([0-9]{1,8})");
				regex reg_d("[н,т]");
				cmatch result;
				bool flag;
				char d;
				int r;
				system("CLS");
				do
				{
					do
					{
						flag = false;
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Введіть ім'я англійською маленькими літерами (максимальна кількість символів - 15): ";
						cin.getline(a.log, 17);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						string log_1 = (string)a.log;
						if (regex_match(log_1.c_str(), result, regular_l))
						{
							flag = true;
						}
						else
						{
							cout << "Можна вводити тільки маленькі літери англійською мовою (максимальна кількість символів - 15)\n";
						}
					} while (!flag);
					flag = false;
					do
					{
						cout << "Введіть пароль (максимальна кількість символів - 8): ";
						cin.getline(a.pass, 10);
						r = strlen(a.pass);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						string pass_1 = (string)a.pass;
						if (regex_match(pass_1.c_str(), result, regular_n))
						{
							flag = true;
						}
						else
						{
							cout << "Можна вводити тільки цифри (максимальна кількість символів - 8)\n";
						}
					} while (!flag);
					flag = false;
					do {
						cout << "Вірні дані (т/н): ";
						string d_1;
						getline(cin, d_1);
						if (regex_match(d_1.c_str(), result, reg_d))
						{
							d = d_1[0];
							flag = true;
						}
						else
						{
							cout << "Можна вводити тільки \"т\" або \"н\"\n";
						}
					} while (!flag);
					cin.ignore(cin.rdbuf()->in_avail());
				} while (d == 'н');
				for (size_t i = 0; i < r; i++)
				{
					char ch = ((a.pass[i] - 'a' + 2) % 26) + 'a';
					a.pass[i] = ch;
				}
				a.pass[r] = '\0';
				fopen_s(&pf_file, file_name, "a+b");
				fwrite(&a, sizeof(Login), 1, pf_file);
				fclose(pf_file);
				Pause();
				break;
			}
			case 4: {
				exit(0);
			}
			}
		}
		}
	}
}
size_t CountRecLog(const char* file_name) {
	fopen_s(&pf_file, file_name, "rb");
	fseek(pf_file, 0, SEEK_END);
	size_t k = ftell(pf_file) / sizeof(Login);
	fclose(pf_file);
	return k;
}
void AdminMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	string Menu[] = { "    МЕНЮ","Ввести запис", "Вивести запис", "Редагувати запис","Видалити запис","Сортування записів", "Виконання запитів","Імпорт у CSV","Вихід"};
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;
		for (size_t i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (active_menu < size(Menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case 13: {
			ConsoleCursorVisible(true, 100);
			switch (active_menu) {
			case 1: {
				VvodMenu(file_country, file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}
			case 2: {
				system("CLS");
				system("color 0F");
				VyvodMenu(file_country, file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}
			case 3: {
				EditMenu(file_country, file_gr,  file_art,file_full, file_name);
				Pause();
				break;
			}
			case 4: {
				DelMenu(file_country,file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}
			case 5: {
				SortMenu( file_country,  file_gr,  file_art,  file_full, file_name);
				Pause();
				break;
			}
			case 6: {
				RequestMenu(file_country, file_gr,  file_art, file_full,  file_name);
				Pause();
				break;
			}
			case 7: {
				if (CountRecFull(file_full) && CountRecArt(file_art) && CountRecCountry(file_country) && CountRecGr(file_gr)) {
					createCSV(file_art, file_full, file_gr, file_country);
				}
				else {
					system("cls");
					system("color 0F");
					cout << "Немає записів, введіть хоча б один\n";
					Pause();
				}
				break;
			}
			case 8: {
				MainMenu(file_country,file_gr, file_art, file_full,file_name);
			}
			}
		}
		}
	}
}
void UserMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	string Menu[] = { "       МЕНЮ", "Вивести запис", "Сортування записів", "Виконання запитів", "Вихід" };
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;
		for (size_t i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (active_menu < size(Menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case 13: {
			ConsoleCursorVisible(true, 100);
			switch (active_menu) {
			case 1: {
				VyvodMenu(file_country, file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}
			case 2: {
				SortMenu(file_country, file_gr,  file_art,  file_full, file_name);
				Pause();
				break;
			}
			case 3: {
				RequestMenu(file_country, file_gr, file_art, file_full, file_name);
				Pause();
				break;
			}
			case 4: {
				MainMenu(file_country, file_gr, file_art, file_full, file_name);
			}
			}
		}
		}
	}
}
void VvodMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	string Menu[] = { "    МЕНЮ","Ввести країну-виробник", "Ввести групу", "Ввести артикль","Ввести весь запис","Вихід" };
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;
		for (size_t i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (active_menu < size(Menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case 13: {
			ConsoleCursorVisible(true, 100);
			switch (active_menu) {
			case 1: {
				system("CLS");
				system("color 0F");
				VvodCountry(file_country);
				Pause();
				break;
			}
			case 2: {
				system("CLS");
				system("color 0F");
				VvodGr(file_gr);
				Pause();
				break;
			}
			case 3: {
				system("CLS");
				system("color 0F");
				if (CountRecGr(file_gr)) {
					vvodart(file_gr, file_art);
				}
				else {
					cout << "Немає записів у файлі Group.dat\n";
				}
				Pause();
				break;
			}
			case 4: {
				system("CLS");
				system("color 0F");
				if (CountRecCountry(file_country) && CountRecArt(file_art) && CountRecGr(file_gr)) {
					vvod(file_gr, file_art, file_full, file_country);
				}
				else {
					cout << "Немає записів у файлі Country.dat/Art.dat/Group.dat\n";
				}
				Pause();
				break;
			}
			case 5: {
				MainMenu(file_country, file_gr, file_art, file_full, file_name);
			}
			}
		}
		}
	}
}
void VyvodMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	string Menu[] = { "    МЕНЮ","Вивести країну-виробник", "Вивести групу", "Вивести артикль","Вивести весь запис","Вихід" };
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;
		for (size_t i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (active_menu < size(Menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case 13: {
			ConsoleCursorVisible(true, 100);
			switch (active_menu) {
			case 1: {
				system("CLS");
				system("color 0F");
				if (CountRecCountry(file_country)) {
					VyvodCountry(file_country);
				}
				else {
					cout << "Немає записів у файлі Country.dat\n";
				}
				Pause();
				break;
			}
			case 2: {
				system("CLS");
				system("color 0F");
				if (CountRecGr(file_gr))
				{
					VyvodGr(file_gr);
				}
				else
				{
					cout << "Немає записів у файлі Group.dat\n";
				}
				Pause();
				break;
			}
			case 3: {
				system("CLS");
				system("color 0F");
				if (CountRecArt(file_art) && CountRecGr(file_gr)) {
					shapka_art();
					vyvodart(file_art, file_gr);
					line_art();
				}
				else {
					cout << "Немає записів у файлі Art.dat/Group.dat\n";
				}
				Pause();
				break;
			}
			case 4: {
				system("CLS");
				system("color 0F");
				if (CountRecFull(file_full) && CountRecGr(file_gr) && CountRecCountry(file_country) && CountRecArt(file_art)) {
					shapka();
					vyvod(file_art, file_full, file_country, file_gr);
					line();
				}
				else {
					cout << "Немає записів у файлі MusicShop.dat/Group.dat/Country.dat/Art.dat\n";
				}
				Pause();
				break;
			}
			case 5: {
				MainMenu(file_country, file_gr, file_art, file_full, file_name);
			}
			}
		}
		}
	}
}
void EditMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	string Menu[] = { "    МЕНЮ","Редагувати країни", "Редагувати групи", "Редагувати артикль","Редагувати основний файл","Вихід" };
	while (true)
	{
		ConsoleCursorVisible(false, 100);
		system("CLS");
		int x = 56, y = 13;
		for (size_t i = 0; i < size(Menu); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
		}
		switch (ch)
		{
		case 72: {
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		}
		case 80: {
			if (active_menu < size(Menu) - 1)
			{
				++active_menu;
			}
			break;
		}
		case 13: {
			ConsoleCursorVisible(true, 100);
			switch (active_menu) {
			case 1: {
				system("CLS");
				system("color 0F");
				if (CountRecCountry(file_country)) {
					EditRecCountry(file_country);
				}
				else {
					cout << "Немає записів у файлі Country.dat\n";
				}
				Pause();
				break;
			}
			case 2: {
				system("CLS");
				system("color 0F");
				if (CountRecGr(file_gr))
				{
					EditRecGroup(file_gr);
				}
				else
				{
					cout << "Немає записів у файлі Group.dat\n";
				}
				Pause();
				break;
			}
			case 3: {
				system("CLS");
				system("color 0F");
				if (CountRecArt(file_art)&&CountRecGr(file_gr)) {
					EditRecArt(file_art, file_gr);
				}
				else {
					cout << "Немає записів у файлі Art.dat\n";
				}
				Pause();
				break;
			}
			case 4: {
				system("CLS");
				system("color 0F");
				if (CountRecFull(file_full) && CountRecGr(file_gr) && CountRecCountry(file_country) && CountRecArt(file_art)) {
					EditRecField(file_full, file_art, file_country, file_gr);
				}
				else {
					cout << "Немає записів у файлі MusicShop.dat/Group.dat/Country.dat/Art.dat\n";
					Pause();
				}
				break;
			}
			case 5: {
				MainMenu(file_country, file_gr, file_art, file_full, file_name);
			}
			}
		}
		}
	}
}
void DelMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	regex reg_d("[н,т]");
	cmatch result;
	int active_menu = 1;
	char ch;
	string Menu[] = { "\t     МЕНЮ", "Видалити за номером запису", "Видалити за групою інструментів","Вихід" };
	system("CLS");
	system("color 0F");
	if (CountRecFull(file_full)) {
		while (true)
		{
			ConsoleCursorVisible(false, 100);
			system("CLS");
			int x = 56, y = 13;
			for (size_t i = 0; i < size(Menu); i++)
			{
				if (i == active_menu)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				}
				GoToXY(x, y++);
				cout << Menu[i] << endl;
			}
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
			}
			switch (ch)
			{
			case 72: {
				if (active_menu > 1)
				{
					--active_menu;
				}
				break;
			}
			case 80: {
				if (active_menu < size(Menu) - 1)
				{
					++active_menu;
				}
				break;
			}
			case 13: {
				ConsoleCursorVisible(true, 100);
				switch (active_menu) {
				case 1: {
					system("CLS");
					system("color 0F");
					DeleteRec(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 2: {
					system("CLS");
					system("color 0F");
					DeleteRecGroup(file_gr, file_full, file_art,file_country);
					Pause();
					break;
				}
				case 3: {
					MainMenu(file_country,file_gr,file_art, file_full, file_name);
				}
				}
			}
			}
		}
	}
	else
	{
		cout << "Немає записів, введіть хоча б один" << endl;
	}
}
void SortMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	int active_menu = 1;
	char ch;
	system("CLS");
	system("color 0F");
	string Menu[] = { "\t          МЕНЮ", "Сортувати за групою інструментів", "Сортувати за країною-виробником","Вихід" };
	if (CountRecFull(file_full)) {
		while (true)
		{
			ConsoleCursorVisible(false, 100);
			system("CLS");
			int x = 52, y = 13;
			for (size_t i = 0; i < size(Menu); i++)
			{
				if (i == active_menu)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				}
				GoToXY(x, y++);
				cout << Menu[i] << endl;
			}
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
			}
			switch (ch)
			{
			case 72: {
				if (active_menu > 1)
				{
					--active_menu;
				}
				break;
			}
			case 80: {
				if (active_menu < size(Menu) - 1)
				{
					++active_menu;
				}
				break;
			}
			case 13: {
				ConsoleCursorVisible(true, 100);
				switch (active_menu) {
				case 1: {
					system("CLS");
					system("color 0F");
					SortGr(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 2: {
					system("CLS");
					system("color 0F");
					SortCountry(file_full, file_art, file_gr,file_country);
					Pause();
					break;
				}
				case 3: {
					MainMenu(file_country, file_gr, file_art, file_full, file_name);
				}
				}
			}
			}
		}
	}
	else
	{
		cout << "Немає записів, введіть хоча б один" << endl;
	}
}
void RequestMenu(const char* file_country, const char* file_gr, const char* file_art, const char* file_full, const char* file_name)
{
	system("CLS");
	system("color 0F");
	int active_menu = 1;
	char ch;
	string Menu[] = { "\t\t           МЕНЮ", "Пошук за групою інструментів", "Загальна вартість інструментів","5 записів з найбільшою ціною","Кількість записів з ціною, менше, ніж була введена","Товари, які вироблені у введеній країні","Товари, які закуплені в місяць, введений користувачем","Вихід" };
	if (CountRecFull(file_full)) {
		while (true)
		{
			system("CLS");
			ConsoleCursorVisible(false, 100);
			int x = 42, y = 13;
			for (size_t i = 0; i < size(Menu); i++)
			{
				if (i == active_menu)
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				}
				GoToXY(x, y++);
				cout << Menu[i] << endl;
			}
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
			}
			switch (ch)
			{
			case 72: {
				if (active_menu > 1)
				{
					--active_menu;
				}
				break;
			}
			case 80: {
				if (active_menu < size(Menu) - 1)
				{
					++active_menu;
				}
				break;
			}
			case 13: {
				ConsoleCursorVisible(true, 100);
				switch (active_menu) {
				case 1: {
					system("CLS");
					system("color 0F");
					searchgroup(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 2: {
					system("CLS");
					system("color 0F");
					vart(file_full, file_art,file_gr, file_country);
					Pause();
					break;
				}
				case 3: {
					system("CLS");
					system("color 0F");
					top_prices(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 4: {
					system("CLS");
					system("color 0F");
					kiltovar(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 5: {
					system("CLS");
					system("color 0F");
					searchcountry(file_full, file_art,file_gr, file_country);
					Pause();
					break;
				}
				case 6: {
					system("CLS");
					system("color 0F");
					searchmonth(file_full, file_art, file_gr, file_country);
					Pause();
					break;
				}
				case 7: {
					MainMenu(file_country,  file_gr,  file_art, file_full,  file_name);
				}
				}
			}
			}
		}
	}
	else
	{
		cout << "Немає записів, введіть хоча б один" << endl;
	}
}
void DeleteRecGroup(const char* file_gr, const char* file_full, const char* file_art,const char*file_country) {
	Data a;
	Data_article g;
	size_t num;
	char b[GROUP];
	char f[GROUP];
	char d;
	bool flag;
	regex reg_d("[н,т]");
	regex reg_num("[1-9]|[1-9][0-9]+?");
	cmatch result;
	size_t k = CountRecGr(file_gr);
	char ot;
	do{
	system("cls");
	VyvodGr(file_gr);
	FILE* ptemp;
	size_t k_1 = CountRecFull(file_full);
	if (k_1) {
		do {
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << endl << "Яку групу Ви хочете видалити: ";
				string num_1;
				getline(cin, num_1);
				if (regex_match(num_1.c_str(), result, reg_num))
				{
					num = atoi(num_1.c_str());
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (1 <= num && num <= k)
				break;
			else
				cout << "\nНема такого запису";
		} while (1);
		system("cls");
		fopen_s(&pf_gr, file_gr, "rb");
		fseek(pf_gr, (num - 1) * GROUP, SEEK_SET);
		fread(&b, GROUP, 1, pf_gr);
		fclose(pf_gr);
		fopen_s(&pf, file_full, "rb");
		flag = false;
		while (fread(&a, sizeof(Data), 1, pf)) {
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&g, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, g.article) == 0)
				{
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (g.otv - 1) * GROUP, SEEK_SET);
					fread(&f, GROUP, 1, pf_gr);
					fclose(pf_gr);
				}
			}
			if (strcmp(b, f) == 0) {
				flag = true;
			}
			fclose(pf_art);
		}
		fclose(pf);
		if (flag)
		{
			int i = 1;
			fopen_s(&pf, file_full, "rb");
			cout << "Записи з групою " << b << ":" << endl;
			shapka();
			while (fread(&a, sizeof(Data), 1, pf)) {
				fopen_s(&pf_art, file_art, "rb");
				while (fread(&g, sizeof(Data_article), 1, pf_art)) {
					if (strcmp(a.article, g.article) == 0) {
						fopen_s(&pf_gr, file_gr, "rb");
						fseek(pf_gr, (g.otv - 1) * GROUP, SEEK_SET);
						fread(&f, GROUP, 1, pf_gr);
						fclose(pf_gr);
						break;
					}
				}
				if (strcmp(b, f) == 0) {
					char c[GROUP], d[COUNTRY];
					tm dat_1;
					char str[9];
					localtime_s(&dat_1, &a.dat1);
					strftime(str, 9, "%d.%m.%y", &dat_1);
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (g.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << g.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
				}
				fclose(pf_art);
				i++;
			}
			fclose(pf);
			line();
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете видалити всі записи? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т')
			{
				fopen_s(&ptemp, "temp.dat", "wb");
				fclose(ptemp);
				fopen_s(&pf, file_full, "rb");
				fopen_s(&ptemp, "temp.dat", "ab");
				while (fread(&a, sizeof(Data), 1, pf)) {
					fopen_s(&pf_art, file_art, "rb");
					while (fread(&g, sizeof(Data_article), 1, pf_art))
					{
						if (strcmp(a.article, g.article) == 0)
						{
							fopen_s(&pf_gr, file_gr, "rb");
							fseek(pf_gr, (g.otv - 1) * GROUP, SEEK_SET);
							fread(&f, GROUP, 1, pf_gr);
							fclose(pf_gr);
							break;
						}
					}
					if (strcmp(b, f) != 0)
					{
						fwrite(&a, sizeof(Data), 1, ptemp);
					}
					fclose(pf_art);
				}
				fclose(ptemp);
				fclose(pf);
				remove(file_full);
				rename("temp.dat", file_full);
				remove("temp.dat");
			}
		}
		else {
			cout << "Вибачте, таких записів немає!\n";
		}
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				ot = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	}
	else 
	{
		system("cls");
		cout << "Немає записів\n";
		break;
	}
}while (ot=='т');
}
void DeleteRec(const char* file_full, const char* file_art, const char* file_gr, const char* file_country) {
	Data a;
	Data_article b;
	size_t num;
	regex reg_d("[н,т]");
	regex reg_num("[1-9]|[1-9][0-9]+?");
	cmatch result;
	char d;
	bool flag;
	do {
		size_t k = CountRecFull(file_full);
		if (k) {
			system("cls");
			shapka();
			vyvod(file_art, file_full, file_country, file_gr);
			line();
			do {
				do {
					flag = false;
					cin.ignore(cin.rdbuf()->in_avail());
					cout << endl << "Який запис Ви хочете видалити: ";
					string num_1;
					getline(cin, num_1);
					if (regex_match(num_1.c_str(), result, reg_num))
					{
						num = atoi(num_1.c_str());
						flag = true;
					}
					else
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
					}
					cin.ignore(cin.rdbuf()->in_avail());
				} while (!flag);
				if (1 <= num && num <= k)
					break;
				else
					cout << "\nНема такого запису";
			} while (1);
			system("cls");
			shapka();
			fopen_s(&pf, file_full, "rb");
			fseek(pf, (num - 1) * sizeof(Data), SEEK_SET);
			fread(&a, sizeof(Data), 1, pf);
			fclose(pf);
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, b.article) == 0)
				{
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << num << " \xB3 " << setw(7) << right;
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << b.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
					break;
				}
			}
			fclose(pf_art);
			line();
			do {
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВи хочете видалити цей запис? (т/н): ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (d == 'т') {
				FILE* ptemp;
				fopen_s(&pf, file_full, "rb");
				fopen_s(&ptemp, "temp.dat", "ab");
				size_t count = 0;
				while (fread(&a, sizeof(Data), 1, pf)) {
					count++;
					if (count != num) {
						fwrite(&a, sizeof(Data), 1, ptemp);
					}
				}
				fclose(ptemp);
				fclose(pf);
				remove(file_full);
				rename("temp.dat", file_full);
			}
			do {
				flag = false;
				cout << "Хочете продовжити? ";
				string d_1;
				getline(cin, d_1);
				if (regex_match(d_1.c_str(), result, reg_d))
				{
					d = d_1[0];
					flag = true;
				}
				else
				{
					cout << "Можна вводити тільки \"т\" або \"н\"\n";
				}
			} while (!flag);
		}
		else {
		cout << "Немає записів\n";
		break;
		}
	}while (d=='т');
}
void SortGr(const char* file_full, const char* file_art, const char* file_gr, const char* file_country)
{
	size_t k = CountRecFull(file_full);
	shapka();
	vyvod(file_art, file_full, file_country, file_gr);
	line();
	Data a, b;
	fopen_s(&pf, file_full, "r+b");
	int p;
	bool f;
	while (true)
	{
		p = 1;
		f = false;
		fread(&a, sizeof(Data), 1, pf);
		while (fread(&b, sizeof(Data), 1, pf)) {
			p++;
			if (strcmp(a.article, b.article) > 0)
			{
				fseek(pf, (p - 2) * sizeof(Data), SEEK_SET);
				fwrite(&b, sizeof(Data), 1, pf);
				fseek(pf, (p - 1) * sizeof(Data), SEEK_SET);
				fwrite(&a, sizeof(Data), 1, pf);
				f = true;
			}
			else
				a = b;
			fseek(pf, p * sizeof(Data), SEEK_SET);
		}
		if (!f) break;
		rewind(pf);
	}
	fclose(pf);

	cout << "Відсортовані записи за групою\n";
	shapka();
	vyvod(file_art, file_full, file_country, file_gr);
	line();
}
void SortCountry(const char* file_full, const char* file_art, const char* file_gr, const char* file_country) {
	size_t k = CountRecFull(file_full);
	shapka();
	vyvod(file_art, file_full, file_country, file_gr);
	line();
	vector<Data> records(k);
	vector<Data_article> articles(k);
	vector<char> countries(k * COUNTRY);
	fopen_s(&pf, file_full, "r+b");
	fopen_s(&pf_art, file_art, "rb");
	fopen_s(&pf_country, file_country, "rb");
	for (size_t i = 0; i < k; i++) {
		fread(&records[i], sizeof(Data), 1, pf);
		fseek(pf_art, (records[i].otv_countrys - 1) * sizeof(Data_article), SEEK_SET);
		fread(&articles[i], sizeof(Data_article), 1, pf_art);
		fseek(pf_country, (records[i].otv_countrys - 1) * COUNTRY, SEEK_SET);
		fread(&countries[i * COUNTRY], COUNTRY, 1, pf_country);
	}
	fclose(pf_country);
	fclose(pf_art);
	for (size_t i = 1; i < k; ++i) {
		bool f = false;
		for (size_t j = 0; j < k - i; ++j) {
			if (strcmp(&countries[j * COUNTRY], &countries[(j + 1) * COUNTRY]) > 0) {
				swap(records[j], records[j + 1]);
				swap(articles[j], articles[j + 1]);
				for (size_t p = 0; p < COUNTRY; ++p) {
					swap(countries[j * COUNTRY + p], countries[(j + 1) * COUNTRY + p]);
				}
				f = true;
			}
		}

		if (!f) {
			break;
		}
	}
	rewind(pf);
	for (const auto& record : records) {
		fwrite(&record, sizeof(Data), 1, pf);
	}
	fclose(pf);
	cout << "Відсортовані записи за країною\n";
	shapka();
	vyvod(file_art, file_full, file_country, file_gr);
	line();
}
void vart(const char* file_full, const char* file_art, const char* file_gr, const char* file_country) {
	shapka();
	vyvod(file_art,file_full,file_country,file_gr);
	line();
	double sum = 0;
	Data a;
	fopen_s(&pf,file_full,"rb");
	while (fread(&a, sizeof(Data), 1, pf)) {
		sum+= a.pr * a.am;
	}
	fclose(pf);
	cout << "Загальна сума: " <<fixed<<setprecision(2) << sum << endl;
}
void searchgroup(const char* file_full, const char* file_art, const char* file_gr, const char* file_country)
{
	Data a;
	Data_article b;
	int otv;
	regex reg_num("[1-9]|[1-9][0-9]+?");
	regex reg_d("[н,т]");
	cmatch result;
	bool flag;
	char d;
	size_t k = CountRecGr(file_gr);
	do {
		system("cls");
		VyvodGr(file_gr);
		do
		{
			do
			{
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВиберіть групу, яку Ви хочете знайти: ";
				string num_1;
				getline(cin, num_1);
				if (regex_match(num_1.c_str(), result, reg_num))
				{
					otv = atoi(num_1.c_str());
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (1 <= otv && otv <= k)
				break;
			else {
				cout << "\nНема такої групи";
			}
		} while (1);
		char groupname[GROUP];
		fopen_s(&pf_gr, file_gr, "rb");
		fseek(pf_gr, (otv - 1) * GROUP, SEEK_SET);
		fread(&groupname, GROUP, 1, pf_gr);
		fclose(pf_gr);
		int i = 1;
		int found_records = 0;
		fopen_s(&pf, file_full, "rb");
		while (fread(&a, sizeof(Data), 1, pf)) {
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, b.article) == 0)
				{
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					if (strcmp(groupname, c) == 0) {
						if (!found_records) {
							shapka();
						}
						found_records++;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << a.article;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(11) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << b.name;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3" << " " << setw(9) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << c;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3  " << setw(3) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << (int)a.am;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << "  \xB3 " << setw(10) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << d;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3  " << setw(8) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << str;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(8) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << fixed << setprecision(2) << (float)a.pr;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(10) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << (float)a.pr * a.am;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3\n";
					}
					i++;
					break;
				}
			}
			fclose(pf_art);
		}
		fclose(pf);
		if (found_records) {
			line();
		}
		else {
			cout << "Записів з вказаною групою не знайдено." << endl;
		}
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				d = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	}while (d == 'т');
}
void top_prices(const char* file_full, const char* file_art, const char* file_gr, const char* file_country)
{
	Data a;
	Data_article b;
	vector<Data> records;
	int i;
	fopen_s(&pf, file_full, "rb");
	while (fread(&a, sizeof(Data), 1, pf)) {
		records.push_back(a);
	}
	fclose(pf);
	set<float> top_prices_set;
	for (const Data& a : records) {
		top_prices_set.insert(a.pr);
		if (top_prices_set.size() > 5) {
			top_prices_set.erase(top_prices_set.begin());
		}
	}
	i = 1;
	shapka();
	for (const Data& a : records) {
		if (top_prices_set.find(a.pr) != top_prices_set.end()) {
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, b.article) == 0)
				{
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << b.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
					i++;
					break;
				}
			}
			fclose(pf_art);
		}
	}
	line();
}
void kiltovar(const char* file_full, const char* file_art, const char* file_gr, const char* file_country) {
	regex reg_pr_1("[1-9][0-9]{3}|[1-4][0-9]{4}|[5][0]{4}");
	regex reg_pr_2("[1-9][0-9]{3}[.]([0-9]){1,2}|[1-4][0-9]{4}[.]([0-9]){1,2}");
	regex reg_d("[н,т]");
	char d;
	cmatch result;
	Data a;
	Data_article b;
	bool flag;
	float pr;
	do {
		system("cls");
	do {
		string price;
		flag = false;
		cout << "\nВведіть ціну (від 1000 до 50000): ";
		getline(cin, price);
		if (regex_match(price.c_str(), result, reg_pr_1)|| regex_match(price.c_str(), result, reg_pr_2)) {
			flag = true;
			pr = stof(price);
		}
		else {
			cout << "Введіть коректно (можна вводити числа від 1000 до 50000)\n";
		}
	} while (!flag);
	fopen_s(&pf, file_full, "rb");
	int i = 0, j = 0;
	while (fread(&a, sizeof(Data), 1, pf)) {
		i++;
		if (pr > a.pr) {
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art)) {
				if (strcmp(a.article, b.article) == 0) {
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					if (!j) {
						shapka();
					}
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << b.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
					j++;
					break;
				}
			}
			fclose(pf_art);
		}
	}
	fclose(pf);
	if (!j) {
		cout << "Немає записів з ціною менше, ніж введено" << endl;
	}
	else {
		line();
		cout << "Кількість записів менше за " << pr << " - " << j << endl;
	}
	do {
		flag = false;
		cout << "Хочете продовжити? ";
		string d_1;
		getline(cin, d_1);
		if (regex_match(d_1.c_str(), result, reg_d))
		{
			d = d_1[0];
			flag = true;
		}
		else
		{
			cout << "Можна вводити тільки \"т\" або \"н\"\n";
		}
	} while (!flag);
}while (d=='т');
}
void searchcountry(const char* file_full, const char* file_art, const char* file_gr, const char* file_country)
{
	Data a;
	Data_article b;
	int otv;
	regex reg_num("[1-9]|[1-9][0-9]+?");
	regex reg_d("[н,т]");
	cmatch result;
	bool flag;
	char dd;
	size_t k = CountRecCountry(file_country);
	do {
		system("cls");
		VyvodCountry(file_country);
		do
		{
			do
			{
				flag = false;
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\nВиберіть країну, яку Ви хочете знайти: ";
				string num_1;
				getline(cin, num_1);
				if (regex_match(num_1.c_str(), result, reg_num))
				{
					otv = atoi(num_1.c_str());
					flag = true;
				}
				else
				{
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Можна вводити тільки цифри від 1 до нескінченності\n";
				}
				cin.ignore(cin.rdbuf()->in_avail());
			} while (!flag);
			if (1 <= otv && otv <= k)
				break;
			else {
				cout << "\nНема такої країни";
			}
		} while (1);
		char countryname[COUNTRY];
		fopen_s(&pf_country, file_country, "rb");
		fseek(pf_country, (otv - 1) * COUNTRY, SEEK_SET);
		fread(&countryname, COUNTRY, 1, pf_country);
		fclose(pf_country);
		int i = 1;
		int found_records = 0;
		fopen_s(&pf, file_full, "rb");
		while (fread(&a, sizeof(Data), 1, pf)) {
			tm dat_1;
			char str[9];
			localtime_s(&dat_1, &a.dat1);
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art))
			{
				if (strcmp(a.article, b.article) == 0)
				{
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					if (strcmp(countryname, d) == 0) {
						if (!found_records) {
							shapka();
						}
						found_records++;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << "\xB3 " << setw(3) << right << i << " \xB3 " << setw(7) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << a.article;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(11) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << b.name;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3" << " " << setw(9) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << c;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3  " << setw(3) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << (int)a.am;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << "  \xB3 " << setw(10) << left;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << d;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3  " << setw(8) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << str;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(8) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << fixed << setprecision(2) << (float)a.pr;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3 " << setw(10) << right;
						SetConsoleCP(1251);
						SetConsoleOutputCP(1251);
						cout << (float)a.pr * a.am;
						SetConsoleCP(866);
						SetConsoleOutputCP(866);
						cout << " \xB3\n";
					}
					i++;
					break;
				}
			}
			fclose(pf_art);
		}
		fclose(pf);
		if (found_records > 0) {
			line();
		}
		else {
			cout << "Записів з вказаною країною не знайдено." << endl;
		}
		do {
			flag = false;
			cout << "Хочете продовжити? ";
			string d_1;
			getline(cin, d_1);
			if (regex_match(d_1.c_str(), result, reg_d))
			{
				dd = d_1[0];
				flag = true;
			}
			else
			{
				cout << "Можна вводити тільки \"т\" або \"н\"\n";
			}
		} while (!flag);
	} while (dd == 'т');
}
void searchmonth(const char* file_full, const char* file_art, const char* file_gr, const char* file_country) {
	Data a;
	Data_article b;
	char d;
	regex reg_d("[н,т]");
	bool found_records;
	regex reg("[1-9]|1[0-2]");
	cmatch result;
	bool flag;
	int month;
	do{
		system("cls");
		found_records = false;
	do {
		flag = false;
		cout << "\nВведіть номер місяця: ";
		string input_month;
		getline(cin, input_month);
		if (regex_match(input_month.c_str(), result, reg)) {
			month = stoi(input_month);
			flag = true;
		}
		else {
			cout << "Введіть коректно\n";
		}
	} while (!flag);
	fopen_s(&pf, file_full, "rb");
	while (fread(&a, sizeof(Data), 1, pf)) {
		tm dat_1;
		localtime_s(&dat_1, &a.dat1);
		int record_month = dat_1.tm_mon + 1;
		if (record_month == month) {
			char str[9];
			strftime(str, 9, "%d.%m.%y", &dat_1);
			fopen_s(&pf_art, file_art, "rb");
			while (fread(&b, sizeof(Data_article), 1, pf_art)) {
				if (strcmp(a.article, b.article) == 0) {
					char c[GROUP], d[COUNTRY];
					fopen_s(&pf_gr, file_gr, "rb");
					fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
					fread(&c, GROUP, 1, pf_gr);
					fclose(pf_gr);
					fopen_s(&pf_country, file_country, "rb");
					fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
					fread(&d, COUNTRY, 1, pf_country);
					fclose(pf_country);
					if (!found_records) {
						shapka();
					}
					found_records = true;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "\xB3 " << setw(3) << right << ftell(pf) / sizeof(Data) << " \xB3 " << setw(7) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << a.article;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(11) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << b.name;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3" << " " << setw(9) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << c;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(3) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (int)a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << "  \xB3 " << setw(10) << left;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << d;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3  " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << str;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(8) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << fixed << setprecision(2) << (float)a.pr;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3 " << setw(10) << right;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);
					cout << (float)a.pr * a.am;
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << " \xB3\n";
					break;
				}
			}
			fclose(pf_art);
		}
	}
	fclose(pf);
	if (!found_records) {
		cout << "Записів з вказаним місяцем не знайдено." << endl;
	}
	else {
		line();
	}
	bool flag;
	do {
		flag = false;
		cout << "Хочете продовжити? ";
		string d_1;
		getline(cin, d_1);
		if (regex_match(d_1.c_str(), result, reg_d))
		{
			d = d_1[0];
			flag = true;
		}
		else
		{
			cout << "Можна вводити тільки \"т\" або \"н\"\n";
		}
	} while (!flag);
}while (d == 'т');
}
void createCSV(const char* file_art, const char* file_full, const char* file_gr, const char* file_country) {
	Data a;
	Data_article b;
	int i = 1;
	fopen_s(&pf, file_full, "rb");
	char country_name[COUNTRY];
	if (ifstream("output.csv")) {
		remove("output.csv");
	}
	ofstream out_file("output.csv", ios::out);
	out_file << "№;Артикль;Назва;Група;Кількість;Країна;Дата;Ціна;Вартість\n";
	while (fread(&a, sizeof(Data), 1, pf)) {
		tm dat_1;
		char str[9];
		localtime_s(&dat_1, &a.dat1);
		strftime(str, 9, "%d.%m.%y", &dat_1);
		fopen_s(&pf_art, file_art, "rb");
		while (fread(&b, sizeof(Data_article), 1, pf_art))
		{
			if (strcmp(a.article, b.article) == 0)
			{
				char c[GROUP], d[COUNTRY];
				fopen_s(&pf_gr, file_gr, "rb");
				fseek(pf_gr, (b.otv - 1) * GROUP, SEEK_SET);
				fread(&c, GROUP, 1, pf_gr);
				fclose(pf_gr);
				fopen_s(&pf_country, file_country, "rb");
				fseek(pf_country, (a.otv_countrys - 1) * COUNTRY, SEEK_SET);
				fread(&d, COUNTRY, 1, pf_country);
				fclose(pf_country);
				out_file << i << ";";
				out_file << " "<<a.article << ";";
				out_file << b.name << ";";
				out_file << c << ";";
				out_file << (int)a.am << ";";
				out_file << d << ";";
				out_file << str << ";";
				string price = to_string((float)a.pr);
				size_t pos = price.find('.');
				if (pos != string::npos && price.length() - pos > 2) {
					price = price.substr(0, pos + 3);
				}
				replace(price.begin(), price.end(), '.', ',');
				out_file << price << ";";
				string total_price = to_string((float)a.pr * a.am);
				pos = total_price.find('.');
				if (pos != string::npos && total_price.length() - pos > 2) {
					total_price = total_price.substr(0, pos + 3);
				}
				replace(total_price.begin(), total_price.end(), '.', ',');
				out_file << total_price << "\n";
				i++;
				break;
			}
		}
		fclose(pf_art);
	}
	fclose(pf);
	out_file.close();
	cout << "Файл відкривається!";
	system("start output.csv");
}
