	.text
	.file	"output.ll"
	.globl	_f2                             # -- Begin function _f2
	.p2align	4, 0x90
	.type	_f2,@function
_f2:                                    # @_f2
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %rbp, -16
	movl	%esi, %ebx
	movl	%edi, %ebp
	xorl	%edi, %edi
	callq	_read@PLT
	testl	%eax, %eax
	je	.LBB0_2
# %bb.1:                                # %LABELthen2
	addl	%ebp, %ebp
	movl	%ebp, %edi
	jmp	.LBB0_3
.LBB0_2:                                # %LABELelse2
	addl	%ebx, %ebx
	movl	%ebx, %edi
.LBB0_3:                                # %LABELfi2
	callq	_write@PLT
	movl	%eax, 4(%rsp)
	movl	4(%rsp), %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	_f2, .Lfunc_end0-_f2
	.cfi_endproc
                                        # -- End function
	.globl	_main                           # -- Begin function _main
	.p2align	4, 0x90
	.type	_main,@function
_main:                                  # @_main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	movl	$2, %esi
	callq	_f2@PLT
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	_main, .Lfunc_end1-_main
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	xorl	%edi, %edi
	callq	_main@PLT
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
