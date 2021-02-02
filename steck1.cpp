/*
Теория:

Считываем элемент.int main()
{
	stack <int> number_steck;
	int temp;
	cout << "Input stack:\n";
	for (int i=0;i<7;i++)
	{
		cin >> temp;
		number_steck.push(temp);//добавить элемент
	}
	cout << "\n Top element in steck is" << number_steck.top();//выдаёт верхний элемент 
	cout << endl;
	while (!number_steck.empty())
	{
		cout << number_steck.top();
		number_steck.pop();//удвление верхнего эл
	}
    return 0;
}

Проверить правильность скобочного выражения

Проверить правильность расстановки скобок(, ), [, ], { , }
в введенном пользователем выражении за линейное время
(один просмотр выражения).
2 + 4 - 5(87192479_7348) {
72648]76823[]->no
({})->yes
({ ) }->no


Алгоритм решения


Если это(, [или{ , то помещаем ее в стек.
Если это),] или }, то сравниваем с верхним элементом стека.
Если образовалась пара, то верхний элемент стека удаляем.
Иначе - выражение неправильное.

Когда все элементы считали, то проверяем стек на пустоту.
Если стек пуст, то выражение правильное.
Иначе - выражение неправильное.
*/

#include <stack>
#include<iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	stack <char> number_steck;
	string exampl;
	cout << "Введите пример:";
	getline(cin, exampl);
	for (int i = 0; i < exampl.length(); i++)
	{
		if (exampl[i] == '(' || exampl[i] == '[' || exampl[i] == '{')
			number_steck.push(exampl[i]);
		if (exampl[i] == ')' || exampl[i] == ']' || exampl[i] == '}')
		{
			if (number_steck.empty())
			{
				cout << "Выражение неверно" << endl;
				system("PAUSE");
				return 0;
			}
			else
				if ((number_steck.top() == '('&& exampl[i] == ')') 
					|| (number_steck.top() == '['&& exampl[i] == ']') 
					|| (number_steck.top() == '{'&& exampl[i] == '}'))
				{
					number_steck.pop();
				}
			else
			{
				cout << "Выражение неверно" << endl;
				system("PAUSE");
				return 0;
			}
		}
	}
	if (number_steck.empty())
		cout << "Выражение верно" << endl;
	else
		cout << "Выражение неверно" << endl;
	system("PAUSE");
	return 0;
}