#pragma once
#include <iostream>
using namespace std;
typedef unsigned int  ui;
class time
{
private:
	ui seconds;
	ui minutes;
	ui hours;
public:
	time(void);
	time(ui);
	time(ui, ui, ui);
	time operator +(const time&) const;
	friend ostream& operator <<(ostream& os, const time &t1);
	~time();
};
