### 创建PHP扩展

##### 下载PHP源码

    wget https://www.php.net/distributions/php-7.3.12.tar.gz
    tar -zxvf php-7.3.12.tar.gz

##### 编译PHP

    sudo apt install libxml2 libxml2-dev
    cd php-7.3.12
    ./configure
    make 
    sudo make install
    # 根据提示复制php.ini到指定目录
    cp php.ini-development /usr/local/lib/php.ini
    make clean

##### 创建扩展

在php 7.3.0之后，创建方法由运行ext/ext_skel命令，改为运行 php ext/ext_skel.php --ext <name> 命令

    php ext/ext_skel.php --ext ext_demo

命令执行成功后，生成的项目文件被放在了 ext/ext_demo 中

##### 修改config.m4

    cd ext/ext_demo
    vim config.m4

修改 config.m4里的内容为：

    PHP_ARG_ENABLE(ext_demo, whether to enable ext_demo support,
        Make sure that the comment is aligned:
    [  --enable-php-ext-demo          Enable ext_demo support])

    if test "$PHP_EXT_DEMO" != "no"; then
        PHP_NEW_EXTENSION(ext_demo, ext_demo.c, $ext_shared)
    fi

PHP_NEW_EXTENSION(ext_demo, ext_demo.c, $ext_shared) 分别声明了扩展的名称，源文件名，编译形式（$ext_shared代表动态库）

##### 修改 ext_demo.c

在ext_demo.c  PHP_FUNCTION(ext_demo_test2) 方法之后 加上：

    PHP_FUNCTION(confirm_ext_demo_compiled)
    {
        php_printf("hello world!\n");
        return;
    }
    
ext_demo.c {{{arginfo}}} 中 加上：
    
    ZEND_BEGIN_ARG_INFO(arginfo_confirm_ext_demo_compiled, 0)
    ZEND_END_ARG_INFO()

ext_demo.c {{{ext_demo_functions[]}}} 修改为：

    static const zend_function_entry ext_demo_functions[] = {
	    PHP_FE(ext_demo_test1,		arginfo_ext_demo_test1)
	    PHP_FE(ext_demo_test2,		arginfo_ext_demo_test2)
	    PHP_FE(confirm_ext_demo_compiled,		arginfo_confirm_ext_demo_compiled)
	    PHP_FE_END
    };

##### 编译扩展

在扩展目录中运行

    phpize
    ./configure
    make
    sudo make install

##### 运行测试文件

测试文件 ext_demo.php

    <?php
    $br = (php_sapi_name() == "cli")? "":"<br>";
    if(!extension_loaded('ext_demo')) {
    	dl('ext_demo.' . PHP_SHLIB_SUFFIX);
    }
    $module = 'ext_demo';
    $functions = get_extension_funcs($module);
    echo "Functions available in the test extension:$br\n";
    foreach($functions as $func) {
        echo $func."$br\n";
    }
    echo "$br\n";
    $function = 'confirm_' . $module . '_compiled';
    if (extension_loaded($module)) {
    	$str = $function($module);
    } else {
    	$str = "Module $module is not compiled into PHP";
    }
    echo "$str\n";

运行文件

    php ext_demo.php

出现以下结果，代表扩展是正确的

    Functions available in the test extension:
    ext_demo_test1
    ext_demo_test2
    confirm_ext_demo_compiled

    hello world!


