#pragma once
#include "x_node.h"

namespace x
{
	// ********** 以下的未经过测试 ********** //
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

		T get_data() const;
		int get_length() const;
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
	T stack<T>::get_data() const
	{
		return p->get_data();
	}

	template<class T>
	int stack<T>::get_length() const
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
		snode<T>*n = new snode<T>(data, p);
		p = n;
		++len;
	}

	// ---------- 结束 stack 实现 ---------- //
}