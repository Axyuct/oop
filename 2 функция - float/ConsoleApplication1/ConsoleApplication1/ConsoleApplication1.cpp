

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian"); //русский шрифт

	float x;
	cout << "Введите x= ";
	cin >> x;


	float y = 2 * x * x + 3 * x + 8;

	float ch = pow(3 - x, 3);
	float zn = pow(x + 4.35, 2);
	float dr = abs(y - 13) / exp(1);
	float z = ch / zn + 10 * y + dr;

	cout << "\n y=" << y;
	cout << "\n z=" << z;

	cout.precision(12);
	cout << "\n y=" << y;
	cout << "\n z=" << z;

	cout << endl;
	system("pause");
}
