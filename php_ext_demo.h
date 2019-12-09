/* ext_demo extension for PHP */

#ifndef PHP_EXT_DEMO_H
# define PHP_EXT_DEMO_H

extern zend_module_entry ext_demo_module_entry;
# define phpext_ext_demo_ptr &ext_demo_module_entry

# define PHP_EXT_DEMO_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_EXT_DEMO)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_EXT_DEMO_H */

