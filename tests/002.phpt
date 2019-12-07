--TEST--
ext_demo_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('ext_demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = ext_demo_test1();

var_dump($ret);
?>
--EXPECT--
The extension ext_demo is loaded and working!
NULL
