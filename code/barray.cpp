#include"barray.h"

x::barray::barray() noexcept :ba(0x00), t(0)
{}

x::barray::barray(int const& array_length, unsigned char const& value)
{
	if (array_length <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = array_length;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = value;
}

x::barray::barray(barray const& origin_barray)
{
	if (origin_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		return;
	}
	t = origin_barray.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_barray.ba[i];
}

x::barray::barray(std::string const& origin_string)
{
	if (origin_string.length() == 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_string.length() > INT_MAX)
		t = INT_MAX;
	else
		t = origin_string.length();
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_string[i];
}

x::barray::barray(char const* const origin_char, int const& origin_char_len)
{
	if (origin_char_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = origin_char_len;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_char[i];
}

x::barray::barray(unsigned char const* const origin_uchar, int const& origin_uchar_len)
{
	if (origin_uchar_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	t = origin_uchar_len;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = origin_uchar[i];
}

x::barray::barray(short const* const origin_short, int const& origin_short_len)
{
	if (origin_short_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_short_len > INT_MAX / 2)
		t = INT_MAX - 1;
	else
		t = origin_short_len * 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 2; ++i)
		for (j = 0; j < 2; ++j)
			ba[i * 2 + j] = origin_short[i] >> j * 8;
}

x::barray::barray(unsigned short const* const origin_ushort, int const& origin_ushort_len)
{
	if (origin_ushort_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_ushort_len > INT_MAX / 2)
		t = INT_MAX - 1;
	else
		t = origin_ushort_len * 2;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 2; ++i)
		for (j = 0; j < 2; ++j)
			ba[i * 2 + j] = origin_ushort[i] >> j * 8;
}

x::barray::barray(int const* const origin_int, int const& origin_int_len)
{
	if (origin_int_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_int_len > INT_MAX / 4)
		t = INT_MAX - 3;
	else
		t = origin_int_len * 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 4; ++i)
		for (j = 0; j < 4; ++j)
			ba[i * 4 + j] = origin_int[i] >> j * 8;
}

x::barray::barray(unsigned int const* const origin_uint, int const& origin_uint_len)
{
	if (origin_uint_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_uint_len > INT_MAX / 4)
		t = INT_MAX - 3;
	else
		t = origin_uint_len * 4;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 4; ++i)
		for (j = 0; j < 4; ++j)
			ba[i * 4 + j] = origin_uint[i] >> j * 8;
}

x::barray::barray(long long const* const origin_long, int const& origin_long_len)
{
	if (origin_long_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_long_len > INT_MAX / 8)
		t = INT_MAX - 7;
	else
		t = origin_long_len * 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 8; ++i)
		for (j = 0; j < 4; ++j)
			ba[i * 4 + j] = origin_long[i] >> j * 8;
}

x::barray::barray(unsigned long long const* const origin_ulong, int const& origin_ulong_len)
{
	if (origin_ulong_len <= 0)
	{
		ba = 0x00;
		t = 0;
		return;
	}
	if (origin_ulong_len > INT_MAX / 8)
		t = INT_MAX - 7;
	else
		t = origin_ulong_len * 8;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i, j;
	for (i = 0; i < t / 8; ++i)
		for (j = 0; j < 4; ++j)
			ba[i * 4 + j] = origin_ulong[i] >> j * 8;
}

x::barray::~barray()
{
	if (t > 0)
		delete[]ba;
	ba = 0x00;
	t = 0;
}

bool x::barray::set_length(int const& array_length, unsigned char const& value)
{
	if (array_length < 0)
		return false;
	if (t == array_length)
		return true;
	else if (t == 0)
	{
		t = array_length;
		try
		{
			ba = new unsigned char[t];
		}
		catch (std::exception& e)
		{
			t = 0;
			ba = 0x00;
			throw(e);
		}
		for (int i = 0; i < t; ++i)
			ba[i] = value;
		return true;
	}
	else if (array_length == 0)
	{
		delete[]ba;
		t = 0;
		ba = 0x00;
		return true;
	}
	delete[]ba;
	t = array_length;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = value;
	return true;
}

