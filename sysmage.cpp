#include <iostream>

void SystemDiagnose(){
	
}

int main(){
	int choice;

	std::cout << "Make your choice: " << '\n';
	std::cout << "0: Exit" << '\n';
	std::cout << "1: System-Diagnostics" << '\n';
	std::cout << "2: Resource & Memory Profiler" << '\n';
	std::cout << "3: Disc Cleaner" << '\n';
	std::cout << "4: LAN Device Manager" << '\n';
	std::cout << "5: Antivirus" << '\n';
	
	std::cout << "input here: ";
	std::cin >> choice;

		switch(choice){
			case 1:
				std::cout << "test 1" << '\n';
				break;
			case 2:
				std::cout << "test 2" << '\n';
				break;
			case 3:
				std::cout << "test 3" << '\n';
				break;
			case 4:
				std::cout << "test 4" << '\n';
				break;
			case 5:
				std::cout << "test 5" << '\n';
				break;	
		};
	return 0;
}
