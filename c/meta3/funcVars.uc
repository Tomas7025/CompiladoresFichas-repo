    int bye(int a, int b);
int bye(int a, int b){

}

int error(int b, int b);

int error1(int c, int c){

}

void error2(void, void);
void error2(void) {}

void error3(void) {}
void error3(void, void);

int ola(int a){

}

int main(void){
    1, ola;
    1, ola();
    1, ola(1);
    1, ola(1, 2);
    ola, 1;
    ola(), 1;
    ola(1), 1;
    1 + ola;
}

void f(void){
    return;
}

void g(void){
    return f();
}


// Num of params
int test(int a, int b);
int test(int a, int b, int c);
int test(int a);

int test1(int a, int b);
int test1(int a, int b, int c){
}

int test2(int a, int b);

int test2(int a){
}