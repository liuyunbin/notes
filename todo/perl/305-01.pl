#!/usr/bin/perl

#use strict;
#use warnings;

=pod 基本说明
* 执行命令: perl -e 'print "Hello World\n"'
* 变量不需要申明和定义, 可以直接使用, 但建议, 变量使用 my 声明, 再使用
* 每条语句都以分号结尾
=cut

## 注释
# 单行注释
# 多行注释
=pod 多行注释
这是一个多行注释
这是一个多行注释
=cut

## 标量
# 整数将当作浮点数处理 -- + 数字相加, 包括数字字符串
$v1 = 3.1415;
$v2 = 3.1415 * 2;
$v3 = 3.1415 ** 2;
$v4 = "111" + "111";
print("测试数字\n");
print("测试数字输出: $v1\n");
print("测试数字乘法: $v2\n");
print("测试数字幂次: $v3\n");
print("测试数字字符串相加: $v4\n");

# 字符串
$v1 = "123\t123";
$v2 = '123\t123';
$v3 = "123
    123\t123";
$v4 = '123
    123\t123';
$v5 = <<"EOF";
    123\t123
    123
EOF
$v6 = <<'EOF';
    123\t123
    123
EOF
$v7 = "123" . "456";
$v8 = "123" .  456;
$v9 = "123" x 3;
$v10 = "abc";
$v11 = "ABC";
$v12 = "abc\tABC";
$v13 = q($v12);    # 相当于 '$v12'
$v14 = qq($v12);   # 相当于 "$v12"
$v15 = qx("date"); # 相当于 bash 的 $("date") -- 可用于执行命令

print("\n");
print("测试字符串\n");
print("测试字符串(双引号): $v1\n");
print("测试字符串(单引号): $v2\n");
print("测试字符串跨行(双引号): $v3\n");
print("测试字符串跨行(单引号): $v4\n");
print("测试字符串跨行(here 文档 双引号): $v5");
print("测试字符串跨行(here 文档 单引号): $v6");
print("测试字符串和字符串连接: $v7\n");
print("测试字符串和数字  连接: $v8\n");
print("测试字符串重复:         $v9\n");
print("测试      的字符串: $v10$v10\n");
print("测试大写(下一字符): \u$v10$v10\n");
print("测试大写(所有字符): \U$v10$v10\n");
print("测试大写(直到   E): \U$v10\E$v10\n");
print("测试      的字符串: $v11$v11\n");
print("测试小写(下一字符): \l$v11$v11\n");
print("测试小写(所有字符): \L$v11$v11\n");
print("测试小写(直到   E): \L$v11\E$v11\n");
print("测试                 的字符串: $v11  $v11\n");
print("测试非单词字符加反斜杠(所有 ): \Q$v11  $v11\n");
print("测试非单词字符加反斜杠(直到E): \Q$v11 \E $v11\n");
print("测试的    字符串: $v12\n");
print("字符串添加单引号: $v13\n");
print("字符串添加双引号: $v14\n");
print("字符串添加反引号: $v15\n");

## 数组 -- 元素只能是标量
print "\n测试数组\n";
@v1 = (1, 2, 3, 4, 5);
@v2 = (1..5);
@v3 = qw/1 2 3 4 5/;
@v4 = qw(1 2 3 4 5);
@v5 = @v4;
@v6 = (1, 9, 8, 7, 5);
@v7 = @v4;
@v8 = @v4;
@v9 = @v4;
@v10 = @v4;
@v11 = (@v1, @v2);              # 数组合并, 返回新数组, 不影响原数组
@v12 = @v1[2, 4];               # 数组切割, 返回新数组, 不影响原素组
@v13 = @v1[2..4];               # 数组切割, 返回新数组, 不影响原数组
@v14 = splice(@v5, 2, 5, 123);  # 数组替换, 返回被替换的元素, 影响原素组
@v15 = sort(@v6);               # 数组排序 返回新数组, 不影响原数组
$v15[10] = 100;                 # 数组赋值
$len1 = @v15;                   # 数组物理长度, 不一定是数组大小
$len2 = scalar(@v15);           # 数组物理长度, 不一定是数组大小
$v16 =    push(@v7,  111, 456); # 数组末尾添加元素, 返回元素个数, 影响原数组
$v17 = unshift(@v8,  111, 456); # 数组开头添加元素, 返回元素个数, 影响原数组
$v18 =     pop(@v9);            # 数组末尾删除元素, 返回删除的元素, 影响原数组
$v19 =   shift(@v10);           # 数组开头删除元素, 返回删除的元素, 影响原数组

