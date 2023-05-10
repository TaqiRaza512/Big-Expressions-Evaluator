#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class HugeInt
{
	int* Ds;
	int size;
	bool isNeg;
	void DeAllocate();
	void removeAtEnd(int*&, int&);
	void TRIM();
	const HugeInt ABS()const;
public:
	HugeInt();
	HugeInt(ifstream& rdr);
	HugeInt(const HugeInt&);
	HugeInt(const char* num);
	HugeInt(string num);

	void SetInteger(ifstream&);
	void SetInteger(const HugeInt&);
	void SetInteger(const char* num);
	void SetInteger(string num);
	void SetInteger(istream&);


	friend ifstream& operator>>(ifstream&, HugeInt&);
	friend istream& operator>>(istream&, HugeInt&);
	friend ostream& operator<<(ostream&, const HugeInt&);


	const HugeInt operator=(const HugeInt&);
	const HugeInt operator=(const char* num);
	const HugeInt operator=(string num);

	int& operator[](int);
	int operator[](int)const;

	const HugeInt ADDQWise(const HugeInt& H)const;
	const HugeInt SUBQWise(const HugeInt& H)const;

	bool QWiseGT(const HugeInt& H)const;
	bool QWiseLT(const HugeInt& H)const;
	bool QWiseET(const HugeInt& H)const;


	const HugeInt operator-()const;
	const HugeInt operator++();
	const HugeInt operator++(int);
	const HugeInt operator--();
	const HugeInt operator--(int);


	const HugeInt operator+(const HugeInt&)const;
	const HugeInt operator-(const HugeInt&)const;
	const HugeInt operator*(const HugeInt&)const;
	const HugeInt operator/(const HugeInt&)const;
	const HugeInt operator%(const HugeInt&)const;


	const HugeInt operator+=(const HugeInt&);
	const HugeInt operator-=(const HugeInt&);
	const HugeInt operator*=(const HugeInt&);
	const HugeInt operator/=(const HugeInt&);
	const HugeInt operator%=(const HugeInt&);

	bool operator==(const HugeInt&)const;
	bool operator!=(const HugeInt&)const;

	bool operator<(const HugeInt&)const;
	bool operator>(const HugeInt&)const;

	bool operator<=(const HugeInt&)const;
	bool operator>=(const HugeInt&)const;



	~HugeInt();

};
