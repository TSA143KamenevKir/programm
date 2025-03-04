#include <iostream>
#include <cmath>
#include <iomanip> // Для форматирования вывода

using namespace std;
/**@brief-функция вычисления a и b по заданному уравнению
@param x-значение переменной x
@param y-значение переменной y 
@param z-значение переменной z
@return 1-Завершение программы с кодом ошибки
@return 0-возвращает рассчитанное значение
*/
int main() 
{
  // Объявление переменных
  double x, y, z;
  double a, b;

  // Задание констант (исходных данных)
  x = -4.8; // Пример значения
  y = 17.5; // Пример значения
  z = 3.2; // Пример значения

  // Вывод исходных данных
  cout << "Исходные данные:" << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;

  // Вычисление a
  if (sin(x / z) == 0.0) {
    cout << "Ошибка: Деление на ноль в sin^2(x/z)!" << endl;
    return 1; // Завершение программы с кодом ошибки
  }

  a = y * z * pow(x, 2) - (z / pow(sin(x / z), 2));

  // Вычисление b
  if (z < 0.0) {
    cout << "Ошибка: Отрицательное число под корнем!" << endl;
    return 1; // Завершение программы с кодом ошибки
  }
  b = z * exp(-sqrt(z)) * cos(y * x / z);


  // Вывод результатов
  cout << "\nРезультаты вычислений:" << endl;
  cout << "a = " << fixed << setprecision(6) << a << endl;  // вывод
  cout << "b = " << fixed << setprecision(6) << b << endl;  // вывод

  return 0;
}