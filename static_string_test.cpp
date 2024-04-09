#include <iostream>
#include <limits>
#include <algorithm>
#include "static_string.h"
#include <cassert>

using namespace snw1;

int main() {
  { // make() simple tests
    constexpr char str1[] = "abc";
    constexpr auto bss1 = STOSS(str1);
    static_assert(bss1 == "abc", "");
    
    constexpr const char* str2 = "abc"; // constexpr auto str2 = "abc";
    constexpr auto bss2 = STOSS(str2);
    static_assert(bss2 == "abc", "");

    constexpr auto bss3 = STOSS("abc");
    static_assert(bss3 == "abc", "");

    constexpr auto len_str1 = c_strlen(str1);
    static_assert(len_str1 == 3, "");

    constexpr auto len_str2 = c_strlen(str2);
    static_assert(len_str2 == 3, "");

    constexpr auto len_str3 = c_strlen("abc");
    static_assert(len_str3 == 3, "");


    const auto cstr = bss1.c_str();
    assert(std::strcmp(str1, cstr) == 0, "");
  }

#if USE_USER_LITERALS
    // operator )() tests
    static_assert(STOSS("") == "", "");
    static_assert(STOSS("H") == "H", "");
    static_assert(STOSS("Hello") == "Hello", "");
    static_assert(STOSS("Hello world") == "Hello world", "");
#else
    // string_to_static_string tests
    static_assert(STOSS("") == "", "");
    static_assert(STOSS("H") == "H", "");
    static_assert(STOSS("Hello") == "Hello", "");
    static_assert(STOSS("Hello world") == "Hello world", "");
#endif

    // sizeof() tests
    static_assert(sizeof(STOSS("")) == 1 * sizeof(char), "");
    static_assert(sizeof(STOSS("H")) == 2 * sizeof(char), "");
    static_assert(sizeof(STOSS("Hello")) == 6 * sizeof(char), "");
    static_assert(sizeof(STOSS("Hello world")) == 12 * sizeof(char), "");
    static_assert(sizeof(STOSS("Hello") + " world") == 12 * sizeof(char), "");
    static_assert(sizeof(STOSW(L"")) == 1 * sizeof(wchar_t), "");
    static_assert(sizeof(STOSW(L"H")) == 2 * sizeof(wchar_t), "");
    static_assert(sizeof(STOSW(L"Hello")) == 6 * sizeof(wchar_t), "");
    static_assert(sizeof(STOSW(L"Hello world")) == 12 * sizeof(wchar_t), "");
    static_assert(sizeof(STOSW(L"Hello") + L" world") == 12 * sizeof(wchar_t), "");

    // c_strlen() tests
    static_assert(c_strlen("") == 0, "");
    static_assert(c_strlen("H") == 1, "");
    static_assert(c_strlen("Hello") == 5, "");
    static_assert(c_strlen("Hello world") == 11, "");
    static_assert(c_strlen(L"") == 0, "");
    static_assert(c_strlen(L"H") == 1, "");
    static_assert(c_strlen(L"Hello") == 5, "");
    static_assert(c_strlen(L"Hello world") == 11, "");

    // size(), length() tests
    static_assert(STOSS("").size() == 0, "");
    static_assert(STOSS("H").size() == 1, "");
    static_assert(STOSS("Hello").size() == 5, "");
    static_assert(STOSS("Hello world").size() == 11, "");
    static_assert((STOSS("Hello") + " world").size() == 11, "");
    static_assert(STOSS("").length() == 0, "");
    static_assert(STOSS("H").length() == 1, "");
    static_assert(STOSS("Hello").length() == 5, "");
    static_assert(STOSS("Hello world").length() == 11, "");
    static_assert((STOSS("Hello") + " world").length() == 11, "");

    static_assert(STOSW(L"").size() == 0, "");
    static_assert(STOSW(L"H").size() == 1, "");
    static_assert(STOSW(L"Hello").size() == 5, "");  
    static_assert(STOSW(L"Hello world").size() == 11, "");
    static_assert((STOSW(L"Hello") + L" world").size() == 11, "");
    static_assert(STOSW(L"").length() == 0, "");
    static_assert(STOSW(L"H").length() == 1, "");
    static_assert(STOSW(L"Hello").length() == 5, "");
    static_assert(STOSW(L"Hello world").length() == 11, "");
    static_assert((STOSW(L"Hello") + L" world").length() == 11, "");

    // comparison operators tests
    static_assert(STOSS("") == "", "");
    static_assert("" == STOSS(""), "");
    static_assert(STOSS("") == STOSS(""), "");
    static_assert(STOSS("") < "Hello", "");
    static_assert("" < STOSS("Hello"), "");
    static_assert(STOSS("") < STOSS("Hello"), "");
    static_assert(STOSS("Hello") > "", "");
    static_assert("Hello" > STOSS(""), "");
    static_assert(STOSS("Hello") > STOSS(""), "");
    static_assert(STOSS("Hello") == "Hello", "");
    static_assert("Hello" == STOSS("Hello"), "");
    static_assert(STOSS("Hello") == STOSS("Hello"), "");
    static_assert(STOSS("Hell") < "Hello", "");
    static_assert("Hell" < STOSS("Hello"), "");
    static_assert(STOSS("Hell") < STOSS("Hello"), "");
    static_assert(STOSS("Hello") > "Hell", "");
    static_assert("Hello" > STOSS("Hell"), "");
    static_assert(STOSS("Hello") > STOSS("Hell"), "");
    static_assert(STOSS("Hella") < "Hello", "");
    static_assert("Hella" < STOSS("Hello"), "");
    static_assert(STOSS("Hella") < STOSS("Hello"), "");
    static_assert(STOSS("Hello") > "Hella", "");
    static_assert("Hello" > STOSS("Hella"), "");
    static_assert(STOSS("Hello") > STOSS("Hella"), "");
    static_assert(STOSS("") != "Hello", "");
    static_assert("" != STOSS("Hello"), "");
    static_assert(STOSS("") != STOSS("Hello"), "");
    static_assert(STOSS("Hello") != "", "");
    static_assert("Hello" != STOSS(""), "");
    static_assert(STOSS("Hello") != STOSS(""), "");
    static_assert(STOSS("Hell") != "Hello", "");
    static_assert("Hell" != STOSS("Hello"), "");
    static_assert(STOSS("Hell") != STOSS("Hello"), "");
    static_assert(STOSS("Hello") != "Hell", "");
    static_assert("Hello" != STOSS("Hell"), "");
    static_assert(STOSS("Hello") != STOSS("Hell"), "");
    static_assert(STOSS("Hella") != "Hello", "");
    static_assert("Hella" != STOSS("Hello"), "");
    static_assert(STOSS("Hella") != STOSS("Hello"), "");
    static_assert(STOSS("Hello") != "Hella", "");
    static_assert("Hello" != STOSS("Hella"), "");
    static_assert(STOSS("Hello") != STOSS("Hella"), "");
    static_assert(STOSS("") <= "", "");
    static_assert("" >= STOSS(""), "");
    static_assert(STOSS("") <= STOSS(""), "");
    static_assert(STOSS("") <= "Hello", "");
    static_assert("" <= STOSS("Hello"), "");
    static_assert(STOSS("") <= STOSS("Hello"), "");
    static_assert(STOSS("Hello") >= "", "");
    static_assert("Hello" >= STOSS(""), "");
    static_assert(STOSS("Hello") >= STOSS(""), "");
    static_assert(STOSS("Hello") <= "Hello", "");
    static_assert("Hello" >= STOSS("Hello"), "");
    static_assert(STOSS("Hello") <= STOSS("Hello"), "");
    static_assert(STOSS("Hell") <= "Hello", "");
    static_assert("Hell" <= STOSS("Hello"), "");
    static_assert(STOSS("Hell") <= STOSS("Hello"), "");
    static_assert(STOSS("Hello") >= "Hell", "");
    static_assert("Hello" >= STOSS("Hell"), "");
    static_assert(STOSS("Hello") >= STOSS("Hell"), "");
    static_assert(STOSS("Hella") <= "Hello", "");
    static_assert("Hella" <= STOSS("Hello"), "");
    static_assert(STOSS("Hella") <= STOSS("Hello"), "");
    static_assert(STOSS("Hello") >= "Hella", "");
    static_assert("Hello" >= STOSS("Hella"), "");
    static_assert(STOSS("Hello") >= STOSS("Hella"), "");

    // make() concat tests
    static_assert(static_string::make() == "", "");
    static_assert(static_string::make("") == "", "");
    static_assert(static_string::make("", "") == "", "");
    static_assert(static_string::make("", "", "") == "", "");
    static_assert(static_string::make("", STOSS(""), "") == "", "");
    static_assert(static_string::make(STOSS(""), "", STOSS("")) == "", "");
    static_assert(static_string::make(STOSS(""), STOSS(""), STOSS("")) == "", "");
    static_assert(static_string::make("Hello") == "Hello", "");
    static_assert(static_string::make("", "Hello") == "Hello", "");
    static_assert(static_string::make("", "Hello", "") == "Hello", "");
    static_assert(static_string::make("", STOSS("Hello"), "") == "Hello", "");
    static_assert(static_string::make(STOSS(""), "", STOSS("Hello")) == "Hello", "");
    static_assert(static_string::make(STOSS("Hello"), STOSS(""), STOSS("")) == "Hello", "");
    static_assert(static_string::make("Hello", "World") == "HelloWorld", "");
    static_assert(static_string::make(STOSS("Hello"), "World") == "HelloWorld", "");
    static_assert(static_string::make("Hello", STOSS("World")) == "HelloWorld", "");
    static_assert(static_string::make(STOSS("Hello"), STOSS("World")) == "HelloWorld", "");
    static_assert(static_string::make("Hello", ", ", "World", "!") == "Hello, World!", "");
    static_assert(static_string::make(STOSS("Hello"), ", ", STOSS("World"), "!") == "Hello, World!", "");
    static_assert(static_string::make(STOSS("Hello"), STOSS(", "), STOSS("World"), STOSS("!")) == "Hello, World!", "");

    // operator+() tests
    static_assert(STOSS("Hello") + "World" == "HelloWorld", "");
    static_assert("Hello" + STOSS("World") == "HelloWorld", "");
    static_assert(STOSS("Hello") + STOSS("World") == "HelloWorld", "");
    static_assert(STOSS("Hello") + ", " + STOSS("World") + "!" == "Hello, World!", "");

    // reverse() tests
    static_assert(STOSS("").reverse() == "", "");
    static_assert(STOSS("H").reverse() == "H", "");
    static_assert(STOSS("Hello").reverse() == "olleH", "");
    static_assert(STOSS("Hello world").reverse() == "dlrow olleH", "");

    // substring() tests
    static_assert(STOSS("").substring<0, 0>() == "", "");
    static_assert(STOSS("H").substring<0, 0>() == "", "");
    static_assert(STOSS("H").substring<1, 1>() == "", "");
    static_assert(STOSS("H").substring<0, 1>() == "H", "");
    static_assert(STOSS("Hello").substring<0, 5>() == "Hello", "");
    static_assert(STOSS("Hello").substring<3, 3>() == "", "");
    static_assert(STOSS("Hello").substring<1, 5>() == "ello", "");
    static_assert(STOSS("Hello").substring<0, 4>() == "Hell", "");
    static_assert(STOSS("Hello").substring<2, 5>() == "llo", "");
    static_assert(STOSS("Hello").substring<3, 4>() == "l", "");
    static_assert(STOSS("Hello").substring<2, 4>() == "ll", "");
    static_assert(STOSS("Hello").substring<1, 4>() == "ell", "");

    // prefix() tests
    static_assert(STOSS("").prefix<0>() == "", "");
    static_assert(STOSS("Hello").prefix<0>() == "", "");
    static_assert(STOSS("Hello").prefix<1>() == "H", "");
    static_assert(STOSS("Hello").prefix<2>() == "He", "");
    static_assert(STOSS("Hello").prefix<3>() == "Hel", "");
    static_assert(STOSS("Hello").prefix<4>() == "Hell", "");
    static_assert(STOSS("Hello").prefix<5>() == "Hello", "");

    // suffix() tests
    static_assert(STOSS("").suffix<0>() == "", "");
    static_assert(STOSS("Hello").suffix<0>() == "Hello", "");
    static_assert(STOSS("Hello").suffix<1>() == "ello", "");
    static_assert(STOSS("Hello").suffix<2>() == "llo", "");
    static_assert(STOSS("Hello").suffix<3>() == "lo", "");
    static_assert(STOSS("Hello").suffix<4>() == "o", "");
    static_assert(STOSS("Hello").suffix<5>() == "", "");

    // find(ch) tests
    static_assert(STOSS("").find('a') == static_string::npos, "");
    static_assert(STOSS("a").find('a') == 0, "");
    static_assert(STOSS("b").find('a') == static_string::npos, "");
    static_assert(STOSS("abcabca").find('a') == 0, "");
    static_assert(STOSS("abcabca").find('a', 1) == 3, "");
    static_assert(STOSS("abcabca").find('a', 4) == 6, "");
    static_assert(STOSS("abcabca").find('a', 7) == static_string::npos, "");
    static_assert(STOSS("abcabca").find('a', 1'000'000) == static_string::npos, "");
    static_assert(STOSS("abcabca").find('a', 0, 0) == 0, "");
    static_assert(STOSS("abcabca").find('a', 0, 1) == 3, "");
    static_assert(STOSS("abcabca").find('a', 0, 2) == 6, "");
    static_assert(STOSS("abcabca").find('a', 0, 3) == static_string::npos, "");
    static_assert(STOSS("abcabca").find('a', 0, 1'000'000) == static_string::npos, "");

    // rfind(ch) tests
    static_assert(STOSS("").rfind('c') == static_string::npos, "");
    static_assert(STOSS("c").rfind('c') == 0, "");
    static_assert(STOSS("b").rfind('c') == static_string::npos, "");
    static_assert(STOSS("cabcabc").rfind('c') == 6, "");
    static_assert(STOSS("cabcabc").rfind('c', 5) == 3, "");
    static_assert(STOSS("cabcabc").rfind('c', 2) == 0, "");
    static_assert(STOSS("cabcabc").rfind('c', -1) == static_string::npos, "");
    static_assert(STOSS("cabcabc").rfind('c', 1'000'000) == static_string::npos, "");
    static_assert(STOSS("cabcabc").rfind('c', 6, 0) == 6, "");
    static_assert(STOSS("cabcabc").rfind('c', 6, 1) == 3, "");
    static_assert(STOSS("cabcabc").rfind('c', 6, 2) == 0, "");
    static_assert(STOSS("cabcabc").rfind('c', 6, 3) == static_string::npos, "");
    static_assert(STOSS("cabcabc").rfind('c', 6, 1'000'000) == static_string::npos, "");

    // find(str) tests
    static_assert(STOSS("").find("") == 0, "");
    static_assert(STOSS("").find("", 1) == static_string::npos, "");
    static_assert(STOSS("").find("", 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").find("") == 0, "");
    static_assert(STOSS("a").find("", 1) == 1, "");
    static_assert(STOSS("a").find("", 0, 1) == 1, "");
    static_assert(STOSS("").find("a") == static_string::npos, "");
    static_assert(STOSS("").find("a", 1) == static_string::npos, "");
    static_assert(STOSS("").find("a", 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").find("a") == 0, "");
    static_assert(STOSS("a").find("a", 1) == static_string::npos, "");
    static_assert(STOSS("a").find("a", 0, 1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find("aa") == 0, "");
    static_assert(STOSS("aaaaa").find("aa", 1) == 1, "");
    static_assert(STOSS("aaaaa").find("aa", 2) == 2, "");
    static_assert(STOSS("aaaaa").find("aa", 3) == 3, "");
    static_assert(STOSS("aaaaa").find("aa", 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find("aa", 0, 1) == 1, "");
    static_assert(STOSS("aaaaa").find("aa", 0, 2) == 2, "");
    static_assert(STOSS("aaaaa").find("aa", 0, 3) == 3, "");
    static_assert(STOSS("aaaaa").find("aa", 0, 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find("aaaaa") == 0, "");
    static_assert(STOSS("ababababa").find("ba") == 1, "");
    static_assert(STOSS("ababababa").find("ba", 2) == 3, "");
    static_assert(STOSS("ababababa").find("ba", 4) == 5, "");
    static_assert(STOSS("ababababa").find("ba", 6) == 7, "");
    static_assert(STOSS("ababababa").find("ba", 8) == static_string::npos, "");
    static_assert(STOSS("ababababa").find("ba", 0, 1) == 3, "");
    static_assert(STOSS("ababababa").find("ba", 0, 2) == 5, "");
    static_assert(STOSS("ababababa").find("ba", 0, 3) == 7, "");
    static_assert(STOSS("ababababa").find("ba", 0, 4) == static_string::npos, "");
    static_assert(STOSS("ababababa").find("ababababa") == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac") == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 3) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 7) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 11) == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 38) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 0, 1) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 0, 2) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 0, 3) == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bac", 0, 4) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("ccb") == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("ccb", 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("ccb", 0, 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bdc") == 58, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bdc", 59) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find("bdc", 0, 1) == static_string::npos, "");
    static_assert(STOSS("").find(STOSS("")) == 0, "");
    static_assert(STOSS("").find(STOSS(""), 1) == static_string::npos, "");
    static_assert(STOSS("").find(STOSS(""), 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").find(STOSS("")) == 0, "");
    static_assert(STOSS("a").find(STOSS(""), 1) == 1, "");
    static_assert(STOSS("a").find(STOSS(""), 0, 1) == 1, "");
    static_assert(STOSS("").find(STOSS("a")) == static_string::npos, "");
    static_assert(STOSS("").find(STOSS("a"), 1) == static_string::npos, "");
    static_assert(STOSS("").find(STOSS("a"), 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").find(STOSS("a")) == 0, "");
    static_assert(STOSS("a").find(STOSS("a"), 1) == static_string::npos, "");
    static_assert(STOSS("a").find(STOSS("a"), 0, 1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa")) == 0, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 1) == 1, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 2) == 2, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 3) == 3, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 0, 1) == 1, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 0, 2) == 2, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 0, 3) == 3, "");
    static_assert(STOSS("aaaaa").find(STOSS("aa"), 0, 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").find(STOSS("aaaaa")) == 0, "");
    static_assert(STOSS("ababababa").find(STOSS("ba")) == 1, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 2) == 3, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 4) == 5, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 6) == 7, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 8) == static_string::npos, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 0, 1) == 3, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 0, 2) == 5, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 0, 3) == 7, "");
    static_assert(STOSS("ababababa").find(STOSS("ba"), 0, 4) == static_string::npos, "");
    static_assert(STOSS("ababababa").find(STOSS("ababababa")) == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac")) == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 3) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 7) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 11) == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 38) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 0, 1) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 0, 2) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 0, 3) == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bac"), 0, 4) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("ccb")) == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("ccb"), 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("ccb"), 0, 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bdc")) == 58, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bdc"), 59) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").find(STOSS("bdc"), 0, 1) == static_string::npos, "");

    // rfind(str) tests
    static_assert(STOSS("").rfind("") == 0, "");
    static_assert(STOSS("").rfind("", 1) == static_string::npos, "");
    static_assert(STOSS("").rfind("", 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind("") == 1, "");
    static_assert(STOSS("a").rfind("", 1) == 1, "");
    static_assert(STOSS("a").rfind("", 0, 1) == static_string::npos, "");
    static_assert(STOSS("").rfind("a") == static_string::npos, "");
    static_assert(STOSS("").rfind("a", 1) == static_string::npos, "");
    static_assert(STOSS("").rfind("a", 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind("a") == 0, "");
    static_assert(STOSS("a").rfind("a", 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind("a", 0, 1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind("aa") == 3, "");
    static_assert(STOSS("aaaaa").rfind("aa", 2) == 2, "");
    static_assert(STOSS("aaaaa").rfind("aa", 1) == 1, "");
    static_assert(STOSS("aaaaa").rfind("aa", 0) == 0, "");
    static_assert(STOSS("aaaaa").rfind("aa", -1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind("aa", 3, 1) == 2, "");
    static_assert(STOSS("aaaaa").rfind("aa", 3, 2) == 1, "");
    static_assert(STOSS("aaaaa").rfind("aa", 3, 3) == 0, "");
    static_assert(STOSS("aaaaa").rfind("aa", 3, 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind("aaaaa") == 0, "");
    static_assert(STOSS("ababababa").rfind("ba") == 7, "");
    static_assert(STOSS("ababababa").rfind("ba", 6) == 5, "");
    static_assert(STOSS("ababababa").rfind("ba", 4) == 3, "");
    static_assert(STOSS("ababababa").rfind("ba", 2) == 1, "");
    static_assert(STOSS("ababababa").rfind("ba", 0) == static_string::npos, "");
    static_assert(STOSS("ababababa").rfind("ba", 7, 1) == 5, "");
    static_assert(STOSS("ababababa").rfind("ba", 7, 2) == 3, "");
    static_assert(STOSS("ababababa").rfind("ba", 7, 3) == 1, "");
    static_assert(STOSS("ababababa").rfind("ba", 7, 4) == static_string::npos, "");
    static_assert(STOSS("ababababa").rfind("ababababa") == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac") == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 36) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 9) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 5) == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 58, 1) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 58, 2) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 58, 3) == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bac", 58, 4) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("ccb") == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("ccb", -1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("ccb", 58, 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bdc") == 58, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bdc", 57) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind("bdc", 58, 1) == static_string::npos, "");
    static_assert(STOSS("").rfind(STOSS("")) == 0, "");
    static_assert(STOSS("").rfind(STOSS(""), 1) == static_string::npos, "");
    static_assert(STOSS("").rfind(STOSS(""), 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind(STOSS("")) == 1, "");
    static_assert(STOSS("a").rfind(STOSS(""), 1) == 1, "");
    static_assert(STOSS("a").rfind(STOSS(""), 0, 1) == static_string::npos, "");
    static_assert(STOSS("").rfind(STOSS("a")) == static_string::npos, "");
    static_assert(STOSS("").rfind(STOSS("a"), 1) == static_string::npos, "");
    static_assert(STOSS("").rfind(STOSS("a"), 0, 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind(STOSS("a")) == 0, "");
    static_assert(STOSS("a").rfind(STOSS("a"), 1) == static_string::npos, "");
    static_assert(STOSS("a").rfind(STOSS("a"), 0, 1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa")) == 3, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 2) == 2, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 1) == 1, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 0) == 0, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), -1) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 3, 1) == 2, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 3, 2) == 1, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 3, 3) == 0, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aa"), 3, 4) == static_string::npos, "");
    static_assert(STOSS("aaaaa").rfind(STOSS("aaaaa")) == 0, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba")) == 7, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 6) == 5, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 4) == 3, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 2) == 1, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 0) == static_string::npos, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 7, 1) == 5, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 7, 2) == 3, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 7, 3) == 1, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ba"), 7, 4) == static_string::npos, "");
    static_assert(STOSS("ababababa").rfind(STOSS("ababababa")) == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac")) == 37, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 36) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 9) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 5) == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 58, 1) == 10, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 58, 2) == 6, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 58, 3) == 2, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bac"), 58, 4) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("ccb")) == 0, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("ccb"), -1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("ccb"), 58, 1) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bdc")) == 58, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bdc"), 57) == static_string::npos, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").rfind(STOSS("bdc"), 58, 1) == static_string::npos, "");

    // contains(ch) tests
    static_assert(!STOSS("").contains('a'), "");
    static_assert(STOSS("a").contains('a'), "");
    static_assert(!STOSS("a").contains('b'), "");
    static_assert(STOSS("cabcabc").contains('a'), "");
    static_assert(STOSS("cabcabc").contains('b'), "");
    static_assert(STOSS("cabcabc").contains('c'), "");
    static_assert(!STOSS("cabcabc").contains('e'), "");
    static_assert(!STOSS("cabcabc").contains('f'), "");
    static_assert(!STOSS("cabcabc").contains('g'), "");

    // contains(str) tests
    static_assert(STOSS("").contains(""), "");
    static_assert(STOSS("a").contains(""), "");
    static_assert(!STOSS("").contains("a"), "");
    static_assert(STOSS("a").contains("a"), "");
    static_assert(!STOSS("a").contains("b"), "");
    static_assert(STOSS("cabcabc").contains("cab"), "");
    static_assert(STOSS("cabcabc").contains("bca"), "");
    static_assert(STOSS("cabcabc").contains("abc"), "");
    static_assert(!STOSS("cabcabc").contains("cba"), "");
    static_assert(!STOSS("cabcabc").contains("aca"), "");
    static_assert(!STOSS("cabcabc").contains("abb"), "");
    static_assert(STOSS("cabcabc").contains("cabcabc"), "");
    static_assert(!STOSS("cabcabc").contains("cabcabca"), "");
    static_assert(!STOSS("cabcabc").contains("acabcabc"), "");
    static_assert(STOSS("").contains(STOSS("")), "");
    static_assert(STOSS("a").contains(STOSS("")), "");
    static_assert(!STOSS("").contains(STOSS("a")), "");
    static_assert(STOSS("a").contains(STOSS("a")), "");
    static_assert(!STOSS("a").contains(STOSS("b")), "");
    static_assert(STOSS("cabcabc").contains(STOSS("cab")), "");
    static_assert(STOSS("cabcabc").contains(STOSS("bca")), "");
    static_assert(STOSS("cabcabc").contains(STOSS("abc")), "");
    static_assert(!STOSS("cabcabc").contains(STOSS("cba")), "");
    static_assert(!STOSS("cabcabc").contains(STOSS("aca")), "");
    static_assert(!STOSS("cabcabc").contains(STOSS("abb")), "");
    static_assert(STOSS("cabcabc").contains(STOSS("cabcabc")), "");
    static_assert(!STOSS("cabcabc").contains(STOSS("cabcabca")), "");
    static_assert(!STOSS("cabcabc").contains(STOSS("acabcabc")), "");

    // static_string_count() tests
    static_assert(STOSS("").count('a') == 0, "");
    static_assert(STOSS("cdbcbdcbdcb").count('a') == 0, "");
    static_assert(STOSS("a").count('a') == 1, "");
    static_assert(STOSS("aa").count('a') == 2, "");
    static_assert(STOSS("abcd").count('a') == 1, "");
    static_assert(STOSS("abcd").count('b') == 1, "");
    static_assert(STOSS("abcd").count('c') == 1, "");
    static_assert(STOSS("abcd").count('d') == 1, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").count('a') == 15, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").count('b') == 13, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").count('c') == 17, "");
    static_assert(STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc").count('d') == 16, "");

    // starts_with() tests
    static_assert(STOSS("").starts_with(""), "");
    static_assert(STOSS("a").starts_with(""), "");
    static_assert(!STOSS("").starts_with("a"), "");
    static_assert(STOSS("a").starts_with("a"), "");
    static_assert(!STOSS("a").starts_with("b"), "");
    static_assert(!STOSS("a").starts_with("ab"), "");
    static_assert(STOSS("abcabca").starts_with(""), "");
    static_assert(STOSS("abcabca").starts_with("a"), "");
    static_assert(STOSS("abcabca").starts_with("ab"), "");
    static_assert(STOSS("abcabca").starts_with("abc"), "");
    static_assert(STOSS("abcabca").starts_with("abca"), "");
    static_assert(STOSS("abcabca").starts_with("abcab"), "");
    static_assert(STOSS("abcabca").starts_with("abcabc"), "");
    static_assert(STOSS("abcabca").starts_with("abcabca"), "");
    static_assert(!STOSS("abcabca").starts_with("abcabcab"), "");
    static_assert(!STOSS("abcabca").starts_with("bcabca"), "");
    static_assert(!STOSS("abcabca").starts_with("acabca"), "");
    static_assert(!STOSS("abcabca").starts_with("abcaba"), "");
    static_assert(STOSS("").starts_with(STOSS("")), "");
    static_assert(STOSS("a").starts_with(STOSS("")), "");
    static_assert(!STOSS("").starts_with(STOSS("a")), "");
    static_assert(STOSS("a").starts_with(STOSS("a")), "");
    static_assert(!STOSS("a").starts_with(STOSS("b")), "");
    static_assert(!STOSS("a").starts_with(STOSS("ab")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("a")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("ab")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("abc")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("abca")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("abcab")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("abcabc")), "");
    static_assert(STOSS("abcabca").starts_with(STOSS("abcabca")), "");
    static_assert(!STOSS("abcabca").starts_with(STOSS("abcabcab")), "");
    static_assert(!STOSS("abcabca").starts_with(STOSS("bcabca")), "");
    static_assert(!STOSS("abcabca").starts_with(STOSS("acabca")), "");
    static_assert(!STOSS("abcabca").starts_with(STOSS("abcaba")), "");

    // ends_with() tests
    static_assert(STOSS("").ends_with(""), "");
    static_assert(STOSS("a").ends_with(""), "");
    static_assert(!STOSS("").ends_with("a"), "");
    static_assert(STOSS("a").ends_with("a"), "");
    static_assert(!STOSS("a").ends_with("b"), "");
    static_assert(!STOSS("a").ends_with("ba"), "");
    static_assert(STOSS("abcabca").ends_with(""), "");
    static_assert(STOSS("abcabca").ends_with("a"), "");
    static_assert(STOSS("abcabca").ends_with("ca"), "");
    static_assert(STOSS("abcabca").ends_with("bca"), "");
    static_assert(STOSS("abcabca").ends_with("abca"), "");
    static_assert(STOSS("abcabca").ends_with("cabca"), "");
    static_assert(STOSS("abcabca").ends_with("bcabca"), "");
    static_assert(STOSS("abcabca").ends_with("abcabca"), "");
    static_assert(!STOSS("abcabca").ends_with("babcabca"), "");
    static_assert(!STOSS("abcabca").ends_with("abcabc"), "");
    static_assert(!STOSS("abcabca").ends_with("abcaba"), "");
    static_assert(!STOSS("abcabca").ends_with("acabca"), "");
    static_assert(STOSS("").ends_with(STOSS("")), "");
    static_assert(STOSS("a").ends_with(STOSS("")), "");
    static_assert(!STOSS("").ends_with(STOSS("a")), "");
    static_assert(STOSS("a").ends_with(STOSS("a")), "");
    static_assert(!STOSS("a").ends_with(STOSS("b")), "");
    static_assert(!STOSS("a").ends_with(STOSS("ba")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("a")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("ca")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("bca")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("abca")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("cabca")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("bcabca")), "");
    static_assert(STOSS("abcabca").ends_with(STOSS("abcabca")), "");
    static_assert(!STOSS("abcabca").ends_with(STOSS("babcabca")), "");
    static_assert(!STOSS("abcabca").ends_with(STOSS("abcabc")), "");
    static_assert(!STOSS("abcabca").ends_with(STOSS("abcaba")), "");
    static_assert(!STOSS("abcabca").ends_with(STOSS("acabca")), "");

    // lower() tests
    static_assert(STOSS("").lower() == "", "");
    static_assert(STOSS("H").lower() == "h", "");
    static_assert(STOSS("He").lower() == "he", "");
    static_assert(STOSS("HeLlO").lower() == "hello", "");
    static_assert(STOSS("abcABCxyzXYZ").lower() == "abcabcxyzxyz", "");

    // upper() tests
    static_assert(STOSS("").upper() == "", "");
    static_assert(STOSS("h").upper() == "H", "");
    static_assert(STOSS("He").upper() == "HE", "");
    static_assert(STOSS("HeLlO").upper() == "HELLO", "");
    static_assert(STOSS("abcABCxyzXYZ").upper() == "ABCABCXYZXYZ", "");

    { // split() tests
        constexpr auto ss = STOSS("abracadabra");
        static_assert(ss.split<5>() == std::make_pair(STOSS("abrac"), STOSS("dabra")), "");
        static_assert(ss.split<ss.find('a')>() == std::make_pair(STOSS(""), STOSS("bracadabra")), "");
        static_assert(ss.split<ss.find('a', 0, 3)>() == std::make_pair(STOSS("abracad"), STOSS("bra")), "");
        static_assert(ss.split<ss.find('d')>() == std::make_pair(STOSS("abraca"), STOSS("abra")), "");
        static_assert(ss.split<ss.find('b')>() == std::make_pair(STOSS("a"), STOSS("racadabra")), "");
        static_assert(ss.split<ss.rfind('b')>() == std::make_pair(STOSS("abracada"), STOSS("ra")), "");
    }

    // hash() tests
    static_assert(STOSS("").hash() == 5381ULL, "");
    static_assert(STOSS("Hello").hash() == 210724412158ULL, "");
    static_assert(STOSS("HelloWorld").hash() == 8246272427518117483ULL, "");
    static_assert(STOSS("HelloWorldHelloWorld").hash() == 889607825945456465ULL, "");

    // ITOSS() tests
    static_assert(ITOSS(0) == "0", "");
    static_assert(ITOSS(1) == "1", "");
    static_assert(ITOSS(9) == "9", "");
    static_assert(ITOSS(10) == "10", "");
    static_assert(ITOSS(11) == "11", "");
    static_assert(ITOSS(14) == "14", "");
    static_assert(ITOSS(19) == "19", "");
    static_assert(ITOSS(99) == "99", "");
    static_assert(ITOSS(873) == "873", "");
    static_assert(ITOSS(496850) == "496850", "");
    static_assert(ITOSS(853104678) == "853104678", "");
    static_assert(ITOSS(2147483647) == "2147483647", "");
    static_assert(ITOSS(4294967295LL) == "4294967295", "");
    static_assert(ITOSS(827394274920LL) == "827394274920", "");
    static_assert(ITOSS(294653986395673LL) == "294653986395673", "");
    static_assert(ITOSS(973946584364859472LL) == "973946584364859472", "");
    static_assert(ITOSS(9223372036854775807LL) == "9223372036854775807", "");
    static_assert(ITOSS(std::numeric_limits<long long>::max()) == "9223372036854775807", "");
    static_assert(ITOSS(-1) == "-1", "");
    static_assert(ITOSS(-9) == "-9", "");
    static_assert(ITOSS(-10) == "-10", "");
    static_assert(ITOSS(-11) == "-11", "");
    static_assert(ITOSS(-14) == "-14", "");
    static_assert(ITOSS(-19) == "-19", "");
    static_assert(ITOSS(-99) == "-99", "");
    static_assert(ITOSS(-873) == "-873", "");
    static_assert(ITOSS(-496850) == "-496850", "");
    static_assert(ITOSS(-853104678) == "-853104678", "");
    static_assert(ITOSS(-2147483647) == "-2147483647", "");
    static_assert(ITOSS(-4294967295LL) == "-4294967295", "");
    static_assert(ITOSS(-827394274920LL) == "-827394274920", "");
    static_assert(ITOSS(-294653986395673LL) == "-294653986395673", "");
    static_assert(ITOSS(-973946584364859472LL) == "-973946584364859472", "");
    static_assert(ITOSS(-9223372036854775807LL) == "-9223372036854775807", "");
    static_assert(ITOSS(std::numeric_limits<long long>::min()) == "-9223372036854775808", "");

    // UTOSS() tests
    static_assert(UTOSS(0) == "0", "");
    static_assert(UTOSS(1) == "1", "");
    static_assert(UTOSS(9) == "9", "");
    static_assert(UTOSS(10) == "10", "");
    static_assert(UTOSS(11) == "11", "");
    static_assert(UTOSS(14) == "14", "");
    static_assert(UTOSS(19) == "19", "");
    static_assert(UTOSS(99) == "99", "");
    static_assert(UTOSS(873) == "873", "");
    static_assert(UTOSS(496850) == "496850", "");
    static_assert(UTOSS(853104678) == "853104678", "");
    static_assert(UTOSS(2147483647) == "2147483647", "");
    static_assert(UTOSS(4294967295ULL) == "4294967295", "");
    static_assert(UTOSS(827394274920ULL) == "827394274920", "");
    static_assert(UTOSS(294653986395673ULL) == "294653986395673", "");
    static_assert(UTOSS(973946584364859472ULL) == "973946584364859472", "");
    static_assert(UTOSS(9223372036854775807ULL) == "9223372036854775807", "");
    static_assert(UTOSS(18446744073709551615ULL) == "18446744073709551615", "");
    static_assert(UTOSS(std::numeric_limits<unsigned long long>::max()) == "18446744073709551615", "");

    // SSTOI() tests
    static_assert(SSTOI("") == 0, "");
    static_assert(SSTOI("0") == 0, "");
    static_assert(SSTOI("1") == 1, "");
    static_assert(SSTOI("9") == 9, "");
    static_assert(SSTOI("10") == 10, "");
    static_assert(SSTOI("11") == 11, "");
    static_assert(SSTOI("14") == 14, "");
    static_assert(SSTOI("19") == 19, "");
    static_assert(SSTOI("99") == 99, "");
    static_assert(SSTOI("873") == 873, "");
    static_assert(SSTOI("496850") == 496850, "");
    static_assert(SSTOI("853104678") == 853104678, "");
    static_assert(SSTOI("2147483647") == 2147483647, "");
    static_assert(SSTOI("4294967295") == 4294967295LL, "");
    static_assert(SSTOI("827394274920") == 827394274920LL, "");
    static_assert(SSTOI("294653986395673") == 294653986395673LL, "");
    static_assert(SSTOI("973946584364859472") == 973946584364859472LL, "");
    static_assert(SSTOI("9223372036854775807") == 9223372036854775807LL, "");
    static_assert(SSTOI("9223372036854775807") == std::numeric_limits<long long>::max(), "");
    static_assert(SSTOI("-1") == -1, "");
    static_assert(SSTOI("-9") == -9, "");
    static_assert(SSTOI("-10") == -10, "");
    static_assert(SSTOI("-11") == -11, "");
    static_assert(SSTOI("-14") == -14, "");
    static_assert(SSTOI("-19") == -19, "");
    static_assert(SSTOI("-99") == -99, "");
    static_assert(SSTOI("-873") == -873, "");
    static_assert(SSTOI("-496850") == -496850, "");
    static_assert(SSTOI("-853104678") == -853104678, "");
    static_assert(SSTOI("-2147483647") == -2147483647, "");
    static_assert(SSTOI("-4294967295") == -4294967295LL, "");
    static_assert(SSTOI("-827394274920") == -827394274920LL, "");
    static_assert(SSTOI("-294653986395673") == -294653986395673LL, "");
    static_assert(SSTOI("-973946584364859472") == -973946584364859472LL, "");
    static_assert(SSTOI("-9223372036854775807") == -9223372036854775807LL, "");
    static_assert(SSTOI("-9223372036854775808") == std::numeric_limits<long long>::min(), "");

    // SSTOU() tests
    static_assert(SSTOU("") == 0, "");
    static_assert(SSTOU("0") == 0, "");
    static_assert(SSTOI("1") == 1, "");
    static_assert(SSTOU("9") == 9, "");
    static_assert(SSTOU("10") == 10, "");
    static_assert(SSTOU("11") == 11, "");
    static_assert(SSTOU("14") == 14, "");
    static_assert(SSTOU("19") == 19, "");
    static_assert(SSTOU("99") == 99, "");
    static_assert(SSTOU("873") == 873, "");
    static_assert(SSTOU("496850") == 496850, "");
    static_assert(SSTOU("853104678") == 853104678, "");
    static_assert(SSTOU("2147483647") == 2147483647, "");
    static_assert(SSTOU("4294967295") == 4294967295ULL, "");
    static_assert(SSTOU("827394274920") == 827394274920ULL, "");
    static_assert(SSTOU("294653986395673") == 294653986395673ULL, "");
    static_assert(SSTOU("973946584364859472") == 973946584364859472ULL, "");
    static_assert(SSTOU("9223372036854775807") == 9223372036854775807ULL, "");
    static_assert(SSTOU("18446744073709551615") == 18446744073709551615ULL, "");
    static_assert(SSTOU("18446744073709551615") == std::numeric_limits<unsigned long long>::max(), "");

    { // struct methods tests
        constexpr auto ss0 = STOSS("");
        static_assert(ss0.empty(), "");
        static_assert(ss0.length() == 0, "");
        static_assert(ss0.size() == 0, "");
        static_assert(sizeof(ss0) == 1 * sizeof(char), "");
        static_assert(ss0.reverse() == "", "");
        static_assert(ss0.substring<0, 0>() == "", "");
        static_assert(ss0.prefix<0>() == "", "");
        static_assert(ss0.suffix<0>() == "", "");
        constexpr auto ss1 = STOSS("Hello");
        static_assert(!ss1.empty(), "");
        static_assert(ss1.length() == 5, "");
        static_assert(ss1.size() == 5, "");
        static_assert(sizeof(ss1) == 6 * sizeof(char), "");
        static_assert(ss1.reverse() == "olleH", "");
        static_assert(ss1.substring<0, 5>() == "Hello", "");
        static_assert(ss1.substring<3, 3>() == "", "");
        static_assert(ss1.substring<1, 5>() == "ello", "");
        static_assert(ss1.substring<0, 4>() == "Hell", "");
        static_assert(ss1.substring<2, 5>() == "llo", "");
        static_assert(ss1.substring<3, 4>() == "l", "");
        static_assert(ss1.substring<2, 4>() == "ll", "");
        static_assert(ss1.substring<1, 4>() == "ell", "");
        static_assert(ss1.prefix<0>() == "", "");
        static_assert(ss1.prefix<1>() == "H", "");
        static_assert(ss1.prefix<2>() == "He", "");
        static_assert(ss1.prefix<3>() == "Hel", "");
        static_assert(ss1.prefix<4>() == "Hell", "");
        static_assert(ss1.prefix<5>() == "Hello", "");
        static_assert(ss1.suffix<0>() == "Hello", "");
        static_assert(ss1.suffix<1>() == "ello", "");
        static_assert(ss1.suffix<2>() == "llo", "");
        static_assert(ss1.suffix<3>() == "lo", "");
        static_assert(ss1.suffix<4>() == "o", "");
        static_assert(ss1.suffix<5>() == "", "");
        constexpr auto ss2 = STOSS("abcabca");
        static_assert(ss2.find('a') == 0, "");
        static_assert(ss2.find('a', ss2.begin()) == 0, "");
        static_assert(ss2.find('a', ss2.end()) == static_string::npos, "");
        static_assert(ss2.find('a', 0) == 0, "");
        static_assert(ss2.find('a', 1) == 3, "");
        static_assert(ss2.find('a', 4) == 6, "");
        static_assert(ss2.find('a', 7) == static_string::npos, "");
        static_assert(ss2.find('a', 1'000'000) == static_string::npos, "");
        static_assert(ss2.find('a', ss2.begin(), 0) == 0, "");
        static_assert(ss2.find('a', ss2.begin(), 1) == 3, "");
        static_assert(ss2.find('a', ss2.begin(), 2) == 6, "");
        static_assert(ss2.find('a', ss2.begin(), 3) == static_string::npos, "");
        static_assert(ss2.find('a', ss2.begin(), 1'000'000) == static_string::npos, "");
        constexpr auto ss3 = STOSS("cabcabc");
        static_assert(ss3.rfind('c') == 6, "");
        static_assert(ss3.rfind('c', ss3.rbegin()) == 6, "");
        static_assert(ss3.rfind('c', ss3.rend()) == static_string::npos, "");
        static_assert(ss3.rfind('c', 6) == 6, "");
        static_assert(ss3.rfind('c', 5) == 3, "");
        static_assert(ss3.rfind('c', 2) == 0, "");
        static_assert(ss3.rfind('c', -1) == static_string::npos, "");
        static_assert(ss3.rfind('c', 1'000'000) == static_string::npos, "");
        static_assert(ss3.rfind('c', ss3.rbegin(), 0) == 6, "");
        static_assert(ss3.rfind('c', ss3.rbegin(), 1) == 3, "");
        static_assert(ss3.rfind('c', ss3.rbegin(), 2) == 0, "");
        static_assert(ss3.rfind('c', ss3.rbegin(), 3) == static_string::npos, "");
        static_assert(ss3.rfind('c', ss3.rbegin(), 1'000'000) == static_string::npos, "");
        static_assert(STOSS("").hash() == 5381ULL, "");
        static_assert(STOSS("Hello").hash() == 210724412158ULL, "");
        static_assert(STOSS("HelloWorld").hash() == 8246272427518117483ULL, "");
        static_assert(STOSS("HelloWorldHelloWorld").hash() == 889607825945456465ULL, "");
        static_assert(ss3[0] == 'c', "");
        static_assert(ss3[1] == 'a', "");
        static_assert(ss3[2] == 'b', "");
        static_assert(ss3[3] == 'c', "");
        static_assert(ss3[4] == 'a', "");
        static_assert(ss3[5] == 'b', "");
        static_assert(ss3[6] == 'c', "");
        static_assert(ss3[7] == '\0', "");
        constexpr auto ss4 = STOSS("ccbacdbacdbacdbdacbdacdacbdacdcbdadcabacbadcbdacdabcdabcdabdc");
        static_assert(ss4.count('a') == 15, "");
        static_assert(ss4.count('b') == 13, "");
        static_assert(ss4.count('c') == 17, "");
        static_assert(ss4.count('d') == 16, "");
        static_assert(ss4.count('a') + ss4.count('b') + ss4.count('c') + ss4.count('d') == ss4.length(), "");
        static_assert(ss2.starts_with(""), "");
        static_assert(ss2.starts_with("a"), "");
        static_assert(ss2.starts_with("ab"), "");
        static_assert(ss2.starts_with("abc"), "");
        static_assert(ss2.starts_with("abca"), "");
        static_assert(ss2.starts_with("abcab"), "");
        static_assert(ss2.starts_with("abcabc"), "");
        static_assert(ss2.starts_with("abcabca"), "");
        static_assert(!ss2.starts_with("abcabcab"), "");
        static_assert(!ss2.starts_with("bcabca"), "");
        static_assert(!ss2.starts_with("acabca"), "");
        static_assert(!ss2.starts_with("abcaba"), "");
        static_assert(ss2.starts_with(STOSS("")), "");
        static_assert(ss2.starts_with(STOSS("a")), "");
        static_assert(ss2.starts_with(STOSS("ab")), "");
        static_assert(ss2.starts_with(STOSS("abc")), "");
        static_assert(ss2.starts_with(STOSS("abca")), "");
        static_assert(ss2.starts_with(STOSS("abcab")), "");
        static_assert(ss2.starts_with(STOSS("abcabc")), "");
        static_assert(ss2.starts_with(STOSS("abcabca")), "");
        static_assert(!ss2.starts_with(STOSS("abcabcab")), "");
        static_assert(!ss2.starts_with(STOSS("bcabca")), "");
        static_assert(!ss2.starts_with(STOSS("acabca")), "");
        static_assert(!ss2.starts_with(STOSS("abcaba")), "");
        static_assert(ss2.ends_with(""), "");
        static_assert(ss2.ends_with("a"), "");
        static_assert(ss2.ends_with("ca"), "");
        static_assert(ss2.ends_with("bca"), "");
        static_assert(ss2.ends_with("abca"), "");
        static_assert(ss2.ends_with("cabca"), "");
        static_assert(ss2.ends_with("bcabca"), "");
        static_assert(ss2.ends_with("abcabca"), "");
        static_assert(!ss2.ends_with("babcabca"), "");
        static_assert(!ss2.ends_with("abcabc"), "");
        static_assert(!ss2.ends_with("abcaba"), "");
        static_assert(!ss2.ends_with("acabca"), "");
        static_assert(ss2.ends_with(STOSS("")), "");
        static_assert(ss2.ends_with(STOSS("a")), "");
        static_assert(ss2.ends_with(STOSS("ca")), "");
        static_assert(ss2.ends_with(STOSS("bca")), "");
        static_assert(ss2.ends_with(STOSS("abca")), "");
        static_assert(ss2.ends_with(STOSS("cabca")), "");
        static_assert(ss2.ends_with(STOSS("bcabca")), "");
        static_assert(ss2.ends_with(STOSS("abcabca")), "");
        static_assert(!ss2.ends_with(STOSS("babcabca")), "");
        static_assert(!ss2.ends_with(STOSS("abcabc")), "");
        static_assert(!ss2.ends_with(STOSS("abcaba")), "");
        static_assert(!ss2.ends_with(STOSS("acabca")), "");
        constexpr auto sss4 = STOSS("bac");
        static_assert(ss4.find("bac") == 2, "");
        static_assert(ss4.find("bac", 3) == 6, "");
        static_assert(ss4.find("bac", 7) == 10, "");
        static_assert(ss4.find("bac", 11) == 37, "");
        static_assert(ss4.find("bac", 38) == static_string::npos, "");
        static_assert(ss4.find("bac", ss4.begin(), 1) == 6, "");
        static_assert(ss4.find("bac", ss4.begin(), 2) == 10, "");
        static_assert(ss4.find("bac", ss4.begin(), 3) == 37, "");
        static_assert(ss4.find("bac", ss4.begin(), 4) == static_string::npos, "");
        static_assert(ss4.find(sss4) == 2, "");
        static_assert(ss4.find(sss4, 3) == 6, "");
        static_assert(ss4.find(sss4, 7) == 10, "");
        static_assert(ss4.find(sss4, 11) == 37, "");
        static_assert(ss4.find(sss4, 38) == static_string::npos, "");
        static_assert(ss4.find(sss4, ss4.begin(), 1) == 6, "");
        static_assert(ss4.find(sss4, ss4.begin(), 2) == 10, "");
        static_assert(ss4.find(sss4, ss4.begin(), 3) == 37, "");
        static_assert(ss4.find(sss4, ss4.begin(), 4) == static_string::npos, "");
        static_assert(ss4.rfind("bac") == 37, "");
        static_assert(ss4.rfind("bac", 36) == 10, "");
        static_assert(ss4.rfind("bac", 9) == 6, "");
        static_assert(ss4.rfind("bac", 5) == 2, "");
        static_assert(ss4.rfind("bac", 1) == static_string::npos, "");
        static_assert(ss4.rfind("bac", ss4.rbegin() - 2, 1) == 10, "");
        static_assert(ss4.rfind("bac", ss4.rbegin() - 2, 2) == 6, "");
        static_assert(ss4.rfind("bac", ss4.rbegin() - 2, 3) == 2, "");
        static_assert(ss4.rfind("bac", ss4.rbegin() - 2, 4) == static_string::npos, "");
        static_assert(ss4.rfind(sss4) == 37, "");
        static_assert(ss4.rfind(sss4, 36) == 10, "");
        static_assert(ss4.rfind(sss4, 9) == 6, "");
        static_assert(ss4.rfind(sss4, 5) == 2, "");
        static_assert(ss4.rfind(sss4, 1) == static_string::npos, "");
        static_assert(ss4.rfind(sss4, ss4.rbegin() - sss4.rbegin(), 1) == 10, "");
        static_assert(ss4.rfind(sss4, ss4.rbegin() - sss4.rbegin(), 2) == 6, "");
        static_assert(ss4.rfind(sss4, ss4.rbegin() - sss4.rbegin(), 3) == 2, "");
        static_assert(ss4.rfind(sss4, ss4.rbegin() - sss4.rbegin(), 4) == static_string::npos, "");
        static_assert(ss3.contains('a'), "");
        static_assert(ss3.contains('b'), "");
        static_assert(ss3.contains('c'), "");
        static_assert(!ss3.contains('e'), "");
        static_assert(!ss3.contains('f'), "");
        static_assert(!ss3.contains('g'), "");
        static_assert(ss3.contains("cab"), "");
        static_assert(ss3.contains("bca"), "");
        static_assert(ss3.contains("abc"), "");
        static_assert(!ss3.contains("cba"), "");
        static_assert(!ss3.contains("aca"), "");
        static_assert(!ss3.contains("abb"), "");
        static_assert(ss3.contains("cabcabc"), "");
        static_assert(!ss3.contains("cabcabca"), "");
        static_assert(!ss3.contains("acabcabc"), "");
    }

    // example #0
    std::cout << STOSS("Hello ") + "World!" << std::endl;

    { // example #1
        constexpr wchar_t name[] = L"Andrew";
        constexpr auto str1 = static_wstring::make(L"Hello, ", name, L"!");
        static_assert(str1 == L"Hello, Andrew!", "");
        std::wcout << str1 << std::endl;

        constexpr auto str2 = L"Hello, " + STOSW(name) + L"!";
        static_assert(str2 == L"Hello, Andrew!", "");
        std::wcout << str2 << std::endl;
    }

    { // example #2
        constexpr char country[] = "Great Britain";
        constexpr char captital[] = "London";
        constexpr auto str1 = static_string::make(captital, " is a capital of ", country);
        static_assert(str1 == "London is a capital of Great Britain", "");
        std::cout << str1 << std::endl;

        constexpr auto str2 = STOSS(captital) + " is a capital of " + STOSS(country);
        static_assert(str2 == "London is a capital of Great Britain", "");
        std::cout << str2 << std::endl;
    }

    { // example #3
        constexpr int apples = 5;
        constexpr int oranges = 7;
        constexpr int fruits = apples + oranges;
        constexpr auto str1 = static_wstring::make(L"I have ", ITOSW(apples), L" apples and ",
            ITOSW(oranges), L" oranges, so I have ", ITOSW(fruits), L" fruits");
        static_assert(str1 == L"I have 5 apples and 7 oranges, so I have 12 fruits", "");
        std::wcout << str1 << std::endl;

        constexpr auto str2 = L"I have " + ITOSW(apples) + L" apples and " +
            ITOSW(oranges) + L" oranges, so I have " + ITOSW(fruits) + L" fruits";
        static_assert(str2 == L"I have 5 apples and 7 oranges, so I have 12 fruits", "");
        std::wcout << str2 << std::endl;
    }

    { // example #4
        constexpr auto sstr1 = static_string::make("1 + 1 = ", ITOSS(1 + 1));
        constexpr auto sstr2 = static_string::make(sstr1, ", 2 + 2 = ", ITOSS(2 + 2));
        static_assert(sstr1 == "1 + 1 = 2", "");
        static_assert(sstr2 == "1 + 1 = 2, 2 + 2 = 4", "");
        std::string str1 = sstr2.str();
        std::cout << str1 << std::endl;

        constexpr auto sstr3 = "1 + 1 = " + ITOSS(1 + 1);
        constexpr auto sstr4 = sstr3 + ", 2 + 2 = " + ITOSS(2 + 2);
        static_assert(sstr3 == "1 + 1 = 2", "");
        static_assert(sstr4 == "1 + 1 = 2, 2 + 2 = 4", "");
        const char* str4 = sstr4.c_str();
        std::cout << str4 << std::endl;
    }

    { // example #5
        constexpr auto sstr2 = STOSS("abcdefgh");
        for (size_t i = sstr2.begin(); i != sstr2.end(); ++i)
        {
          std::cout << sstr2[i];
        }
        std::cout << std::endl;
        for (size_t i = sstr2.rbegin(); i != sstr2.rend(); --i)
        {
          std::cout << sstr2[i];
        }
        std::cout << std::endl;

        for (const auto& c : sstr2.data)
        {
          std::cout << c;
        }
        std::cout << std::endl;
        for (const auto& c : sstr2.reverse().data)
        {
          std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}
