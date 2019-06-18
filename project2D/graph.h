#pragma once
#include <vector>
#include "node.h"
#include "edge.h"
#include <algorithm>

template <typename T>
class graph
{
public:
	graph<T>()
	{}

	~graph()
	{
		for (auto node : m_nodes)
			delete node;

		for (auto edges : m_edges)
			delete edges;
	}


	node<T>* createNode(const T&a_data)
	{
		node<T>* newNode = new node<T>(a_data);
		m_nodes.push_back(newNode);
		return newNode;
	}


	edge<T>* createEdge(node<T>* a_node_A, node<T>* a_node_B)
	{
		edge<T>* newEdge = new edge<T>(a_node_A, a_node_B);
		m_edges.push_back(newEdge);
		return newEdge;
	}

	void removeEdge(edge<T>* a_edge)
	{
		a_edge->m_nodes[0]->remove_edge(a_edge);
		a_edge->m_nodes[1]->remove_edge(a_edge);
		auto iter = std::find(m_edges.begin(), m_edges.end(), a_edge);
		delete *iter;
		m_edges.erase(iter);
	}

	void removeNode(node<T>* a_node)
	{
		while (a_node->m_edges.size() > 0)
		{
			removeEdge(a_node->m_edges.at(0));
		}

		/*for (auto edge : a_node->get_edges())
		{
			removeEdge(edge);
		}*/
		auto iter = std::find(m_nodes.begin(), m_nodes.end(), a_node);
		delete *iter;
		m_nodes.erase(iter);
	}


//private:

	std::vector<node<T>*>& calculatePath(node<T>* start, node<T>* end)
	{
		for (auto& a_node : m_nodes)
		{
			a_node->reset();
		}
		path.clear();

		if(!start || !end)
		{
			return path;
		}
		if (start == end)
		{
			path.push_back(start);
			return path;
		}
		std::list<node<T>*> openList;
		std::list<node<T>*> closedList;

		openList.push_back(start);
		node<T>* currentNode; 

			while (openList.size())
			{
				currentNode = openList.front();
				openList.pop_front();

				closedList.push_back(currentNode);

				for (auto& edge : currentNode->get_edges())
				{
					node<T>* otherNode = nullptr;
					
					if (edge->m_nodes[0] == currentNode)
					{
						otherNode = edge->m_nodes[1];
					}
					else
					{
						otherNode = edge->m_nodes[0];
					}
					// good above this------------------------------------
					if (std::find(std::begin(closedList), std::end(closedList), otherNode) == closedList.end())
					{
						int gScore = currentNode->gScore +1;

						if (std::find(std::begin(openList), std::end(openList), otherNode) == openList.end())
						{
							otherNode->gScore = currentNode->gScore;
							otherNode->previous = currentNode;
							openList.push_back(otherNode);
						}
						else if (currentNode->gScore < otherNode->gScore)
						{
							otherNode->gScore = currentNode->gScore;
							otherNode->previous = currentNode;
						}
					}
				}

			}

			node<T>* endNode = end;
			node<T>* pathTracer = end->previous;
			path.push_back(endNode);
			while (endNode != start)
			{
				pathTracer = endNode->previous;
				for (auto& edge : endNode->get_edges())
				{
					for (auto& Secondedge : pathTracer->get_edges())
					{
						if (edge == Secondedge)
						{
							edge->hasBeenTraced = true;
						}
					}
				}

				if (endNode->previous == nullptr)
				{
					break;
				}
				endNode = endNode->previous;
				path.push_back(endNode);

			}
			return path;
	}

	std::vector<node<T>*>& calculatePathAStar(node<T>* start, node<T>* end)
	{
		for (auto& a_node : m_nodes)
		{
			a_node->reset();
		}
		path.clear();

		if (!start || !end)
		{
			return path;
		}
		if (start == end)
		{
			path.push_back(start);
			return path;
		}

		heap openHeap;
		std::list<node<T>*> closedHeap;

		openHeap.add(start);
		node<T>* currentNode;

		while (openHeap.size())
		{
			currentNode = openHeap.pop();

			closedHeap.push_back(currentNode);

			for (auto& edge : currentNode->get_edges())
			{
				node<T>* otherNode = nullptr;

				if (edge->m_nodes[0] == currentNode)
				{
					otherNode = edge->m_nodes[1];
				}
				else
				{
					otherNode = edge->m_nodes[0];
				}
				
				if (std::find(std::begin(closedHeap), std::end(closedHeap), otherNode) == closedHeap.end())
				{
					int currentGScore = currentNode->gScore + 1;

					int fScore = currentNode->fScore + 1;
					int currentHeuristic = (int)(otherNode->m_data - end->m_data).magnitude();

					//if (std::find(std::begin(openHeap), std::end(openHeap), otherNode) == openHeap.end())
					if(openHeap.find(otherNode) == -1)
					{
						otherNode->gScore = currentGScore;
						otherNode->hScore = currentHeuristic;
						otherNode->fScore = currentGScore + currentHeuristic;

						otherNode->previous = currentNode;
						openHeap.add(otherNode);
					}
					else if (currentGScore + currentHeuristic < otherNode->fScore)
					{
						otherNode->gScore = currentNode->gScore;
						otherNode->previous = currentNode;
					}
				}
			}

		}

		node<T>* endNode = end;
		node<T>* pathTracer = end->previous;
		path.push_back(endNode);
		while (endNode != start)
		{
			pathTracer = endNode->previous;
			for (auto& edge : endNode->get_edges())
			{
				for (auto& Secondedge : pathTracer->get_edges())
				{
					if (edge == Secondedge)
					{
						edge->hasBeenTraced = true;
					}		
				}
			}

			endNode = endNode->previous;
			if (endNode->previous == nullptr)
			{
				break;
			}
			path.push_back(endNode);
			
		}
		return path;
	}

	std::vector<node<T>*> m_nodes;
	std::vector<edge<T>*> m_edges;
	std::vector<node<T>*> path;
};

