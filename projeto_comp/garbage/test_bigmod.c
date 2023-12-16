
void printNumber(int num) {
    int digit;
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

int bigmod(int a, int b, int m) {
    int temp;
    if (b == 0) {
        return 1;
    } else if (b % 2 == 1) {
        temp = bigmod(a, b - 1, m);
        return (temp * a) % m;
    } else {
        temp = bigmod(a, b / 2, m);
        return (temp * temp) % m;
    }
}

int main(void) {
    int a = 2, b = 5, m = 1000;

    int result = bigmod(a, b, m);

    putchar(' ');
    printNumber(a);
    putchar('^');
    printNumber(b);
    putchar(' ');
    putchar('%');
    putchar(' ');
    printNumber(m);
    putchar(' ');
    putchar('=');
    putchar(' ');
    printNumber(result);
    putchar('\n');

    return 0;
}
