/*
 *    Xcode does not fully support std::optional yet. When compiling
 *    with Xcode use <experimental/optional> and std::experimental as
 *    the namespace.
 */

#ifdef LEROY_PLATFORM_MACOS
    #include <experimental/optional>
    #define Optional std::experimental::optional
#else
    #include <optional>
    #define Optional std::optional
#endif
