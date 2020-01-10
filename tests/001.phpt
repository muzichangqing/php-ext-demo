--TEST--
Check if ext_demo is loaded
--SKIPIF--
<?php
if (!extension_loaded('ext_demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "ext_demo" is available';
?>
--EXPECT--
The extension "ext_demo" is available
