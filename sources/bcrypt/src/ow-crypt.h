/*
 * Written by Solar Designer <solar at openwall.com> in 2000-2011.
 * No copyright is claimed, and the software is hereby placed in the public
 * domain.  In case this attempt to disclaim copyright and place the software
 * in the public domain is deemed null and void, then the software is
 * Copyright (c) 2000-2011 Solar Designer and it is hereby released to the
 * general public under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * There's ABSOLUTELY NO WARRANTY, express or implied.
 *
 * See crypt_blowfish.c for more information.
 */

#ifndef _OW_CRYPT_H
#define _OW_CRYPT_H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#if _WIN32
#	if defined( __MINGW32__ )
#		define _BcryptCommonExport
#	else
#		if defined BCRYPT_EXPORT
#			define _BcryptCommonExport __declspec(dllexport)
#		else
#			define _BcryptCommonExport __declspec(dllimport)
#		endif
#	endif
#else
#	define _BcryptCommonExport
#endif

#ifndef __GNUC__
#undef __const
#define __const const
#endif

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

#ifndef __SKIP_GNU
	char *crypt(__const char *key, __const char *setting);
	char *crypt_r(__const char *key, __const char *setting, void *data);
#endif

#ifndef __SKIP_OW
extern char *crypt_rn(__const char *key, __const char *setting,
	void *data, int size);
extern char *crypt_ra(__const char *key, __const char *setting,
	void **data, int *size);
extern char *crypt_gensalt(__const char *prefix, unsigned long count,
	__const char *input, int size);
extern char *crypt_gensalt_rn(__const char *prefix, unsigned long count,
	__const char *input, int size, char *output, int output_size);
extern char *crypt_gensalt_ra(__const char *prefix, unsigned long count,
	__const char *input, int size);
#endif

#ifdef __cplusplus
}
#endif

#endif
