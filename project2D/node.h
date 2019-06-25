#pragma once
#include <vector>
template <typename T>
class edge;

template <typename T>
class node
{
public:
	node<T>(const T& a_data) : m_data(a_data)
	{}
	~node()
	{}

	void add_edge(edge<T>* a_edge)
	{
		m_edges.push_back(a_edge);
	}


	void remove_edge(edge<T>* a_edge)
	{
		auto iter = std::find(m_edges.begin(), m_edges.end(), a_edge);
		m_edges.erase(iter);
	}

	std::vector<edge<T>*>& get_edges()
	{
		return m_edges;
	}
//private:
	std::vector<edge<T>*> m_edges;
	T m_data;
	node<T>* previous = nullptr;
	int gScore = 0;
	int fScore = 0;
	int hScore = 0;
	bool hasBeenSelected = false;
	bool avaliable = true;

	void reset()
	{
		previous = nullptr;
		gScore = 0;
		fScore = 0;
		hScore = 0;
	}
};

