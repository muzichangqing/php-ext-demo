--TEST--
php-ext-demo_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('php-ext-demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(php-ext-demo_test2());
var_dump(php-ext-demo_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
