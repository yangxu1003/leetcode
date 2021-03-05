#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	void Print();
	//全缺省的构造函数
	Date(int year = 1999, int month = 1, int day = 1);
	
	//拷贝构造函数
	//d2(d1)
	Date(const Date& d);

	//赋值运算符重载
	//d2 = d3 -> d2.operator(&d2,d3);
	Date& operator=(const Date& d);

	//析构函数
	~Date();

	// d3 += 30
	Date& operator+=(int day);

	// d3 + 30;
	Date operator+(int day);

	//d3 -= 50
	Date& operator-=(int day);

	//d3 - 50
	Date operator-(int day);

	//++d3
	Date& operator++();

	//d3++
	//为了和前置++区别，加了一个区别的形参，
	//这个参数不使用，仅仅为了和前置++构成函数重载
	//d3.operator(&d3,0)
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载
	bool operator==(const Date& d);

	// >=运算符重载
	inline bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);

	// <=运算符重载
	bool operator <= (const Date& d);

	// !=运算符重载
	bool operator != (const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};