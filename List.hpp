// Author: KanHar

#include "Functor.hpp"
#include "Utils.h"

#include <algorithm>
#include <list>

template <class T>
class List : public std::list<T> {
public:
	INHERRITE_CTORS(List, std::list<T>)

	template<class T2>
	List<T2> _fmap(std::function<T2(const T&)> f) const{
		List<T2> l2;
		std::transform(this->begin(), this->end(), std::back_inserter(l2), f);
		return l2;
	}
};

using ListF = Functor<List>;
