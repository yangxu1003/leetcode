#include "Date.h"

Date::Date(int year , int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!(year >= 0 && month > 0 && month < 13 && day > 0 
		&& day <= GetMonthDay(year, month)))
	{
		cout << "�Ƿ�����" << endl;
	}
	
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
	static int daysArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = daysArr[month];
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			days = 29;
		}
	}

	return days;
}

//�������캯��
//  d2(d1)
Date::Date(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

//��ֵ���������
	//d2 = d3 -> d2.operator(&d2,d3);
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	return *this;
}

//��������
Date::~Date()
{
	//����
}

// d1 + 30
//�Ȱ���ӵ���������,������ڲ��Ϸ�,�ͼ������µ�����,Ȼ���һ���¡��������,����
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	//�����Ƿ�Ϸ�
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

// d3 + 10;
Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	
	return ret;
}

//d3 -= 50
//������ڲ���,
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

//d3 - 50
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;

	return ret;
}

//++d3 -> d3 += 1 ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//d3++ ����++
//d3.operator(&d3,0)
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}

// ����--
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;

	return ret;
}


// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// >���������
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

// ==��������� d1 == d2
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}

// >=���������
inline bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// ����-���� ��������
int Date::operator-(const Date& d)
{
	Date max(*this);
	Date min(d);

	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int days = 0;
	while (max != min)
	{
		min++;
		days++;
	}


	return days*flag;
}