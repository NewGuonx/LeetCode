	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_newguo
	.p2align	4, 0x90
_newguo:                                ## @newguo
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$1, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	cmpl	$1, -4(%rbp)
	jg	LBB0_1
## BB#3:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
