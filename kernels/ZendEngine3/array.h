
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_ARRAY_H
#define ZEPHIR_KERNEL_ARRAY_H
#define ZEPHIR_MAX_ARRAY_LEVELS 16

#include <php.h>
#include <Zend/zend.h>
#include "kernel/globals.h"
#include "kernel/main.h"

void ZEPHIR_FASTCALL zephir_create_array(zval *return_value, uint size, int initialize);

/** Combined isset/fetch */
int zephir_array_isset_fetch(zval *fetched, const zval *arr, zval *index, int readonly);
int zephir_array_isset_string_fetch(zval *fetched, zval *arr, char *index, uint index_length, int readonly);
int zephir_array_isset_long_fetch(zval *fetched, zval *arr, unsigned long index, int readonly);

/** Check for index existence */
int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index);
int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, unsigned long index);
int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint index_length);

/** Unset existing indexes */
int ZEPHIR_FASTCALL zephir_array_unset_string(zval *arr, const char *index, uint index_length, int flags);

/** Fetch items from arrays */
int zephir_array_fetch(zval *return_value, zval *arr, zval *index, int flags ZEPHIR_DEBUG_PARAMS);
int zephir_array_fetch_string(zval *return_value, zval *arr, const char *index, uint index_length, int flags ZEPHIR_DEBUG_PARAMS);

/** Append elements to arrays */
int zephir_array_append(zval *arr, zval *value, int separate ZEPHIR_DEBUG_PARAMS);

/** Modify array */
int zephir_array_update_zval(zval *arr, zval *index, zval *value, int flags);
int zephir_array_update_string(zval *arr, const char *index, uint index_length, zval *value, int flags);
int zephir_array_update_long(zval *arr, unsigned long index, zval *value, int flags ZEPHIR_DEBUG_PARAMS);

/* Update array using multiple keys */
void zephir_array_update_multi_ex(zval *arr, zval *value, const char *types, int types_length, int types_count, va_list ap);
int zephir_array_update_multi(zval *arr, zval *value, const char *types, int types_length, int types_count, ...);

#define zephir_array_fast_append(arr, value) \
  Z_TRY_ADDREF(value); \
  zend_hash_next_index_insert(Z_ARRVAL(arr), &value);

#endif /* ZEPHIR_KERNEL_ARRAY_H */
