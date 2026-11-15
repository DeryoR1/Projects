#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

int GetTerminalWidth(){
	struct winsize w;
	
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0){
		return w.ws_col;
	}
	return 80;
}

void PrintSeparator(const std::string& text){
	int TotalWidth = GetTerminalWidth();
	int TextLength = text.length();

	if(TotalWidth <= TextLength + 4){
		std::cout << "=" << text << "=\n";
		return;
	}
	int RemainingSpace = TotalWidth - TextLength - 2;
	int LeftSide = RemainingSpace / 2;
	int RightSide = RemainingSpace - LeftSide;

	for(int i = 0; i < LeftSide; i++){
		std::cout << '=';
	}
	std::cout << ' ' << text << ' ';
	for(int i = 0; i < RightSide; i++){
		std::cout << '=';
	}
	std::cout << '\n';
}

void Menu(){
	std::cout << "0: Exit\n";
	std::cout << "1: System-Diagnostics\n";
	std::cout << "2: Resource & Memory Profiler\n";
	std::cout << "3: Disk Cleaner\n";
	std::cout << "4: LAN Device Manager\n";
	std::cout << "5: Antivirus\n";
	std::cout << "Make your choice: ";
}

void Diagnose(){
	int DagChoice = -1;
	
	std::cout << "0: back to main menu\n";
	std::cout << "1: check system health\n";
	std::cout << "2: check hardware health\n";
	std::cout << "3: check network security\n";
	std::cout << "4: system management\n";
	std::cout << "Make your choice: ";
	std::cin >> DagChoice;
	
	//1 system health
	if(DagChoice == 1){
	// 1.1 failed systemd services
		PrintSeparator("FAILED SERVICES");
		std::system("systemctl list-units --state failed");
	// 1.2 boot errors
		PrintSeparator("BOOT ERRORS");
		std::system("journalctl -b 0 | tail -n 20 --no-pager");
	// 1.3 kernel warnings
		PrintSeparator("KERNEL WARNINGS");
	// 1.3.1 error
	// 1.3.2 alert
	// 1.3.3 critical
	}

	//2 hardware health
	PrintSeparator("HARDWARE HEALTH");
	// 2.1 smart disk status
	// 2.2 fan temp.
	// 2.3 memory stress

	//3 network security
	PrintSeparator("NETWORK SECURITY");
	// 3.1 open ports
	// 3.2 firewall status
	// 3.3 failed logins

	//4 system management
	PrintSeparator("SYSTEM MANAGEMENT");
	// 4.1 app errors
	// 4.2 disk inodes
	
}

void Profiler(){
	//1 journalctl
	PrintSeparator("SYSTEM LOGS");
	std::system("journalctl -n 20 --no-pager");
	//2 dmesg
	PrintSeparator("KERNEL LOGS");
	std::system("dmesg --color=always -T | tail -n 20");
	//3 df
	PrintSeparator("DISK USAGE");
	std::system("df -h -a -T --total");
	//4 vmstat
	PrintSeparator("VIRTUAL MEMORY");
	std::system("vmstat -adtw");
	//5 iostat
	PrintSeparator("IOSTAT");
	std::system("iostat -p -t -x");
	PrintSeparator("END");
}

void DiskCleaner(){
	//1 cache clean-up
	
	//2 log clean-up

	//3 user cache
	// 3.1 trashbin clean-up
	// 3.2 browsercache clean-up

	//4 kernel clean-up

	//5 container clean-up
}

void LDM(){
	//1 LAN scanning
	// 1.1 ip & mac gathering
	// 1.2 hostname gathering

	//2 hardware ID

	//3 device port scanning

	//4 wake-on-LAN

	//5 network tree
	// 5.1 device tree
	// 5.2 gateway
	// 5.3 arp table
	// 5.4 traceroute
}

void Antivirus(){
	//1 malware scanner
	// 1.1 file traverser
	// 1.2 file inspection
	// 1.2 hash inspection
	// 1.3 patern recognition
	// 1.4 downloads folder check
	// 1.5 real time monitor
	// 1.6 archive inspection

	//2 quarantine zone
	// 2.1 isolated folder
	// 2.2 moving files to iso. folder
	// 2.3 saving metadatae files NOT copy
}

int main(){
	int Choice = -1;
	
	while(Choice != 0){
		Menu();
		
		if(Choice > 5){
				std::cout <<"Invalid input try again!\n";
			}
			
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
