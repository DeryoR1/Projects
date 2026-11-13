#include <iostream>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>

int GetTerminalWidth(){
	struct winsize w;
	
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0){
		return w.ws_col;
	}
	return 80;
}

void PrintSeparator(char symbol = '-'){
	int width = GetTerminalWidth();

	for(int i = 0; i < width; i++){
		std::cout << symbol;
	}
	std::cout << '\n';
}

void Menu(){
	std::cout << "Make your choice:\n ";
	std::cout << "0: Exit\n";
	std::cout << "1: System-Diagnostics\n";
	std::cout << "2: Resource & Memory Profiler\n";
	std::cout << "3: Disk Cleaner\n";
	std::cout << "4: LAN Device Manager\n";
	std::cout << "5: Antivirus\n";
	std::cout << "input here: ";
}

void Diagnose(){
	
}

void Profiler(){
	//journalctl
	std::system("journalctl -n 20");
	PrintSeparator('=');
	//dmesg
	std::system("dmesg --color=always -T | tail -n 20");
	PrintSeparator('=');
	//df
	std::system("df -h -a -T --total");
	PrintSeparator('=');
	//vmstat
	std::system("vmstat -adtw");
	PrintSeparator('=');
	//iostat
	std::system("iostat -p -t -x");
	PrintSeparator('=');
}

void DiskCleaner(){
	
}

void LDM(){
	
}

void Antivirus(){
	
}

int main(){
	int Choice = -1;
	
	while(Choice != 0){
		Menu();
		std::cin >> Choice;

		switch(Choice){
			case 1:
				Diagnose();
				break;
			case 2:
				Profiler();
				break;
			case 3:
				DiskCleaner();
				break;
			case 4:
				LDM();
				break;
			case 5:
				Antivirus();
				break;	
		};
	}
	return 0;
}
