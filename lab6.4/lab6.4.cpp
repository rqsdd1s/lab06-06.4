// lab6.4.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.4, ітераційний спосіб. Варіант 18.
// У динамічному масиві з n дійсних елементів обчислити:
//   1.1. Кількість елементів масиву, менших C.
//   1.2. Суму цілих частин елементів, розташованих після останнього
//        від'ємного елемента.
// 2. Переставити елементи так, щоб спочатку йшли всі елементи, що
//    відрізняються від максимального не більше ніж на 20 %, а потім - всі
//    інші. Відносне розташування елементів зберегти.
// Параметри n, C вводяться з клавіатури.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

// заповнює масив a випадковими дійсними числами з діапазону [Low; High]
void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + (High - Low) * rand() / RAND_MAX;
}

// виводить масив a в один рядок, 2 знаки після коми
void Print(double* a, const int size)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < size; i++)
        cout << setw(8) << a[i];
    cout << endl;
}

// 1.1. повертає кількість елементів, менших C
int CountLess(double* a, const int size, const double C)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < C)
            k++;
    return k;
}

// повертає індекс останнього від'ємного елемента, або -1, якщо таких немає
int IndexLastNegative(double* a, const int size)
{
    for (int i = size - 1; i >= 0; i--)
        if (a[i] < 0)
            return i;
    return -1;
}

// 1.2. повертає суму цілих частин елементів з номерами start, ..., size-1
int SumIntParts(double* a, const int size, const int start)
{
    int S = 0;
    for (int i = start; i < size; i++)
        S += (int)a[i];                 // (int) відкидає дробову частину
    return S;
}

// повертає значення максимального елемента
double Max(double* a, const int size)
{
    double maxValue = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > maxValue)
            maxValue = a[i];
    return maxValue;
}

// повертає true, якщо x відрізняється від maxValue не більше ніж на 20 %
bool IsNearMax(const double x, const double maxValue)
{
    return maxValue - x <= 0.2 * fabs(maxValue);
}

// копіює з a в t (починаючи з позиції k) ті елементи, для яких
// IsNearMax(...) == nearMax; повертає нове значення k
int CopyGroup(double* a, const int size, double* t, int k,
              const double maxValue, const bool nearMax)
{
    for (int i = 0; i < size; i++)
        if (IsNearMax(a[i], maxValue) == nearMax)
        {
            t[k] = a[i];
            k++;
        }
    return k;
}

// копіює всі елементи масиву from у масив to
void CopyArray(double* from, double* to, const int size)
{
    for (int i = 0; i < size; i++)
        to[i] = from[i];
}

// 2. переставляє елементи: спочатку "близькі до максимуму", потім інші
void Rearrange(double* a, const int size)
{
    double maxValue = Max(a, size);
    double* t = new double[size];       // допоміжний динамічний масив

    int k = 0;
    k = CopyGroup(a, size, t, k, maxValue, true);   // спочатку близькі до max
    k = CopyGroup(a, size, t, k, maxValue, false);  // потім усі інші

    CopyArray(t, a, size);              // переписуємо результат назад в a
    delete[] t;                         // звільняємо пам'ять
}

int main()
{
    srand((unsigned)time(NULL));        // ініціалізація генератора вип. чисел

    int n;
    cout << "n = "; cin >> n;
    if (n <= 0)
    {
        cout << "n must be > 0" << endl;
        return 0;
    }

    double C;
    cout << "C = "; cin >> C;

    double* a = new double[n];          // створюємо динамічний масив

    double Low = -10;
    double High = 20;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "1.1. Count (a[i] < C) = " << CountLess(a, n, C) << endl;

    int last = IndexLastNegative(a, n);
    if (last == -1)
        cout << "1.2. There are no negative elements" << endl;
    else
        cout << "1.2. Sum of int parts after last negative = "
             << SumIntParts(a, n, last + 1) << endl;

    Rearrange(a, n);
    cout << "2. Rearranged array (max = " << Max(a, n) << "):" << endl;
    Print(a, n);

    delete[] a;                         // знищуємо динамічний масив
    return 0;
}
