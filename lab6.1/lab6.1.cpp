// lab6.1.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.1, ітераційний спосіб. Варіант 18.
// Масив r із 26 цілих чисел, значення від 3 до 92.
// Критерій: всі, крім непарних або з індексами, кратними 7,
//           тобто елемент парний І його індекс НЕ кратний 7.
// Знайти кількість і суму таких елементів, потім замінити їх нулями.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// заповнює масив r випадковими числами з діапазону [Low; High]
void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        r[i] = Low + rand() % (High - Low + 1);
}

// виводить масив r в один рядок, кожне число займає 4 позиції
void Print(int* r, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i];
    cout << endl;
}

// повертає кількість елементів, які задовольняють критерій
int Count(int* r, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (r[i] % 2 == 0 && i % 7 != 0)
            k++;
    return k;
}

// повертає суму елементів, які задовольняють критерій
int Sum(int* r, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (r[i] % 2 == 0 && i % 7 != 0)
            S += r[i];
    return S;
}

// замінює нулями елементи, які задовольняють критерій
void Replace(int* r, const int size)
{
    for (int i = 0; i < size; i++)
        if (r[i] % 2 == 0 && i % 7 != 0)
            r[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    const int n = 26;                   // кількість елементів масиву
    int r[n];

    int Low = 3;                        // нижня межа діапазону
    int High = 92;                      // верхня межа діапазону

    Create(r, n, Low, High);
    Print(r, n);

    cout << "Count = " << Count(r, n) << endl;
    cout << "Sum   = " << Sum(r, n) << endl;

    Replace(r, n);                      // заміну робимо ПІСЛЯ підрахунку
    Print(r, n);

    return 0;
}
