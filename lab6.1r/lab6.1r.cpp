// lab6.1r.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.1, рекурсивний спосіб. Варіант 18.
// Масив r із 26 цілих чисел, значення від 3 до 92.
// Критерій: всі, крім непарних або з індексами, кратними 7,
//           тобто елемент парний І його індекс НЕ кратний 7.
// Знайти кількість і суму таких елементів, потім замінити їх нулями.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює масив r випадковими числами з діапазону [Low; High]
// i - номер поточного елемента (перший виклик з i = 0)
void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}

// виводить масив r в один рядок, кожне число займає 4 позиції
void Print(int* r, const int size, int i)
{
    cout << setw(4) << r[i];
    if (i < size - 1)
        Print(r, size, i + 1);
    else
        cout << endl;
}

// повертає кількість елементів, які задовольняють критерій,
// серед елементів з номерами i, i+1, ..., size-1
int Count(int* r, const int size, int i)
{
    if (i < size)
    {
        if (r[i] % 2 == 0 && i % 7 != 0)
            return 1 + Count(r, size, i + 1);
        else
            return Count(r, size, i + 1);
    }
    else
        return 0;
}

// повертає суму елементів, які задовольняють критерій,
// серед елементів з номерами i, i+1, ..., size-1
int Sum(int* r, const int size, int i)
{
    if (i < size)
    {
        if (r[i] % 2 == 0 && i % 7 != 0)
            return r[i] + Sum(r, size, i + 1);
        else
            return Sum(r, size, i + 1);
    }
    else
        return 0;
}

// замінює нулями елементи, які задовольняють критерій
void Replace(int* r, const int size, int i)
{
    if (r[i] % 2 == 0 && i % 7 != 0)
        r[i] = 0;
    if (i < size - 1)
        Replace(r, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    const int n = 26;                   // кількість елементів масиву
    int r[n];

    int Low = 3;                        // нижня межа діапазону
    int High = 92;                      // верхня межа діапазону

    Create(r, n, Low, High, 0);
    Print(r, n, 0);

    cout << "Count = " << Count(r, n, 0) << endl;
    cout << "Sum   = " << Sum(r, n, 0) << endl;

    Replace(r, n, 0);                   // заміну робимо ПІСЛЯ підрахунку
    Print(r, n, 0);

    return 0;
}
