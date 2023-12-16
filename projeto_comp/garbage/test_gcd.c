// #include <stdio.h>

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

// Function to print an integer using putchar
void printInt(int num) {
    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }

    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }

    while (reversed > 0) {
        putchar('0' + reversed % 10);
        reversed = reversed / 10;
    }
}

int main(void) {
    int num1, num2;
    num1 = 30;
    num2 = 4;
    // Input two numbers
    // printf("Enter first number: ");
    // scanf("%d", &num1);
    // printf("Enter second number: ");
    // scanf("%d", &num2);

    // Calculate and print the GCD
    int result = gcd(num1, num2);
    // printf("GCD: ");
    printInt(result);
    putchar('\n');

    return 0;
}
