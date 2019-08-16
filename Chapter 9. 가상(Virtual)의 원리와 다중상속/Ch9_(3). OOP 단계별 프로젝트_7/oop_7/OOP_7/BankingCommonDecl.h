#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN 20

// 프로그램 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
// 신용등급(등급, 이자율)
enum { A = 7, B = 4, C = 2 };

#endif;