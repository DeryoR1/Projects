#include <iostream>
#include <cmath>

int main(){
	double first, second;
	char operation;

	std::cout << "What would you like to do?: ";
	std::cout << "+, -, *, /, %: ";
	std::cin >> operation;

	std::cout << "Enter your first number: ";
	std::cin >> first;
	std::cout << "Enter your second number: ";
	std::cin >> second;

	switch(operation){
		case '+':
			std::cout << first + second << '\n';
			break;
		case '-':
			std::cout << first - second << '\n';
			break;
		case '*':
			std::cout << first * second << '\n';
			break;
		case '/':
			if(second == 0){
				std::cout << "ERROR! Can't divide by zero!!!\n";
			}else{
				std::cout << first / second << '\n';
			}
			break;
		case '%':
			if(second == 0){
				std::cout << "ERROR can't calculate the remainders of zero!!!\n";
			}else{
				std::cout << std::fmod(first, second) << '\n';
			}
	}
	return 0;
}
