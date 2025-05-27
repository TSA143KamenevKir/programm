#include <iostream>
#include <iomanip>
#include <cstdlib> // для abs и rand
#include <ctime>   // для time

using namespace std;

// --- Функции ввода и проверки ---
/**
 * @brief Считывает значение с клавиатуры с проверкой ввода.
 * @return Введенное значение.
 */
int getValue();
/**
 * @brief Считывает размер массива с клавиатуры и проверяет его на положительность.
 * @return Размер массива (size_t).
 */
size_t getSize();
/**
 * @brief Проверяет, что введенное значение является положительным.
 * @param n - Значение для проверки.
 */
void checkPositive(const int n);
/**
 * @brief Проверяет, что значение start меньше значения end.
 * @param start - Начальное значение диапазона.
 * @param end - Конечное значение диапазона.
 */
void checkStep(const int start,const int end);

// --- Работа с динамическим массивом ---
/**
 * @brief Создает новый двумерный массив целых чисел.
 * @param rows - Количество строк.
 * @param cols - Количество столбцов.
 * @return Указатель на созданный двумерный массив (int**).
 */
int** createArray(size_t rows, size_t cols);
/**
 * @brief Освобождает память, занятую массивом.
 * @param array - Указатель на массив.
 * @param rows - Количество строк в массиве.
 */
void deleteArray(int** array, size_t rows);
/**
 * @brief Выводит содержимое двумерного массива на экран.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param cols - Количество столбцов.
 */
void printArray(int** array, size_t rows, size_t cols);
/**
 * @brief Заполняет массив элементами, вводимыми пользователем.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param cols - Количество столбцов.
 */
void fillArray(int** array, size_t rows, size_t cols);
/**
 * @brief Заполняет массив случайными числами в заданном диапазоне.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param cols - Количество столбцов.
 * @param start - Начало диапазона случайных чисел.
 * @param end - Конец диапазона случайных чисел.
 */
void fillArrayWithRandom(int** array, size_t rows, size_t cols, int start, int end);

// --- Логика задачи ---
/**
 * @brief Находит максимальный по модулю элемент в указанном столбце.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param col - Индекс столбца.
 * @return Максимальный по модулю элемент в столбце.
 */
int getMaxAbsInColumn(int** array, size_t rows, size_t col);
/**
 * @brief Заменяет нулевые элементы массива максимальными по модулю элементами в соответствующих столбцах.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param cols - Количество столбцов.
 */
void replaceZerosWithMax(int** array, size_t rows, size_t cols);
/**
 * @brief Находит индекс строки с максимальным элементом в указанном столбце.
 * @param array - Указатель на массив.
 * @param rows - Количество строк.
 * @param col - Индекс столбца.
 * @return Индекс строки с максимальным элементом.
 */
size_t findRowWithMaxInColumn(int** array, size_t rows, size_t col);
/**
 * @brief Вставляет строку, заполненную нулями, после указанной строки.
 * @param array - Указатель на массив (по ссылке для возможности изменения).
 * @param rows - Количество строк (по ссылке для возможности изменения).
 * @param cols - Количество столбцов.
 * @param insertAfterRow - Индекс строки, после которой будет вставлена новая строка.
 * @return Указатель на новый массив.
 */
int** insertZeroRow(int** array, size_t& rows, size_t cols, size_t insertAfterRow);
/**
 * @brief Вставляет строки, заполненные нулями, после каждого столбца, содержащего максимальный по модулю элемент.
 * @param array - Указатель на массив (по ссылке для возможности изменения).
 * @param rows - Количество строк (по ссылке для возможности изменения).
 * @param cols - Количество столбцов.
 */
void insertZeroRowsAfterMaxColumns(int**& array, size_t& rows, size_t cols);
/**
 * @brief Точка входа в программу.
 * @return 0.
 */
