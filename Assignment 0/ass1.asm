
section .data
	msg1 : db "Enter A Number: " ,10,0
	input_num : db "%d",0
	msg2 : db "Enter A String: " ,10,0
	input_string : db "%s",0
	msg3 : db "Printing number and string: " ,10,0
	new_line : db "" ,10,0

section .bss
	num resb 4
	string resb 9

section .text
	global main
	extern printf
	extern scanf

main :

	push rbp
	mov rbp , rsp

	lea rdi,[msg1]
	xor eax, eax
	call printf

	xor eax,eax
	lea rdi , [input_num];  
	lea rsi, [num]
	xor eax,eax
	call scanf

	lea rdi,[msg2]
	xor eax, eax
	call printf

	xor eax,eax
	lea rdi , [input_string];  
	lea rsi, [string]
	xor eax,eax
	call scanf

	lea rdi,[msg3]
	xor eax, eax
	call printf

	xor eax, eax
	lea rdi,[input_num];
	mov rsi,[num]
	mov rdx, rax
	xor eax, eax
	call printf
	
	lea rdi,[new_line]
	xor eax, eax
	call printf	

	xor eax, eax
	lea rdi,[input_string]
	lea rsi,[string]
	mov rdx, rax
	xor eax, eax
	call printf
	
	lea rdi,[new_line]
	xor eax, eax
	call printf	

	xor eax,eax
	leave
	 
	ret
