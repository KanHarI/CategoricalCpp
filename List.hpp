
#ifndef _LIST_HPP
#define _LIST_HPP


#include "Utils.h"

#include "Functor.hpp"
#include "Monad.hpp"

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

	static _unit(const T& val) {
		return List<T>({val});
	}

	static List<T> _join(const List<List<T>>& mmt) {
		List<T> r;
		for (const auto& mt : mmt) {
			r.insert(r.end(), mt.begin(), mt.end());
		}
		return r;
	}
};

using ListF = Functor<List>;
using ListM = Monad<List>;

#endif
