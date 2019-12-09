/* ext_demo extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_ext_demo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void ext_demo_test1()
 */
PHP_FUNCTION(ext_demo_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "ext_demo");
}
/* }}} */

/* {{{ string ext_demo_test2( [ string $var ] )
 */
PHP_FUNCTION(ext_demo_test2)
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

/*{{{ void confirm_ext_demo_compiled() }}}
*/
PHP_FUNCTION(confirm_ext_demo_compiled)
{
    php_printf("hello world!\n");
    return;
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ext_demo)
{
#if defined(ZTS) && defined(COMPILE_DL_EXT_DEMO)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ext_demo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "ext_demo support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_ext_demo_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_ext_demo_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_confirm_ext_demo_compiled, 0)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ ext_demo_functions[]
 */
static const zend_function_entry ext_demo_functions[] = {
	PHP_FE(ext_demo_test1,		arginfo_ext_demo_test1)
	PHP_FE(ext_demo_test2,		arginfo_ext_demo_test2)
	PHP_FE(confirm_ext_demo_compiled,		arginfo_confirm_ext_demo_compiled)
	PHP_FE_END
};
/* }}} */

/* {{{ ext_demo_module_entry
 */
zend_module_entry ext_demo_module_entry = {
	STANDARD_MODULE_HEADER,
	"ext_demo",					/* Extension name */
	ext_demo_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(ext_demo),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(ext_demo),			/* PHP_MINFO - Module info */
	PHP_EXT_DEMO_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EXT_DEMO
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(ext_demo)
#endif