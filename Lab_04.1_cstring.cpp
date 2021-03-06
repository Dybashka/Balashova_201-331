/*
Необходимо сделать меню, к которому можно обращаться несколько раз. 
Каждое задание делать в виде отдельной функции. 
К каждой функции написать комментарий: что она делает, что подается на вход, 
что на выход, какие входные данные изменяются в результате работы функции.
Считывание С-строки:
1 способ :
int i = 0;
char text[255];
cin>>text[i];
while(text[i] != ‘.‘
{
i++; cin>>text[i];
}
text[i]=’\n’;
2 способ:
cin.getline(…)
3 способ
scanf

1) проверка на палиндром
Пользователь вводит строку не более 255 символов, возможно с пробелами. Реализовать функцию
bool Palindrom(char* str),
которая проверяет, является ли строка палидромом 
(читается одинаково с разных сторон, пробелы не считаются: «А роза упала на лапу Азора»). 
Критерий качества – наименьшее количество операций.
А роза упала на лапу Азора
i                               j
Цикл (по i=0, j=len-1; i<j; i++, j--)
Если text[i]==’ ‘ то i++
Если text[j]==’ ‘ то j—
Если большая буква, то ее сделать маленькой.
Сравнить text[i] и text[j]

2) поиск подстроки в строке
Реализовать функцию, которая находит все вхождения заданной подстроки в заданную строку:

int find_substring1(const char * str_for_search_in, const char * substring, int start_position)
– возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in, 
поиск ведется с позиции start_position.

int* find_substring2(const char * str_for_search_in, const char * substring) 
– возвращает массив всех позиций вхождения подстроки в строку.

Вход: str_for_search_in =”abcghds\frghd okughn_jyghde”
substring = “ghd”
Выход: [3, 10, 23]

3) шифрование сдвигами (шифр Цезаря)
Вход 	«abcdefgh ijk”   2
Выход  	«cdefghij klm”

void encrypt(char* str_for_encrypt, int key)

результат шифрования записать в str_for_encrypt

4) на вход получаете некоторый текст, который введен с клавиатуры.
Вывести все названия (то, что внутри кавычек) из текста. Названия могут содержать пробелы.
Вход: fhgfdsaghfd «jhjg gjhg” jhxkjhvk “jhgjhgjhg kjhkjh kjhkj/-345678”hgjhg
Выход: jhjg gjhg | jhgjhgjhg kjhkjh kjhkj/-345678
*/
#include <iostream>
#include <cstdio>
using namespace std;
int len_str(char * str)//нахождение длинны строки
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
		len++;
	return len;
}
//задание 1
void task1(char &st, int n)
{
	int q = 0, k = 0;
	char* str = &st;

	for (int i = 0; i < n; i++)
		if (str[i] > 'A'&& str[i] < 'Z')//замена заглавных букв на строчные 
			str[i] += ' ';

	for (int i = 0; i < n- i - 1 + q ; i++)
	{
		if (str[i] == ' ')//пропускание левого пробела 
		{
			i++;
			q++;
		}

		if (str[n - i - 1 + q] == ' ') //пропускание правого пробела 
			q--;

		if (str[i] != str[n - i - 1 + q]) 
		{
			k++;
			cout << "Строка не является палиндромом" << endl;
			break;
		}
	}
	if (k == 0)
		cout << "Строка является палиндромом" << endl;
}
//задание 2
int* task2(char  &str_search_, char &substr_, int start_position, int& size)
{
	char* str_search = &str_search_;
	char* substr = &substr_;
	int* arr = new int[len_str(str_search) / len_str(substr)];//массив для запоминания индексов входов 
	int ind, i_ind = 0;

	for (int i = start_position; str_search[i] != '\0'; i++)
	{
		bool is_find = false;

		if (str_search[i] == substr[0])
		{
			ind = i;
			is_find = true;

			for (int j = 0; substr[j] != '\0'; j++)
			{
				if (str_search[i] != substr[j])
				{
					i++;
					is_find = false;
					break;
				}

				i++;
			}

			i--;
		}

		if (is_find)
		{
			arr[i_ind] = ind;
			i_ind++;
		}
	}
	size = i_ind;
	return arr;
}
//задание 3
void task3(char &st, int key)
{
	char* str = &st;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') //пропуск пробела
		{
			i++;
		}
		str[i] += key;
		if (  )
	}

	printf(str);
}
//меню
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int n;
	char st[250];
	bool err = true;
	cout << "1.Опрелеление является ли строка палиондромом 1\n2.Функция find 2\n3.Шифрование строки 3\n4.Введение строки 4\n5.Выход\n" << endl;
	while (choice != 5)
	{
		cout << "\nЧто вы хотиете выполнить?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (err)
			{
				cout << "Вы не ввели строку!" << endl;
				break;
			}

			task1(*st, n);
			break;
		}
		case 2:
		{
			if (err)
			{
				cout << "Вы не ввели строку!" << endl;
				break;
			}

			int size;
			int start_position;
			char mini_str[250];

			cout << "Введите подстроку, которую необходимо найти: ";
			cin.ignore();
			gets_s(mini_str);

			cout << "Введите стартовую позицию поиска: ";
			cin >> start_position;
			int* arr = task2(*st, *mini_str, start_position, size);

			if (size == 0)
				cout << "нет вхождений";
			else
				for (int i = 0; i < size; i++)
					cout << arr[i] << " ";
			break;
		}
		case 3:
		{
			if (err)
			{
				cout << "Вы не ввели строку!" << endl;
				break;
			}
			int key;
			cout << "Введите key: ";
			cin >> key;
			task3(*st, key);
			break;
		}
		case 4:
		{
			//задание 4
			cout << "Введите строку:";
			cin.ignore(); //очищение потка
			gets_s(st);
			n = len_str(st);
			err = false;
			break;
		}
		}
	}
	return 0;
}