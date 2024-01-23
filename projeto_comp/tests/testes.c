int main(void) {
    if (1 == 1){
    return 0;}
    else{
    return 1;}
}

/*
declare i32 @_read(i32)
declare i32 @_write(i32)
declare i32 @_putchar(i32)
declare i32 @_getchar()

define void @_global_vars_init() {
	ret void
}

define i32 @_main() {
	%1 = add i32 1, 0
	%2 = add i32 1, 0
	%3 = icmp eq i32 %2, %1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %6, label %8
6:
	%7 = add i32 0, 0
	ret i32 %7
8:
	%9 = add i32 1, 0
	ret i32 %9
10:
	ret i32 0
}

define i32 @main() {
	 call void @_global_vars_init()
	 call i32 @_main()
	 ret i32 0
}

*/