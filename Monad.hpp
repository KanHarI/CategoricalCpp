
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
	static M<T> join(M<M<T>> mmt) {
		return M<T>::_join(mmt);
	}
	
};

#endif
