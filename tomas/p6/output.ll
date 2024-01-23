declare i32 @_read(i32)
declare i32 @_write(i32)

define i32 @_f2(i32 %c, i32 %d) {
  %1 = add i32 0, 0
  %2 = call i32 @_read(i32 %1)
  %3 = alloca i32
  %4 = icmp ne i32 %2, 0
  br i1 %4, label %LABELthen2, label %LABELelse2
LABELthen2:
  %5 = add i32 %c, 0
  %6 = add i32 2, 0
  %7 = mul i32 %5, %6
  %8 = call i32 @_write(i32 %7)
  store i32 %8, i32* %3
  br label %LABELfi2
LABELelse2:
  %9 = add i32 %d, 0
  %10 = add i32 2, 0
  %11 = mul i32 %9, %10
  %12 = call i32 @_write(i32 %11)
  store i32 %12, i32* %3
  br label %LABELfi2
LABELfi2:
  %13 = load i32, i32* %3
  ret i32 %13
}

define i32 @_main(i32 %l) {
  %1 = add i32 1, 0
  %2 = add i32 2, 0
  %3 = call i32 @_f2(i32 %1, i32 %2)
  ret i32 %3
}

define i32 @main() {
  %1 = call i32 @_main(i32 0)
  ret i32 %1
}
