// lab6.4r.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 6.4, рекурсивний спосіб. Варіант 18.
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
void Create(double* a, const int size,
            const double Low, const double High, int i)
{
    a[i] = Low + (High - Low) * rand() / RAND_MAX;
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// виводить масив a в один рядок, 2 знаки після коми
void Print(double* a, const int size, int i)
{
    cout << fixed << setprecision(2) << setw(8) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// 1.1. повертає кількість елементів, менших C, серед a[i], ..., a[size-1]
int CountLess(double* a, const int size, const double C, int i)
{
    if (i < size)
    {
        if (a[i] < C)
            return 1 + CountLess(a, size, C, i + 1);
        else
            return CountLess(a, size, C, i + 1);
    }
    else
        return 0;
}

// повертає індекс останнього від'ємного елемента, або -1, якщо таких немає
// йдемо з кінця: перший виклик IndexLastNegative(a, n, n - 1)
int IndexLastNegative(double* a, const int size, int i)
{
    if (i < 0)
        return -1;                      // переглянули все - від'ємних немає
    if (a[i] < 0)
        return i;
    return IndexLastNegative(a, size, i - 1);
}

// 1.2. повертає суму цілих частин елементів з номерами i, ..., size-1
int SumIntParts(double* a, const int size, int i)
{
    if (i < size)
        return (int)a[i] + SumIntParts(a, size, i + 1);
    else
        return 0;
}

// повертає значення максимального елемента
// перший виклик: Max(a, n, 0, a[0])
double Max(double* a, const int size, int i, double maxValue)
{
    if (a[i] > maxValue)
        maxValue = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, maxValue);
    else
        return maxValue;
}

// повертає true, якщо x відрізняється від maxValue не більше ніж на 20 %
bool IsNearMax(const double x, const double maxValue)
{
    return maxValue - x <= 0.2 * fabs(maxValue);
}

// копіює з a в t (починаючи з позиції k) ті елементи a[i], ..., a[size-1],
// для яких IsNearMax(...) == nearMax; повертає нове значення k
int CopyGroup(double* a, const int size, double* t, int k,
              const double maxValue, const bool nearMax, int i)
{
    if (i < size)
    {
        if (IsNearMax(a[i], maxValue) == nearMax)
        {
            t[k] = a[i];
            k++;
        }
        return CopyGroup(a, size, t, k, maxValue, nearMax, i + 1);
    }
    else
        return k;
}

// копіює всі елементи масиву from у масив to
void CopyArray(double* from, double* to, const int size, int i)
{
    to[i] = from[i];
    if (i < size - 1)
        CopyArray(from, to, size, i + 1);
}

// 2. переставляє елементи: спочатку "близькі до максимуму", потім інші
void Rearrange(double* a, const int size)
{
    double maxValue = Max(a, size, 0, a[0]);
    double* t = new double[size];       // допоміжний динамічний масив

    int k = 0;
    k = CopyGroup(a, size, t, k, maxValue, true, 0);  // спочатку близькі до max
    k = CopyGroup(a, size, t, k, maxValue, false, 0); // потім усі інші

    CopyArray(t, a, size, 0);           // переписуємо результат назад в a
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

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "1.1. Count (a[i] < C) = " << CountLess(a, n, C, 0) << endl;

    int last = IndexLastNegative(a, n, n - 1);
    if (last == -1)
        cout << "1.2. There are no negative elements" << endl;
    else
        cout << "1.2. Sum of int parts after last negative = "
             << SumIntParts(a, n, last + 1) << endl;

    Rearrange(a, n);
    cout << "2. Rearranged array (max = " << Max(a, n, 0, a[0]) << "):" << endl;
    Print(a, n, 0);

    delete[] a;                         // знищуємо динамічний масив
    return 0;
}
