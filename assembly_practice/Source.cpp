#include <iostream>

int get_and_print_text()
{
	std::cout << "Would you like to add(1), multiply(2), divide(3), or subtract(4): ";
	int user_text;
	std::cin >> user_text;
	system("cls");
	return user_text;
}

int ask_for_number()
{
	std::cout << "Input a number" << std::endl;
	int user_text;
	std::cin >> user_text;
	system("cls");
	return user_text;
}

void print_number(int numb)
{
	std::cout << numb << std::endl;
}

__declspec(naked) int main()
{
	__asm
	{
		xor eax, eax
		call get_and_print_text // ask for what they are doing
		push eax
		call print_number
		pop eax

		main:
		cmp eax, 1
		je add_n
		jne main
		cmp eax, 2
		je multiply_n
		jne main
		cmp eax, 3
		je divide_n
		jne main
		cmp eax, 4
		je subtract_n
		jne main

		add_n:
			xor eax, eax
			call ask_for_number
			push eax
			call ask_for_number
			mov ebx, eax
			pop eax
			add eax, ebx
			push eax
			call print_number
			pop eax

			retn
		multiply_n :
			add eax, 1
			retn
		divide_n:
			add eax, 1
			retn
		subtract_n:
			add eax, 1
			retn

		retn

	}
}
