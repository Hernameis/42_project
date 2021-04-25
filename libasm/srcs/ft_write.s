section .text					;	ssize_t ft_write(int fd, void *buf, size_t nbytes)
	global _ft_write
	extern ___error

_ft_write :
	mov rax, 0x2000004
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
