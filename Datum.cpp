#include "Datum.h"

const int Datum::DEFAULT_TAG = 1;

const int Datum::DEFAULT_MONAT = 1;

const int Datum::DEFAULT_JAHR = 2000;

const string Datum::MONAT_NAME[]{ 
	" Januar "," Februar "," März "," April "," Mai "," Juni "," Juli ",
	" August "," September "," Oktober "," November "," Dezember "
};

const int Datum::MONAT_TAGE[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Datum::Datum()
{
	tag = DEFAULT_TAG;
	monat = DEFAULT_MONAT;
	jahr = DEFAULT_JAHR;
}

Datum::Datum(int tag, int monat, int jahr) : Datum()
{
	setDatum(tag, monat, jahr);
}

void Datum::setTag(int tag)
{
	if(checkTag(tag, monat, jahr))
		this->tag = tag;
	else
		cerr << "Sie haben einen falschen Wert für den Tag eingegeben!" << endl;
}

void Datum::setMonat(int monat)
{
	if (checkMonat(monat) && checkTag(tag, monat, jahr))
		this->monat = monat;
	else
		cerr << "Sie haben den falschen Wert für den Monat eingegeben!" << endl;
}

void Datum::setJahr(int jahr)
{
	if(checkJahr(jahr) && checkTag(tag, monat, jahr))
		this->jahr = jahr;
	else
		cerr << "Sie haben einen falschen Wert für das Jahr eingegeben!" << endl;
}

void Datum::setDatum(int tag, int monat, int jahr)
{
	if (checkJahr(jahr) && checkMonat(monat) && checkTag(tag, monat, jahr))
	{
		this->jahr = jahr;
		this->monat = monat;
		this->tag = tag;
	}
	else
		cerr << "Sie haben ein nicht vorhandenes Datum eingegeben!" << endl;
}

int Datum::getTag() const
{
	return tag;
}

int Datum::getMonat() const
{
	return monat;
}

int Datum::getJahr() const
{
	return jahr;
}

string Datum::toShortString()
{
	return numberToString(tag) + numberToString(monat) + to_string(jahr);
}

string Datum::toLongString()
{
	return numberToString(tag) + MONAT_NAME[monat - 1] + to_string(jahr);
}

bool Datum::checkTag(int tag, int monat, int jahr)
{
	return tag > 0 && tag <= getNumberDaysOfMonth(monat, jahr);
}

bool Datum::checkMonat(int monat)
{
	return monat > 0 && monat < 13;
}

bool Datum::checkJahr(int jahr)
{
	return jahr > 1582 && jahr < 10000;
}

int Datum::getNumberDaysOfMonth(int monat, int jahr)
{
	int retValue = MONAT_TAGE[monat - 1];

	if (monat == 2 && isLeapYear(jahr))
		retValue = 29;

	return retValue;
}

bool Datum::isLeapYear(int jahr)
{
	return (jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0);
}

string Datum::numberToString(int number)
{
	stringstream ss;

	ss << setw(2) << setfill('0') << number << '.';

	return ss.str();
}