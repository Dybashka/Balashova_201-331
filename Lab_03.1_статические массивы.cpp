/*
1.Сортирует числовой массив (длины не более 1000) по возрастанию по алгоритму пузырьковой сортировки. 
Саму сортировку написать отдельной функцией. 
Массив, введенный пользователем передавать в функцию сортировки.

2.Сортирует символьный массив (буквы a-z) (длины не более 1000) по возрастанию по 
алгоритму сортировки подсчетом. Саму сортировку написать отдельной функцией. 
Массив, введенный пользователем передавать в функцию сортировки.

3.Сортирует числовой массив (длины не более 1000) по возрастанию по алгоритму сортировки слиянием. 
Саму сортировку написать отдельной функцией. 
Массив, введенный пользователем передавать в функцию сортировки.
*/
#include <iostream>
using namespace std;
//сортировка пузырьком
void task1()
{
	int arr[10000], n;
	cin >> n;
	cout << "Введите массив: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int j = 0; j < n - 1; j++)
		for (int i = j; i < n; i++)
		{
			if (arr[j] > arr[i])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}
//сортировка подсчётом
void task2()
{
	char array[10000];
	int n, c[26] = {0};
	cin >> n;
	cout << "Введите массив: ";

	for (int i = 0; i < n; i++)
		cin >> array[i];

	for (int i = 0; i < n; i++)
	{
		int x = static_cast<int>(array[i]) - 97;
		c[x]++;
	}

	int b = 0;

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < c[i]; j++)
		{
			array[b] = static_cast<char>(i + 97);
			b++;
		}

	for (int i = 0; i < n; i++)
		cout << array[i] << ' ';
}
//сортировка слияния
void merge(int* a, int l, int r)
{
	int l_curr = l, r_curr = (l + r) / 2 + 1;
	int mas[1000] = { 0 };//результат слияния тут
	for (int i = l; i < r; i++)
	{
		if ((l_curr < (l + r) / 2 + 1) && (r_curr < r + 1))//если обе половины не закончились
			if (a[l_curr] < a[r_curr]) 
			{
				mas[i] = a[l_curr];
				l_curr++;
			}
			else
			{
				mas[i] = a[r_curr];
				r_curr++;//mas[i] = a[l_curr] < a[r_curr] ? a[l_curr] : a[r_curr]; теpнарный оператор
			}
											 					   
		else
			if (l_curr < (l + r) / 2 + 1)
			{
				mas[i] = a[l_curr];//если закончились значения спава
				l_curr++;
			}
			else
			{
				mas[i] = a[r_curr];//если закончились значения слева
				r_curr++;
			}//mas[i] = a[l_curr] * int(l_curr < (l + r) / 2 + 1) + a[r_curr] * int(r_curr < r + 1); тернарный оператор
																								 
																								
	}
	for (int i = l; i < r+1; i++)
		a[i] = mas[i];
}
void task3(int* a ,int l,int r)//сама функция сортировки
{
	if (r - l > 1)
	{
		task3(a, l, (l + r) / 2);
		task3(a, (l + r) / 2 + 1, r);
		merge(a, l, r);
	}
	else
		if (l = r) return;
		else
			if (a[r] < a[l])
			{
				int temp = a[r];
				a[r] = a[l];
				a[l] = temp;
			}
}
//меню
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	cout << "Что вы хотиете выполнить?\n1.Сортировка пузырьком 1\n2.Сортировка подсчётом 2\n3.Сортировка слияния 3\n4.Выход" << endl;
	while (choice != 4)
	{
		cout << "\nЧто вы хотиете выполнить?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите  колличество эллементов массива: ";
			task1();
			break;
		}
		case 2:
		{
			cout << "Введите колличество эллементов массива: ";
			task2();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Введите колличество эллементов массива: ";
			int a[10000], l = 0, r, n;
			cin >> n;
			r = n;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			task3(a,0,n);
			for (int i = 0; i < n; i++) {
				cout << a[i]<<' ';
			}
			break;
		}
		}
	}
	return 0;
}