#include <iostream>
#include <memory>
using namespace std;
template<typename T>
void Empty_pointer(shared_ptr<T>& ptr)
{
	if (ptr)
	{
		cout << endl << "Указатель не нулевой";
	}
	else
	{
		cout << endl << "Указатель нулевой";
	}
}

class Date
{
public:
	Date() {}
	friend ostream &operator<< (std::ostream &out, const Date &date)
	{
		out << "Сегодняшняя дата: " << date.D_day << "." << date.D_month << "." << date.D_year;
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

private:
	int D_day{}, D_month{}, D_year{};
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Date *p = new Date;
	shared_ptr<Date> today(p);
	today->setDay(20);
	today->setMonth(7);
	today->setYear(2021);
	cout << *today;
	shared_ptr<Date> date(today);
	Empty_pointer(today);
	Empty_pointer(date);
	return 0;
}