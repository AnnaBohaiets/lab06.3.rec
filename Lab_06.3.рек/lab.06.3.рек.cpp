#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* Create(int n, const int Low, const int High, int* a = 0, int i = 0)
{
    if (a == 0)
    {
        a = new int[n];
    }

    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(n, Low, High, a, i + 1);
    }
    return a;
}

void Print(int* a, int n, int i = 0) {
    if (i < n) {
        cout << setw(5) << a[i];
        Print(a, n, i + 1);
    }
    else {
        cout << endl;
    }
}

int Sum(int* a, const int size, int i, int S)
{
    if (a[i] % 2 == 0)
        S += a[i];
    if (i < size - 1)
        return Sum(a, size, i + 1, S);
    else
        return S;
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cin >> n;
    const int Low = -100;
    const int High = 100;

    int* a = Create(n, Low, High);

    Print(a, n);
    int count = Sum(a, n, 0, 0);
    cout << "Sum of even elements  is " << count << endl;
    delete[] a; // Звільнення пам'яті

    return 0;
}
