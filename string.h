#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class str
{
public:
	str();
	str(string c);
	str(const str & c);
	~str();

	void setString(string c);
	char* getString();

	//get length is redundant
	int getLength();

	void output() {
		for (int i = 0; i < length; i++)
		{
			cout << s[i];
		}
		cout << endl;
	}

	void uppercase() {
		for (int i = 0; i < length; i++)
		{
			if ((s[i] >= 'a') && (s[i] <= 'z'))
			{
				s[i] = s[i] - 32;
			}
		}
	}

	void lowercase() {
		for (int i = 0; i < length; i++)
		{
			if ((s[i] >= 'A') && (s[i] <= 'Z'))
			{
				s[i] = s[i] + 32;
			}
		}
	}

	char at(int index) {
		if (index <= length)
		{
			return s[index];
		}
		else
		{
			cout << "You cannot give index larger than length of string!" << endl;
			cout << "NULL character will be returned" << endl;
			return NULL;
		}
	}

	char* substring(int start, int end) {
		if (end < start)
		{
			cout << "You cannot give ending index less than starting index" << endl;
			char* substr = new char[1];
			substr[0] = NULL;
			return substr;
		}
		else
		{
			if ((start < 0) || (end < 0))
			{
				cout << "Starting or Ending index cannot be less than 0" << endl;
				char* substr = new char[1];
				substr[0] = NULL;
				return substr;
			}
			else
			{
				if ((end > length) || (start > length))
				{
					cout << "Starting or Ending index cannot be more than last index of string" << endl;
					char* substr = new char[1];
					substr[0] = NULL;
					return substr;
				}
				else
				{
					int l = end - start + 1;
					char* substr = new char[l + 1];
					int x = 0;
					for (int i = start; i <= end; i++)
					{
						substr[x] = s[i];
						x++;
					}
					substr[l] = NULL;
					return substr;
				}
			}
		}
	}

	void compare(const str & m) {
		if (length > m.length)
		{
			cout << "First string is larger than second" << endl;
		}
		else
		{
			if (m.length > length)
			{
				cout << "Second string is larger than first" << endl;
			}
			else
			{
				int x = 0;
				bool flag1 = false;
				while (flag1 == false)
				{
					if (s[x] == m.s[x])
					{
						x++;
						if (x == length)
						{
							cout << "Both strings are the same" << endl;
							flag1 = true;
						}
					}
					else
					{
						if (s[x] > m.s[x])
						{
							cout << "First string comes higher in lexicographic order" << endl;
						}
						else
						{
							cout << "Second string comes higher in lexicographic order" << endl;
						}
						flag1 = true;
					}
				}
			}
		}
	}

	void concat(char* temp) {
		bool flag1 = false;
		int x = 0;
		while (flag1 == false)
		{
			if (temp[x] == '\0')
			{
				flag1 = true;
			}
			x++;
		}

		/*cout << x << endl;*/

		char* newStr = new char[length + x + 1];

		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		for (int i = length; i < (length + x); i++)
		{
			newStr[i] = temp[i - length];
		}
		newStr[length + x] = '\0';

		delete[] s;
		s = newStr;

		length = length + x + 1;

		//for (int i = 0; i < (length + x); i++)
		//{
		//    cout << newStr[i];
		//}
		//cout << endl;

		//s = new char[length + x + 1];
		//for (int i = 0; i < (length + x); i++)
		//{
		//    s[i] = newStr[i];
		//}
		//newStr[length + x] = '\0';
	}

	void concat(string temp) {
		int l = temp.length();

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		for (int i = length; i < (length + l); i++)
		{
			newStr[i] = temp[i - length];
		}
		newStr[length + l] = '\0';

		delete[] s;
		s = newStr;
		length = length + l + 1;
	}

	void concat(char temp) {
		char* newStr = new char[length + 2];
		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		newStr[length] = temp;
		newStr[length + 1] = '\0';

		delete[] s;
		s = newStr;
		length = length + 2;
	}

	void concat(int k) {
		stringstream ss;
		ss << k;
		char* temp = new char;
		ss >> temp;

		int l = 0;
		bool flag1 = false;
		while (flag1 == false)
		{
			if (temp[l] == '\0')
			{
				flag1 = true;
			}
			l++;
		}

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		for (int i = length; i < (length + l); i++)
		{
			newStr[i] = temp[i - length];
		}
		newStr[length + l] = '\0';

		delete[] s;
		s = newStr;

		length = length + l + 1;
	}

	void concat(double n) {
		stringstream ss;
		ss << n;
		char* temp = new char;
		ss >> temp;

		int l = 0;
		bool flag1 = false;
		while (flag1 == false)
		{
			if (temp[l] == '\0')
			{
				flag1 = true;
			}
			l++;
		}

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		for (int i = length; i < (length + l); i++)
		{
			newStr[i] = temp[i - length];
		}
		newStr[length + l] = '\0';

		delete[] s;
		s = newStr;

		length = length + l + 1;
	}

	void prepend(char* temp) {
		bool flag1 = false;
		int x = 0;
		while (flag1 == false)
		{
			if (temp[x] == '\0')
			{
				flag1 = true;
			}
			x++;
		}

		char* newStr = new char[length + x + 1];

		for (int i = 0; i < x; i++)
		{
			newStr[i] = temp[i];
		}
		for (int i = x; i < (length + x); i++)
		{
			newStr[i] = s[i - x];
		}
		newStr[length + x] = '\0';

		delete[] s;
		s = newStr;
		length = length + x + 1;
	}

	void prepend(string temp) {
		int x = temp.length();
		char* newStr = new char[length + x + 1];

		for (int i = 0; i < x; i++)
		{
			newStr[i] = temp[i];
		}
		for (int i = x; i < (length + x); i++)
		{
			newStr[i] = s[i - x];
		}
		newStr[length + x] = '\0';

		delete[] s;
		s = newStr;
		length = length + x + 1;
	}

	void prepend(char temp) {
		char* newStr = new char[length + 2];
		newStr[0] = temp;
		for (int i = 1; i < length + 1; i++)
		{
			newStr[i] = s[i - 1];
		}
		newStr[length + 1] = '\0';

		delete[] s;
		s = newStr;
		length = length + 2;
	}

	void prepend(int k) {
		stringstream ss;
		ss << k;
		char* temp = new char;
		ss >> temp;

		int l = 0;
		bool flag1 = false;
		while (flag1 == false)
		{
			if (temp[l] == '\0')
			{
				flag1 = true;
			}
			l++;
		}

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < l; i++)
		{
			newStr[i] = temp[i];
		}
		for (int i = l; i < (length + l); i++)
		{
			newStr[i] = s[i - l];
		}
		newStr[length + l] = '\0';

		delete[] s;
		s = newStr;

		length = length + l + 1;
	}

	void prepend(double n) {
		stringstream ss;
		ss << n;
		char* temp = new char;
		ss >> temp;

		int l = 0;
		bool flag1 = false;
		while (flag1 == false)
		{
			if (temp[l] == '\0')
			{
				flag1 = true;
			}
			l++;
		}

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < l; i++)
		{
			newStr[i] = temp[i];
		}
		for (int i = l; i < (length + l); i++)
		{
			newStr[i] = s[i - l];
		}
		newStr[length + l] = '\0';

		delete[] s;
		s = newStr;

		length = length + l + 1;
	}

	str operator +(const str & t) {
		char* temp = new char[this->length + t.length + 1];

		for (int i = 0; i < this->length; i++)
		{
			temp[i] = s[i];
		}
		for (int i = this->length; i < (this->length + t.length); i++)
		{
			temp[i] = t.s[i - this->length];
		}

		temp[this->length + t.length] = NULL;

		str s2;
		s2.s = temp;
		s2.length = this->length + t.length;

		return s2;
	}

	str operator +(string temp) {
		int l = temp.length();

		char* newStr = new char[length + l + 1];

		for (int i = 0; i < length; i++)
		{
			newStr[i] = s[i];
		}
		for (int i = length; i < (length + l); i++)
		{
			newStr[i] = temp[i - length];
		}
		newStr[length + l] = '\0';

		str s2;
		s2.s = newStr;
		s2.length = length + l + 1;

		return s2;
	}

	void operator ==(const str & m) {
		if (length == m.length)
		{
			bool flag1 = false;
			int x = 0;
			while ((flag1 == false) && (x == length))
			{
				if (s[x] != m.s[x])
				{
					cout << "Strings are not equal" << endl;
					flag1 = true;
				}
				x++;
			}
			if (flag1 == false)
			{
				cout << "Strings are equal" << endl;
			}
		}
		else
		{
			cout << "Strings are not equal" << endl;
		}
	}

	void operator !=(const str & m) {
		if (length == m.length)
		{
			bool flag1 = false;
			int x = 0;
			while ((flag1 == false) && (x == length))
			{
				if (s[x] != m.s[x])
				{
					cout << "Strings are not equal" << endl;
					flag1 = true;
				}
				x++;
			}
			if (flag1 == false)
			{
				cout << "Strings are equal" << endl;
			}
		}
		else
		{
			cout << "Strings are not equal" << endl;
		}

	}

	void operator >(const str & m) {
		if (length > m.length)
		{
			cout << "First string is larger than second one" << endl;
		}
		else
		{
			if (length == m.length)
			{
				bool flag1 = false;
				int x = 0;
				while ((flag1 == false) && (x == length))
				{
					if (s[x] > m.s[x])
					{
						cout << "First string is larger than second one in lexography" << endl;
						flag1 = true;
					}
					x++;
				}
				if (flag1 == false)
				{
					cout << "First string is not larger than second one" << endl;
				}
			}
			else
			{
				cout << "First string is not larger than second" << endl;
			}
		}
	}

	void operator <(const str & m) {
		if (length < m.length)
		{
			cout << "First string is smaller than second one" << endl;
		}
		else
		{
			if (length == m.length)
			{
				bool flag1 = false;
				int x = 0;
				while ((flag1 == false) && (x == length))
				{
					if (s[x] < m.s[x])
					{
						cout << "First string is smaller than second one in lexography" << endl;
						flag1 = true;
					}
					x++;
				}
				if (flag1 == false)
				{
					cout << "First string is not smaller than second one" << endl;
				}
			}
			else
			{
				cout << "First string is not smaller than second" << endl;
			}
		}
	}

	char operator[](int x) {
		if (x <= length)
		{
			return s[x];
		}
		else
		{
			cout << "Index is larger than string size" << endl;
			return NULL;
		}
	}

	friend ostream & operator << (ostream &out, const str &c);
	friend istream & operator >> (istream &in, str &c);

