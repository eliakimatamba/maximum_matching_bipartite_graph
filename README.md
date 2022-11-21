# maximum_matching_bipartite_graph
The code is a function that takes in two parameters, s and t. It then creates a vector of vectors called residual which is the result of bfs(s,t).
The function then iterates through each element in the residual vector to find the maximum flow from one end to another.
The code starts by creating an empty queue q with size 1.
Then it pushes s onto the queue and sets ```visited[s] = 1```.
Next, it sets ```path[s] = -1``` so that when we get to this point there will be no paths left for us to follow back up from here.
Then 
```
while (!q.empty()) {
      int u = q.front(); 
      q.pop(); if (u == t) break; 
      for (int v=0; v 0) { q .push(v); 
      path [v ] = u; 
      visited [v ] = 1 ; 
      } 
      } 
      } 
      if (visited[t] == 0) 
        return 0; 
       return 1;
```
The code attempts to calculate the maximum flow in a network.
The code iterates through all of the nodes in the network, and calculates the flow from one node to another.
The first line of code creates a vector > called residual.
This vector will store all of the nodes that have not been visited yet.
Next, it iterates through all of the nodes in this list and sets their value to -1.
After this, it creates a queue which will be used as an input for ```bfs(residual, s, t)```.
The function ```bfs(residual, s, t)``` calculates the maximum flow between two nodes by following a path until they reach either one node.
