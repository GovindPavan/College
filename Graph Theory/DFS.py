

# Python program to print DFS traversal from a 
# given given graph 

# This class represents a directed graph using 
# adjacency list representation 
class Graph: 

	# Constructor 
	def __init__(self): 

		# a dictionary to store the graph 
		self.graph = dict()
		# a list to know if the vertices are visited or not
		self.visited = list()

	# function to add an edge to the graph 
	def add_edge(self,u,v):

		# if we want to add an edge to an old vertex
		if (u in self.graph):
			self.graph[u].append(v)
		# if there is a new vetrex involved
		else:
			self.graph[u] = [v]

	# A function used by DFS 
	def DFSUtil(self, v): 

		# Mark the current node as visited and print it 
		self.visited[v]= True
		print (v) 

		# Recur for all the vertices adjacent to this vertex 
		for i in self.graph[v]: 
			if self.visited[i] == False:
				self.DFSUtil(i) 


	# The function to do DFS traversal. It uses recursive DFSUtil() 
	def DFS(self,v): 
		
		print(self.graph)
		# Mark all the vertices as not visited 
		self.visited = [False]*(len(self.graph)) 

		# Call the recursive helper function to print 
		# DFS traversal 
		self.DFSUtil(v) 


# Create a graph given in the above diagram 
g = Graph() 

#Number of vertices
n = 4

#Defining the adjacency matrix
#  vertices		0 1 2 3
adj_matrix = [ [0,1,1,0],
               [0,0,1,0],
               [1,0,0,1],
               [0,0,0,1] ]

for i in range(n):
	for j in range(n):
		if (adj_matrix[i][j] == 1):
			g.add_edge(i,j)
  
print ("Following is DFS from (starting from vertex 2)")
g.DFS(2)
