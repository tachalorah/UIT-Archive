.section .bss
	.lcomm n_in,  3
	.lcomm n_out, 2
	.lcomm num_nx, 7

.section .data
in_msg: .string "Enter a number (10-99): "

.section .text
	.globl _start

_start:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $in_msg, 	%ecx
	movl $25, 	%edx
	int  $0x80

	movl $3, 	%eax
	xorl %ebx, 	%ebx
	movl $n_in, 	%ecx
	movl $3, 	%edx
	int  $0x80

	movzbl n_in, 	%eax
	subl $48, 	%eax
	imull $10, 	%eax
	movzbl n_in + 1, %ebx
	subl $48, 	%ebx
	addl %ebx, 	%eax

	andl $1, 	%ebx
	xorl $1, 	%ebx
	addl $48, 	%ebx
	movb %bl, 	n_out
	movb $10, 	n_out + 1

	movw n_in, 	%cx
	movw %cx, 	num_nx
	movb $32, 	num_nx + 2

	addl $1, 	%eax
	cmpl $100, 	%eax
	je   three_digits

	movl $10, 	%ecx
	xorl %edx, 	%edx
	divl %ecx

	addl $48, 	%eax
	addl $48, 	%edx
	movb %al, 	num_nx + 3
	movb %dl, 	num_nx + 4
	movb $0, 	num_nx + 5
	movb $10, 	num_nx + 6

print_output:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $n_out, 	%ecx
	movl $2, 	%edx
	int  $0x80

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $num_nx, 	%ecx
	movl $7, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int  $0x80

three_digits:
	movb $49, 	num_nx + 3
	movb $48, 	num_nx + 4
	movb $48, 	num_nx + 5
	movb $10, 	num_nx + 6

	jmp  print_output
