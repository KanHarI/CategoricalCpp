
#ifndef _MONAD_HPP
#define _MONAD_HPP

#include "Functor.hpp"

// M stands for monad
template <template <class TM> class M>
class Monad : public Functor<M> {
public:
	template <class T>
	static M<T> unit(const T& val) {
		return M<T>::_unit(val);
	}

	template <class T>
	static M<T> join(const M<M<T>>& mmt) {
		return M<T>::_join(mmt);
	}

	template <class T1, class T2>
	static M<T2> bind(const M<T1>& mt1, std::function<M<T2>(const T1&)> f) {
		auto mf = Functor<M>::template fmap<T1,M<T2>>(f);
		auto mmt2 = mf(mt1);
		return Monad<M>::template join<T2>(mmt2);
	}
	
};

#endif
