// lab6.3r.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.3, рекурсивний спосіб. Варіант 18.
// Функція, яка міняє місцями елементи масиву з парними та непарними
// індексами - тобто міняє місцями перший та другий, третій та
// четвертий і т.д. елементи.
// Реалізовано двома способами: звичайні функції та шаблони функцій.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// ---------- звичайні функції (тільки для int) ----------

// заповнює масив a випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив a в один рядок
void Print(int* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// міняє місцями елементи в парах: a[i]<->a[i+1], потім a[i+2]<->a[i+3], ...
// перший виклик: SwapPairs(a, n, 0)
void SwapPairs(int* a, const int size, int i)
{
    if (i + 1 < size)                   // є пара: елементи i та i+1
    {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        SwapPairs(a, size, i + 2);      // переходимо до наступної пари
    }
}

// ---------- шаблони функцій (для будь-якого типу T) ----------

// виводить масив a будь-якого типу в один рядок
template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// міняє місцями елементи в парах для масиву будь-якого типу
template <typename T>
void SwapPairs(T* a, const int size, int i)
{
    if (i + 1 < size)
    {
        T tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        SwapPairs<T>(a, size, i + 2);
    }
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    const int n = 11;                   // непарна к-сть: перевіримо останній
    int Low = -50;
    int High = 50;

    // 1) звичайні функції
    int a[n];
    Create(a, n, Low, High, 0);
    cout << "SwapPairs(a, n, 0):" << endl;
    Print(a, n, 0);
    SwapPairs(a, n, 0);
    Print(a, n, 0);

    // 2) шаблон з типом int
    int b[n];
    Create(b, n, Low, High, 0);
    cout << "SwapPairs<int>(b, n, 0):" << endl;
    Print<int>(b, n, 0);
    SwapPairs<int>(b, n, 0);
    Print<int>(b, n, 0);

    // 3) шаблон з типом double
    double c[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.1 };
    cout << "SwapPairs<double>(c, n, 0):" << endl;
    Print<double>(c, n, 0);
    SwapPairs<double>(c, n, 0);
    Print<double>(c, n, 0);

    return 0;
}
