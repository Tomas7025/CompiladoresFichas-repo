// #include <stdio.h>

// Function to check if a number is prime
int isPrime(int num, int divisor) {
    if (num <= 1) {
        return 0; // Not prime
    } else if (divisor == 1) {
        return 1; // Prime
    } else {
        if (num % divisor == 0) {
            return 0; // Not prime
        } else {
            return isPrime(num, divisor - 1); // Check with the next divisor
        }
    }
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

// Function to print primes from 0 to x
void printPrimesUpTo(int x, int current) {
    if (current <= x) {
        if (isPrime(current, current / 2)) {
            printInt(current);
            putchar(' ');
        }
        printPrimesUpTo(x, current + 1);
    }
}

int main(void) {
    int x;
    x = 50;
    // Input a number
    // printf("Enter a value of x: ");
    // scanf("%d", &x);

    // Print primes from 0 to x
    // printf("
    putchar('P');
    putchar('r');
    putchar('i');
    putchar('m');
    putchar('e');
    putchar('s');
    putchar(' ');
    putchar('f');
    putchar('r');
    putchar('o');
    putchar('m');
    putchar(' ');
    putchar('0');
    putchar(' ');
    putchar('t');
    putchar('o');
    putchar(' ');
    putchar(x);
    putchar(':');
    putchar(' ');

    printPrimesUpTo(x, 0);
    putchar('\n');

    return 0;
}
