
#include "List.hpp"

#include <iostream>

int main() {
	List<int> a;
	a.push_back(1);
	List<int> b = a._fmap<int>([](int a) {return +a%10;});
	std::cout << a.back() << std::endl;
}
