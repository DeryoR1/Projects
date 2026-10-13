#include <iostream>
#include <string>

void Running_Count(int& Total_Cards_In_Shoe, int& Count, std::string& Value){
	std::cout << "ENTER A VALUE: ";		
	std::cin >> Value;

	if(Value == "2" || Value == "3" || Value == "4" || Value == "5" || Value == "6"){
		Count++;
		Total_Cards_In_Shoe--;
	} else if(Value == "10" || Value == "J" || Value == "Q" || Value == "K" || Value == "A"){
		Count--;
		Total_Cards_In_Shoe--;
	} else if (Value == "j" || Value == "q" || Value == "k" || Value == "a"){
		Count--;
		Total_Cards_In_Shoe--;
	} else if(Value =="7" || Value == "8" || Value == "9"){
		Total_Cards_In_Shoe--;
	}
}

void True_Count(int& Total_Cards_In_Shoe, int& Count, double& TrueCount){
	if(Count != 0){
		double Decks_In_Shoe_Left = Total_Cards_In_Shoe / 52.0;
		TrueCount = Count / (double)Decks_In_Shoe_Left;
	}
	
}

int main(){
	int Deck = 52;
	int Count = 0;
	int Deck_Amount;
	double TrueCount = 0;
	std::string Value;
		
	std::cout << "with How many decks would you like to play: ";
	std::cin >> Deck_Amount;
	
	int Total_Cards_In_Shoe = Deck * Deck_Amount;
	
	do{
		Running_Count(Total_Cards_In_Shoe, Count, Value);
		if(Value == "r"){
			Total_Cards_In_Shoe = Deck * Deck_Amount;
			Count = 0;
			TrueCount = 0;
			std::cout << "Reshuffled and ready to go! \n";
			continue;
		}
		True_Count(Total_Cards_In_Shoe, Count, TrueCount);

		std::cout << "Running Count: " << Count << "\n";
		std::cout << "True Count: " << TrueCount << "\n";
		std::cout << "Total cards left in shoe: " << Total_Cards_In_Shoe << "\n";
		std::cout << "Total decks left in shoe: " << Total_Cards_In_Shoe / 52.0 << "\n";
		std::cout << "=================\n";	
	} while(Value != "e");
	return 0;
}
