/*
1)ФИО, номер группы; (1 балл)

2)минимальные и максимальные значения встроенных типов данных, а так же их размер; (10 баллов)

3)запросить у пользователя некоторое целое число и вывести на экран это число в 
бинарном и шестнадцатиричном виде, а так же результат преобразования типов ко всем 
встроенным; (5 баллов)

4)записать условие и полное решение уравнения вида a*x = b(a отлично от нуля), 
причем значения коэффициентов(целые числа) вводит пользователь; (10 баллов)

5)записать программу для нахождения середины отрезка, 
заданного целыми координатами концевых точек.(10 баллов)
*/
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	//задание 1
	cout << "1." << endl;
	cout << "Balashova Daria, 201-331" << endl;
	// задание 2 (данные с сайта https://docs.microsoft.com/ru-ru/cpp/c-language/cpp-integer-limits?view=vs-2019)
	cout << "2." << endl;
	cout << "min int=-214748364, max int=214748363, size of int=" << sizeof(int) << endl;
	cout << "min unsigned int=0, max unsigned int=4294967295, unsigned int=" << sizeof(unsigned int) << endl;
	cout << "min short=-32768, max short=32767, size of short=" << sizeof(short) << endl;
	cout << "min unsigned short=0, max unsigned short=65535, size of unsigned short=" << sizeof(unsigned short) << endl;
	cout << "min long=-2147483648, max long=2147483647, size of long=" << sizeof(long) << endl;
	cout << "min long long=-9223372036854775808, max long long=9223372036854775807, size of long long=" << sizeof(long long) << endl;
	cout << "min double=1,7*(10^(-308)) ,max double=1,7*(10^308) ,size of double=" << sizeof(double) << endl;
	cout << "min char=-128, max char=127, size of char=" << sizeof(char) << endl;
	cout << "min bool=0 (false), max bool=1 (true), size of bool=" << sizeof(bool) << endl;
	//задание 3
	cout << "3." << endl;
	setlocale(LC_ALL, "Russian");
	int q; // q-водимео чило с которым проводятся преобразования
	cout << "Введите число:";
	cin >> q;
	cout << "В бинарном виде:" << bitset<32>(q) << endl; //вывод в бинарном виде
	cout << "В шеснадцатиричном виде:";
	printf("%x", q); //вывод в 16 системе
	cout << "\nbool " << (bool)q << "\ndouble " << (double)q << "\nchar " << (char)q << endl; //вывод в разных видах
	 //задание 4 (решение уравнения с выводом этого решения на экран)
	int a, b;//a,b коэффициенты уравнения
	cout << "4." << "\nВведите коэффициенты a*x=b:";
	cin >> a >> b;
	cout << a << "*x=" << b << endl;
	cout << "x=" << b << "/" << a << endl;
	cout << "x=" << 1.0*a / b << endl;
	//задание 5 (нахождение середины отрезка)
	int c, d;
	cout << "5." << "\nВведите координаты отрезка на прямой:";
	cin >> c >> d;
	cout << "Середина отрезка находится в точке с координатой " << (c + d) / 2. << endl;
	system("PAUSE");
	return 0;
}