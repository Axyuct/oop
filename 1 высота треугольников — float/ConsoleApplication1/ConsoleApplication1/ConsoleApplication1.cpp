

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //русский шрифт

    cout.precision(12);

    float a = 12.1;
    float b = 8.82;
    float c = 10.21;

    float p = a + b + c;
    float ha = sqrt(p * (p - a) * (p - b) * (p - c)) * 2 / a;
    float hb = sqrt(p * (p - a) * (p - b) * (p - c)) * 2 / b;
    float hc = sqrt(p * (p - a) * (p - b) * (p - c)) * 2 / c;

    cout << "\n Высота ha=" << ha;
    cout << "\n Высота hb=" << hb;
    cout << "\n Высота hc=" << hc;

    float ma = sqrt(2*b*b+2*c*c-a*a) / 2;
    float mb = sqrt(2 * a *a + 2 * c * c - b * b) / 2;
    float mc = sqrt(2 * b * b + 2 * a * a - c * c) / 2;

    cout << "\n Медиана ma=" << ma;
    cout << "\n Медиана mb=" << mb;
    cout << "\n Медиана mc=" << mc;

    float ba = 2 * sqrt(b * c * p * (p - a)) / (b + c);
    float bb = 2 * sqrt(a * c * p * (p - b)) / (a + c);
    float bc = 2 * sqrt(b * a * p * (p - c)) / (b + a);

    cout << "\n Биссектриса ba=" << ba;
    cout << "\n Биссектриса bb=" << bb;
    cout << "\n Биссектриса bc=" << bc;

    cout << endl;
    system("pause");
}
