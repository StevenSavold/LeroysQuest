#pragma once

#ifdef LEROY_PLATFORM_WINDOWS
	#define LEROY_DEBUG_BREAK() /* inline debuger breakpoint for Visual C++ */ __debugbreak()
#else
	#define LEROY_DEBUG_BREAK() /* inline assembly to break gcc and clang */   asm("int $3") 
#endif

#define LEROY_ASSERT(x) if (!(x))\
 { std::cerr << "Assertion failed! (" #x ") " << "on line " << __LINE__ << " in file " << __FILE__ << '\n'; LEROY_DEBUG_BREAK(); }

#define GetInstanceOf(x) x::GetInstance()

template<typename T>
bool IsTypeOf(std::string word)
{
	return T::HasCommandWord(word);
}
#define IsTypeOf(Type, word) IsTypeOf<Type>(word)