int x::barray::get_length() const noexcept
{
	return t;
}

unsigned char& x::barray::operator[](int const& num) const
{
	if (num < 0 || num >= t)
		throw(range_error("Index out of range!"));
	return ba[num];
}

x::barray& x::barray::operator=(x::barray const& right_barray)
{
	if (this == &right_barray)
		return *this;
	if (t != 0 && t != right_barray.t)
		delete[]ba;
	if (right_barray.t == 0)
	{
		t = 0;
		ba = 0x00;
		return *this;
	}
	t = right_barray.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = right_barray.ba[i];
	return *this;
}

bool x::barray::operator==(x::barray const& right_barray) const noexcept
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

bool x::barray::operator!=(x::barray const& right_barray) const noexcept
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

x::barray x::barray::operator+(x::barray const& right_barray) const
{
	if (t == 0)
		return right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a;
	if (right_barray.t > INT_MAX - t)
		a.t = INT_MAX;
	else
		a.t = t + right_barray.t;
	try 
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < t; ++i)
		a.ba[i] = ba[i];
	for (i; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i - t];
	return a;
}

x::barray& x::barray::operator+=(x::barray const& right_barray)
{
	if (t == 0)
		return *this = right_barray;
	if (right_barray.t == 0)
		return *this;
	barray a = *this;
	if (this == &right_barray)
	{
		delete[]ba;
		if (a.t > INT_MAX / 2)
			t = INT_MAX;
		else
			t = 2 * a.t;
		try
		{
			ba = new unsigned char[t];
		}
		catch (std::exception& e)
		{
			t = 0;
			ba = 0x00;
			throw(e);
		}
		for (int i = 0; i < t; ++i)
			ba[i] = a.ba[i%a.t];
		return *this;
	}
	delete[]ba;
	if (a.t > INT_MAX - right_barray.t)
		t = INT_MAX;
	else
		t = a.t + right_barray.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	int i;
	for (i = 0; i < a.t; ++i)
		ba[i] = a.ba[i];
	for (i; i < t; ++i)
		ba[i] = right_barray.ba[i - a.t];
	return *this;
}

x::barray x::barray::operator*(int const& multiple) const
{
	if (t == 0)
		return *this;
	barray a;
	if (multiple <= 0)
		return a;
	if (t > INT_MAX / multiple)
		a.t = INT_MAX;
	else
		a.t = multiple * t;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = ba[i%t];
	return a;
}

x::barray& x::barray::operator*=(const int& multiple)
{
	if (t == 0)
		return *this;
	if (multiple <= 0)
	{
		delete[]ba;
		t = 0;
		return *this;
	}
	barray a = *this;
	delete[]ba;
	if (a.t > INT_MAX / multiple)
		t = INT_MAX;
	else
		t = multiple * a.t;
	try
	{
		ba = new unsigned char[t];
	}
	catch (std::exception& e)
	{
		t = 0;
		ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < t; ++i)
		ba[i] = a.ba[i%a.t];
	return *this;
}

x::barray x::operator*(const int& multiple, const x::barray& right_barray)
{
	if (right_barray.t == 0)
		return right_barray;
	barray a;
	if (multiple <= 0)
		return a;
	if (right_barray.t > INT_MAX / multiple)
		a.t = INT_MAX;
	else
		a.t = multiple * right_barray.t;
	try
	{
		a.ba = new unsigned char[a.t];
	}
	catch (std::exception& e)
	{
		a.t = 0;
		a.ba = 0x00;
		throw(e);
	}
	for (int i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}










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
	if (multiple <= 0)
		return a;
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
	if (multiple <= 0)
	{
		delete[]ba;
		t = 0;
		status = code::INIT;
		return *this;
	}
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
	if (multiple <= 0)
		return a;
	a.t = multiple * right_barray.t;
	a.ba = new unsigned char[a.t];
	a.status = code::NORMAL;
	for (long long i = 0; i < a.t; ++i)
		a.ba[i] = right_barray.ba[i%right_barray.t];
	return a;
}