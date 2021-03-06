/*
1.Ввод массива

2.Вывод массива в консоль

3.Сортировка по сумме цифр, стоящих на четных местах

4.Отсортировать массив вначале по возрастанию последней цифры, 
а при совпадении последних цифр - по убыванию.

5.выход
*/
#include <iostream>
using namespace std;
//задание 2
void task2(int& a,int n)//вывод массива
{
	int* mass = &a;
	for (int i = 0; i < n; i++)
		cout << mass[i]<<' ';
	cout << endl;
}
//задание 3
int sum(int num)//нахождение суммы элементов массива наход. на чётных позициях 
{
	int k=0, SUM=0, num1 = num;
	while (num1 != 0)
	{
		k++;
		num1 /= 10;
	}
	int* mass_num = new int[k];
	for (int i=k-1;i>=0;i--)
	{ 
		mass_num[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < k; i++)
	{
		if (i % 2 == 0)
			SUM += mass_num[i];
	}
	return SUM;
}
void task3(int& a, int n)//упорядочивание массива 
{
	int* mass = &a;
	for (int j = 0; j < n - 1; j++)//сортировка всего массива по суммам 
		for (int i = j; i < n ; i++)
		{
			if (sum(mass[j]) > sum(mass[i]))
			{
				int t = mass[i];
				mass[i] = mass[j];
				mass[j] = t;
			}
		}

	for (int w = 0; w < n-1; w++)
	{
		int  q= w + 1,k=1;

		while (sum(mass[w])==sum(mass[q]))//нахождение кусков массива с одинаковыми суммами
		{
			q++;
			k++;
			if (q >= n)
				break;
		}

		if (k != 1)
		{
			for (int j = w; j < w+k-1; j++)//сортировка кусочка с одинаковыми суммами
				for (int i = j + 1; i < w + k; i++)
				{
					if (mass[j] < mass[i])
					{
						int t = mass[i];
						mass[i] = mass[j];
						mass[j] = t;
					}
				}
		}
	}
}
//задание 4
void task4(int& a, int n)//упорядочивание массива по последней цифре 
{
	int* mass = &a;
	for (int j = 0; j < n - 1; j++)//сортировка всего массива по последей цифре
		for (int i = j; i < n; i++)
		{
			if ((mass[j]%10) > (mass[i]%10))
			{
				int t = mass[i];
				mass[i] = mass[j];
				mass[j] = t;
			}
		}

	for (int w = 0; w < n - 1; w++)
	{
		int  q = w + 1, k = 1;

		while ((mass[w]%10) == (mass[q]%10))//нахождения кусочка массива с одинаковыми последними цифрами
		{
			q++;
			k++;
			if (q >= n)
				break;
		}

		if (k != 1)
		{
			for (int j = w; j < w + k - 1; j++)//сортировка кусочка массива с одинаковыми последними цифрами
				for (int i = j + 1; i < w + k; i++)
				{
					if (mass[j] < mass[i])
					{
						int t = mass[i];
						mass[i] = mass[j];
						mass[j] = t;
					}
				}
		}
	}
}
//меню
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int n;
	int* a = new int[0];
	bool err = true;
	cout << "1.Объявление массив 1\n2.Вывод массива 2\n3.Сортирова по сумме 3\n4.Сортировка по последней цифре 4\n5.Выход\n" << endl;
	while (choice != 5)
	{
		cout << "\nЧто вы хотиете выполнить?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			//задание 1
			cout << "Введите  колличество эллементов массива: ";
			cin >> n;
			cout << "Введите эллементы массива:";
			a = new int[n];
			for (int i = 0; i < n; i++)
				cin >> a[i];
			err = false;
			break;
		}
		case 2:
		{
			if (err)
			{
				cout << "Вы не ввели массив!" << endl;
				break;
			}
			task2(*a, n);
			break;
		}
		case 3:
		{
			if (err)
			{
				cout << "Вы не ввели массив!" << endl;
				break;
			}
			task3(*a, n);
			break;
		}
		case 4:
		{
			if (err)
			{
				cout << "Вы не ввели массив!" << endl;
				break;
			}
			task4(*a, n);
			break;
		}
		}
	}
	return 0;
}