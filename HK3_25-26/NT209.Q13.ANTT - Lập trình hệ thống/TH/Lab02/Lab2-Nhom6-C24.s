.section .bss
	.lcomm str, 4

.section .text
	.globl _start

_start:
	movl $3, %eax
	movl $0, %ebx
	movl $str, %ecx
	movl $4, %edx
	int $0x80

	subb $32, str
	subb $32, str + 1
	subb $32, str + 2

	movl $4, %eax
	movl $1, %ebx
	movl $str, %ecx
	movl $4, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