private:
	char* s;
	int length;
};

str::str()
{
	s = new char[0];
	length = 0;
}

str::str(string c) {
	int l = c.length();
	length = l;
	s = new char[length + 1];
	for (int i = 0; i < l; i++)
	{
		s[i] = c[i];
	}
	s[l] = NULL;
}

str::str(const str & c) {
	length = c.length;
	s = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		s[i] = c.s[i];
	}
	s[length] = NULL;
}

str::~str()
{
	//cout << "Destructor called!" << endl;
	delete[] s;
	s = nullptr;
}

void str::setString(string c) {
	int l = c.length();
	length = l;
	s = new char[length + 1];
	for (int i = 0; i < l; i++)
	{
		s[i] = c[i];
	}
	s[l] = NULL;
}

char* str::getString() {
	return s;
}

int str::getLength() {
	return length;
}

ostream & operator << (ostream &out, const str &c)
{
	for (int i = 0; i < c.length; i++)
	{
		out << c.s[i];
	}
	out << endl;
	return out;
}

istream & operator >> (istream &in, str &c)
{
	delete[] c.s;
	char* temp = new char[100];
	cout << "Enter String: ";
	in.getline(temp, 100);
	int x = 0;
	bool flag1 = false;
	while (flag1 == false)
	{
		if (c.s[x] == NULL)
		{
			flag1 = true;
		}
		x++;
	}
	c.length = x;
	c.s = temp;
	return in;
}
