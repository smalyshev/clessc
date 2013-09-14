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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_less.h"

/* If you declare any globals in php_less.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(less)
*/

/* True global resources - no need for thread safety here */
static int le_less;

/* {{{ less_functions[]
 *
 * Every user visible function must have an entry in less_functions[].
 */
const zend_function_entry less_functions[] = {
	PHP_FE(less_compile,	NULL)		
	PHP_FE_END	/* Must be the last line in less_functions[] */
};
/* }}} */

/* {{{ less_module_entry
 */
zend_module_entry less_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"less",
	less_functions,
	PHP_MINIT(less),
	PHP_MSHUTDOWN(less),
	PHP_RINIT(less),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(less),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(less),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LESS
ZEND_GET_MODULE(less)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("less.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_less_globals, less_globals)
    STD_PHP_INI_ENTRY("less.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_less_globals, less_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_less_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_less_init_globals(zend_less_globals *less_globals)
{
	less_globals->global_value = 0;
	less_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(less)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(less)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(less)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(less)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(less)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "less support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* {{{ proto string compile_less(string arg)
   Compile LESS string */
PHP_FUNCTION(less_compile)
{
	char *arg = NULL;
	int arg_len, len, out_len;
	char *strg;
	char *out = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}
	
	if(process_lessc(arg, arg_len, &out, &out_len) != SUCCESS) {
		RETURN_FALSE;
	}

	RETURN_STRINGL(out, out_len, 0);
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
