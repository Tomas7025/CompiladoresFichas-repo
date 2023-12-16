// #include <stdio.h>

void printNumber(int num) {
    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }
int digit;
    int reversed = 0;
    while (num > 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    while (reversed > 0) {
        digit = reversed % 10;
        putchar(digit + '0');
        reversed = reversed / 10;
    }
}

void divisionByHand(int dividend, int divisor) {
    if (divisor == 0) {
        putchar('e');
        return;
    }

    int quotient = 0;
    int remainder = 0;

    while (dividend >= divisor) {
        dividend = dividend - divisor;
        quotient = quotient + 1;
    }

    remainder = dividend;

    putchar('Q');
    putchar('u');
    putchar('o');
    putchar('t');
    putchar('i');
    putchar('e');
    putchar('n');
    putchar('t');
    putchar(':');
    putchar(' ');
    
    printNumber(quotient);
    putchar('\n');

    putchar('R');
    putchar('e');
    putchar('m');
    putchar('a');
    putchar('i');
    putchar('n');
    putchar('d');
    putchar('e');
    putchar('r');
    putchar(':');
    putchar(' ');

    printNumber(remainder);
    putchar('\n');
}

int main(void) {
    int dividend = 27;
    int divisor = 4;

    divisionByHand(dividend, divisor);

    return 0;
}
