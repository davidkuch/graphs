#include <iostream>
#include <vector>
#include <string>

#include "graph.hpp"


static bool isOneLetterDif(const std::string& first,const std::string& second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    int counter = 0;

    for (int i = 0; i < first.size(); ++i)
    {
        if (first[i] != second[i])
        {
            counter++;
        }

    }

    return counter == 1;
}


int main()
{
    std::vector<std::string> word_list = {"ops","top", "pop", "sok", "def","sed","wok","wow","dow"};

    graph::Graph<std::string> graph(word_list, &isOneLetterDif);


   std::cout << "pathlen: " << graph.getPathLen("sok", "dow");
  // std::cout << "pathlen: " << graph.getPathLen("pop", "dow");





    return 0;
}