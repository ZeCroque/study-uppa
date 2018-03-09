	.file	"exo3_2.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$0, -36(%rbp)
	movl	$0, %edi
	call	time
	movq	%rax, %rdi
	movl	$0, %eax
	call	srand
	movl	$0, -36(%rbp)
	jmp	.L2
.L3:
	movl	$0, %eax
	call	rand
	movl	-36(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, -32(%rbp,%rdx,4)
	addl	$1, -36(%rbp)
.L2:
	cmpl	$4, -36(%rbp)
	jle	.L3
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
