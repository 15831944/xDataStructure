#pragma once
#include"code.h"

namespace x
{
	// barry ���������飬unsigned char���飬�����Ϊ2147483647
	class barray
	{
	private:
		unsigned char *ba;
		int t;
		int status;
	public:
		barray();
		barray(const int& array_length, unsigned char value = 0);  // Ԥ�賤�ȣ�Ĭ������Ϊvalue��ֵ
		barray(const barray& origin_barray);
		~barray();

		bool set_length(const int& array_length, unsigned char value = 0);  // ���ó���,Ĭ������Ϊvalue��ֵ
		int get_length() const;  // ��ȡ����
		int get_status() const;  // ��ȡ״̬����


		// ----- ������������� ----- //
		unsigned char& operator[](const int& num) const;
		barray& operator=(const barray& right_barray);
		bool operator==(const barray& right_barray) const;
		bool operator!=(const barray& right_barray) const;
		barray operator+(const barray& right_barray) const;
		barray& operator+=(const barray& right_barray);
		barray operator*(const int& multiple) const;  // ��multiple<=0�����ؿ�barray
		barray& operator*=(const int& multiple);
		friend barray operator*(const int& multiple, const barray& right_barray);
		// ----- ������������� ----- //
	};

	// ********** ���µ�δ�������� ********** //
	// barry_long ���������飬unsigned char���飬�����Ϊ9223372036854775807
	class barray_long
	{
	private:
		unsigned char *ba;
		long long t;
		int status;
	public:
		barray_long();
		barray_long(const long long& array_length, unsigned char value = 0);  // Ԥ�賤�ȣ�Ĭ������Ϊvalue��ֵ
		barray_long(const barray_long& origin_barray);
		barray_long(const barray& origin_barray);
		~barray_long();

		bool set_length(const long long& array_length, unsigned char value = 0);  // ���ó���,Ĭ������Ϊvalue��ֵ
		long long get_length() const;  // ��ȡ����
		int get_status() const;  // ��ȡ״̬����


		// ----- ������������� ----- //
		unsigned char& operator[](const long long& num) const;
		barray_long& operator=(const barray_long& right_barray);
		bool operator==(const barray_long& right_barray) const;
		bool operator!=(const barray_long& right_barray) const;
		barray_long operator+(const barray_long& right_barray) const;
		barray_long& operator+=(const barray_long& right_barray);
		barray_long operator*(const int& multiple) const;  // ��multiple<=0�����ؿ�barray
		barray_long& operator*=(const int& multiple);
		friend barray_long operator*(const int& multiple, const barray_long& right_barray);
		// ----- ������������� ----- //
	};
}