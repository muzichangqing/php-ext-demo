### 传递参数

在[创建函数](create-func.md)中，创建了函数 int ed_strlen(); 函数，现在的目标是为该函数添加一个字符串参数，并实现获取字符串长度的逻辑

    int ed_strlen(string str);

#### 添加参数声明

原来的参数声明是空的

    ZEND_BEGIN_ARG_INFO(arginfo_ed_strlen, 0)
    ZEND_END_ARG_INFO()

现在我们需要添加一个参数，需要改为：
    
    ZEND_BEGIN_ARG_INFO(arginfo_ed_strlen, 0)
	    ZEND_ARG_INFO(0, str)
    ZEND_END_ARG_INFO()

简单的解释一下，ZEND_BEGIN_ARG_INFO和ZEND_END_ARG_INFO是一对声明参数的宏，arginfo_ed_strlen是我们声明arginfo的名称，可以用来和函数ed_strlen匹配（是后面显示匹配的），arginfo_ed_strlen 这种写法只是为了可读性好，并不是非要这样写，ZEND_BEGIN_ARG_INFO的第二个参数 0 代表所有的参数是否需要传递引用，1为强制传递引用参数

ZEND_ARG_INFO 用来声明普通的参数，以用来表示PHP中的int, float, double, string等基本数据类型，第一个参数代表是否传递引用，第二个参数代表参数的名称

#### 函数内参数的获取

函数原来的实现是简单的返回了0

```c
PHP_FUNCTION(ed_strlen)
{
	RETURN_LONG(0)
}
```

现在添加获取参数和计算长度的逻辑

```c
/* {{{ int ed_strlen(string $str) */
PHP_FUNCTION(ed_strlen)
{
    char *str;
    size_t str_len;
    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
        Z_PARAM_STRING(str, str_len)
    ZEND_PARSE_PARAMETERS_END();
    RETURN_LONG(str_len)
}
/* }}} */
```

1. ZEND_PARSE_PARAMETERS_START_EX 为获取参数的宏，第一个参数代表着当参数数量错误时的处理行为。ZEND_PARSE_PARAMS_QUIET：不会报错，但是会产生一个Warning， ZEND_PARSE_PARAMS_THROW代表会产生一个Exception。后面两个参数代表当前函数可以接受的参数数量最小值和数量最大值。

2. ZEND_PARSE_PARAMETERS_START 是 ZEND_PARSE_PARAMETERS_START_EX的特殊用法，即默认flag为ZEND_PARSE_PARAMS_QUIET

3. Z_PARAM_STRING 解析参数：

    #define Z_PARAM_STRING(dest, dest_len) \
	Z_PARAM_STRING_EX(dest, dest_len, 0, 0)

第一个参数为指针，第二个为长度

4. ZEND_PARSE_PARAMETERS_END 是解析参数宏的闭合宏


#### 运行

编译安装后运行

    php -r "echo ed_strlen('hello');"

可以检查结果正不正确