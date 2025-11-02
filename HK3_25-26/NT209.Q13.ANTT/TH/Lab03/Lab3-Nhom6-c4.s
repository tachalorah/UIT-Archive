.section .bss
	.lcomm cccd, 13
	.lcomm ns, 5
	.lcomm gt, 4
	.lcomm ld, 1

.section .data
prompt: .string "CCCD: "
msg_ns: .string "Nam sinh: "
msg_gt: .string "Gioi tinh: "
msg_ch: .string "Chua den do tuoi lao dong\n"
msg_tr: .string "Trong do tuoi lao dong\n"
msg_qt: .string "Het do tuoi lao dong\n"

.section .text
	.globl _start

_start:
	movl $4, %eax
	movl $1, %ebx
	movl $prompt, %ecx
	movl $7, %edx
	int $0x80

	movl $3, %eax
	movl $0, %ebx
	movl $cccd, %ecx
	movl $13, %edx
	int $0x80

	xorl %eax, %eax
	xorl %ebx, %ebx
	xorl %ecx, %ecx
	xorl %edx, %edx
	xorl %edi, %edi

	movb $10, ns + 4
	movw cccd + 4, %bx
	movw %bx, ns + 2

	movb cccd + 3, %al
	cmpb $50, %al
	jl truoc_2000

	movb $50, ns
	movb $48, ns + 1
	movl $2000, %edi
	jmp tiep_1

truoc_2000:
	movb $49, ns
	movb $57, ns + 1
	movl $1900, %edi

tiep_1:
	testb $1, %al
	jnz gioitinh_nu

	movb $78, gt
	movb $97, gt + 1
	movb $109, gt + 2
	movb $10, gt + 3
	movl $60, %edx
	jmp ktra_tuoilaodong

gioitinh_nu:
	movb $78, gt
	movb $117, gt + 1
	movb $0, gt + 2
	movb $10, gt + 3
	movl $55, %edx

ktra_tuoilaodong:
	movb %bl, %cl
	subb $48, %cl
	imull $10, %ecx
	addl %ecx, %edi

	movb %bh, %cl
	subb $48, %cl
	addl %ecx, %edi

	movl $2025, %ecx
	subl %edi, %ecx

	cmpl $15, %ecx
	jl duoi_tld
	cmpl %edx, %ecx
	jg qua_tld
	movb $0, ld
	jmp in_thongtin

duoi_tld:
	movb $1, ld
	jmp in_thongtin

qua_tld:
	movb $2, ld

in_thongtin:
	movl $4, %eax
	movl $1, %ebx
	movl $msg_ns, %ecx
	movl $11, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $ns, %ecx
	movl $5, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $msg_gt, %ecx
	movl $12, %edx
	int $0x80

	movl $4, %eax
	movl $1, %ebx
	movl $gt, %ecx
	movl $4, %edx
	int $0x80

	movb ld, %al
	cmpb $1, %al
	je in_duoi_tld
	cmpb $2, %al
	je in_qua_tld

	movl $4, %eax
	movl $1, %ebx
	movl $msg_tr, %ecx
	movl $24, %edx
	int $0x80

exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80

in_duoi_tld:
	movl $4, %eax
	movl $1, %ebx
	movl $msg_ch, %ecx
	movl $27, %edx
	int $0x80

	jmp exit

in_qua_tld:
	movl $4, %eax
	movl $1, %ebx
	movl $msg_qt, %ecx
	movl $22, %edx
	int $0x80

	jmp exit