print("测试数组赋值和初始化: @v1\n");
print("测试数组赋值和初始化: @v2\n");
print("测试数组赋值和初始化: @v3\n");
print("测试数组赋值和初始化: @v4\n");
print("测试数组合并, 原数组: @v1, 原数组: @v2, 新数组: @v11\n");
print("测试数组切割, 原数组: @v1, 新数组: @v12\n");
print("测试数组切割, 原数组: @v1, 新数组: @v13\n");
print("测试数组替换, 替换前的原数组: @v4, 替换后的原数组: @v5, 被替换的元素: @v14\n");
print("测试数组排序, 原数组: @v6, 新数组: @v15\n");
print("测试数组的物理大小, 不一定等于元素个数: $len1\n");
print("测试数组的物理大小, 不一定等于元素个数: $len2\n");
print("测试末尾添加元素, 添加前: @v4, 添加后: @v7, 元素的个数: $v16\n");
print("测试开头添加元素, 添加前: @v4, 添加后: @v8, 元素的个数: $v17\n");
print("测试末尾删除元素, 删除前: @v4, 删除后: @v9, 删除的元素: $v18\n");
print("测试开头删除元素, 删除前: @v4, 删除后: @v10, 删除的元素: $v19\n");

$v1 = "1, 2, 3";
@v2 = split(',', $v1);
$len = @v2;
print("测试 字符串 => 数组, 字符串: $v1, 数组: @v2, 数组个数: $len\n");

@v1 = (1..10);
$v2 = join('-', @v1);
print("测试 数组 => 字符串, 字符串: $v2, 数组: @v1\n");

%v1 = ('a', 1,'b', 2, 'c', 3, 'd', 4, 'e', 5);
@v2 = @v1{'a', 'b'};
@v3 = keys(%v1);
@v4 = values(%v1);
@v5 = %v1;
print("测试 字典 => 数组, 某几项的值, 数组: @v2\n");
print("测试 字典 => 数组, 所有的 key, 数组: @v3\n");
print("测试 字典 => 数组, 所有的  值, 数组: @v4\n");
print("测试 字典 => 数组, key   和值, 数组: @v5\n");

$v1 = (1..10);
%v2 = @v1;
$len = %v2;
print("测试 数组 => 字典: $v2{1}, 长度: $len\n");

## 字典 -- key 和 value 只能是标量
print("\n测试字典\n");
%v1  = ('a', 123, 'b', 456);
%v2  = ('a'=>123, 'b'=>456);
$v3 = $v1{'a'};
$v4 = $v2{'a'};
%v5  = %v1;
$v5{"1"} =  123;
$v5{"2"} = "123";
$v6 = $v5{"1"};
$v7 = $v5{"2"};
%v8  = %v1;
delete($v8{"a"});
$v9 = $v8{"a"};
$len = %v1;

print("测试字典元素: $v3\n");
print("测试字典元素: $v4\n");
print("测试字典元素值为数字: $v6\n");
print("测试字典元素值为字符串: $v7\n");
print("测试字典添加元素: $v7\n");
print("测试字典删除元素: $v9\n");
print("测试字典元素个数: $len\n");

# 测试字典 => 数组 见数组部分
if (exists($v1{'a'})) {
    print("元素存在\n");
} else {
    print("元素不存在\n");
}

if (exists($v1{'cc'})) {
    print("元素存在\n");
} else {
    print("元素不存在\n");
}

## 条件和循环
print("\n测试条件和循环\n");
=pod 条件判断
* if, else, elseif
* unless(和 if 相反) -- 一般不用
* switch
* ?:
* 语句块必须包含大括号, 其他和 C 语言类似
=cut

=pod 循环
* while
* do ... while -- 不常用
* until(和 while 相反) -- 一般不用
* for
* foreach $v (@v1)
* next     -- 执行 continue 块, 然后进入下一循环
* last     -- 退出循环
* continue -- 可用于新增变量的值, 一般不用
* redo     -- 重新开始本轮循环, 一般不用
* goto     -- 一般不用
* 语句块必须包含大括号
=cut

$i = 0;
while ($i < 5) {
    if ($i == 3) {
        next;
    }
    print("循环体内的 i = $i\n");
} continue {
    ++$i;
}

print("测试 foreach: ");
@v1 = (1..5);
foreach (@v1) {
    print;
    print($_);
}
print("\n");

## 时间处理
print("\n时间处理: \n");
$v1 = time();      # 时间戳
$v2 = localtime(); # 获取本地时区时间, 赋值给变量 -- 这个有点儿吊, 赋值不同, 返回结果不同
@v2 = localtime(); # 获取本地时区时间, 赋值给数组
$v3 =  gmtime();   # 获取格林威治时间, 赋值给变量
@v3 =  gmtime();   # 获取格林威治时间, 赋值给数组
use POSIX;
#use POSIX qw(strftime);
$v4 = strftime("%Y-%m-%d %H:%M:%S %z", localtime());
$v5 = strftime("%Y-%m-%d %H:%M:%S %z", gmtime());
print("测试      时间戳: $v1\n");
print("测试本地时区时间: $v2\n");
print("测试本地时区时间: @v2\n");
print("测试格林威治时间: $v3\n");
print("测试格林威治时间: @v3\n");
print("测试 strftime(本地时间): $v4\n");
print("测试 strftime(GMT 时间): $v5\n");

