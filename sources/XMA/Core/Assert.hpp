#ifndef _XMA_CORE_ASSERT_HPP
#define _XMA_CORE_ASSERT_HPP

#include <XMA/Core/STL.hpp>

// ---------------------------------------------------------------------------------------------------------------------
// Internal
// ---------------------------------------------------------------------------------------------------------------------

inline void _xma_core_assert(const char* expression, const char* file, int line)
{
    std::ostringstream s;
    s << "Assertion '" << expression << "' failed, ";
    s << "file '" << file << "' ";
    s << "line '" << line << "'.";
    throw std::logic_error(s.str());
}

// ---------------------------------------------------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------------------------------------------------

#define XMA_TEST(MESSAGE, FUNCTION) {\
    try { FUNCTION(); std::cout << MESSAGE << ": OK" << std::endl; }\
    catch(const std::exception& e) {\
        std::cerr << MESSAGE << ": KO" << std::endl;\
        std::cerr << e.what() << std::endl;\
    }\
    catch(...) { std::cerr << MESSAGE << ": KO" << std::endl; }\
}

// ---------------------------------------------------------------------------------------------------------------------

#define XMA_ASSERT(EXPRESSION) ((EXPRESSION) ? (void)0 : _xma_core_assert(#EXPRESSION, __FILE__, __LINE__));
#define XMA_ASSERT_EQUAL(A, B) ((A == B) ? (void)0 : _xma_core_assert(#A " must be equal to " #B, __FILE__, __LINE__));
#define XMA_ASSERT_NOT_EQUAL(A, B) ((A != B) ? (void)0 : _xma_core_assert(#A " must be different of " #B, __FILE__, __LINE__));
#define XMA_ASSERT_HIGHER(A, B) ((A > B) ? (void)0 : _xma_core_assert(#A " must be higher to " #B, __FILE__, __LINE__));
#define XMA_ASSERT_HIGHER_OR_EQUAL(A, B) ((A >= B) ? (void)0 : _xma_core_assert(#A " must be higher or equal to " #B, __FILE__, __LINE__));
#define XMA_ASSERT_LOWER(A, B) ((A < B) ? (void)0 : _xma_core_assert(#A " must be lower to " #B, __FILE__, __LINE__));
#define XMA_ASSERT_LOWER_OR_EQUAL(A, B) ((A <= B) ? (void)0 : _xma_core_assert(#A " must be lower or equal to " #B, __FILE__, __LINE__));

// ---------------------------------------------------------------------------------------------------------------------

#define XMA_ASSERT_THROW(EXPRESSION) {\
    bool exceptionThrown = false;\
    try { EXPRESSION(); } catch(...) { exceptionThrown = true; }\
    if(!exceptionThrown) {\
        std::ostringstream s;\
        s << "Should throw error, ";\
        s << "file '" << __FILE__ << "' ";\
        s << "line '" << __LINE__ << "'.";\
        throw std::logic_error(s.str());\
    }\
}

// ---------------------------------------------------------------------------------------------------------------------

#define XMA_ASSERT_THROW_TYPE(EXPRESSION, TYPE) {\
    bool exceptionThrown = false;\
    try { EXPRESSION(); }\
    catch(const TYPE& e) { exceptionThrown = true; }\
    catch(...) { exceptionThrown = false; }\
    if(!exceptionThrown) {\
        std::ostringstream s;\
        s << "Should throw '" << #TYPE << "', ";\
        s << "file '" << __FILE__ << "' ";\
        s << "line '" << __LINE__ << "'.";\
        throw std::logic_error(s.str());\
    }\
}

// ---------------------------------------------------------------------------------------------------------------------

#define XMA_ASSERT_NOT_THROW(EXPRESSION) {\
    bool exceptionThrown = false;\
    try { EXPRESSION(); } catch(...) { exceptionThrown = true; }\
    if(exceptionThrown) {\
        std::ostringstream s;\
        s << "Should not throw error, ";\
        s << "file '" << __FILE__ << "' ";\
        s << "line '" << __LINE__ << "'.";\
        throw std::logic_error(s.str());\
    }\
}

// ---------------------------------------------------------------------------------------------------------------------

#define XMA_ASSERT_NOT_THROW_TYPE(EXPRESSION, TYPE) {\
    bool exceptionThrown = false;\
    try { EXPRESSION(); }\
    catch(const TYPE& e) { exceptionThrown = true; }\
    catch(...) { exceptionThrown = false; }\
    if(exceptionThrown) {\
        std::ostringstream s;\
        s << "Should not throw '" << #TYPE << "', ";\
        s << "file '" << __FILE__ << "' ";\
        s << "line '" << __LINE__ << "'.";\
        throw std::logic_error(s.str());\
    }\
}

// ---------------------------------------------------------------------------------------------------------------------

#endif
