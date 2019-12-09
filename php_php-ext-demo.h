/* php-ext-demo extension for PHP */

#ifndef PHP_PHP-EXT-DEMO_H
# define PHP_PHP-EXT-DEMO_H

extern zend_module_entry php-ext-demo_module_entry;
# define phpext_php-ext-demo_ptr &php-ext-demo_module_entry

# define PHP_PHP-EXT-DEMO_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHP-EXT-DEMO)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PHP-EXT-DEMO_H */