## 子函数
# my    ...; -- 声明局部变量, 在子程序中不存在
# local ...; -- 声明局部变量, 在子程序中依然存在 -- 一般不用
# state ...; -- 静态变量, -- 一般不用
# 引用 -- 一般不用, 在 perl 太复杂了
# 使用数组 @_ 传递参数
# 实参为标量时, 引用传递
# 实参为数组时, 引用传递, 当作值传递吧, 引用太复杂了
# 实参为字典时, 值传递
# 函数调用时, 可以不加括号(已声明, 在后面定义 或 已定义), 建议加上括号, 方便和其他语言统一
print("\n测试子函数: \n");

sub test {
    print("测试函数内修改前的值: $_[0]\n");
    $_[0] = 10;
    print("测试函数内修改后的值: $_[0]\n");
}

$v1 = 111;
print("测试调用前的标量的值: $v1\n");
test($v1);
print("测试调用后的标量的值: $v1\n");

@v1 = (111, 222, 333);
print("测试调用前的数组的值: $v1[0]\n");
test(@v1);
print("测试调用后的数组的值: $v1[0]\n");

%v1 = (111, 222, 333, 444);
print("测试调用前的字典的值: $v1{10}\n");
test(%v1);
print("测试调用后的字典的值: $v1{10}\n");

## 子模块
=pod 子模块
package ...; -- 定义子模块
require ...; -- 引用子模块, 运行时, 不包括子模块的子模块
use     ...; -- 引用子模块, 编译时,   包括子模块的子模块
=cut

## 正则表达式
# 查找: /.../ 或 m/.../ 或 m(...) 或 其他分隔符
# s/.../.../
# t/.../.../ d(删除) s(去重)
# $`: 匹配部分的前一部分字符串
# $&: 匹配的字符串
# $': 还没有匹配的剩余字符串
# i -- 忽略大小写
# g -- 全局匹配
# m -- 多行模式         -- 一般不用
# s -- 点可以匹配换行符 -- 一般不用
# x -- 将忽略空白字符   -- 一般不用
# n -- 非捕获模式       -- 一般不用
# p -- 输出结果到变量   -- 一般不用
# (...)     --   捕获的子表达式
# (?...)    -- 不捕获的子表达式
# (?=...)   --   向前探测
# (?!...)   --   向前探测, 非
# (?<=...)  --   向后探测
# (?<!...)  --   向后探测, 非
# (?(1)...) -- 条件表达式

print("\n测试正则表达式\n");

$v1 = "abc abc ABC";

print("测试单个匹配, ");
if ($v1 =~ m/abc/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

print("测试多个匹配, 忽略大小写, 已匹配: ");
while ($v1 =~ m/abc/gi) {
    print("$& ");
}
print("\n");

$v2 = "123\n456";
print("测试跨行匹配, ");
if ($v2 =~ m/.*/ms) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v2 = "123 456";
print("测试忽略正则表达式的空格, 匹配, ");
if ($v2 =~ m/1 2 3/x) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v3 = "abc abc";
$v4 = "abc ABC";
print("测试小范围内忽略大小写, 匹配, ");
if ($v3 =~ m/(?i:ABC) ABC/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

print("测试小范围内忽略大小写, 匹配, ");
if ($v4 =~ m/(?i:ABC) ABC/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "123456";
print("测试贪心匹配, ");
if ($v1 =~ m/\d+/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

print("测试懒惰匹配, ");
if ($v1 =~ m/\d+?/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "123 123 456";
$v2 = "123 456 456";
print("测试分组匹配, ");
if ($v1 =~ m/(123) \1/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

print("测试分组匹配, ");
if ($v2 =~ m/(123) \1/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "123 456 456";
print("测试只分组, 不捕获, ");
if ($v1 =~ m/(?:123) (456) \1/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = '$0123-';
print("测试向前探测, ");
if ($v1 =~ m/\d+(?=-)/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

print("测试向后探测, ");
if ($v1 =~ m/(?<=\$)\d+/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "(0354)5757023";
print("测试条件表达式, ");
if ($v1 =~ m/(\()\d+(?(1)\))\d+/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "abc ABC";
print("测试查找中的 U, ");
if ($v1 =~ m/(abc) \U\1/) {
    print("已匹配: $&\n");
} else {
    print("未匹配\n");
}

$v1 = "Abc abc ABC";
$v2 = $v1;
$v2 =~ s/(.*)/\U\1/;
$v3 = $v1;
$v3 =~ s/abc/ABC/;
$v4 = $v1;
$v4 =~ s/abc/ABC/g;
$v5 = $v1;
$v5 =~ s/abc/ABC/gi;

print("              测试字符串: $v1\n");
print("          测试替换中的 U: $v2\n");
print("            测试替换一个: $v3\n");
print("            测试替换全部: $v4\n");
print("测试替换全部, 忽略大小写: $v5\n");

$v1 = "aaa bbb ccc";
$v2 = $v1;
$v2 =~ tr/abc/ABC/;
$v3 = $v1;
$v3 =~ tr/ab//d;
$v4 = $v1;
$v4 =~ tr/ab//s;
$v5 = $v1;
$v5 =~ tr/ab/1/c;
print("              测试字符串: $v1\n");
print("            测试字符转换: $v2\n");
print("            测试字符删除: $v3\n");
print("            测试字符合并: $v4\n");
print("    测试转换未匹配的字符: $v5\n");

