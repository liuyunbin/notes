#ifndef CPP_STANDARD_LIBRARY_CCTYPE_TOUPPER_H_
#define CPP_STANDARD_LIBRARY_CCTYPE_TOUPPER_H_

#include <stdio.h> // EOF

namespace liuyunbin {

/*
 * 函数原型：
 *   int toupper(int ch);
 *
 * 函数说明：
 *   * 将小写字母转换为对应的大写字母
 *
 * 参数说明：
 *   * 参数 ch 必须是 EOF 或 可以用 unsigned char 表示，否则，是未定义的行为
 *
 * 返回说明：
 *   * 如果 ch 是小写字母，返回其对应的大写字母
 *   * 否则，返回原值
 */

int toupper(int ch) {
  if (ch == EOF)
    return ch;

  const char *p_lower = "abcdefghijklmnopqrstuvwxyz";
  const char *p_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; p_lower[i] != '\0'; ++i)
    if (p_lower[i] == ch)
      return p_upper[i];
  return ch;
}

} // namespace liuyunbin

#endif
