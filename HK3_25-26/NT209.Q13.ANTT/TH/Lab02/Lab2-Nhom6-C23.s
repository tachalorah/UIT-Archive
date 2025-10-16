.section .bss
	.lcomm num1, 3
	.lcomm num2, 3
	.lcomm num3, 3
	.lcomm num4, 3
	.lcomm dtb, 3

.section .data
msg_in: .string "Enter a number: "

.section .text
	.globl _start

_start:
	movl $4, %eax
	movl $1, %ebx
	movl $msg_in, %ecx
	movl $17, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $num1, %ecx
	movl $3, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $msg_in, %ecx
	movl $17, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $num2, %ecx
	movl $3, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $msg_in, %ecx
	movl $17, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $num3, %ecx
	movl $3, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $msg_in, %ecx
	movl $17, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $num4, %ecx
	movl $3, %edx
	int $0x80

	xorl %eax, %eax
	xorl %ebx, %ebx

	movw num1, %ax
	cmpb $10, %ah
	jne add_10_1
	subb $48, %al
	addb %al, %bl
	jmp continue_1

add_10_1:
	addl $10, %ebx
	jmp continue_1

continue_1:
	movw num2, %ax
	cmpb $10, %ah
	jne add_10_2
	subb $48, %al
	addb %al, %bl
	jmp continue_2

add_10_2:
	addl $10, %ebx
	jmp continue_2

continue_2:
	movw num3, %ax
	cmpb $10, %ah
	jne add_10_3
	subb $48, %al
	addb %al, %bl
	jmp continue_3

add_10_3:
	addl $10, %ebx
	jmp continue_3

continue_3:
	movw num4, %ax
	cmpb $10, %ah
	jne add_10_4
	subb $48, %al
	addb %al, %bl
	jmp continue_4

add_10_4:
	addl $10, %ebx
	jmp continue_4

continue_4:
	sarl $2, %ebx
	cmpl $10, %ebx
	je dtb_10
	addl $48, %ebx
	movb %bl, dtb
	movb $0, dtb + 1
	movb $10, dtb + 2
	jmp continue_5

dtb_10:
	movb $49, dtb
	movb $48, dtb + 1
	movb $10, dtb + 2
	jmp continue_5

continue_5:
	movl $4, %eax
	movl $1, %ebx
	movl $dtb, %ecx
	movl $3, %edx
	int $0x80

	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
