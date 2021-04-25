section .text				;	char	*ft_strdup(char *s);
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	global _ft_strdup

_ft_strdup :
	call _ft_strlen			;	rax = _ft_strlen(rdi);
	inc rax					;	rax++;
	push rdi				;	push(rdi);
	mov rdi, rax			;	rdi = rax;
	call _malloc			;	rax = malloc(rdi byte)
	pop rsi					;	pop(rsi);
	mov rdi, rax			;	rdi
	call _ft_strcpy			;	rax = ft_strcpy(rdi, rsi);	
	ret						;	return (rax);
