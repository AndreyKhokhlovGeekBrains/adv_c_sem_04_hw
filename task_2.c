// Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

// Пример №1
// Данные на вход: ( 3 & 5 ) ^ 4 | 9
// Данные на выход: 3 5 & 4 ^ 9 |

// Пример №2
// Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 )
// Данные на выход: 8 2 5 & ^ 6 1 & |

#include <stdio.h>
#include <ctype.h>

#define MAX_STACK 500
typedef struct stack_t {
    char operators[MAX_STACK + 1];
    int size;
} stack_t;

stack_t stack;
stack_t *st = &stack;

int precedence(char op) {
    switch (op)
    {
    case '|': return 1;
    case '^': return 2;
    case '&': return 3;
    default: return 0;
    }
}

void push(char op) {
    if(st->size == MAX_STACK) {
        printf("Error: stack overflow\n");
        return;
    }
    st->operators[st->size++] = op;
}

char pop() {
    if(st->size == 0) {
        printf("Error: stack underflow\n");
        return '\0';
    }
    return st->operators[--st->size];
}

char peek() {
    if (st->size == 0) {
        return '\0';
    }
    return st->operators[st->size - 1];
}

int is_empty() {
    return st->size == 0;
}

void process_operator(char op) {
    while (!is_empty() && precedence(peek()) >= precedence(op)) { 
        printf("%c ", pop());
    }
    push(op);
}

void process_parentheses() {
    while (!is_empty() && peek() != '(')
    {
        printf("%c ", pop());
    }
    pop(); // Remove the '(' from the stack
}

int main(void) {
    st->size = 0;
    int ch;

    while ((ch = getchar()) != EOF) { // When the user inputs the end-of-file indicator (typically Ctrl + D on Unix/Linux or Ctrl + Z on Windows), getchar() returns EOF, causing the loop to terminate.
        if (isdigit(ch)) {
            // If it's a digit, output it directly
            printf("%c ", ch);
        } else if (ch == '(') {
            // Push '(' to stack
            push(ch);
        } else if (ch == ')') {
            // Process until the matching '('
            process_parentheses();
        } else if (ch == '&' || ch == '^' || ch == '|') {
            // Process operator precedence
            process_operator(ch);
        } else if (ch == ' ' || ch == '\n') {
            // Ignore spaces and newlines
            continue;
        } else {
            break;;
        }
    }

    // Print remaining operators in the stack
    while (!is_empty()) {
        printf("%c ", pop());
    }

    return 0;
}