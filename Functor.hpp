// Author: KanHar

#include <functional>

template <template <class FT> class F>
class Functor {
public:
	template <class T1, class T2>
	static std::function<F<T2>(const F<T1>&)> fmap(std::function<T2(const T1&)> f) {
		return [=](const F<T1>& Functor1) -> F<T2>{
			return Functor1._fmap(f);
		};
	}
};
