#include <iostream>
#include <string>
//#include <cstring>
#include <map>
using namespace std;
int main()
{
	/*	setlocale(LC_ALL, "Russian");
	int col = 0;
	map<string, int> map_text;
	char str[250];
	cin >> str;
	char* next_p;
	char *pch = strtok_s(str, " ,.-",&next_p);    //раздел сроку на слова надо указать заки разделители
	while (pch != NULL)                  // пока есть лексемы
	{
		if (map_text.find(strtok_s(str, " ,.-", &next_p)) != map_text.end())
			map_text[strtok_s(str, " ,.-", &next_p)]++;
		else
			map_text[strtok_s(str, " ,.-",&next_p)] = 1;
		pch = strtok_s(NULL, " ,.-",&next_p);
		col++;
	}
	cout << "Общее количество слов: " << col << endl;
	cout << "Слово \t| Частота " << endl;
	for (auto q = map_text.begin(); q != map_text.end(); ++q)
	cout << q->first << "\t|  " << q->second * 100 / col << "%" << endl;
	system("pause");
	return 0;
	*/
	setlocale(LC_ALL, "Russian");
	string text;
	int col = 0;
	map <string, double> map_text;
	cout << "Введите текст (0 символ конца ввода): " << endl;
	cin >> text;
	while (text != "0")
	{
		if (map_text.find(text) != map_text.end()) //если итератор не перевёлся на конец то значение увел на 1
			map_text[text]++;
		else
			map_text[text] = 1;
		col++;
		cin >> text;
	}
	cout << "Общее количество слов: " << col << endl;
	cout << "Слово \t| Частота " << endl;
	 for (auto q = map_text.begin(); q != map_text.end(); ++q)
		cout << q->first << "\t|  " <<  100/col*q->second << "%" << endl;
	system("pause");
    return 0;
}
//wer sdf dc fv dc fv qwe qwe fv dc r 0