int main()
{
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    cout << "Enter m (rows): ";
    size_t m = getSize();
    cout << "Enter n (cols): ";
    size_t n = getSize();

    int** array = createArray(m, n);

    cout << "Do you want to fill the array manually (1) or randomly (2) ";
    int choice = getValue();
    if (choice == 1) {
        cout << "Fill the array manually:\n";
        fillArray(array, m, n);
    } else if (choice == 2) {
        cout << "Enter start value: ";
        int start = getValue();
        cout << "Enter end value: ";
        int end = getValue();
        checkStep(start,end);
        fillArrayWithRandom(array, m, n, start, end);
    } else {
        cout << "Invalid choice. Exiting." << endl;
        deleteArray(array, m);
        return 1;
    }

    cout << "Original Array:\n";
    printArray(array, m, n);

    replaceZerosWithMax(array, m, n);
    cout << "Array after replacing zeros with max abs elements:\n";
    printArray(array, m, n);

    insertZeroRowsAfterMaxColumns(array, m, n);
    cout << "Array after inserting zero rows:\n";
    printArray(array, m, n);

    deleteArray(array, m);
    return 0;
}

// --- Реализация функций ---

int getValue()
{
    int value=0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Input error" << endl;
        exit(EXIT_FAILURE);
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkPositive(n);
    return static_cast<size_t>(n);
}

void checkPositive(int n)
{
    if (n <= 0)
    {
        cout << "Value must be positive" << endl;
        exit(EXIT_FAILURE);
    }
}
void checkStep(const int start,const int end){
if(start>end)
{cout << "the value of start must be greater than end" << endl;
    abort();}}

int** createArray(size_t rows, size_t cols)
{
    int** array = new int*[rows];
    for (size_t i = 0; i < rows; i++)
        array[i] = new int[cols];
    return array;
}

void deleteArray(int** array, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        delete[] array[i];
    delete[] array;
}

void printArray(int** array, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            cout << setw(6) << array[i][j];
        cout << '\n';
    }
}

void fillArray(int** array, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Enter array[" << i << "][" << j << "]: ";
            array[i][j] = getValue();
        }
}

void fillArrayWithRandom(int** array, size_t rows, size_t cols, int start, int end)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            array[i][j] = rand() % (end - start + 1) + start; // Генерация случайного числа в диапазоне [start, end]
        }
}

int getMaxAbsInColumn(int** array, size_t rows, size_t col)
{
    int maxVal = array[0][col];
    for (size_t i = 1; i < rows; i++)
    {
        if (abs(array[i][col]) > abs(maxVal))
            maxVal = array[i][col];
    }
    return maxVal;
}

void replaceZerosWithMax(int** array, size_t rows, size_t cols)
{
    for (size_t col = 0; col < cols; col++)
    {
        int maxAbs = getMaxAbsInColumn(array, rows, col);
        for (size_t row = 0; row < rows; row++)
        {
            if (array[row][col] == 0)
                array[row][col] = maxAbs;
        }
    }
}

size_t findRowWithMaxInColumn(int** array, size_t rows, size_t col)
{
    int maxVal = array[0][col];
    size_t maxRow = 0;
    for (size_t i = 1; i < rows; i++)
    {
        if (array[i][col] > maxVal)
        {
            maxVal = array[i][col];
            maxRow = i;
        }
    }
    return maxRow;
}

int** insertZeroRow(int** array, size_t& rows, size_t cols, size_t insertAfterRow)
{
    int** newArray = createArray(rows + 1, cols);

    // Копируем строки до вставки
    for (size_t i = 0; i <= insertAfterRow; i++)
        for (size_t j = 0; j < cols; j++)
            newArray[i][j] = array[i][j];

    // Вставляем строку из нулей
    for (size_t j = 0; j < cols; j++)
        newArray[insertAfterRow + 1][j] = 0;

    // Копируем оставшиеся строки
    for (size_t i = insertAfterRow + 1; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newArray[i + 1][j] = array[i][j];

    deleteArray(array, rows);
    rows++;
    return newArray;
}

void insertZeroRowsAfterMaxColumns(int**& array, size_t& rows, size_t cols)
{
    // Чтобы корректно вставлять строки, идём с конца, чтобы индексы не смещались
    for (int col = static_cast<int>(cols) - 1; col >= 0; col--)
    {
        int maxAbs = getMaxAbsInColumn(array, rows, col);

        // Ищем первую строку с максимальным элементом в столбце
        size_t maxRow = rows; // если не нашли
        for (size_t row = 0; row < rows; row++)
        {
            if (array[row][col] == maxAbs)
            {
                maxRow = row;
                break;
            }
        }

        if (maxRow < rows)
        {
            array = insertZeroRow(array, rows, cols, maxRow);
        }
    }
}
