#include <iostream>
#include <vector>
#include <string>

class Product{
	int voorraad;
	float prijs;
	std::vector<std::string> product_naam;
	
	public:
		std::string prodvar;
		
		void ProductLijst(){
			while(prodvar != "q"){
				std::cout << "Enter product name: ";
				std::cin >> prodvar;

				if(prodvar != "q"){
					product_naam.push_back(prodvar);
				}
			}
		}
		
		void ToonLijst(){
			for(const auto& naam : product_naam){
				std::cout << "- " << naam << '\n';
			}
		}
};

int main(){
	Product Prod;
	std::string choice;

		std::cout << "1: Products" << '\n';
		std::cout << "2: Price" << '\n';
		std::cout << "2: Total" << '\n';
		std::cout << "Press 'q' to quit" << '\n';
		std::cout << "Choice: ";
		std::cin >> choice;

		if(choice == "1"){
			Prod.ProductLijst();		
		};
		Prod.ToonLijst();
		
	return 0;
}
