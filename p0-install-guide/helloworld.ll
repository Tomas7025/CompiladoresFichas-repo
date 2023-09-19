@.msg = private unnamed_addr constant [14 x i8] c"Hello World!\0A\00"

declare i32 @puts(i8* nocapture) nounwind

define i32 @main() {
    call i32 @puts(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.msg, i64 0, i64 0))
    ret i32 0
}

