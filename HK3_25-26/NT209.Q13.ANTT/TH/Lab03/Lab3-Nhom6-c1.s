.section .bss
	.lcomm input, 6

.section .data
prompt: .string "Enter a number (5-digits): "
msg_yes: .string "Giam dan\n"
msg_no: .string "Khong giam dan\n"

.section .text
	.globl _start

_start:
	movl $4, %eax
	movl $1, %ebx
	movl $prompt, %ecx
	movl $28, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $input, %ecx
	movl $6, %edx
	int $0x80

	xorl %eax, %eax
	movb input, %al

	cmpb $52, %al
	jl print_no

	movl $1, %ecx

loop:
	movb input(%ecx), %bl
	cmpb %al, %bl
	jge print_no

	movb %bl, %al
	incl %ecx
	cmpl $5, %ecx
	jl loop

	movl $4, %eax
	movl $1, %ebx
	movl $msg_yes, %ecx
	movl $9, %edx
	int $0x80

exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80

print_no:
	movl $4, %eax
	movl $1, %ebx
	movl $msg_no, %ecx
	movl $15, %edx
	int $0x80

	jmp exit
