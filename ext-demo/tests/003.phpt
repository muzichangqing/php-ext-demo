--TEST--
ext_demo_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('ext_demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(ext_demo_test2());
var_dump(ext_demo_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
