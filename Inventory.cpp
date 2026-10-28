#include <iostream>
#include <vector>
#include <string>

class Product{
	int voorraad;
	float prijs;
	
	public:
		std::string product_naam;

};

int main(){
	Product Prod;
	do{
		std::cout << "enter products: ";
		std::cin >> Prod.product_naam;
		std::cout << Prod.product_naam << '\n';
		
	}while(Prod.product_naam != "q");
		
	return 0;
}
