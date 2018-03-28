#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "WordData.h"

using namespace std;

bool isalpha_string(string str);
bool alfabetico(string str);
void rm_spaces(string &s);
bool wildcardMatch(const char *str, const char *strWild);
bool isValid(string str, vector<char> vec);
bool menu(WordData &wd);
void op_a(WordData &wd);
void op_b(WordData &wd);
void op_c(WordData &wd);
void op_d(WordData &wd);
void op_e(WordData &wd);
bool op_f(WordData &wd);