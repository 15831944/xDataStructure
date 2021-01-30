#pragma once
#ifndef XDATASTRUCTURE_H
#define XDATASTRUCTURE_H

#include"code.h"

namespace x
{

	// ---------- 以下尚未经过测试 ---------- //

	// barry 二进制数组，unsigned char数组
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
		bool set_length(int array_length);  // 设置长度
		int get_length();  // 获取长度
		int get_status();  // 获取状态代码

		// ----- 以下重载运算符 ----- //
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
		// ----- 结束重载运算符 ----- //
	};

	template<class T>
	class node
	{
	private :
		T d;
		node* ln, rn;
	public:
		node();
		node(const T& data);
		~node();
		node* get_left();
		node* get_right();
		T get_data();
	};

	template<class T>
	class snode
	{
	private:
		T d;
		snode<T>* rn;
	public:
		snode();
		snode(const T& data);
		~snode();
		snode* next();
		T get_data();
	};

	template<class T>
	class stack
	{
	private:
		int len;
		snode<T>* p;
	public:
		stack();
		~stack();
		T get_point();
		bool pop();
		bool push(T data);
		int length();
	};


}

#endif