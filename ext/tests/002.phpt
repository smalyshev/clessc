--TEST--
Test less
--SKIPIF--
<?php if (!extension_loaded("less")) print "skip"; ?>
--FILE--
<?php 
chdir(__DIR__);
echo less_compile(file_get_contents("test.css"));
?>
--EXPECT--
@import "lib.css";#header{color:#6c94be}.class{content:"I am f'nord. I am f'nord. "}.bordered{border-top:dotted 1px black;border-bottom:solid 2px black}#menu a{color:#111;border-top:dotted 1px black;border-bottom:solid 2px black}.post a{color:red;border-top:dotted 1px black;border-bottom:solid 2px black}#header{border-radius:4px;-moz-border-radius:4px;-webkit-border-radius:4px}.button{border-radius:6px;-moz-border-radius:6px;-webkit-border-radius:6px}pre{text-wrap:wrap;white-space:pre-wrap;white-space:-moz-pre-wrap;word-wrap:break-word}.some .selector div{color-1:#008000;color-2:#008000;padding-2:2}.test mixin2a{color:#000}.test mixin2b{color:rgba(0,0,0,0.5)}.class{box-shadow:2px 5px 1px #000;-moz-box-shadow:2px 5px 1px #000;-webkit-box-shadow:2px 5px 1px #000;box-shadow:4px 10px 2px #000;-moz-box-shadow:4px 10px 2px #000;-webkit-box-shadow:4px 10px 2px #000;box-shadow:8px 20px 1px #000;-moz-box-shadow:8px 20px 1px #000;-webkit-box-shadow:8px 20px 1px #000}.test mixin3{border1:1px #000 solid;border2:4px #000 solid;border3:4px #456 dashed}#header{color:black}#header .navigation{font-size:12px}#header .logo{width:300px}#header .logo:hover{text-decoration:none}#header .logo:hover,#header .logo:focus{text-decoration:none}#header .logo h2 a{height:10px}#header .logo a:hover{text-decoration:underline}#header .logo div,#header .logo span{color:#FFF}#header .class1 a,#header .class2 a{font-weight:bold}.class{background-color:#161616;width:30px;border:20px solid black;height:60%;top:15em}.class{color:#ed2c2c;color:#a50e0e;color:#e00606;color:#c91d1d;color:#d41212;color:rgba(212,18,18,0.9);color:#d43212;color:#d41232;color:#f1dada;clip:rect(1px,1px,1px,1px);color:#1a1a1a}#header a{color:orange;display:block;border:1px solid black;background-color:grey}#header a:hover{background-color:white}#header a span a{display:none}#page #header{color:white}#footer{color:red}.lib-test{color:#123}.class{background-image:url("http://assets.fnord.com/images/bg.png")}.class{filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src='image.png')}body{background-image:linear-gradient(bottom,#e83f19 0%,#ff825f 50%);width:10 -1;filter:progid:DXImageTransform.Microsoft.gradient(enabled="false",startColorstr=#57ba52,endColorstr=#2c9027,GradientType=0)}video{*zoom:1}audio:not([controls]){display:none}.class1{background-color:black;color:#ddd}.class2{background-color:white;color:#555}h1{color:white;height:20px}body{test2:1px;test1:1px}body footer,body .push{height:60px}body header{height:90px}.test5{background:url(test.png) no-repeat;width:0px;height:0px;width-jpg:0px;height-jpg:0px}

