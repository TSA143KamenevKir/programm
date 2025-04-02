#include <iostream>
#include <cmath>
#include <iomanip> //для вывода
#include <limits> // Для numeric_limits

using namespace std;

// Функция для вычисления значения заданной функции
/**
* @brief проверка синуса на осмысленный числовой результат
* @param x - значение x
*/
 double calculateFunction (const double x);
 /**
 *@brief проверка значения шага
 *@param step - шаг
 */
 void checkStep(const double step);
 /**
 *@brief проверка интервала
 * @param start - начало интервала
 * @param end - конец интервала
 */
 double getValue();

int main() {
  
     cout<<"Enter start: ";
    double start = getValue();
    cout<<"Enter end: ";
    double end = getValue();
    cout<<"Enter step: ";
    double step = getValue();
    checkStep(step);

    cout << "---------------------------" << endl;
    cout << "|      x     |      y     |" << endl;
    cout << "---------------------------" << endl;

    // Табулирование функции
    for (double x = start; x <= end; x += step) 
    {
        double y = calculateFunction(x);
{
        cout << "| " << fixed << setprecision(6) << setw(10) << x << " | ";
            cout << fixed << setprecision(6) << setw(10) << y << " |" << endl;
        }
cout << "---------------------------" << endl;
}
}

  double calculateFunction (const double x) 
    {
    return x - (1.0/3.0 + sin(3.6 * x));
}

void checkStep(const double step)
{
    if(step <= 0 )
    {
        cout<<"Ошибка:неверное значение"<< endl;
        abort();
    }
}
    double getValue()
{
    double value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
    }
