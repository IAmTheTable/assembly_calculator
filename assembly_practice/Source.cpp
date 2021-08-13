#include <iostream>

int get_and_print_text()
{
	std::cout << "Would you like to add(1), multiply(2), or subtract(3): ";
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

		main:
		cmp eax, 1
		je add_n
		cmp eax, 2
		je multiply_n
		cmp eax, 3
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

			xor eax, eax

			retn
		multiply_n :
			xor eax, eax

			call ask_for_number // number 1 
			push eax // add to stack for later use

			call ask_for_number // number 2
			mov ebx, eax

			pop eax // get the value of the first number from the stack
			imul ebx, eax
			push ebx // push value onto stack for the function parameter

			call print_number
			pop eax // get last value from stack and put onto eax
			xor eax, eax // set return code to 0

			retn
		subtract_n:
			xor eax, eax

			call ask_for_number
			push eax

			call ask_for_number
			mov ebx, eax

			pop eax

			sub eax, ebx

			push eax
			call print_number
			pop eax

			xor eax, eax
			retn
		retn

	}
}
