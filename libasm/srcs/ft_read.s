section .text
	global _ft_read
	extern ___error

_ft_read :
	mov rax, 0x2000003
	syscall
	jc _ft_error
	ret

_ft_error :
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret
