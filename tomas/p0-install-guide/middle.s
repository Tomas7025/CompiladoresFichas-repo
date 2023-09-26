	.text
	.file	"helloworld.ll"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$.L.msg, %edi
	callq	puts@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.msg,@object                  # @.msg
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.msg:
	.asciz	"Hello World!\n"
	.size	.L.msg, 14

	.section	".note.GNU-stack","",@progbits
