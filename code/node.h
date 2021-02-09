#pragma once

namespace x
{
	// ********** ���µ�δ�������� ********** //
	// node �ڵ� ������ָ��
	template<class T>
	class node
	{
	private:
		T d;
		node* ln, rn;
	public:
		node();
		node(const T& data, const node* const left_node = 0x00, const node* const right_node = 0x00);
		~node();

		node* get_left() const;
		node* get_right() const;
		T get_data() const;

		void set_data(const T& data);
		void set_left(const node* const left_node = 0x00);
		void set_right(const node* const right_node = 0x00);
	};










	// ---------- ��ʼ node ʵ�� ---------- //
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
	node<T>* node<T>::get_left() const
	{
		return ln;
	}

	template<class T>
	node<T>* node<T>::get_right() const
	{
		return rn;
	}

	template<class T>
	T node<T>::get_data() const
	{
		return d;
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

	// ---------- ���� node ʵ�� ---------- //










	// snode �ڵ� ֻ��һ��ָ��
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

		snode* get_next() const;
		T get_data() const;

		void set_data(const T& data);
		void set_nextsnode(const snode* const next_snode);
	};










	// ---------- ��ʼ snode ʵ�� ---------- //

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
	snode<T>* snode<T>::get_next() const
	{
		return rn;
	}

	template<class T>
	T snode<T>::get_data() const
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

	// ---------- ���� snode ʵ�� ---------- //
}
