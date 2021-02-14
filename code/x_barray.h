#pragma once
#include "x_exception.h"
#include <string>

namespace x
{
	// ********** barry **********
	// 二进制数组，unsigned char数组。长度最长为2147483647(2^31-1 or 0x7FFFFFFF)
	class barray
	{
	private:
		unsigned char *ba;
		int t;

	public:
		// ---------- 构造、析构函数 ----------
		barray() noexcept;
		barray(barray const& origin_barray);
		explicit barray(int const& array_length, unsigned char const& value = 0);  // 预设长度，默认设置为value的值
		~barray() noexcept;

		// ----- 数组初始化 -----
		barray(std::string const& origin_string);
		barray(char const* const origin_char, int const& origin_char_len);  // char数组初始化barray
		barray(unsigned char const* const origin_uchar, int const& origin_uchar_len);
		barray(bool const* const origin_bool, int const& origin_bool_len);  // bool数组初始化barray，bool数组中True对应1、False对应0，例如bool[3]=True，那么对应barray[3]=0x01。
		barray(short const* const origin_short, int const& origin_short_len);  // short数组初始化barray，short数组中每个short对应barray两个位置，例如short[3]=0xF0F1，那么对应barray[6]=0xF1、barray[7]=0xF0
		barray(unsigned short const* const origin_ushort, int const& origin_ushort_len);
		barray(int const* const origin_int, int const& origin_int_len);  // int数组初始化barray，int数组中每个int对应barray四个位置，例如int[3]=0xF0F1F2F3，那么对应barray[12]=0xF3、barray[13]=0xF2、barray[14]=0xF1、barray[15]=0xF0
		barray(unsigned int const* const origin_uint, int const& origin_uint_len);
		barray(long long const* const origin_long, int const& origin_long_len);    // long long数组初始化barray，long long数组中每个long long对应barray八个位置，例如long long[3]=0xF0F1F2F3F4F5F6F7，那么对应barray[24]=0xF7、barray[25]=0xF6、barray[26]=0xF5、barray[27]=0xF4、barray[28]=0xF3、barray[29]=0xF2、barray[30]=0xF1、barray[31]=0xF0
		barray(unsigned long long const* const origin_ulong, int const& origin_ulong_len);

		// ----- 单个数据类型初始化 -----
		barray(bool, char const& origin_char);
		barray(bool, unsigned char const& origin_uchar);
		barray(bool, bool const& origin_bool);
		barray(bool, short const& origin_short);
		barray(bool, unsigned short const& origin_ushort);
		barray(bool, int const& origin_int);
		barray(bool, unsigned int const& origin_uint);
		barray(bool, long long const& origin_long);
		barray(bool, unsigned long long const& origin_ulong);

		// ---------- 功能函数 ----------
		bool set_length(int const& array_length, unsigned char const& value = 0);  // 设置长度,默认设置为value的值
		int get_length() const noexcept;  // 获取长度
		void clear() noexcept;  // 清空

		// ---------- 重载运算符 ----------
		// ----- operator[]重载 -----
		unsigned char& operator[](int const & num) const; // 如果索引不在barray的范围内，throw出x::range_error 

		// ----- operator=重载 -----
		barray& operator=(barray const& right_barray);
		barray& operator=(char const& right_char);  // 把barray用一个char赋值，barray长度为1，参考用char数组初始化的构造函数
		barray& operator=(unsigned char const& right_uchar);
		barray& operator=(bool const& right_bool);  // 把barray用一个bool赋值，barray长度为1，参考用bool数组初始化的构造函数
		barray& operator=(short const& right_short);  // 把barray用一个short赋值，barray长度为2，参考用short数组初始化的构造函数
		barray& operator=(unsigned short const& right_ushort);
		barray& operator=(int const& right_int);  // 把barray用一个int赋值，barray长度为4，参考用int数组初始化的构造函数
		barray& operator=(unsigned int const& right_uint);
		barray& operator=(long long const& right_long);  // 把barray用一个long long赋值，barray长度为8，参考用long long数组初始化的构造函数
		barray& operator=(unsigned long long const& right_ulong);

