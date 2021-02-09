#pragma once
#include"code.h"

namespace x
{
	// barry 二进制数组，unsigned char数组，长度最长为2147483647
	class barray
	{
	private:
		unsigned char *ba;
		int t;
		int status;
	public:
		barray();
		barray(const int& array_length, unsigned char value = 0);  // 预设长度，默认设置为value的值
		barray(const barray& origin_barray);
		~barray();

		bool set_length(const int& array_length, unsigned char value = 0);  // 设置长度,默认设置为value的值
		int get_length() const;  // 获取长度
		int get_status() const;  // 获取状态代码


		// ----- 以下重载运算符 ----- //
		unsigned char& operator[](const int& num) const;
		barray& operator=(const barray& right_barray);
		bool operator==(const barray& right_barray) const;
		bool operator!=(const barray& right_barray) const;
		barray operator+(const barray& right_barray) const;
		barray& operator+=(const barray& right_barray);
		barray operator*(const int& multiple) const;  // 若multiple<=0，返回空barray
		barray& operator*=(const int& multiple);
		friend barray operator*(const int& multiple, const barray& right_barray);
		// ----- 结束重载运算符 ----- //
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