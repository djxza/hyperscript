#pragma once

#include "core.hpp"

/* All these definitions are as of c++23 */
/* Just to clarify -> means similar to, not is same as */
/* As = means it is the EXACT same as in the c++ stl */
enum class token_t {
	/* null = nullptr */
	null,

	/// builtin functions

	/* builtin typeof, see docs */
	BUILTIN_TYPEOF, // = __typeof__

	/* builtin sizeof, see docs */
	BUILTIN_SIZEOF, // = sizeof

	/* builtin alloca, see docs */
	BUILTIN_ALLOCA, // (platform dependant)

	/* builtin malloc, see docs */
	BUILTIN_MALLOC, // stdlib's malloc

	/* builtin heap free, see docs */
	BUILTIN_HEAP_FREE, // stdlib's free

	/* Builtin stack free, see docs */
	BUILTIN_STACK_FREE, // idk?


	/// builtin types

	/* builtin stack array -> std::array */
	BUILTIN_STACK_ARRAY,

	/* builtin heap array -> std::vector */
	BUILTIN_HEAP_ARRAY,

	/// Non-integral type definiton
	
	/* builtin string type -> std::string */
	STRING,
	
	/* builtin allocator type = std::alocator */

	/// Integral type definition

#if ARCH >= 8
	/* 8-bit definition */
	I8,

	/* 8-bit definition */
	U8,

#define _USIZE_ U8
#define _ISIZE_ I8

#endif // ARCH >= 8

#if ARCH >= 16
	/* 16-bit definition */
	I16,

	/* 16-bit definition */
	U16,

# undef  _USIZE_
# undef  _ISIZE_
# define _USIZE_ U16
# define _ISIZE_ I16

#endif // ARCH >= 16

#if ARCH >= 32
	/* 32-bit definition */
	I32,

	/* 32-bit definition */
	U32,

	/* 32-bit definition */
	F32,

# undef  _USIZE_
# undef  _ISIZE_
# define _USIZE_ U32
# define _ISIZE_ I32

#endif // ARCH >= 32

#if ARCH >= 64
	/* 64-bit definition */
	I64,

	/* 64-bit definition */
	U64,

	/* 64-bit definition */
	F64,

# undef  _USIZE_
# undef  _ISIZE_
# define _USIZE_ U64
# define _ISIZE_ I64

#endif // ARCH >= 64

#if ARCH == 128
	/* 128-bit definition */
	I128,

	/* 128-bit definition */
	U128,

# undef  _USIZE_
# undef  _ISIZE_
# define _USIZE_ U128
# define _ISIZE_ I128

#endif // ARCH == 128

	/// Size 

	/* Unsigned */
	USIZE,

	/* Signed */
	ISIZE,

	/// Type modifiers

	/* Const */
	CONSTANT,

	/* Consterxpr */
	CONSTEXPR,

	/* Volatile */
	VOLATILE,

	FN,
	VAR,
	CLASS,
	IF,
	ELSE,
	WHILE,
	DO,
	TRY,
	CATCH,
	THROW,
	CDEF_START,
	CDEF_END,
	BRACE_START,
	BRACE_END,

	/// Ex function definition, array definiton ...
	/* Define begin of a curly brace pair */
	CURLY_START,

	/* Define end of a curly brace pair */
	CURLY_END,

	/* Define begin of file */
	COMPILE_BEGIN,

	/* Define end of file */
	COMPILE_END,

	/* Check docs for an example */
	USING,

	/// What can be utilized by using
	/* Only utilized by using, to include a file */
	USING_FILE,

	/* also for module definitions */
	MODULE,

	/* class, See docs */
	//CLASS,
}
;

class token_list_t {
private:
	std::vector<token_t> tokens;

public:
	token_list_t(
		const std::string& path
	);

	std::vector<token_t> get_data() const;
};