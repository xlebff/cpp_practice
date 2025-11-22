#pragma once
#include <string>

extern const std::string ABORT;
extern const std::string NO_VALUES;

/**
 * @brief Очистка потока ввода после ошибки
 */
void errorClear();

/**
 * @brief Получение размера массива с валидацией
 * @param start_msg Сообщение для ввода
 * @param minValue Минимальное допустимое значение
 * @param maxValue Максимальное допустимое значение
 * @return Валидный размер массива
 */
int getSize(const std::string start_msg, int minValue, int maxValue);

/**
 * @brief Заполнение массива значениями
 * @param element Префикс элемента
 * @param array Указатель на массив
 * @param size Размер массива
 */
void fillArray(const std::string element, int* array, int size);

/**
 * @brief Заполнение массива значениями с ограничениями
 * @param element Префикс элемента
 * @param array Указатель на массив
 * @param size Размер массива
 * @param minValue Минимальное допустимое значение
 * @param maxValue Максимальное допустимое значение
 */
void fillArray(const std::string element, int* array, int size, int minValue, int maxValue);

/**
 * @brief Вывод массива в консоль
 * @param array Указатель на массив
 * @param size Размер массива
 * @param isReverse Флаг обратного порядка вывода
 */
void printArray(int* array, int size, bool isReverse = false);

void printExceptValue(int *array, const int size, int exeptValue);

/**
 * @brief Вывод массива с подписями элементов
 * @param element Префикс элемента
 * @param array Указатель на массив
 * @param size Размер массива
 * @param isReverse Флаг обратного порядка вывода
 */
void printArray(const std::string element, int* array, int size, bool isReverse = false);

/**
 * @brief Поиск минимального значения в массиве
 * @param array Указатель на массив
 * @param size Размер массива
 * @return Минимальное значение
 */
int getMinValue(int* array, int size);

/**
 * @brief Поиск максимального значения в массиве
 * @param array Указатель на массив
 * @param size Размер массива
 * @return Максимальное значение
 */
int getMaxValue(int* array, int size);

/**
 * @brief Вычисление суммы элементов массива
 * @param array Указатель на массив
 * @param size Размер массива
 * @return Сумма элементов
 */
int getSum(int* array, int size);

/**
 * @brief Вычисление среднего арифметического массива
 * @param array Указатель на массив
 * @param size Размер массива
 * @return Среднее арифметическое
 */
float getAverage(int* array, int size);

/**
 * @brief Увеличение размера массива
 * @param array Указатель на массив
 * @param size Текущий размер массива
 * @return Указатель на новый увеличенный массив
 */
int* extend(int* array, int size);

/**
 * @brief Проверка наличия значения в массиве
 * @param array Указатель на массив
 * @param size Размер массива
 * @param value Искомое значение
 * @return true если значение найдено, false в противном случае
 */
bool contains(int* array, int size, int value);

/**
 * @brief Добавление значения в массив
 * @param msg Сообщение для ввода
 * @param array Указатель на массив (передается по ссылке)
 * @param capacity Емкость массива (передается по ссылке)
 * @return Новая емкость массива
 */
int addValue(const std::string msg, int*& array, int& capacity);

/**
 * @brief Добавление уникального значения в массив
 * @param msg Сообщение для ввода
 * @param array Указатель на массив (передается по ссылке)
 * @param capacity Емкость массива (передается по ссылке)
 * @return Новая емкость массива
 */
int addUniqValue(const std::string msg, int*& array, int& capacity);

/**
 * @brief Удаление значения из массива
 * @param msg Сообщение для ввода
 * @param array Указатель на массив
 * @param size Размер массива
 */
void removeValue(const std::string msg, int* array, int size);

void clearArray(int *array, int size);