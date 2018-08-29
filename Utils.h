
#include <utility>

#define INHERRITE_CTORS(CLASSNAME, PARENT) \
	template <class... _MACRO_Ts> \
	CLASSNAME(_MACRO_Ts&&... params) : PARENT(std::forward<_MACRO_Ts>(params)...) {}

template <template <class... TT1, class... TTs> class MetaTemplate, class... T1>
struct Partial {
	template <class... Ts>
	struct Apply : public MetaTemplate<T1..., Ts...> {};
}
