--TEST--
ed_strlen() Basic test
--SKIPIF--
<?php
if (!extension_loaded('ext_demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(ed_strlen(""));
var_dump(ed_strlen("ext_demo"));
?>
--EXPECT--
int(0)
int(8)
