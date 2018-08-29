
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

	template <class T1, class T2>
	static M<T2> extend(const w<T1>& wt1, std::function<T2(const W<T1>&)> f) {
		auto wwt1 = Comonad<M>::template extend<T1>(wt1);
		auto mf = Functor<M>::template fmap<W<T1>,T2>(f);
		return wf(wwt1);
	}
}

#endif
