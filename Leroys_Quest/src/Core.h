#pragma once

#ifdef _MSC_VER
	#define LEROY_DEBUG_BREAK() __debugbreak()
#else
	#define LEROY_DEBUG_BREAK() /* debug break was here */
#endif


#if _MSVC_LANG == 201703L
	#define fallthrough_case [[fallthough]]
#else	
	#define fallthrough_case /* fall through */
#endif

#define LEROY_ASSERT(x) if (!(x))\
 { std::cerr << "Assertion failed! (" #x ")" << '\n'; LEROY_DEBUG_BREAK(); }

#define GetInstanceOf(x) x::GetInstance()

template<typename T>
bool IsTypeOf(std::string word)
{
	return T::HasCommandWord(word);
}
#define IsTypeOf(Type, word) IsTypeOf<Type>(word)