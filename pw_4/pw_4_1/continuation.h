#pragma once
#include <string>

// Строковые константы
extern const std::string CONTINUATION_CHOICE_MSG;
extern const char YES;
extern const char NO;

/**
 * @brief Получение выбора пользователя о продолжении работы
 * @return true если пользователь выбрал 'y', false если 'n'
 * 
 * Функция запрашивает у пользователя подтверждение продолжения
 * и повторяет запрос до получения корректного ответа ('y' или 'n')
 */
bool getChoice();