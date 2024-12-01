#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Рекурсивная функция для вычисления суммы цифр
int sum_of_digits(char* str) {
    if (*str == '\0') {
        return 0;
    }
    // Если символ является цифрой, добавляем его к результату
    if (isdigit(*str)) {
        return (*str - '0') + sum_of_digits(str + 1);
    }
    // Иначе игнорируем символ и продолжаем
    return sum_of_digits(str + 1);
}

int main() {
    char input[100];

    while (1) {
        printf("Please enter a number: ");
        // Считываем строку ввода
        fgets(input, sizeof(input), stdin);

        // Убираем символ новой строки, если он есть
        input[strcspn(input, "\n")] = 0;

        // Проверяем, содержит ли строка только цифры
        int valid_input = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid_input = 0;
                break;
            }
        }

        if (valid_input) {
            // Если ввод корректный, вычисляем сумму цифр
            int sum = sum_of_digits(input);
            printf("Sum of digits: %d\n", sum);
            break;  // Выход из цикла
        }
        else {
            // Если ввод некорректный, выводим сообщение
            printf("Please enter a number without any other characters.\n");
        }
    }

    return 0;
}
