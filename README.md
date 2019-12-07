# php-ext-demo

从 [PHP扩展开发笔记](https://github.com/php-extension-research/php-ext) 和 [手把手教你写PHP协程扩展 ](https://github.com/php-extension-research/study) 文档中学习PHP扩展的开发

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

在ext_demo.c末尾加上方法：

    PHP_FUNCTION(confirm_ext_demo_compiled)
    {
        php_printf("hello world!\n");
        return;
    }
    

##### 编译扩展

在扩展目录中运行

    phpize
    ./configure --with-php-config=/usr/local/bin/php-config
    make
    sudo make install

##### 运行测试文件

    