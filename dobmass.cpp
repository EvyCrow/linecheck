#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	setlocale(0, "Russian");

	int chek = 1;
	while (chek == 1)
	{
		cout << "Введите 1 для запуска, 0 для завершения программы >";
		cin >> chek;
		switch (chek)
		{
		case(0):
			break;
		case(1):
		{
			srand(time(0));
			int n;
			bool chekk = 1;

			while (chekk = 1)
			{
				cout << "Введите n. Для единичного запуска программы добавьте к желаемому числу дробную часть. >";
				cin >> n;
				if (n < 0)
				{
					cout << "Некорректное значение" << endl;
					continue;
				}
				break;
			}

			int** mass1 = new int* [n];
			for (int i = 0; i < n; i++)
				mass1[i] = new int[n];

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					mass1[i][j] = rand()%10;

			int ub=0, voz=0, rav=0, un=0;

			for (int i = 0; i < n; i++)
			{
				int un2 = un;
				if (mass1[i][1] < mass1[i][0])
				{
					for (int j = 2; j<= n; j++)
					{
						if (mass1[i][j] > mass1[i][j-1])
						{
						    un += 1;
							break;
						}
					}
					if (un == un2) ub += 1;
					continue;
				}

				if (mass1[i][1] > mass1[i][0])
				{
					for (int j = 2; j <= n; j++)
					{
						if (mass1[i][j] < mass1[i][j-1])
						{
							un += 1;
							break;
						}
					}
					if (un == un2)voz += 1;
					continue;
				}

				if (mass1[i][1] = mass1[i][0])
				{
					for (int j = 2; j <= n; j++)
					{
						if ((mass1[i][j] > mass1[i][j-1]) or (mass1[i][j] < mass1[i][j-1]))
						{
							un += 1;
							break;
						}
					}
					if (un == un2)rav += 1;
					continue;
				}

			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << mass1[i][j] <<' ';
				cout << endl;
			}
			cout << endl << "Количество по:" << endl << "Убыванию >" << ub << endl << "Ворзрастанию >";
			cout << voz << endl<<"Равенству >"<< rav << endl << "Отсутсвию сортировки>"<< un << endl;

		}
		default:
		{
			cout << endl;
			chek = 1;
			continue;
		}
		}
	}
}