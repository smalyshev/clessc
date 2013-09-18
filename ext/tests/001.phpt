--TEST--
Check for less presence
--SKIPIF--
<?php if (!extension_loaded("less")) print "skip"; ?>
--FILE--
<?php 
echo "less extension is available";
?>
--EXPECT--
less extension is available
