--TEST--
Check if php-ext-demo is loaded
--SKIPIF--
<?php
if (!extension_loaded('php-ext-demo')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "php-ext-demo" is available';
?>
--EXPECT--
The extension "php-ext-demo" is available
