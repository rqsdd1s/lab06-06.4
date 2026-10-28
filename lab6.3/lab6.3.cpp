// lab6.3.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.3, ітераційний спосіб. Варіант 18.
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
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив a в один рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// міняє місцями елементи в парах: a[0]<->a[1], a[2]<->a[3], ...
// якщо size непарне - останній елемент лишається на місці
void SwapPairs(int* a, const int size)
{
    int tmp;
    for (int i = 0; i + 1 < size; i += 2)
    {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
    }
}

// ---------- шаблони функцій (для будь-якого типу T) ----------

// виводить масив a будь-якого типу в один рядок
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// міняє місцями елементи в парах для масиву будь-якого типу
template <typename T>
void SwapPairs(T* a, const int size)
{
    T tmp;
    for (int i = 0; i + 1 < size; i += 2)
    {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
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
    Create(a, n, Low, High);
    cout << "SwapPairs(a, n):" << endl;
    Print(a, n);
    SwapPairs(a, n);
    Print(a, n);

    // 2) шаблон з типом int
    int b[n];
    Create(b, n, Low, High);
    cout << "SwapPairs<int>(b, n):" << endl;
    Print<int>(b, n);
    SwapPairs<int>(b, n);
    Print<int>(b, n);

    // 3) шаблон з типом double
    double c[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.1 };
    cout << "SwapPairs<double>(c, n):" << endl;
    Print<double>(c, n);
    SwapPairs<double>(c, n);
    Print<double>(c, n);

    return 0;
}
