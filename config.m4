PHP_ARG_ENABLE(ext_demo, whether to enable ext_demo support,
    Make sure that the comment is aligned:
[  --enable-php-ext-demo          Enable ext_demo support])

if test "$PHP_EXT_DEMO" != "no"; then
    PHP_NEW_EXTENSION(ext_demo, ext_demo.c, $ext_shared)
fi
