#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum class Month : short unsigned int {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, 
	Sep, Oct, Nov, Dec};


//CLASS DATE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Date{

	private:

		short unsigned int _day;
		Month _month;
		short unsigned int _year;
		void add_day();

	public:

		Date();
		Date(short unsigned int d, Month m, short unsigned int y): _day{d}, 
			_month{m}, _year{y} {}
		Date(Month m, short unsigned int d, short unsigned int y): _day{d},
			_month{m}, _year{y} {}
		~Date() {}

		auto day() const {return _day;}
		auto month() const {return static_cast<short unsigned int>(_month);}
		auto year() const {return _year;}

		void day(short unsigned int a){_day=a;}
		void month(Month a){_month = a;}
		void year(short unsigned int a){_year=a;}

		void add_days(const unsigned int n){for (unsigned int i = 0; i < n; ++i) add_day();}

		void print_date(){cout << "dd/mm/yyyy:\t" << day() <<"/"<< month() <<"/"<< year()<<endl;}
	
};	

//HELPER FUNCTIONS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool operator==(const Date&, const Date&);
bool operator!=(const Date& lhs, const Date& rhs){return !(lhs==rhs);}
std::ostream& operator<<(std::ostream&, const Date&);
bool is_leap(const int);

//MAIN+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(){

	Date temp(1,Month::Jan,2000);
	Date temp1(1,Month::Jan,2020);
	Date temp2(1,Month::Jan,1900);

//	test print function
	temp.print_date();
	temp1.print_date();
	temp2.print_date();

// 	test days addition	
	temp.add_days(365);
	temp.print_date();

//	test operators == and !=
	cout << (temp==temp1) << endl;
	cout << (temp==temp2) << endl;
	cout << (temp!=temp1) << endl;
	cout << (temp!=temp2) << endl;

// 	tets operator <<
	cout << temp;

//	test is_leap function
	cout << is_leap(temp.year()) << "\n" << is_leap(temp1.year()) << "\n" << is_leap(temp2.year()) << "\n";

	return 0;

}

//DEFINITIONS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Date::add_day(){


//	set the number od days in each month
	int max_day{0};

	switch(_month){
		case Month::Jan: case Month::Mar: case Month::May: case Month::Jul:
		case Month::Aug: case Month::Oct: case Month::Dec:
			max_day = 31;
			break;
		case Month::Feb:
			max_day = 28;
			break;
		case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
			max_day = 30;
			break;
		default:
			cout << "month not specified, use 30 days format" << endl;
			max_day = 30;
			break;

	}

//	chieck whether we have to increase month and year
	if (_day < max_day){
		_day += 1;
	}
	else{
		_day = 1;
		if (_month==Month::Dec){
			_month = Month::Jan;
			_year++;
		}
		else{
			_month = Month(static_cast<int>(_month)+1);		// this works!!
		}
	}

}

//---------------------------------------------------------------------

bool operator==(const Date& lhs, const Date& rhs){

	if (lhs.day()==rhs.day() && lhs.month()==rhs.month() && lhs.year()==rhs.year())
		return 1;
	else
		return 0;
}

//---------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Date& d){

	os << d.day() << "/" << d.month() << "/" << d.year() << endl;
	return os;
}

//---------------------------------------------------------------------

bool is_leap(const int y){

	if (y%4==0){
		if (y%100==0){
			if (y%400==0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;

}
