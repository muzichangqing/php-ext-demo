# php-ext-demo

从 [PHP扩展开发笔记](https://github.com/php-extension-research/php-ext) 和 [手把手教你写PHP协程扩展 ](https://github.com/php-extension-research/study) 文档中学习PHP扩展的开发

### 创建PHP扩展

##### 下载PHP源码

    wget https://www.php.net/distributions/php-7.3.12.tar.gz
    tar -zxvf php-7.3.12.tar.gz

##### 编译PHP

    sudo apt install libxml2 libxml-dev
    cd php-7.3.12
    ./configure
    sudo make & make install
    sudo ln -s /usr/local/bin/php /usr/bin/php7.3

##### 创建扩展

在php 7.3.0之后，创建方法由运行ext/ext_skel命令，改为运行 php ext/ext_skel.php --ext <name> 命令

    php7.3 ext/ext_skel.php --ext php-ext-demo

命令执行成功后，生成的项目文件被放在了 ext/php-ext-demo 中

##### 修改config.m4
