#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string str;
	cout << "Введите строку:";
	getline(cin, str);
	deque <char> deque_str;

	for (int i = 0; i < str.length(); i++)
		if ((str[i] >= 'A'&& str[i] <= 'Z') || ((str[i] >= 'a'&& str[i] <= 'z')))
			deque_str.push_front(str[i]);

	while (not deque_str.empty() && deque_str.front() == deque_str.back() && deque_str.size() != 1)
	{
		deque_str.pop_front();
		deque_str.pop_back();
	}

	if (deque_str.empty() || deque_str.size() == 1)
		cout << "Строка палиндром"<<endl;
	else 
		cout << "Строка не палиндром"<<endl;
	system("pause");
    return 0;
}
//live not on evil
