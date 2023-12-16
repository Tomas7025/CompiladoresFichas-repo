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
        reversed = reversed /10;
    }
}

int main(void) {
    int num;
    num = 18;
    // Input a number
    // printf("Enter a number: ");
    // scanf("%d", &num);

    // Check if the number is prime and print the result
    if (isPrime(num, num / 2)) {
        // printf("The number is prime.\n");
        putchar('T');
    } else {
        // printf("The number is not prime.\n");
        putchar('F');
    }

    putchar('\n');
    return 0;
}
