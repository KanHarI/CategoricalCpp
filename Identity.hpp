
#include "Utils.h"

#include "Functor.hpp"
#include "Monad.hpp"
#include "Comonad.hpp"
#include "MonadTrans.hpp"
#include "ComonadTrans.hpp"

template <class T>
class Id {
	T v;
	Id(T val) : v(val){};

public:
	template <class T2>
	Id<T2> _fmap(std::function<T2(const T&)> f) {
		return Id<T2>(f(v));
	}

	static Id<T> _unit(const T& val) {
		return Id(val);
	}

	static Id<T> _join(const Id<Id<T>>& mmt) {
		return Id(mmt.v.v);
	}

	static T _extract(const Id<T>& wt) {
		return wt.v;
	}

	static Id<Id<T>> _duplicate(const Id<T>) {
		return Id(Id(v));
	}
};

template <template <class TF> F, class T>
class _IdT {
	F<T> v;
	Id(F<T> val) : v(val){};

public:
	template <class T2>
	_IdT<F, T2> _fmap(std::function<T2(const T&)> f) {
		return _IdT<F, T2>(v._fmap(f));
	}

	static _IdT<F, T> _unit(const T& val) {
		return _IdT(F<T>::_unit(val));
	}

	static _IdT<F, T> _join(const _IdT<F, _IdT<F, T>>& ifift) {
		F<_IdT<F, T>> fift = ifift.val;
		F<F<T>> fft = fift._fmap([](const _IdT<F, T>& ift){return ift});
		F<T> ft = F<T>::_join(fft);
		return _IdT<F, T>::_unit(ft);
	}

	static T _extract(const _IdT<F, T>& ift) {
		return F<T>::_extract(ift.val);
	}

	static _IdT<F, _IdT<F, T>> _duplicate(const _IdT<F, T>& ift) {
		F<_IdT<F, T>> fift = F<_IdT<F, T>>::_unit(ift);
		return _IdT(fift);
	}
}

using IdF = Functor<Id>;
using IdM = Monad<Id>;
using IdC = Comonad<Id>;

template <class M>
using IdMT = Functor<Partial<_IdT, M>::Apply>;
