// lab6.2.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.2, ітераційний спосіб. Варіант 18.
// Функція, яка обчислює суму індексів максимального та мінімального
// елементів одновимірного масиву a із n елементів цілого типу.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює масив a випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив a в один рядок, кожне число займає 4 позиції
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// повертає індекс максимального елемента (першого, якщо їх кілька)
int IndexMax(int* a, const int size)
{
    int imax = 0;                       // вважаємо, що максимум - нульовий
    for (int i = 1; i < size; i++)
        if (a[i] > a[imax])
            imax = i;
    return imax;
}

// повертає індекс мінімального елемента (першого, якщо їх кілька)
int IndexMin(int* a, const int size)
{
    int imin = 0;                       // вважаємо, що мінімум - нульовий
    for (int i = 1; i < size; i++)
        if (a[i] < a[imin])
            imin = i;
    return imin;
}

// повертає суму індексів максимального та мінімального елементів
int SumIndexMaxMin(int* a, const int size)
{
    return IndexMax(a, size) + IndexMin(a, size);
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    const int n = 12;                   // кількість елементів масиву
    int a[n];

    int Low = -20;
    int High = 20;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "index max = " << IndexMax(a, n) << endl;
    cout << "index min = " << IndexMin(a, n) << endl;
    cout << "sum of indexes = " << SumIndexMaxMin(a, n) << endl;

    return 0;
}
