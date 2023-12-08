	.text
	.file	"factorial.ll"
	.globl	_factorial                      # -- Begin function _factorial
	.p2align	4, 0x90
	.type	_factorial,@function
_factorial:                             # @_factorial
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	testl	%edi, %edi
	je	.LBB0_2
# %bb.1:                                # %L1then
	movl	%edi, %ebx
	leal	-1(%rbx), %edi
	callq	_factorial@PLT
	imull	%ebx, %eax
	movl	%eax, 12(%rsp)
	jmp	.LBB0_3
.LBB0_2:                                # %L1else
	movl	$1, 12(%rsp)
.LBB0_3:                                # %L1end
	movl	12(%rsp), %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	_factorial, .Lfunc_end0-_factorial
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	xorl	%edi, %edi
	callq	_read@PLT
	movl	%eax, %edi
	callq	_factorial@PLT
	movl	%eax, %ebx
	movl	%eax, %edi
	callq	_write@PLT
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
