// printf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//double, str, char, int
//zamiana '~' na '(")'
//do wypisywania jedynie putchar()
#include "pch.h"
#include <iostream>
#include<stdarg.h>
using namespace std;
void outDec( int x );    //znakowo wypisuje liczbe ca³kowita
void outChar( char c );  // wypisuje znak //putchar()
void outStr ( char* );   // wypisuje znakowo string
void outDouble ( double x ); // wypisuje liczbe double 0.
void outNum( int x );     // wypisuje znakowo liczbe int >0 rekurencyjnie
int Printf( const char* Format, ... );
int PrintfV( const char* Format, va_list  arg_list );
int main()
{
	int n = -0;
	char c = '$';
	double x = 12000000.3450000123;
		//double y = -.12;
		//double z = -0.5;
		//char* str = "to jest string";

	Printf ("%c", n)	;
	//Printf( "%s\n%f%c n=%d \\ % /\ny=%f z=%f\n\n", str, x, c, n, y, z)
}

int Printf( const char* Format, ... )
{

	
	
		va_list arg;
		va_start( arg, Format );
	    int res= PrintfV(Format, arg);
		va_end( arg );
		return  res;
	

}

int PrintfV(const char* Format, va_list arg_list )
{


	int i = 0;
	
	char c;

	while ( c=Format[i++] )
	{

		switch ( c )
	  {
		case'%':
		{
			switch (c)
			{
			case'd':  outDec(va_arg(arg_list, int)); break;
			case's':  outStr(va_arg(arg_list, char*));    break;
			case'f': outDouble(va_arg(arg_list, double)); break;
			case'c': outChar(va_arg(arg_list,  char));   break;
			deafult: outChar('%'); outChar(c); break;

			}
		}
			break;
	  
		case '`': c = '\'';
		default: outChar(c);
		}
	
	}
		
		return 0;
}


	void outDec(int x)
	{
		

		if (x<0)
		{
			x = -x;
			outChar('-');
			outNum(x);

		}
		else outNum(x);
		

	}
	void outChar(char c)
	{
		putchar(c);
	}
	void outStr(char* pStr)
	{
		while(*pStr) outChar(*pStr++);
	}
	void outDouble(double x)
	{
		if ((x > -1) && (x < 0))
		outChar('-');

	}
	void outNum(int x)
	{
		if (x > 0)
		{
			outNum(x / 10);
			outNum(x % 10 + '0');
		}
	}