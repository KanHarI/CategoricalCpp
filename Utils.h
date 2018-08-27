
#include <utility>

#define INHERRITE_CTORS(CLASSNAME, PARENT) \
	template <class... _MACRO_Ts> \
	CLASSNAME(_MACRO_Ts&&... params) : PARENT(std::forward<_MACRO_Ts>(params)...) {}
