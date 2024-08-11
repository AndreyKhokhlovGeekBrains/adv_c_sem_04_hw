// Задание 1. Биномиальный коэффициент
// 1-е практическое задание:
// Разыгрывается тираж лотереи. Участвует N номеров. Из них выпадает M номеров. Сколькими вариантами набора номеров это может произойти? Данные на вход: Два целых числа N и M Данные на выход: Одно целое число – количество вариантов

// Реализовать программу 1-го практического задания с помощью биномиального коэффициента.
// Данные на вход: Два целых числа N и M
// Данные на выход: Одно целое число – количество вариантов

// Пример №1
// Данные на вход: 10 5
// Данные на выход: 252

// Пример №2
// Данные на вход: 35 5
// Данные на выход: 324632

// Пример №3
// Данные на вход: 40 10
// Данные на выход: 847660528

#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the binomial coefficient C(N, M)
unsigned long long binomial_coefficient(int n, int m) {
    if (m > n) {
        return 0;
    }

    // C(N,0)=C(N,N)=1
    if(m == 0 || m == n) {
        return 1;
    }

    // C(N,M)=C(N,N−M)
    if(m > n - m) {
        m = n-m;
    }

    // C(N,M) = (n-i)/(i+1) for i=0 to M−1
    unsigned long long result = 1;
    for(int i = 0; i < m; i++) {
        result *= (n-i);
        result /= (i+1);
    }

    return result;
}

int main() {
    int n, m;
    
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter M: ");
    scanf("%d", &m);
    
    unsigned long long result = binomial_coefficient(n, m);
    printf("%llu\n", result);
    
    return 0;
}
