#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	void Print();
	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1999, int month = 1, int day = 1);
	
	//�������캯��
	//d2(d1)
	Date(const Date& d);

	//��ֵ���������
	//d2 = d3 -> d2.operator(&d2,d3);
	Date& operator=(const Date& d);

	//��������
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
	//Ϊ�˺�ǰ��++���𣬼���һ��������βΣ�
	//���������ʹ�ã�����Ϊ�˺�ǰ��++���ɺ�������
	//d3.operator(&d3,0)
	Date operator++(int);

	// ����--
	Date operator--(int);

	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);

	// ==���������
	bool operator==(const Date& d);

	// >=���������
	inline bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);

	// <=���������
	bool operator <= (const Date& d);

	// !=���������
	bool operator != (const Date& d);

	// ����-���� ��������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};