### 创建函数

#### 添加函数 ed_strlen

1. 编辑ext_demo.c, 添加函数ed_strlen

```c
/* {{{ int ed_strlen() */
PHP_FUNCTION(ed_strlen)
{
	RETURN_LONG(0)
}
/* }}} */
```

- PHP_FUNCTION 是定义函数的宏，定义在 php.h 中，使用的是ZEND_FUNCTION宏定义
- ed_strlen 是声明的函数名
- RETURN_LONG 是声明返回值的宏，定义在 Zend/zend_API.h 中

2. 添加参数声明

暂时不需要参数

```c
/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_ext_demo_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_ext_demo_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_confirm_ext_demo_compiled, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_ed_strlen, 0)
ZEND_END_ARG_INFO()
/* }}} */
```

3. 添加函数到ext_demo_functions中

```c
/* {{{ ext_demo_functions[]
 */
static const zend_function_entry ext_demo_functions[] = {
	PHP_FE(ext_demo_test1,		arginfo_ext_demo_test1)
	PHP_FE(ext_demo_test2,		arginfo_ext_demo_test2)
	PHP_FE(confirm_ext_demo_compiled, arginfo_confirm_ext_demo_compiled)
	PHP_FE(ed_strlen, arginfo_ed_strlen)
	PHP_FE_END
};
/* }}} */
```

4. 编译安装

```shell
phpize
./configure
make
make install
```

在php.ini中启用扩展

```
extension=ext_demo.so
```

5. 运行函数

```
php -r "echo ed_strlen();"
```

出现结果0，则代表没有问题