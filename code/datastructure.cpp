#include"datastructure.h"

x::barray::barray()
{
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

x::barray::barray(const int& array_length,unsigned char value)
{
	if (array_length <= 0)
	{
		ba = 0x00;
		t = 0;
		status = code::INIT;
		return;
	}
	t = array_length;
	ba = new unsigned char[t];
	for (int i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
}

x::barray::barray(const barray& origin_barray)
{
	if (origin_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return;
	}
	t = origin_barray.t;
	ba = new unsigned char[t];
	status = code::NORMAL;
	for (int i = 0; i < t; ++i)
		ba[i] = origin_barray.ba[i];
}

x::barray::~barray()
{
	if (t > 0)
		delete[]ba;
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

bool x::barray::set_length(const int& array_length, unsigned char value)
{
	if (array_length < 0)
		return false;
	if (t == array_length)
		return true;
	else if (t == 0)
	{
		t = array_length;
		ba = new unsigned char[t];
		for (int i = 0; i < t; ++i)
			ba[i] = value;
		status = code::NORMAL;
		return true;
	}
	else if (array_length == 0)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return true;
	}
	delete[]ba;
	t = array_length;
	ba = new unsigned char[t];
	for (int i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
	return true;
}

int x::barray::get_length() const
{
	return t;
}

int x::barray::get_status() const
{
	return status;
}

unsigned char& x::barray::operator[](const int& num) const
{
	return ba[num];
}

x::barray& x::barray::operator=(const x::barray& right_barray)
{
	if (t != 0 && t != right_barray.t)
		delete[]ba;
	if (right_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return *this;
	}
	t = right_barray.t;
	ba = new unsigned char[t];
	for (int i = 0; i < t; ++i)
		ba[i] = right_barray.ba[i];
	status = code::NORMAL;
	return *this;
}

bool x::barray::operator==(const x::barray& right_barray) const
{
	if (t != right_barray.t)
		return false;
	if (t == 0)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return false;
	return true;
}

bool x::barray::operator!=(const x::barray& right_barray) const
{
	if (t != right_barray.t)
		return true;
	if (t == 0)
		return true;
	for (int i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return true;
	return false;
}

x::barray x::barray::operator+(const x::barray& right_barray) const
{
	if (t == 0)
		return right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a;
	a.t = t + right_barray.t;
	a.ba = new unsigned char[a.t];
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i - t];
	a.status = code::NORMAL;
	return a;
}

x::barray& x::barray::operator+=(const x::barray& right_barray)
{
	if (t == 0)
		return *this = right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a = *this;
	t = a.t + right_barray.t;
	delete[]ba;
	ba = new unsigned char[t];
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_barray.ba[i - a.t];
	return *this;
}

x::barray x::barray::operator*(const int& multiple) const
{
	if (t == 0)
		return *this;
	barray a;
	a.t = multiple * t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = ba[i%t];
	return a;
}

x::barray& x::barray::operator*=(const int& multiple)
{
	if (t == 0)
		return *this;
	barray a = *this;
	t = multiple * a.t;
	ba = new unsigned char[t];
	for (int i = 0; i < t; ++i)
		ba[i] = a.ba[i%a.t];
	return *this;
}

x::barray x::operator*(const int& multiple, const x::barray& right_barray)
{
	if (right_barray.t == 0)
		return right_barray;
	barray a;
	a.t = multiple * right_barray.t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}


// ********** 以下的未经过测试 ********** //

x::barray_long::barray_long()
{
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

x::barray_long::barray_long(const long long& array_length, unsigned char value)
{
	if (array_length <= 0)
	{
		ba = 0x00;
		t = 0;
		status = code::INIT;
		return;
	}
	t = array_length;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
}

x::barray_long::barray_long(const barray_long& origin_barray)
{
	if (origin_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return;
	}
	t = origin_barray.t;
	ba = new unsigned char[t];
	status = code::NORMAL;
	for (long long i = 0; i < t; ++i)
		ba[i] = origin_barray.ba[i];
}

x::barray_long::barray_long(const barray& origin_barray)
{
	if (origin_barray.get_length() == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return;
	}
	t = origin_barray.get_length();
	ba = new unsigned char[t];
	status = code::NORMAL;
	for (long long i = 0; i < t; ++i)
		ba[i] = origin_barray[i];
}

x::barray_long::~barray_long()
{
	if (t > 0)
		delete[]ba;
	ba = 0x00;
	t = 0;
	status = code::INIT;
}

bool x::barray_long::set_length(const long long& array_length, unsigned char value)
{
	if (array_length < 0)
		return false;
	if (t == array_length)
		return true;
	else if (t == 0)
	{
		t = array_length;
		ba = new unsigned char[t];
		for (long long i = 0; i < t; ++i)
			ba[i] = value;
		status = code::NORMAL;
		return true;
	}
	else if (array_length == 0)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return true;
	}
	delete[]ba;
	t = array_length;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = value;
	status = code::NORMAL;
	return true;
}

long long x::barray_long::get_length() const
{
	return t;
}

int x::barray_long::get_status() const
{
	return status;
}

unsigned char& x::barray_long::operator[](const long long& num) const
{
	return ba[num];
}

x::barray_long& x::barray_long::operator=(const x::barray_long& right_barray)
{
	if (t != 0 && t != right_barray.t)
		delete[]ba;
	if (right_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		status = code::INIT;
		return *this;
	}
	t = right_barray.t;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = right_barray.ba[i];
	status = code::NORMAL;
	return *this;
}

bool x::barray_long::operator==(const x::barray_long& right_barray) const
{
	if (t != right_barray.t)
		return false;
	if (t == 0)
		return true;
	for (long long i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return false;
	return true;
}

bool x::barray_long::operator!=(const x::barray_long& right_barray) const
{
	if (t != right_barray.t)
		return true;
	if (t == 0)
		return true;
	for (long long i = 0; i < t; ++i)
		if (ba[i] != right_barray.ba[i])
			return true;
	return false;
}

x::barray_long x::barray_long::operator+(const x::barray_long& right_barray) const
{
	if (t == 0)
		return right_barray;
	if (right_barray.t == 0)
		return *this;
	barray_long a;
	a.t = t + right_barray.t;
	a.ba = new unsigned char[a.t];
	long long i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i - t];
	a.status = code::NORMAL;
	return a;
}

x::barray_long& x::barray_long::operator+=(const x::barray_long& right_barray)
{
	if (t == 0)
		return *this = right_barray;
	if (right_barray.t == 0)
		return *this;
	barray_long a = *this;
	t = a.t + right_barray.t;
	delete[]ba;
	ba = new unsigned char[t];
	long long i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_barray.ba[i - a.t];
	return *this;
}

x::barray_long x::barray_long::operator*(const int& multiple) const
{
	if (t == 0)
		return *this;
	barray_long a;
	a.t = multiple * t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (long long i = 0; i < a.t; ++i)
		a.ba[i] = ba[i%t];
	return a;
}

x::barray_long& x::barray_long::operator*=(const int& multiple)
{
	if (t == 0)
		return *this;
	barray_long a = *this;
	t = multiple * a.t;
	ba = new unsigned char[t];
	for (long long i = 0; i < t; ++i)
		ba[i] = a.ba[i%a.t];
	return *this;
}

x::barray_long x::operator*(const int& multiple, const x::barray_long& right_barray)
{
	if (right_barray.t == 0)
		return right_barray;
	barray_long a;
	a.t = multiple * right_barray.t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (long long i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}







