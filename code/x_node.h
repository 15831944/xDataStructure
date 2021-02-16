#pragma once

#ifndef X_NODE_H
#define x_NODE_H

namespace x
{
	// ********** node **********
	// 节点。有两个指针
	template<class TYPE>
	class node
	{
	private:
		TYPE d;
		node<TYPE>* ln;
		node<TYPE>* rn;

	public:
		// ---------- 构造、析构函数 ----------
		node() noexcept;
		node(TYPE const& data, node<TYPE>* const left_node = 0x00, node<TYPE>* const right_node = 0x00) noexcept;
		~node() noexcept;

		// ---------- 功能函数 ----------
		node<TYPE>* get_left() const noexcept;
		node<TYPE>* get_right() const noexcept;
		TYPE get_data() const noexcept;
		void set_data(TYPE const& data) noexcept;
		void set_left(node<TYPE>* const left_node = 0x00) noexcept;
		void set_right(node<TYPE>* const right_node = 0x00) noexcept;
		bool is_equal(node<TYPE> const& other_node) const noexcept;  // 对数据和指针都进行判断
		void copy(node<TYPE> const& other_node) noexcept;  // 完全赋值，包括数据和指针

		// ---------- 重载运算符 ----------
		node<TYPE>& operator=(node<TYPE> const& right_node) noexcept;  // 只对数据进行赋值，不赋值指针
		node<TYPE>& operator=(TYPE const& right_data) noexcept;  //  对数据进行赋值
		bool operator==(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator==(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator==(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
		bool operator!=(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator!=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator!=(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
		bool operator>(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator>(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator>(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
		bool operator>=(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator>=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator>=(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
		bool operator<(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator<(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator<(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
		bool operator<=(node<TYPE> const& right_node) const noexcept;  // 只对数据进行判断
		bool operator<=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator<=(TYPE const& left_data, node<TYPE> const& right_node) noexcept;
	};










	// ********** node **********

	// ---------- 构造、析构函数 ----------
	template<class TYPE>
	node<TYPE>::node() noexcept :ln(0x00), rn(0x00)
	{}

	template<class TYPE>
	node<TYPE>::node(TYPE const& data, node<TYPE>* const left_node, node<TYPE>* const right_node) noexcept :d(data), ln(left_node), rn(right_node)
	{}

	template<class TYPE>
	node<TYPE>::~node() noexcept
	{
		ln = 0x00;
		rn = 0x00;
	}

	// ---------- 功能函数 ----------
	template<class TYPE>
	node<TYPE>* node<TYPE>::get_left() const noexcept
	{
		return ln;
	}

	template<class TYPE>
	node<TYPE>* node<TYPE>::get_right() const noexcept
	{
		return rn;
	}

	template<class TYPE>
	TYPE node<TYPE>::get_data() const noexcept
	{
		return d;
	}

	template<class TYPE>
	void node<TYPE>::set_data(TYPE const& data) noexcept
	{
		d = data;
	}

	template<class TYPE>
	void node<TYPE>::set_left(node<TYPE>* const left_node) noexcept
	{
		ln = left_node;
	}

	template<class TYPE>
	void node<TYPE>::set_right(node<TYPE>* const right_node) noexcept
	{
		rn = right_node;
	}


	template<class TYPE>
	bool node<TYPE>::is_equal(node<TYPE> const& other_node) const noexcept
	{
		if (d != other_node.d || ln != other_node.ln || rn != other_node.rn)
			return false;
		return true;
	}

	template<class TYPE>
	void node<TYPE>::copy(node<TYPE> const& other_node) noexcept
	{
		d = other_node.d;
		ln = other_node.ln;
		rn = other_node.rn;
	}

	// ---------- 重载运算符 ----------
	template<class TYPE>
	node<TYPE>& node<TYPE>::operator=(node<TYPE> const& right_node) noexcept
	{
		d = right_node.d;
		return *this;
	}

	template<class TYPE>
	node<TYPE>& node<TYPE>::operator=(TYPE const& right_data) noexcept
	{
		d = right_data;
		return *this;
	}

	template<class TYPE>
	bool node<TYPE>::operator==(node<TYPE> const& right_node) const noexcept
	{
		return d == right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator==(TYPE const& right_data) const noexcept
	{
		return d == right_data;
	}

	template<class TYPE>
	bool operator==(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data == right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator!=(node<TYPE> const& right_node) const noexcept
	{
		return d != right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator!=(TYPE const& right_data) const noexcept
	{
		return d != right_data;
	}

	template<class TYPE>
	bool operator!=(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data != right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator>(node<TYPE> const& right_node) const noexcept
	{
		return d > right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator>(TYPE const& right_data) const noexcept
	{
		return d > right_data;
	}

	template<class TYPE>
	bool operator>(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data > right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator>=(node<TYPE> const& right_node) const noexcept
	{
		return d >= right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator>=(TYPE const& right_data) const noexcept
	{
		return d >= right_data;
	}

	template<class TYPE>
	bool operator>=(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data >= right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator<(node<TYPE> const& right_node) const noexcept
	{
		return d < right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator<(TYPE const& right_data) const noexcept
	{
		return d < right_data;
	}

	template<class TYPE>
	bool operator<(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data < right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator<=(node<TYPE> const& right_node) const noexcept
	{
		return d <= right_node.d;
	}

	template<class TYPE>
	bool node<TYPE>::operator<=(TYPE const& right_data) const noexcept
	{
		return d <= right_data;
	}

	template<class TYPE>
	bool operator<=(TYPE const& left_data, node<TYPE> const& right_node) noexcept
	{
		return left_data <= right_node.d;
	}










	// ********** node_single **********
	// 节点。只有一个指针
	template<class TYPE>
	class node_single
	{
	private:
		TYPE d;
		node_single<TYPE>* nn;

	public:
		// ---------- 构造、析构函数 ----------
		node_single() noexcept;
		node_single(TYPE const& data, node_single<TYPE>* const next_node_single = 0x00) noexcept;
		~node_single() noexcept;

		// ----------功能函数----------
		node_single<TYPE>* get_next() const noexcept;
		TYPE get_data() const noexcept;
		void set_data(TYPE const& data) noexcept;
		void set_next(node_single<TYPE>* const next_node_single) noexcept;
		bool is_equal(node_single<TYPE> const& other_node_single) const noexcept;  // 对数据和指针都进行判断
		void copy(node_single<TYPE> const& other_node_single) noexcept;  // 完全赋值，包括数据和指针

		// ---------- 重载运算符 ----------
		node_single<TYPE>& operator=(node_single<TYPE> const& right_node_single) noexcept;  // 只对数据进行赋值，不赋值指针
		node_single<TYPE>& operator=(TYPE const& right_data) noexcept;  //  对数据进行赋值
		bool operator==(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator==(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator==(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
		bool operator!=(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator!=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator!=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
		bool operator>(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator>(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator>(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
		bool operator>=(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator>=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator>=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
		bool operator<(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator<(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator<(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
		bool operator<=(node_single<TYPE> const& right_node_single) const noexcept;  // 只对数据进行判断
		bool operator<=(TYPE const& right_data) const noexcept;
		template<class TYPE> friend bool operator<=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept;
	};










	// ********** node_single **********

	// ---------- 构造、析构函数 ----------
	template<class TYPE>
	node_single<TYPE>::node_single() noexcept :nn(0x00)
	{}

	template<class TYPE>
	node_single<TYPE>::node_single(TYPE const& data, node_single* const node_single) noexcept :d(data), nn(node_single)
	{}

	template<class TYPE>
	node_single<TYPE>::~node_single() noexcept
	{
		nn = 0x00;
	}


	// ----------功能函数----------
	template<class TYPE>
	node_single<TYPE>* node_single<TYPE>::get_next() const noexcept
	{
		return nn;
	}

	template<class TYPE>
	TYPE node_single<TYPE>::get_data() const noexcept
	{
		return d;
	}

	template<class TYPE>
	void node_single<TYPE>::set_data(TYPE const& data) noexcept
	{
		d = data;
	}

	template<class TYPE>
	void node_single<TYPE>::set_next(node_single* const next_node_single) noexcept
	{
		nn = next_node_single;
	}

	template<class TYPE>
	bool node_single<TYPE>::is_equal(node_single<TYPE> const& other_node_single) const noexcept
	{
		if (d != other_node_single.d || nn != other_node_single.nn)
			return false;
		return true;
	}

	template<class TYPE>
	void node_single<TYPE>::copy(node_single<TYPE> const& other_node_single) noexcept
	{
		d = other_node_single.d;
		nn = other_node_single.nn;
	}

	// ---------- 重载运算符 ----------
	template<class TYPE>
	node_single<TYPE>& node_single<TYPE>::operator=(node_single<TYPE> const& right_node_single) noexcept
	{
		d = right_node_single.d;
		return *this;
	}

	template<class TYPE>
	node_single<TYPE>& node_single<TYPE>::operator=(TYPE const& right_data) noexcept
	{
		d = right_data;
		return *this;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator==(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d == right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator==(TYPE const& right_data) const noexcept
	{
		return d == right_data;
	}

	template<class TYPE>
	bool operator==(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data == right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator!=(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d != right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator!=(TYPE const& right_data) const noexcept
	{
		return d != right_data;
	}

	template<class TYPE>
	bool operator!=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data != right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator>(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d > right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator>(TYPE const& right_data) const noexcept
	{
		return d > right_data;
	}

	template<class TYPE>
	bool operator>(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data > right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator>=(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d >= right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator>=(TYPE const& right_data) const noexcept
	{
		return d >= right_data;
	}

	template<class TYPE>
	bool operator>=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data >= right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator<(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d < right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator<(TYPE const& right_data) const noexcept
	{
		return d < right_data;
	}

	template<class TYPE>
	bool operator<(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data < right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator<=(node_single<TYPE> const& right_node_single) const noexcept
	{
		return d <= right_node_single.d;
	}

	template<class TYPE>
	bool node_single<TYPE>::operator<=(TYPE const& right_data) const noexcept
	{
		return d <= right_data;
	}

	template<class TYPE>
	bool operator<=(TYPE const& left_data, node_single<TYPE> const& right_node_single) noexcept
	{
		return left_data <= right_node_single.d;
	}
}

#endif