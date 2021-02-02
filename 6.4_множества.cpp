#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество элементов в списке:";
	cin >> n;
	cout << "\nВведите список:"<<endl;
	unordered_set <int> key_itog;
	queue <string> otv_itog;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		string otv;
		int key;
		cin >> key >> otv;
		key_itog.insert(key);
		if (k < key_itog.size())
		{
			k = key_itog.size();
			otv_itog.push(otv);
		}
	}
	for (unordered_set<int>::iterator q = key_itog.begin(); q != key_itog.end(); ++q)//q - это указатель на эл. идём с 1 до последнего эл
	{
		cout << *q << " " << otv_itog.front() << endl;
		otv_itog.pop();
	}
	system("pause");
    return 0;
}