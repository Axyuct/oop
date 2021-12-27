#include <iostream>
#include <ctime>

using namespace std;

void main()
{
    srand(time(0));
    int** A, n, m, count = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    A = new int* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            //A[i][j] = rand() % 100;//если нужны случайные числа
            A[i][j] = i * j;
            //cin >> A[i][j];//если нужно вводить с клавиатуры
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; k++)
        for (int i = 1; i < m - 1; i++)
        {
            bool flag = true;
            int j;
            for (j = 0; j < i; j++)
                flag &= A[k][j] < A[k][i];
            for (j = i + 1; j < m; j++)
                flag &= A[k][j] > A[k][i];
            if (flag)
                //cout << A[k][i] << endl;//если нужно выводить "особые" элементы
                count++;
        }
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
    cout << "\n 'Special': " << count << endl;
    system("pause");
}