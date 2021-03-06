/*
написать набор функций для работы с файловой системой:
по введенному полному расположению файла получить расширение, название, 
расположение, название диска, переименование файла, вывести полный путь с названием. 
создать диалоговое меню.


Необходимо сделать меню, к которому можно обращаться несколько раз. 
Каждое задание делать в виде отдельной функции. 
К каждой функции написать комментарий: что она делает, что подается на вход, 
что на выход, какие входные данные изменяются в результате работы функции.

Написать набор функций для работы с файловой системой:
1.	string file_format(const string file_path_full) 
по введенному полному расположению файла получить расширение,
2.	string file_name(const string file_path_full) 
по введенному полному расположению файла получить название,
3.	string file_path (const string file_path_full) 
по введенному полному расположению файла получить расположение,
4.	char file_disk (const string file_path_full) 
по введенному полному расположению файла получить название диска,
5.	bool file_rename(string * file_path_full) 
по введенному полному расположению файла и новому имени  переименовать файл,
6.	bool file_copy(const string file_path_full) 
по введенному полному расположению файла создать копию файла 
(имя копии получается приписыванием  «_copy» к имени файла).

При реализации функций 1-5 должна реализовываться работа со строками 
(работа с файловой системой не происходит): 
разбор строк, получение нужной информации из строки, заданной определенным форматом.

В функции 6 нужно
а)	открыть файл, полное расположение которого задано аргументом file_path_full, 
если такого файла нет или он не открывается вернуть false;
б)	создать (открыть) файл, полное расположение которого получается из file_path_full 
приписыванием  «_copy» к имени файла, если неуспешно, вернуть false;
в)	реализовать построчное или посимвольное считывание из file_path_full и 
соответствующую запись в созданный файл. Буфер не должен быть меньше длины файла.
г)	Закрыть оба файла и вернуть true.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//задание 1 нахождение формата документа
string file_format(const string file_path_full)
{
	string format;
	for (int i = file_path_full.length(); i > 0; i--)
	{
		if (file_path_full[i] != '.')
			format = file_path_full[i] + format;
		else
		{
			format = file_path_full[i] + format;
			break;
		}
	}
	return format;
}
//задание 2 нахождение названия документа
string file_name(const string file_path_full)
{
	/*string name;
	int number=0;
	for (int i = 0; i < file_path_full.length(); i++)
	{
		if (file_path_full[i] == '\\')
			number = i;
		if (file_path_full[i] == '.')
			for (int j = i-1; j>number; j--)
				name = file_path_full[j]+ name;
	}
	return name;*/
	return file_path_full.substr(file_path_full.rfind('\\'));
}
//задание 3 нахождение путь к файлу
string file_path(const string file_path_full)
{
	string path;
	int number = 0;
	for (int i = 0; i < file_path_full.length(); i++)
		if (file_path_full[i] == '\\')
			number = i;
	for (int i = 0; i < number+1; i++)
		path += file_path_full[i];
	return path;
}
//задание 4 нахождение диска
char file_disk(const string file_path_full)
{
	char disk;
	disk = file_path_full[0];
	return disk;
}
//задание 5 изменение имени файла 
bool file_rename(string *file_path_full)
{
	string rename;
	cout << "Введите новое название файла ";
	cin.ignore();
	getline(cin, rename);
	for (int i = 0; i < rename.length(); i++)
		if (rename[i] == '\\' || rename[i] == '|' || rename[i] == '&' || rename[i] == '/' || rename[i] == ':' || rename[i] == '*' || rename[i] == '>' || rename[i] == '<' || rename[i] == '"')
			return false;

	int number = 0;
	for (int i = 0; i < (*file_path_full).length(); i++)
		if ((*file_path_full)[i] == '\\')
			number = i;

	string format;
	for (int i = (*file_path_full).length(); i > 0; i--)
	{
		if ((*file_path_full)[i] != '.')
			format = (*file_path_full)[i] + format;
		else
		{
			format = (*file_path_full)[i] + format;
			break;
		}
	}

	string path;
	int num = 0;
	for (int i = 0; i < (*file_path_full).length(); i++)
		if ((*file_path_full)[i] == '\\')
			num = i;
	for (int i = 0; i < num+1; i++)
		path += (*file_path_full)[i];

	*file_path_full = path;

	int j = 0;
	for (int i = number + 1; i < number + 1+rename.length(); i++)
	{
		(*file_path_full) += rename[j];
		j++;
	}
	*file_path_full += format;
	return true;
}
//задание 6 копирование файла
bool file_copy(const string file_path_full)
{
	ifstream inf(file_path_full); //открытие файла
	if (!inf)
		return false;

	const string copy_file = file_path(file_path_full)  + file_name(file_path_full) + "_copy" + file_format(file_path_full);//формирование полного нахождения файла

	ofstream outf(copy_file); //создание копии файла 
	if (!outf)
		return false;

	outf << inf.rdbuf();//копирование из основного файла в копию

	inf.close();
	outf.close();

	return true;
}
//меню
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите строку:";
	string b_str;
	getline(cin, b_str);
	const string cb_str = b_str;

	int choice = 0;
	cout << "1 Определит формат документа\n2 Определить название файла\n3 Определить полный путь к файлу\n4 Определить диск на котором находится файл\n5 Изменить имя файла\n6 Создание копии документа\n7 Выход" << endl;
	
	while (choice != 7)
	{

		cout << "\nЧто вы хотиете выполнить?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string str = file_format(b_str);
			cout << str << endl;
			break;
		}
		case 2:
		{
			string str = file_name(b_str);
			cout << str << endl;
			break;
		}
		case 3:
		{
			string str = file_path(b_str);
			cout << str << endl;
			break;
		}
		case 4:
		{
			char str = file_disk(b_str);
			cout << str << endl;
			break;
		}
		case 5:
		{
			string* str_file;
			string str = b_str;
			bool reth;
			str_file = &str;
			reth = file_rename(str_file);
			if (reth==true)
				cout << str;
			else
				cout << reth;
			break;
		}
		case 6:
		{
			bool copy = file_copy(b_str);
			cout << copy;
			break;
		}
		}
	}
	return 0;
}