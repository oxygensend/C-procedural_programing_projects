#pragma once

#ifndef ONPFUN_H_ABF4
#define ONPFUN_H_ABF4
#include<stdio.h>









void skipSpaces();//getchar
double getNum();
int isDigit(char c);
int isOper(char c0per);
int prior(char c0per);
char getOper();
void onp();
double ONP();
double onpkalkulator();
double Eval(char cOper, double arg1, double arg2);
#endif