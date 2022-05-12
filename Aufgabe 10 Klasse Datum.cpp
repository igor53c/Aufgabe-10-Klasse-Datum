// Aufgabe 10 Klasse Datum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
 * Aufgabe: Deklarieren und implementieren Sie ein nach ihrem Ermessen sinnvolles
 *          Konzept für eine Klasse 'Datum'. Definieren Sie ihre Klasse in einer
 *          separaten Code-Datei.
 *
 *          Beachten Sie dabei folgende Vorgaben:
 *
 *            - das Datum besteht aus drei Werten: int tag, monat, jahr;
 *            - bei den Werten für 'tag' gilt: tag > 0 und abhängig vom jeweiligen
 *               Monat < 32 oder < 31.   Die Schaltjahr-Problematik (29.Februar)
 *               ist mit einzubeziehen.
 *            - bei den Werten für 'monat' gilt:  monat > 0 und kleiner 13
 *            - die Werte für 'jahr' dürfen nur größer als 1582 sein (Einführung des
 *              Gregorianischen Kalenders)
 *            - Initialisierungs- bzw. Default-Werte: tag = monat = 1, jahr = 2000
 *
 *          Hinweis: Ein Jahr ist ein Schaltjahr, wenn es ganzzahlig durch 4, aber
 *                   nicht ganzzahlig durch 100 teilbar ist, es sein denn, es ist
 *                   ganzzahlig durch 400 teilbar.
 *
 *          Testen Sie ihre Klasse, indem Sie verschiedene Objekte erzeugen und
 *          diese entsprechend bearbeiten.
 *
 *
 */


 /* Zusätzliche Methoden
  *
  * Rückgabe des Datums im Standardformat tt.MM.jjjj		- 01.01.2000
  * Rückgabe des Datums im langen Format tt. Monatsname jjjj	- 01. Januar 2000
  *
  * Die Datumslogik der folgenden Methoden sind ohne Verwendung evtl. vorhandener Systemklassen für
  * Datumswerte zu implementieren.
  *
  * addiereTage(int)   - addiert/subtrahiert die angegebene Anzahl von Tagen auf/vom Datum.
  * addiereMonate(int) - addiert/subtrahiert die angegebene Anzahl von Monaten auf/vom Datum.
  * addiereJahre(int)  - addiert/subtrahiert die angegebene Anzahl von Jahren auf/vom Datum.
  */

  // https://www.timeanddate.com/date/dateadded.html

/*
 * Übung:
 *  		Überladen/Definieren Sie für die Klasse 'Datum' die Vergleichs-Operatoren
 *          	('==', '!=', '<', '>', '<=' und '>=), um zwei Datumswerte vergleichen zu können.
 *
 *		Überladen/Definieren Sie für die Klasse 'Datum' folgende Operatoren:
 *	  	+ 	-> 	Addition des angegebenen int-Werts auf den aktuellen Tag der Klasse 'Datum'
 *      - 	-> 	Subtraktion des angegegeben int-Werts vom aktuellen Tag der Klasse 'Datum'
 *
 */

#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{
	locale::global(locale("German_germany"));

	/*Datum datum(29, 2, 2001);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;

	datum.setDatum(29, 2, 2000);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;

	datum.setJahr(2001);
	datum.setJahr(2100);
	datum.setTag(30);
	datum.setTag(28);
	datum.setJahr(2001);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;

	datum.setDatum(31, 8, 1995);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;

	datum.setMonat(3);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;

	datum.setMonat(4);

	cout << datum.toLongString() << endl;
	cout << datum.toString() << endl;*/

	Datum datum(29, 2, 2000);

	cout << datum.toString() << endl;

	datum.addiereJahre(1);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(13);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(22);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(13);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(-22);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(-5);

	cout << datum.toString() << endl;

	datum.setDatum(31, 1, 1999);
	datum.addiereMonate(-1);

	cout << datum.toString() << endl;

	datum.setDatum(31, 3, 1999);
	datum.addiereMonate(-1);

	cout << datum.toString() << endl;

	datum.setDatum(31, 3, 1999);
	datum.addiereMonate(9);

	cout << datum.toString() << endl;

	Datum datum2(1, 1, 1999);

	if (datum == datum2)
		cout << "==" << endl;
	else cout << "!=" << endl;

	if (datum != datum2)
		cout << "!=" << endl;
	else cout << "==" << endl;

	if (datum > datum2)
		cout << ">" << endl;
	else cout << "<=" << endl;

	if (datum < datum2)
		cout << "<" << endl;
	else cout << ">=" << endl;

	if (datum <= datum2)
		cout << "<=" << endl;
	else cout << ">" << endl;

	if (datum >= datum2)
		cout << ">=" << endl;
	else cout << "<" << endl;

	datum = datum2 + 31;

	cout << datum.toString() << endl;

	datum = datum2 - 31;

	cout << datum.toString() << endl;

	datum2 += 10;

	cout << datum2.toString() << endl;

	datum2 -= 10;

	cout << datum2.toString() << endl;

	++datum2;

	cout << datum2.toString() << endl;

	--datum2;

	cout << datum2.toString() << endl;

	datum2++;

	cout << datum2.toString() << endl;

	datum2--;

	cout << datum2.toString() << endl;

	return EXIT_SUCCESS;
}
