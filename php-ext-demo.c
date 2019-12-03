/* php-ext-demo extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_php-ext-demo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void php-ext-demo_test1()
 */
PHP_FUNCTION(php-ext-demo_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "php-ext-demo");
}
/* }}} */

/* {{{ string php-ext-demo_test2( [ string $var ] )
 */
PHP_FUNCTION(php-ext-demo_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php-ext-demo)
{
#if defined(ZTS) && defined(COMPILE_DL_PHP-EXT-DEMO)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php-ext-demo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php-ext-demo support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_php-ext-demo_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_php-ext-demo_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ php-ext-demo_functions[]
 */
static const zend_function_entry php-ext-demo_functions[] = {
	PHP_FE(php-ext-demo_test1,		arginfo_php-ext-demo_test1)
	PHP_FE(php-ext-demo_test2,		arginfo_php-ext-demo_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ php-ext-demo_module_entry
 */
zend_module_entry php-ext-demo_module_entry = {
	STANDARD_MODULE_HEADER,
	"php-ext-demo",					/* Extension name */
	php-ext-demo_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(php-ext-demo),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(php-ext-demo),			/* PHP_MINFO - Module info */
	PHP_PHP-EXT-DEMO_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP-EXT-DEMO
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(php-ext-demo)
#endif

