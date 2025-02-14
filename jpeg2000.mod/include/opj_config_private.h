/* create opj_config_private.h for CMake */
#define OPJ_HAVE_INTTYPES_H 	1

#define OPJ_PACKAGE_VERSION "2.5.0"

#define _LARGEFILE_SOURCE
#define _LARGE_FILES
#define _FILE_OFFSET_BITS 64
#define OPJ_HAVE_FSEEKO 1

/* find whether or not have <malloc.h> */
#if !defined(__APPLE__)
# define OPJ_HAVE_MALLOC_H 1
#endif

#if defined(_WIN32)
/* check if function `_aligned_malloc` exists */
#define OPJ_HAVE__ALIGNED_MALLOC 1
#endif

/* check if function `memalign` exists */
#if !defined(_WIN32)
#define OPJ_HAVE_MEMALIGN 1
/* check if function `posix_memalign` exists */
#define OPJ_HAVE_POSIX_MEMALIGN 1
#endif

#if !defined(_POSIX_C_SOURCE)
#if defined(OPJ_HAVE_FSEEKO) || defined(OPJ_HAVE_POSIX_MEMALIGN)
/* Get declarations of fseeko, ftello, posix_memalign. */
#define _POSIX_C_SOURCE 200112L
#endif
#endif

/* Byte order.  */
/* All compilers that support Mac OS X define either __BIG_ENDIAN__ or
__LITTLE_ENDIAN__ to match the endianness of the architecture being
compiled for. This is not necessarily the same as the architecture of the
machine doing the building. In order to support Universal Binaries on
Mac OS X, we prefer those defines to decide the endianness.
On other platforms we use the result of the TRY_RUN. */
#if defined(__APPLE__)
# if defined(__BIG_ENDIAN__)
#  define OPJ_BIG_ENDIAN
# endif
#elif defined(__linux__)
# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define OPJ_BIG_ENDIAN
# endif
#elif defined(_WIN32) && defined(__GNUC__)
# if defined(__BIG_ENDIAN__)
#  define OPJ_BIG_ENDIAN
# endif
#endif
