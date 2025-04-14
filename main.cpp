#include <iostream>
#include <cmath>
#include <iomanip> // Для форматирования вывода

using namespace std;

/**@brief-функция вычисления a и b по заданному уравнению
*@param x-значение переменной x
*@param y-значение переменной y 
*@param z-значение переменной z
*/
double getA(const double x, const double y, const double z);

/**@brief-функция вычисления a и b по заданному уравнению
*@param x-значение переменной x
*@param y-значение переменной y 
*@param z-значение переменной z
*/
double getB(const double x, const double y, const double z);
/**@brief-точка входа в программу
*@return-возвращает 0
*/
int main() 
{ 
 const double x = -4.8; // Пример значения
 const double y = 17.5; // Пример значения
 const double  z = 3.2; // Пример значения
  // Вывод результатов
  cout << "\nРезультаты вычислений:" << endl;
  cout << "a = " << fixed << setprecision(6) << getA(x,y,z) << endl;  // вывод
  cout << "b = " << fixed << setprecision(6) << getB(x,y,z) << endl;  // вывод

  return 0;
}

double getA(const double x, const double y, const double z)
  {
   return y * z * pow(x, 2) - (z / pow(sin(x / z), 2));
  }
  
  double getB(const double x, const double y, const double z)
  {
   return z * exp(-sqrt(z)) * cos(y * x / z);
  }
