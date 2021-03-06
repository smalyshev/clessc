/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_LESS_H
#define PHP_LESS_H

extern zend_module_entry less_module_entry;
#define phpext_less_ptr &less_module_entry

#ifdef PHP_WIN32
#	define PHP_LESS_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_LESS_API __attribute__ ((visibility("default")))
#else
#	define PHP_LESS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(less);
PHP_MSHUTDOWN_FUNCTION(less);
PHP_RINIT_FUNCTION(less);
PHP_RSHUTDOWN_FUNCTION(less);
PHP_MINFO_FUNCTION(less);

PHP_FUNCTION(less_compile);
PHP_FUNCTION(less_error);

ZEND_BEGIN_MODULE_GLOBALS(less)
	char *last_error;
ZEND_END_MODULE_GLOBALS(less)

#ifdef ZTS
#define LESS_G(v) TSRMG(less_globals_id, zend_less_globals *, v)
#else
#define LESS_G(v) (less_globals.v)
#endif

int process_lessc(const char *input, int input_len, char **output, int *output_len);

#endif	/* PHP_LESS_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
