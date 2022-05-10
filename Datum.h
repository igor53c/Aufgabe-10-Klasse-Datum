#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Datum
{
public:
	Datum();
	Datum(int, int, int);

	void setTag(int);
	void setMonat(int);
	void setJahr(int);

	void setDatum(int, int, int);

	int getTag() const;
	int getMonat() const;
	int getJahr() const;

	string toShortString();
	string toLongString();

private:
	int tag, monat, jahr;

	static const int DEFAULT_TAG;
	static const int DEFAULT_MONAT;
	static const int DEFAULT_JAHR;

	static const string MONAT_NAME[];
	static const int MONAT_TAGE[];

	bool checkTag(int, int, int);
	bool checkMonat(int);
	bool checkJahr(int);

	int getNumberDaysOfMonth(int, int);

	bool isLeapYear(int);

	string numberToString(int);
};

