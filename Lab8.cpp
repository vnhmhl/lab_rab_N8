#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;
FILE* fp;

//Государство
struct Employee
{
	string name;	//Название
	string capital;	//Столица
	int number;		//Численность населения
	int square;		//Площадь
	Employee()
	{
		number = 0;
		square = 0;
	};
};

void delete_struct_from_file(int k)
{
	Employee mas[10];
	if ((fp = fopen("text.dat", "r")) == NULL) exit(3);
	int i = 0;
	while (!feof(fp) && i < 9)
	{
		fread(&mas[i], sizeof(Employee), 10, fp);
		if (mas[i].number < k) mas[i] = mas[i + 1];
		i++;
	}
	fclose(fp);
}

void insert_struct_to_file(Employee emp, int ind)
{
	if ((fp = fopen("text.dat", "a+")) == NULL) exit(3);
	int i = 0;
	while (!feof(fp))
	{
		if (i == ind) fwrite(&emp, sizeof(Employee), 1, fp);
		i++;
	}
	fclose(fp);
}

int main()
{
	Employee e[10];

	//открываем файл
	if ((fp = fopen("text.dat", "w")) == NULL)
		exit(1);
	else
	{
		//формируем запись е
		e[0].name = "Россия"; e[0].capital = "Москва"; e[0].number = 15; e[0].square = 35;
		e[1].name = "Россия1"; e[1].capital = "Москва1"; e[1].number = 35; e[1].square = 40;
		e[2].name = "Россия2"; e[2].capital = "Москва2"; e[2].number = 45; e[2].square = 31;
		e[3].name = "Россия3"; e[3].capital = "Москва3"; e[3].number = 148; e[3].square = 20;
		e[4].name = "Россия4"; e[4].capital = "Москва4"; e[4].number = 369; e[4].square = 23;
		e[5].name = "Россия5"; e[5].capital = "Москва5"; e[5].number = 78; e[5].square = 47;
		e[6].name = "Россия6"; e[6].capital = "Москва6"; e[6].number = 32; e[6].square = 40;
		e[7].name = "Россия7"; e[7].capital = "Москва7"; e[7].number = 102; e[7].square = 24;
		e[8].name = "Россия8"; e[8].capital = "Москва8"; e[8].number = 354; e[8].square = 13;
		e[9].name = "Россия9"; e[9].capital = "Москва9"; e[9].number = 78; e[9].square = 7;

		//запись е в файл
		fwrite(&e, sizeof(Employee), 10, fp);
		if (ferror(fp) == NULL) exit(2);
		fclose(fp);
	}

	//удаление структур, у которых численность меньше num
	int num = 70;
	delete_struct_from_file(num);

	//добавление элемента по индексу
	int index = 3;
	Employee el;
	el.name = "CША"; el.capital = "Вашингтон"; el.number = 44; el.square = 333;
	insert_struct_to_file(el,index);
};