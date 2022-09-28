#include <string>
#include <vector>
#include <queue>

namespace graph
{


template <typename T>
class Graph
{
public:
    explicit Graph(std::vector<T> data_list, bool (*linkFunc)(const T&,const T&));
    ~Graph();
    int getPathLen(T start, T end);


private:
    class Node
    {
        public:
            Node(T data)
            {
                this->data = data;
                mark = false;
                level = -1;
            }

            T data;
            bool mark;
            int level;
            std::vector<Node*> edges;
    };

    std::vector<Node*> nodes;
    bool (*linkFunc)(const T&,const T&);
    
    Node* findNode(T data);

    Graph(const Graph& other); // cctor blocked
    Graph& operator=(const Graph& other); // copy= blocked

};



template <typename T>
typename Graph<T>::Node* Graph<T>::findNode(T data)
{
    typename std::vector<Graph::Node*>::iterator it = nodes.begin();
    
    for (; it != nodes.end(); ++it)
    {
        if ((**it).data == data)
        {
            return *it;
        }
    }

    return nullptr;
}


template <typename T>
Graph<T>::Graph(std::vector<T> data_list, bool (*linkFunc_)(const T&,const T&))
{
    this->linkFunc = linkFunc_;
    
    //init nodes vector
    for (typename std::vector<T>::iterator it = data_list.begin(); it != data_list.end(); ++it)
    {
        Graph::Node* node = new Graph::Node(*it);
        nodes.push_back(node);
    }


   // init edges
   for (typename std::vector<Graph::Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
   {
       
       for (typename std::vector<Graph::Node*>::iterator other = nodes.begin(); other != nodes.end(); ++other)
       {
           if (linkFunc((**it).data,(**other).data))
           {
               (**it).edges.push_back(*other);
           }
       }
   }

}


template <typename T>
Graph<T>::~Graph()
{
    typename std::vector<Node*>::iterator it = nodes.begin();
    typename std::vector<Node*>::iterator end = nodes.end();

    for (; it != end; ++it)
    {
        delete (*it);
    }
}


//assume start and end data are in word list
template <typename T>
int Graph<T>::getPathLen(T start, T end)
{
    std::queue<Graph::Node*> explored;

    Node* start_node = findNode(start);

    explored.push(start_node);
    start_node->mark = true;
    start_node->level = 0;

    while (explored.empty() == false)
    {
        Node* curr = explored.front();
        explored.pop();

        for (typename std::vector<Node*>::iterator it = curr->edges.begin(); it != curr->edges.end(); ++it)
        {
            explored.push(*it);
            (*it)->mark = true;

            (*it)->level = curr->level + 1;

            if ((*it)->data == end)
            {
                return (*it)->level;
            }
            
        }

    }
    
    // err status return: no path present
    return -1;
}



}//namespace graph