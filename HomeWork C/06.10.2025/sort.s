	.file	"sort.c"
	.text
	.globl	merge
	.def	merge;	.scl	2;	.type	32;	.endef
	.seh_proc	merge
merge:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movl	32(%rbp), %eax
	subl	24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movl	40(%rbp), %eax
	subl	32(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-16(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -32(%rbp)
	movl	-20(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -40(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	24(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-32(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L3
	movl	$0, -8(%rbp)
	jmp	.L4
.L5:
	movl	32(%rbp), %eax
	leal	1(%rax), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-40(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -8(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L5
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L6
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jg	.L7
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -4(%rbp)
	jmp	.L8
.L7:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -8(%rbp)
.L8:
	addl	$1, -12(%rbp)
.L6:
	movl	-4(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	.L11
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L10
	jmp	.L11
.L12:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -4(%rbp)
	addl	$1, -12(%rbp)
.L11:
	movl	-4(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L12
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -8(%rbp)
	addl	$1, -12(%rbp)
.L13:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L14
	movq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	free
	nop
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	merge_sort
	.def	merge_sort;	.scl	2;	.type	32;	.endef
	.seh_proc	merge_sort
merge_sort:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$1, 32(%rbp)
	jg	.L16
	movl	$0, %eax
	jmp	.L17
.L16:
	movl	$1, -8(%rbp)
	jmp	.L18
.L25:
	movl	$0, -12(%rbp)
	jmp	.L19
.L24:
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	subl	$1, %eax
	movl	%eax, -20(%rbp)
	movl	32(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -20(%rbp)
	jge	.L29
	movl	-8(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	cmpl	%eax, 32(%rbp)
	jle	.L22
	movl	-8(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	subl	$1, %eax
	jmp	.L23
.L22:
	movl	32(%rbp), %eax
	subl	$1, %eax
.L23:
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %r8d
	movl	-20(%rbp), %ecx
	movl	-12(%rbp), %edx
	movq	16(%rbp), %rax
	movl	%r8d, %r9d
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	merge
	jmp	.L21
.L29:
	nop
.L21:
	movl	-8(%rbp), %eax
	addl	%eax, %eax
	addl	%eax, -12(%rbp)
.L19:
	movl	32(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jl	.L24
	sall	-8(%rbp)
.L18:
	movl	32(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jg	.L25
	movl	$0, -16(%rbp)
	jmp	.L26
.L28:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L27
	addl	$1, -4(%rbp)
.L27:
	addl	$1, -16(%rbp)
.L26:
	movl	-16(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L28
	movl	-4(%rbp), %eax
.L17:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 13.2.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
