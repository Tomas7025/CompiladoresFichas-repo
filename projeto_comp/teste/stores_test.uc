void main (void) {
    int inteiro;
    short litle_int;
    char caracter;
    double real;
    
    inteiro = inteiro;
    inteiro = litle_int;
    inteiro = caracter;
    inteiro = real; // waring
    inteiro = main(); // waring
    inteiro = undef; // waring


    litle_int = inteiro; 
    litle_int = litle_int; 
    litle_int = caracter;
    litle_int = real; // waring
    litle_int = main(); // waring
    litle_int = undef; // waring

    caracter = inteiro;
    caracter = litle_int;
    caracter = caracter;
    caracter = real; // waring
    caracter = main(); // waring
    caracter = undef; // waring

    real = inteiro;
    real = litle_int;
    real = caracter;
    real = real;
    real = main(); // waring
    real = undef; // waring
    
    under = inteiro; // waring
    under = litle_int; // waring
    under = caracter; // waring
    under = real; // waring
    under = main(); // waring
    under = undef; // waring

    int a = inteiro;
    int b = litle_int;
    int c = caracter;
    int d = real; // Conflicting types (got double, expected int)
    int e = main(); // Conflicting types (got void, expected int)
    int f = undef;

    short g = inteiro;
    short h = litle_int;
    short i = caracter;
    short j = real; // Conflicting types (got double, expected short)
    short k = main(); // Conflicting types (got void, expected short)
    short l = undef;

    char m = inteiro;
    char n = litle_int;
    char o = caracter;
    char p = real; // Conflicting types (got double, expected char)
    char q = main(); // Conflicting types (got void, expected char)
    char r = undef;

    double s = inteiro;
    double t = litle_int;
    double u = caracter;
    double v = real;
    double w = main(); // Conflicting types (got void, expected double)
    double x = undef;

    void y = inteiro;
    void z = litle_int;
    void aa = caracter;
    void bb = real;
    void cc = main();
    void dd = undef;
    
}