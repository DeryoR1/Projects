#include <iostream>
#include <vector>
#include <string>

class Product{
	int voorraad;
	std::vector<std::string> product_prijs;
	std::vector<std::string> product_naam;
	std::vector<std::string> product_totaal;
	
	public:
		std::string prodvar;
		std::string prijsvar;
		std::string totaalvar;
		
		void ProductLijst(){
			prodvar = "";
			while(prodvar != "q"){
				std::cout << "Enter product name: ";
				std::cin >> prodvar;

				if(prodvar != "q"){
					product_naam.push_back(prodvar);
				}
			}
		}

		void PrijsLijst(){
			prijsvar = "";
			for(size_t i = 0; i < product_naam.size(); ++i){
				std::cout << product_naam[i] << " | € ";
				std::cin >> prijsvar;

				if(prijsvar  != "q"){
					product_prijs.push_back(prijsvar);
				}
			}
		}

		void TotaalLijst(){
			totaalvar = "";
			for(size_t i = 0; i < product_naam.size(); ++i){
				std::cout << product_naam[i] << " | € " << product_prijs[i] << " : ";
				std::cin >> totaalvar;

				if(totaalvar != "q"){
					product_totaal.push_back(totaalvar);
				}
			}
		}
		
		void ToonLijst(){
			for(size_t i = 0; i < product_naam.size(); ++i){
				std::cout << "- " << product_naam[i] << " | € " << product_prijs[i] << " : " << product_totaal[i] << '\n';
			}
			
		}
};

int main(){
	Product Prod;
	std::string choice;

	do{
		std::cout << "1: Products" << '\n';
		std::cout << "2: Price" << '\n';
		std::cout << "3: Total" << '\n';
		std::cout << "4: Show inventory" << '\n';
		std::cout << "Press 'q' to go back" << '\n';
		std::cout << "Press 'exit' to quit" << '\n';
		std::cout << "Choice: ";
		std::cin >> choice;

		if(choice == "1"){
			Prod.ProductLijst();		
		}
		if(choice == "2"){
			Prod.PrijsLijst();
		}
		if(choice == "3"){
			Prod.TotaalLijst();
		}
		if(choice == "4"){
			Prod.ToonLijst();
		}
		
		}while(choice != "exit");		
	return 0;
}
