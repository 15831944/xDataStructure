#pragma once
#ifndef XDATASTRUCTURE_H
#define XDATASTRUCTURE_H

#include"code.h"

namespace x
{
	class barray
	{
	private:
		unsigned char *ba;
		int t;
		int status;
	public:
		barray();
		barray(int array_length);
		barray(const barray& origin_barray);
		~barray();
		bool set_length(int array_length);
		int length();
		unsigned char& operator[](const int& num);
		barray& operator=(const barray& right_barray);
		bool operator==(const barray& right_barray);
		bool operator!=(const barray& right_barray);
		barray operator+(const barray& right_barray);
		barray& operator+=(const barray& right_barray);
		barray operator*(const int& multiple);
		barray& operator*=(const int& multiple);
		friend barray operator*(const int& multiple, const barray& right_barray);
		friend barray operator*=(const int& multiple, barray& right_barray);
	};
}

#endif