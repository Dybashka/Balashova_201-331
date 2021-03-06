/*
1.Числовой треугольник

2.Нахождение биномиальных коэффициентов

3.Вычисление среднего арифметического введенных точек

4.выход
*/
#include <iostream>
#include <string>
using namespace std;
//задание 1
void task1()
{
	int num;
	cin >> num;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << j;
		cout << "\n";
	}
}
//задание 2
unsigned long long make_C(int k, int n)
{
	unsigned long long c;
	if (k == 0)
		c = 1;
	else
		c = make_C(k - 1, n) * (n - k + 1) / k;//рекурсия 
	return c;
}
void task2()
{
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		cout << make_C(i, N) << " ";
	}
}
//задание 3
void task3()
{
	int sum = 0, k = 0, num;
	string x;
	cin >> x;
	while (x != "stop")
	{
		num = atoi(x.c_str());//конст строка
		sum += num;
		k++;
		cin >> x;
	}
	cout << "Средне aрифмeтическoе данных координат равно: " << 1.0 * sum / k << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	cout << "Что вы хотиете выполнить?\n1.Задание 1\n2.Задание 2\n3.Задание 3\n4.Выход" << endl;
	while (choice!=4)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите целое положительное число: ";
			task1();
			break;
		}
		case 2:
		{
			cout << "Введите целое положительное число: ";
			task2();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Введите координаты точек (если вы ввели все данные напишите stop): ";
			task3();
			break;
		}
		}
		cout << "Что вы хотиете выполнить?"<<endl;
	}
	system("PAUSE");
	return 0;
}