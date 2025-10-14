.section .bss
	.lcomm str_in, 4
	.lcomm str_out, 4

.section .text
	.globl _start

_start:
	movl $3, %eax
	movl $0, %ebx
	movl $str_in, %ecx
	movl $4, %edx
	int $0x80

	movb str_in, %al
	subb $32, %al
	movb %al, str_out
	movb str_in + 1, %al
	subb $32, %al
	movb %al, str_out + 1
	movb str_in + 2, %al
	subb $32, %al
	movb %al, str_out + 2
	movb $10, str_out + 3

	movl $4, %eax
	movl $1, %ebx
	movl $str_out, %ecx
	movl $4, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
