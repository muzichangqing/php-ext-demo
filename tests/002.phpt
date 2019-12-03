--TEST--
php-ext-demo_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('php-ext-demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = php-ext-demo_test1();

var_dump($ret);
?>
--EXPECT--
The extension php-ext-demo is loaded and working!
NULL
