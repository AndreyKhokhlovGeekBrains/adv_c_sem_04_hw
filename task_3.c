// Задание 3. Префикс и суффикс

// Реализовать программу 3-го практического задания более эффективным способом со сложностью О(n) (см. код в лекции).

// Пример №1
// Данные на вход:

// don't_panic
// nick_is_a_mastodon
// Данные на выход: 3

// Пример №2
// Данные на вход:

// monty_python
// python_has_list_comprehensions
// Данные на выход: 6

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 150

int findMaxPrefSuff(char* str1, char* str2) {
    int len_1 = strlen(str1);
    int len_2 = strlen(str2);

    for(int i = 0; i < len_1; i++) {
        int match = 1;
        for(int j = 0; (i+j) < len_1 && j < len_2; j++) {
            if(str1[i+j] != str2[j]) {
                match = 0;
                break;
            }
        }
        if(match && (len_1 - i) <= len_2) {
            return len_1 - i;
        }
    }
    return 0;
}

int main(void) {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter a line of text 1: \n");
    scanf("%s", str1);

    printf("Enter a line of text 2: \n");
    scanf("%s", str2);

    printf("Result: %d\n", findMaxPrefSuff(str1, str2));

    return 0;
}