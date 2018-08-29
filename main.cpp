
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
		case 9:
			return "Nine";
		default:
			return "NAN";

	}
}

void testFunctor() {
	List<int> listA;
	listA.push_back( 75341);
	listA.push_back(919343);
	listA.push_back(  2793);
	listA.push_back( 84267);
	
	auto mappedFunction = ListF::fmap<int, std::string>(findLastDigit);
	
	List<std::string> listB = mappedFunction(listA);
	
	std::cout <<"Size: " << listB.size() << std::endl << std::endl << "Content: " << std :: endl;

	for (auto c : listB) {
		std::cout << c << std::endl;
	}
}

List<std::string> findAllDigits(int i) {
	List<std::string> r;
	while (i!=0) {
		r.push_back(findLastDigit(i));
		i/=10;
	}
	return r;
}

void testMonad() {
	List<int> listA;
	listA.push_back( 75341);
	listA.push_back(919343);
	listA.push_back(  2793);
	listA.push_back( 84267);

	auto mappedFunction = ListM::fmap<int, List<std::string>>(findAllDigits);

	List<List<std::string>> listB = mappedFunction(listA);

	List<std::string> listC = ListM::join<std::string>(listB);

	std::cout <<"Size: " << listC.size() << std::endl << std::endl << "Content: " << std :: endl;

	for (auto c : listC) {
		std::cout << c << std::endl;
	}
}

void testMonad2() {
	List<int> listA;
	listA.push_back( 75341);
	listA.push_back(919343);
	listA.push_back(  2793);
	listA.push_back( 84267);

	List<std::string> listB = ListM::bind<int, std::string>(listA, findAllDigits);

	std::cout <<"Size: " << listB.size() << std::endl << std::endl << "Content: " << std :: endl;

	for (auto c : listB) {
		std::cout << c << std::endl;
	}	
}

int main() {
	testMonad2();
	return 0;
}
