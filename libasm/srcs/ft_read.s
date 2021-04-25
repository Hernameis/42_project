section .text				;	ft_read(int fd, char *buff, size_t count)
	global _ft_read
	extern ___error

_ft_read :
	mov rax, 0x2000003		;	rax = 0x20000003 // read
	syscall					;	rax = call(rax);
	jc _ft_error			;	if (carry_flag)
							;		goto(_ft_error);
	ret						;	return (rax);

_ft_error :
	push rax				;	push(rax);
	call ___error			;	// func.error returns adress
	pop rdx					;	pop(rdx);
	mov [rax], rdx			;	*rax = rdx;
	mov rax, -1				;	rax = -1;
	ret						;	return (rax);
