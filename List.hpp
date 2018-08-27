// Author: KanHar

#include "Utils.h"

#include <algorithm>
#include <functional>
#include <list>

template <class T>
class List : public std::list<T> {
public:
	INHERRITE_CTORS(List, std::list<T>)

	template<class T2>
	List<T2> _fmap(std::function<T2(const T&)> f){
		List<T2> l2;
		std::transform(this->begin(), this->end(), l2.begin(), f);
		return l2;
	}
};
