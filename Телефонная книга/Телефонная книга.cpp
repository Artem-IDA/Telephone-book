// Телефонная книга.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <Windows.h>

using namespace std;

struct Kontact
{
	string Name;
	string Surname;
	string Middle_name;
	string Main_telephone;
	string Home_telephone;
	string Work_telephone;
	string Email;
};

string wayFile;
vector<Kontact> Tel_Book;

void Input(void)
{
	system("cls");
	Kontact NEW;
	cout << "Введите имя -> ";
	cin >> NEW.Name;
	cout << "Введите фамилию -> ";
	cin >> NEW.Surname;
	cout << "Введите отчество -> ";
	cin >> NEW.Middle_name;
	cout << "Введите основной телефон -> ";
	cin.ignore();
	getline(cin, NEW.Main_telephone);
	cout << "Введите домашний телефон -> ";
	cin.ignore();
	getline(cin, NEW.Home_telephone);
	cout << "Введите рабочий телефон -> ";
	cin.ignore();
	getline(cin, NEW.Work_telephone);
	cout << "Введите почту -> ";
	cin.ignore();
	getline(cin, NEW.Email);
	Tel_Book.push_back(NEW);
}

void Output(int i)
{
	cout << "--------------------------------------------" << endl;
	cout << "Имя: " << Tel_Book[i].Name << endl;
	cout << "Фамилия: " << Tel_Book[i].Surname << endl;
	cout << "Отчество: " << Tel_Book[i].Middle_name << endl;
	cout << "Основной телефон: " << Tel_Book[i].Main_telephone << endl;
	cout << "Домашний телефон: " << Tel_Book[i].Home_telephone << endl;
	cout << "Рабочий телефон: " << Tel_Book[i].Work_telephone << endl;
	cout << "Почта: " << Tel_Book[i].Email << endl;
	cout << "--------------------------------------------" << endl;
}

void Sort_N(void)
{
	for (int i = 0; i < Tel_Book.size(); i++) {
		for (int j = 0; j < Tel_Book.size() - i - 1; j++) {
			if (Tel_Book[j].Name > Tel_Book[j + 1].Name) {
				swap(Tel_Book[j], Tel_Book[j + 1]);
			}
		}
	}
}

void Edit(string name)
{
	for (int i = 0; i < Tel_Book.size(); i++)
	{
		if (Tel_Book[i].Name == name)
		{
			cout << "________ВВЕДИТЕ ДАННЫЕ ДЛЯ ЗАМЕНЫ________" << endl;
			Input();
			return;
		}
	}
	cout << "Не найдено контакта с таким именем!" << endl;
	system("pause");
}

void Delete(string name)
{
	for (int i = 0; i < Tel_Book.size(); i++)
	{
		if (Tel_Book[i].Name == name)
		{
			Tel_Book.erase(Tel_Book.begin() + i);
			cout << "Контакт удален!" << endl;
			return;
		}
	}
	cout << "Не найдено контакта с таким именем!" << endl;
}

void InFile(void)
{
	ofstream fout(wayFile, ios_base::trunc);
	for (int i = 0; i < Tel_Book.size(); i++)
	{
		fout << "--------------------------------------------" << endl;
		fout << "Имя: " << Tel_Book[i].Name << endl;
		fout << "Фамилия: " << Tel_Book[i].Surname << endl;
		fout << "Отчество: " << Tel_Book[i].Middle_name << endl;
		fout << "Основной телефон: " << Tel_Book[i].Main_telephone << endl;
		fout << "Домашний телефон: " << Tel_Book[i].Home_telephone << endl;
		fout << "Рабочий телефон: " << Tel_Book[i].Work_telephone << endl;
		fout << "Почта: " << Tel_Book[i].Email << endl;
		fout << "--------------------------------------------" << endl;
	}
	fout.close();
}

void Menu(void)
{
	system("cls");
	cout << "Добавить контакт (1)" << endl;
	cout << "Вывести все контакты на экран (2)" << endl;
	cout << "Редактировать контакт (3)" << endl;
	cout << "Удалить контакт (4)" << endl;
	cout << "Выход (0)" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите путь к файлу (включая название файла и расширение) в который будет сохранятся ваши контакты" << endl;
	cout << "Пример: D:\\\Desktop\\Text.txt" << endl;
	getline(cin, wayFile);

	bool Usl = true;
	
	while (Usl)
	{
		int lever_m;
		Menu();
		cin >> lever_m;
		if (lever_m == 1)
		{
			Input();
			Sort_N();
			InFile();
		}
		else if (lever_m == 2)
		{
			system("cls");
			if (Tel_Book.size() != 0)
			{
				for (int i = 0; i < Tel_Book.size(); i++)
				{
					Output(i);
				}
			}
			else
				cout << "Список контактов пуст!" << endl;
			system("pause");
		}
		else if (lever_m == 3)
		{
			system("cls");
			string name;
			cout << "Введите имя контакта который нужно отредактировать ->";
			cin >> name;
			Edit(name);
			Sort_N();
			InFile();
		}
		else if (lever_m == 4)
		{
			system("cls");
			string name;
			cout << "Введите имя контакта который нужно удалить ->";
			cin >> name;
			Delete(name);
			Sort_N();
			InFile();
		}
		else
			Usl = false;
	}

	return 0;
}



