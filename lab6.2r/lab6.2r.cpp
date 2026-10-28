// lab6.2r.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.2, рекурсивний спосіб. Варіант 18.
// Функція, яка обчислює суму індексів максимального та мінімального
// елементів одновимірного масиву a із n елементів цілого типу.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює масив a випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив a в один рядок, кожне число займає 4 позиції
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// повертає індекс максимального елемента
// i    - номер поточного елемента
// imax - індекс найбільшого серед уже переглянутих елементів
// перший виклик: IndexMax(a, n, 0, 0)
int IndexMax(int* a, const int size, int i, int imax)
{
    if (a[i] > a[imax])
        imax = i;
    if (i < size - 1)
        return IndexMax(a, size, i + 1, imax);
    else
        return imax;
}

// повертає індекс мінімального елемента
// перший виклик: IndexMin(a, n, 0, 0)
int IndexMin(int* a, const int size, int i, int imin)
{
    if (a[i] < a[imin])
        imin = i;
    if (i < size - 1)
        return IndexMin(a, size, i + 1, imin);
    else
        return imin;
}

// повертає суму індексів максимального та мінімального елементів
int SumIndexMaxMin(int* a, const int size)
{
    return IndexMax(a, size, 0, 0) + IndexMin(a, size, 0, 0);
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    const int n = 12;                   // кількість елементів масиву
    int a[n];

    int Low = -20;
    int High = 20;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "index max = " << IndexMax(a, n, 0, 0) << endl;
    cout << "index min = " << IndexMin(a, n, 0, 0) << endl;
    cout << "sum of indexes = " << SumIndexMaxMin(a, n) << endl;

    return 0;
}
