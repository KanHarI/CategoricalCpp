
#include "List.hpp"

#include <iostream>

std::string findLastDigit(int i) {
	switch(i%10) {
		case 0:
			return "Zero";
		case 1:
			return "One";
		case 2:
			return "Two";
		case 3:
			return "Three";
		case 4:
			return "Four";
		case 5:
			return "Five";
		case 6:
			return "Six";
		case 7:
			return "Seven";
		case 8:
			return "Eight";
		default:
			return "Nine";

	}
}

int main() {
	List<int> listA;
	listA.push_back( 75341);
	listA.push_back(919343);
	listA.push_back(  2793);
	listA.push_back( 84267);
	
	auto mf = ListF::fmap<int, std::string>(findLastDigit);
	
	List<std::string> listB = mf(listA);
	
	std::cout <<"Size: " << listB.size() << std::endl << std::endl << "Content: " << std :: endl;

	for (auto c : listB) {
		std::cout << c << std::endl;
	}
}
