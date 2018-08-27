
#ifndef _COMONAD_HPP
#define _COMONAD_HPP

#include "Functor.hpp"

// W in an inverted M - hence the notation
template <template <class TW> class W>
class Comonad : public Functor<W> {
public:
	template <class T>
	static T extract(const W<T>& w) {
		return W<T>::_extract(w);
	}

	template <class T>
	static W<W<T>> duplicate(const W<T>& w) {
		return W<T>::_duplicate();
	}
}

#endif
