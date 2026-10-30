#include <iostream>
#include <vector>
#include <string>

class Product{
	int voorraad;
	std::vector<std::string> product_prijs;
	std::vector<std::string> product_naam;
	
	public:
		std::string prodvar = "";
		std::string prijsvar = "";
		
		void ProductLijst(){
			while(prodvar != "q"){
				std::cout << "Enter product name: ";
				std::cin >> prodvar;

				if(prodvar != "q"){
					product_naam.push_back(prodvar);
				}
			}
		}

		void ProductPrijs(){
			while(prijsvar != "q"){
				std::cout << "Enter the price" << '\n';
				std::cin >> prijsvar;

				if(prijsvar != "q"){
					product_prijs.push_back(prijsvar);
				}
			}
		}
		
		void ToonLijst(){
			for(size_t i = 0; i < product_naam.size(); ++i){
				std::cout << "- " << product_naam[i] << " | " << "€ " << product_prijs[i] << '\n';
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
		std::cout << "Press 'q' to go back" << '\n';
		std::cout << "Press 'exit' to quit" << '\n';
		std::cout << "Choice: ";
		std::cin >> choice;

		if(choice == "1"){
			Prod.ProductLijst();		
		}
		if(choice == "2"){
			Prod.ProductPrijs();
		}
		Prod.ToonLijst();
		}while(choice != "exit");		
	return 0;
}
