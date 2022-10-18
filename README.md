# Graphs
A C++ implementation of graph data structure and algorithms.

#  Goal
Create easy to use infrastructure
for solving various problems that can be translated to Graph problem.


#  Current
At the moment, the project consists of a basic graph implementation and example use-case.
The graph is templated by the data type the nodes are expected to hold. <br>
Constructor - takes a vector of the chosen data type and a link function. <br>
For each item in the vector, a node with the item as data would be created. <br>
The nodes are linked using the link func: for each pair of data items, the func 
should return a boolean: true- if the nodes should be linked, false - otherwise.  

#  Example use case
The example problem is: given a list of words, and assuming that a step from one word to another<br>
can be made only when the two words differ only in one letter,<br> find the length of the shortest path from word A to word B.
In the example, the problem is solved by translating it to the corresponding graph and running a BFS algorithm.
