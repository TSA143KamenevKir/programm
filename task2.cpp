#include <iostream>
#include <cmath>   // Для sqrt() (корень квадратный)

using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getValue();

/**
 * @brief Вычисляет площадь прямоугольника
 * @param a Длина прямоугольника
 * @param b Ширина прямоугольника
 * @return Площадь прямоугольника
 */
double getRectangleArea(const double a, const double b);

/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 * @param a Первая сторона треугольника
 * @param b Вторая сторона треугольника
 * @param c Третья сторона треугольника
 * @return Площадь треугольника
 */
double getTriangleArea(const double a, const double b, const double c);

/**
 * @brief Проверяет существование треугольника по введенным сторонам
 * @param a Первая сторона треугольника
 * @param b Вторая сторона треугольника
 * @param c Третья сторона треугольника
 */
void checkExist(const double a, const double b, const double c);

 /**@brief проверяет положителины ли стороны треугольника
 * @param a Длина прямоугольника
 * @param b Ширина прямоугольника 
 */
 void checkPositive(const double a, const double b, const double c);
 /**@brief проверяет положителины ли стороны прямоугольника
  * @param a Первая сторона треугольника
 * @param b Вторая сторона треугольника
 * @param c Третья сторона треугольника
 */
 
 void checkPositiveB(const double length, const double width);
 /**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
 {

            cout << "Enter the length of the rectangle: ";
            double length = getValue();
            cout << "Enter the width of the rectangle: ";
            double width = getValue();
            checkPositiveB( length,width);
            cout << "Area of the rectangle is: " << getRectangleArea(length, width) << endl;
           
        
        
           cout << "Enter the first side of the triangle: ";
            double a = getValue();
            cout << "Enter the second side of the triangle: ";
            double b = getValue();
            cout << "Enter the third side of the triangle: ";
            double c = getValue();
            checkPositive( a, b, c);
            

            checkExist(a, b, c); // Проверка существования треугольника

            cout << "Area of the triangle is: " << getTriangleArea(a, b, c) << endl;
        

    return 0;
}

double getValue() 
{
    double value=0;
    cin >> value;
    if (cin.fail()) {
        cout << "Incorrect value." << endl;
        abort();
    }
    return value;
}

double getRectangleArea(const double a, const double b) 
{
    return a * b;
}

double getTriangleArea(const double a, const double b, const double c)
{
    double p = (a + b + c) / 2.0; // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Формула Герона
}

void checkExist(const double a, const double b, const double c)
{
    if (a + b <= c or a + c <= b or b + c <= a)
    {
        cout<<"It can't be triangle"<<endl;
        abort();
        }}
void checkPositive(const double a, const double b, const double c)
            {
            if (a<0 or b<0 or c<0)
            {
            cout<<"A negative value has been entered"<<endl;
            abort();
            }}
 void checkPositiveB(const double length,const double width)
            {
            if (length<0 or width<0)
            {
            cout<<"A negative value has been entered"<<endl;
            abort();
            }}