		// ----- operator==重载 -----
		bool operator==(barray const& right_barray) const noexcept;
		bool operator==(char const& right_char) const noexcept;
		bool operator==(unsigned char const& right_uchar) const noexcept;
		bool operator==(bool const& right_bool) const noexcept;
		bool operator==(short const& right_short) const noexcept;
		bool operator==(unsigned short const& right_ushort) const noexcept;
		bool operator==(int const& right_int) const noexcept;
		bool operator==(unsigned int const& right_uint) const noexcept;
		bool operator==(long long const& right_long) const noexcept;
		bool operator==(unsigned long long const& right_ulong) const noexcept;

		// ----- operator!=重载 -----
		bool operator!=(barray const& right_barray) const noexcept;
		bool operator!=(char const& right_char) const noexcept;
		bool operator!=(unsigned char const& right_uchar) const noexcept;
		bool operator!=(bool const& right_bool) const noexcept;
		bool operator!=(short const& right_short) const noexcept;
		bool operator!=(unsigned short const& right_ushort) const noexcept;
		bool operator!=(int const& right_int) const noexcept;
		bool operator!=(unsigned int const& right_uint) const noexcept;
		bool operator!=(long long const& right_long) const noexcept;
		bool operator!=(unsigned long long const& right_ulong) const noexcept;

		// ----- operator+重载 -----
		barray operator+(barray const& right_barray) const;  // 若长度超过INT_MAX，只返回到INT_MAX的长度
		barray operator+(char const& right_char) const;  // barray往后加1个位置，且值为char，参考用char数组初始化的构造函数
		barray operator+(unsigned char const& right_uchar) const;
		barray operator+(bool const& right_bool) const;  // barray往后加1个位置，且值为0或1，参考用char数组初始化的构造函数
		barray operator+(short const& right_short) const;  // barray往后加2个位置，且值为short，参考用short数组初始化的构造函数
		barray operator+(unsigned short const& right_ushort) const;
		barray operator+(int const& right_int) const;  // barray往后加4个位置，且值为int，参考用int数组初始化的构造函数
		barray operator+(unsigned int const& right_uint) const;
		barray operator+(long long const& right_long) const;  // barray往后加8个位置，且值为long long，参考用long long数组初始化的构造函数
		barray operator+(unsigned long long const& right_ulong) const;
		
		// ----- operator+=重载 -----
		barray& operator+=(barray const& right_barray);
		barray& operator+=(char const& right_char);
		barray& operator+=(unsigned char const& right_uchar);
		barray& operator+=(bool const& right_bool);
		barray& operator+=(short const& right_short);
		barray& operator+=(unsigned short const& right_ushort);
		barray& operator+=(int const& right_int);
		barray& operator+=(unsigned int const& right_uint);
		barray& operator+=(long long const& right_long);
		barray& operator+=(unsigned long long const& right_ulong);

		// ----- operator*重载 -----
		barray operator*(int const& multiple) const;  // 若multiple<=0，返回空barray。若长度超过INT_MAX，保留长度在INT_MAX以内的数据
		friend barray operator*(int const& multiple, barray const& right_barray);

		// ----- operator*=重载 -----
		barray& operator*=(int const& multiple);  // 当multiple<=0时，barray长度为零

		// ----- operator/重载 -----
		barray operator/(int const& divisor) const;  // 若divisor<=0时，返回空barray。若长度超过INT_MAX，保留长度在INT_MAX以内的数据

		// ----- operator/=重载 -----
		barray& operator/=(int const& divisor);  // 当divisor<=0时，barray长度为零

		// ----- operator<<重载 -----
		barray operator<<(int const& offset) const;  // 当offset为正数的时候，则在索引0向后添加offset个值为0x00的字节；当offset为负数的时候，则在最大索引往前添加offset个值为0x00的字节。若barray的长度超过INT_MAX，则优先保存原barray的值，值为0x00的字节则补到长度为INT_MAX为止

		// ----- operator<<=重载 -----
		barray& operator<<=(int const& offset);

		// ----- operator>>重载 -----
		barray operator>>(int const& offset) const;  // 当offset为正数的时候，则在索引0向前删除offset个字节；当offset为负数的时候，则在最大索引向后删除offset个字节。offset的绝对值大于原barray的长度，则返回长度为0的barray

		// ----- operator>>=重载 -----
		barray& operator>>=(int const& offset);
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