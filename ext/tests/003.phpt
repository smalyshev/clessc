--TEST--
Test less
--SKIPIF--
<?php if (!extension_loaded("less")) print "skip"; ?>
--FILE--
<?php 
chdir(__DIR__);
var_dump(less_compile(file_get_contents("test2.css")));
var_dump(less_error());
?>
--EXPECT--
bool(false)
string(78) "Line 249, Column 8 Parse Error: Found "lib2.less" when expecting existing file"
