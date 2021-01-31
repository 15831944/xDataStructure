#pragma once
#ifndef XDATASTRUCTURE_H
#define XDATASTRUCTURE_H

#include"code.h"

namespace x
{
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

		bool set_length(const int& array_length, unsigned char value = 0);  // 设置长度,默认设置为value的值
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
		// ----- 结束重载运算符 ----- //
	};

	// ********** 以下的未经过测试 ********** //
	// node 节点 有两个指针
	template<class T>
	class node
	{
	private :
		T data;
		node* ln, rn;
	public:
		node();
		node(const T& data, const node* const left_node = 0x00, const node* const right_node = 0x00);
		~node();

		node* get_left();
		node* get_right();
		T get_data();

		void set_data(const T& data);
		void set_left(const node* const left_node = 0x00);
		void set_right(const node* const right_node = 0x00);
	};

	// ---------- 开始 node 实现 ---------- //
	template<class T>
	node<T>::node()
	{
		ln = 0x00;
		rn = 0x00;
	}

	template<class T>
	node<T>::node(const T& data, const node* const left_node, const node* const right_node)
	{
		d = data;
		ln = left_node;
		rn = right_node;
	}

	template<class T>
	node<T>::~node()
	{
		ln = 0x00;
		rn = 0x00;
	}

	template<class T>
	node<T>* node<T>::get_left()
	{
		return ln;
	}

	template<class T>
	node<T>* node<T>::get_right()
	{
		return rn;
	}

	template<class T>
	T node<T>::get_data()
	{
		return data;
	}

	template<class T>
	void node<T>::set_data(const T& data)
	{
		d = data;
	}

	template<class T>
	void node<T>::set_left(const node* const left_node)
	{
		ln = left_node;
	}

	template<class T>
	void node<T>::set_right(const node* const right_node)
	{
		rn = right_node;
	}

	// ---------- 结束 node 实现 ---------- //

	// snode 节点 只有一个指针
	template<class T>
	class snode
	{
	private:
		T d;
		snode<T>* rn;
	public:
		snode();
		snode(const T& data, const snode* const next_snode = 0x00);
		~snode();

		snode* get_next();
		T get_data();

		void set_data(const T& data);
		void set_nextsnode(const snode* const next_snode);
	};

	// ---------- 开始 snode 实现 ---------- //

	template<class T>
	snode<T>::snode()
	{
		rn = 0x00;
	}

	template<class T>
	snode<T>::snode(const T& data, const snode* const next_snode)
	{
		d = data;
		rn = next_snode;
	}

	template<class T>
	snode<T>::~snode()
	{
		rn = 0x00;
	}

	template<class T>
	snode<T>* snode<T>::get_next()
	{
		return rn;
	}

	template<class T>
	T snode<T>::get_data()
	{
		return d;
	}

	template<class T>
	void snode<T>::set_data(const T& data)
	{
		d = data;
	}

	template<class T>
	void snode<T>::set_nextsnode(const snode* const next_snode)
	{
		rn = next_snode;
	}

	// ---------- 结束 snode 实现 ---------- //

	// stack 栈
	template<class T>
	class stack
	{
	private:
		int len;
		int status;
		snode<T>* p;
	public:
		stack();
		~stack();

		T get_data();
		int get_length();
		bool pop();
		void push(const T& data);
	};

	// ---------- 开始 stack 实现 ---------- //

	template<class T>
	stack<T>::stack()
	{
		p = 0x00;
		len = 0;
		status = code::INIT;
	}

	template<class T>
	stack<T>::~stack()
	{
		snode<T>* n;
		while (p != 0x00)
		{
			n = p->get_next();
			delete[]p;
			p = n;
		}
		len = 0;
	}

	template<class T>
	T stack<T>::get_data()
	{
		return p->get_data();
	}

	template<class T>
	int stack<T>::get_length()
	{
		return len;
	}

	template<class T>
	bool stack<T>::pop()
	{
		if (len == 0)
			return false;
		snode<T>* n = p->get_next();
		delete p;
		p = n;
		--len;
		if (len == 0)
			status = code::INIT;
		return true;
	}

	template<class T>
	void stack<T>::push(const T& data)
	{
		if (len == 0)
		{
			p = new snode<T>(data);
			len = 1;
			status = code::NORMAL;
		}
		snode<T>*n = new snode<T>(data,p);
		p = n;
		++len;
	}

	// ---------- 结束 stack 实现 ---------- //



}

#endif