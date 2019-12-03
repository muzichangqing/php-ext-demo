PHP_ARG_ENABLE(php-ext-demo, whether to enable php-ext-demo support,
    Make sure that the comment is aligned:
[  --enable-php-ext-demo          Enable php-ext-demo support])

if test "$PHP_PHP-EXT-DEMO" != "no"; then

  AC_DEFINE(HAVE_PHP-EXT-DEMO, 1, [ Have php-ext-demo support ])

  PHP_NEW_EXTENSION(php-ext-demo, php-ext-demo.c, $ext_shared)
fi
