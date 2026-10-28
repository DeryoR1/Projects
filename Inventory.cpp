#include <iostream>
#include <vector>
#include <string>

class Product{
	int voorraad;
	float prijs;
	std::vector<std::string> product_naam;
	
	public:
		std::string prodvar;
		
		std::string ProductLijst(){
			std::cout << "Enter product name: ";
			std::cin >> prodvar;

			product_naam.push_back(prodvar);
			
			return 0;
		}

};

int main(){
	Product Prod;
	int choice;

		std::cout << "1: Products" << '\n';
		std::cout << "2: Price" << '\n';
		std::cout << "Choice: ";
		std::cin >> choice;

		if(choice == 1){
			do{
				Prod.ProductLijst();		
			}while(choice != 'q');
		};
		
	return 0;
}
