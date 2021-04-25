section .text					;	char	*ft_strcpy(char *dst, char *src)
	global _ft_strcpy

_ft_strcpy :
	mov rax, 0					;	rax = 0;
	start :
	cmp byte [rsi + rax], 0		;	compare(rsi[rax], 0);
	jne _if_value				;	if (rsi[rax] != 0)
								;		_if_value;
	je _if_null					;	if (rsi[rax] == 0)
								;		_if_null;
_if_value :
	mov dl, byte [rsi + rax]	;	di = (char)(rsi[rax]);
	mov byte [rdi + rax], dl	;	(char)(rdi[rax]) == dl;
	inc rax						;	rax++;
	jmp	start					;	goto(start);

_if_null :
	mov byte [rdi + rax], 0		;	(char)(rdi[rax]) = 0;
	mov rax, rdi				;	rax = rdi;
	ret							;	return(rax);
