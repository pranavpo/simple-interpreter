#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number in a range
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to evaluate the arithmetic expression
int evaluateExpression(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Avoid division by zero
    }
    return 0;
}

// Function to generate a random arithmetic expression
void generateExpression(int length) {
    char operators[] = {'+', '-', '*', '/'};
    int result;

    // Start with a positive number
    int num = getRandomNumber(1, 20); // Random first number
    printf("%d", num);
    result = num;

    // Generate random operations and numbers
    for (int i = 0; i < length; i++) {
        char op = operators[getRandomNumber(0, 3)]; // Random operator
        int nextNum = getRandomNumber(1, 10);      // Random next number (non-negative)
        printf("%c%d", op, nextNum);

        // Update the result by evaluating the current operation
        result = evaluateExpression(result, op, nextNum);
    }

    printf(" = %d\n", result);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int expressionLength;
    printf("Enter the number of operations: ");
    scanf("%d", &expressionLength);

    // Generate a random arithmetic expression
    generateExpression(expressionLength);

    return 0;
}