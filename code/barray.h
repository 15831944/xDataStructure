#pragma once
#include "exception.h"
#include <string>

namespace x
{
	// barry 二进制数组，unsigned char数组，长度最长为2147483647
	class barray
	{
	private:
		unsigned char *ba;
		long long t;

	public:
		// 构造函数，拷贝构造函数，析构函数
		barray() noexcept;
		explicit barray(int const& array_length, unsigned char const& value = 0);  // 预设长度，默认设置为value的值
		barray(barray const& origin_barray);
		barray(std::string const& origin_string);
		barray(char const* const origin_char, int const& origin_char_len);
		barray(unsigned char const* const origin_uchar, int const& origin_uchar_len);
		barray(short const* const origin_short, int const& origin_short_len);
		barray(unsigned short const* const origin_ushort, int const& origin_ushort_len);
		barray(int const* const origin_int, int const& origin_int_len);
		barray(unsigned int const* const origin_uint, int const& origin_uint_len);
		barray(long long const* const origin_long, int const& origin_long_len);
		barray(unsigned long long const* const origin_ulong, int const& origin_ulong_len);
		~barray() noexcept;

		// 功能函数
		bool set_length(int const& array_length, unsigned char const& value = 0);  // 设置长度,默认设置为value的值
		int get_length() const noexcept;  // 获取长度

		// 运算符重载
		unsigned char& operator[](int const & num) const;
		barray& operator=(barray const& right_barray);
		bool operator==(barray const& right_barray) const noexcept;
		bool operator!=(barray const& right_barray) const noexcept;
		barray operator+(barray const& right_barray) const;
		barray& operator+=(barray const& right_barray);
		barray operator*(int const& multiple) const;  // 若multiple<=0，返回空barray
		barray& operator*=(int const& multiple);
		friend barray operator*(int const& multiple, const barray& right_barray);
	};

	// ********** 以下的未经过测试 ********** //
	// barry_long 二进制数组，unsigned char数组，长度最长为9223372036854775807
	class barray_long
	{
	private:
		unsigned char *ba;
		long long t;
		int status;
	public:
		barray_long();
		barray_long(const long long& array_length, unsigned char value = 0);  // 预设长度，默认设置为value的值
		barray_long(const barray_long& origin_barray);
		barray_long(const barray& origin_barray);
		~barray_long();

		bool set_length(const long long& array_length, unsigned char value = 0);  // 设置长度,默认设置为value的值
		long long get_length() const;  // 获取长度
		int get_status() const;  // 获取状态代码


		// ----- 以下重载运算符 ----- //
		unsigned char& operator[](const long long& num) const;
		barray_long& operator=(const barray_long& right_barray);
		bool operator==(const barray_long& right_barray) const;
		bool operator!=(const barray_long& right_barray) const;
		barray_long operator+(const barray_long& right_barray) const;
		barray_long& operator+=(const barray_long& right_barray);
		barray_long operator*(const int& multiple) const;  // 若multiple<=0，返回空barray
		barray_long& operator*=(const int& multiple);
		friend barray_long operator*(const int& multiple, const barray_long& right_barray);
		// ----- 结束重载运算符 ----- //
	};
}