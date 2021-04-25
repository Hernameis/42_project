section .text					;	int		ft_strlen(char *s)
	global _ft_strlen

_ft_strlen :
	mov RAX, 0					;	rax = 0;
_start :
	cmp byte [RDI + RAX], 0		;	compare(rdi[rax], 0);
	je	_end					;	if (rdi[rax] == 0)
								;		_end();
	jne	_value_exist			;	if (rdi[rax] != 0)
								;		_value_exist;
_value_exist :
	inc	RAX						;	rax++;
	jmp _start					;	goto(_start);
_end :
	ret							;	return (rax);
