#include <iostream>
#include <memory>
using namespace std;

class Date
{
public:
	Date(int day, int month, int year) : D_day(day), D_month(month), D_year(year) {}
	friend ostream &operator<< (std::ostream &out, const Date &date)
	{
		out << date.D_day << "." << date.D_month << "." << date.D_year;
		return out;
	}
	void setDay(int day)
	{
		D_day = day;
	}
	void setMonth(int month)
	{
		D_month = month;
	}
	void setYear(int year)
	{
		D_year = year;
	}
	int getDay() const
	{
		return D_day;
	}
	int getMonth() const
	{
		return D_month;
	}
	int getYear() const
	{
		return D_year;
	}

private:
	int D_day{}, D_month{}, D_year{};
};

void compare(shared_ptr<Date> date1, shared_ptr<Date> date2)
{
	if (date1->getYear() > date2->getYear())
	{
		cout << "date1" << *date1 << endl;
	}
	if (date1->getYear() == date2->getYear() && date1->getMonth() > date2->getMonth())
	{
		cout << "date1 " << *date1 << endl;
	}
	if (date1->getYear() == date2->getYear() && date1->getMonth() == date2->getMonth() && date1->getDay() > date2->getDay())
	{
		cout << "date1 " << *date1 << endl;
	}
	if (date2->getYear() > date1->getYear())
	{
		cout << "date2 " << *date2 << endl;
	}
	if (date2->getYear() == date1->getYear() && date2->getMonth() > date1->getMonth())
	{
		cout << "date2 " << *date2 << endl;
	}
	if (date2->getYear() == date1->getYear() && date2->getMonth() == date1->getMonth() && date2->getDay() > date1->getDay())
	{
		cout << "date2 " << *date2 << endl;
	}
}

void exchange(shared_ptr<Date> date1, shared_ptr<Date> date2)
{
	int temp1 = date1->getDay();
	int temp2 = date2->getDay();
	date1->setDay(temp2);
	date2->setDay(temp1);
	temp1 = date1->getMonth();
	temp2 = date2->getMonth();
	date1->setMonth(temp2);
	date2->setMonth(temp1);
	temp1 = date1->getYear();
	temp2 = date2->getYear();
	date1->setYear(temp2);
	date2->setYear(temp1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	shared_ptr<Date> date1 = make_shared<Date>(20, 7, 2021);
	shared_ptr<Date> date2 = make_shared<Date>(21, 8, 2022);
	cout << "Поздняя дата: ";
	compare(date1, date2);
	exchange(date1, date2);
	cout << "date1 с датой date2: ";
	cout << *date1 << endl;
	cout << "date2 с датой date1: ";
	cout << *date2 << endl;
	return 0;
}