.section .bss
	.lcomm num, 3
	.lcomm is_even, 2
	.lcomm pr_num, 7

.section .data
prompt: .string "Enter a number (10-99): "

.section .text
	.globl _start

_start:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $prompt, 	%ecx
	movl $25,	%edx
	int  $0x80

	movl $3, 	%eax
	xorl %ebx, 	%ebx
	movl $num, 	%ecx
	movl $3, 	%edx
	int  $0x80

	movzbl num, 	%eax
	subl $48, 	%eax
	imull $10, 	%eax
	movzbl num + 1, %ebx
	subl $48, 	%ebx
	addl %ebx, 	%eax

	andl $1, 	%ebx
	xorl $1, 	%ebx
	addl $48, 	%ebx
	movb %bl, 	is_even
	movb $10, 	is_even + 1

	movw num, 	%cx
	movw %cx, 	pr_num
	movb $32, 	pr_num + 2

	addl $1, 	%eax
	cmpl $100, 	%eax
	je   three_digits

	movl $10, 	%ecx
	xorl %edx, 	%edx
	divl %ecx

	addl $48, 	%eax
	addl $48, 	%edx
	movb %al, 	pr_num + 3
	movb %dl, 	pr_num + 4
	movb $0, 	pr_num + 5
	movb $10, 	pr_num + 6

print_output:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $is_even, 	%ecx
	movl $2, 	%edx
	int  $0x80

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $pr_num, 	%ecx
	movl $7, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int  $0x80

three_digits:
	movb $49, 	pr_num + 3
	movb $48, 	pr_num + 4
	movb $48, 	pr_num + 5
	movb $10, 	pr_num + 6

	jmp  print_output
