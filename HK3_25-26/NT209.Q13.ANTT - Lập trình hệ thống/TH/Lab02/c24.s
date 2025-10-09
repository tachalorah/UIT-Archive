.section .bss
	.lcomm input, 6
	.lcomm output, 6

.section .data
str: 	.string "Enter a string: "
nl: 	.string "\n"

.section .text
	.globl _start

_start:
	movl $4, 	%eax
	movl $1, 	%ebx
	movl $str, 	%ecx
	movl $17, 	%edx
	int  $0x80

	movl $3, 	%eax
	movl $0, 	%ebx
	movl $input, 	%ecx
	movl $6, 	%edx
	int  $0x80

	movb $10, 	output + 5
	movb input, 	%al
	movb %al, 	output + 4
	movb input + 1, %al
	movb %al, 	output + 3
	movb input + 2, %al
	movb %al, 	output + 2
	movb input + 3, %al
	movb %al, 	output + 1
	movb input + 4, %al
	movb %al, 	output

	movl $4, 	%eax
	movl $1, 	%ebx
	movl $output, 	%ecx
	movl $6, 	%edx
	int  $0x80

	movl $1, 	%eax
	xorl %ebx, 	%ebx
	int  $0x80
