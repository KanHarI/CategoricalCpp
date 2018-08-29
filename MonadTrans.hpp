
#include "Monad.hpp"

template <template <template <class TM> class M> class Trans>
class MonadTrans {
	template <class M>
	using Transformed = Monad<Trans<M>>;
};
