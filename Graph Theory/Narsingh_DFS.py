

class Graph:

	def __init__(self):
		self.x = 4
		self.count = 0
		self.NUM = dict()
		self.PALM = list()
		self.FRON = list()
		self.traversed_edges = list()

		self.adj_matrix = list()
		self.n = 0

	def init_graph(self, n):
		self.n = n
		for i in range(self.n):
			row = list()
			for j in range(self.n):
				print("Enter if there is an edge between vertices ", (i, j), "(1/0) : ");
				item = int(input())
				row.append(item)
			self.adj_matrix.append(row)
		
		for row in self.adj_matrix:
			print(row)

	def untraversed_edge_finder (self, v):
		for j in range(self.n):
			if (self.adj_matrix[v][j] == 1) and ((v, j) not in self.traversed_edges):
				return (v, j)

		return None

	def step3(self, v):
		# Look for an untraversed edge from v
		untraversed_edge = self.untraversed_edge_finder(v)
		if (untraversed_edge != None): # (v,w)
			self.traversed_edges.append(untraversed_edge)

			# Step 4
			(v,w) = untraversed_edge
			if (w not in self.NUM):
				self.PALM.append((v, w))
				self.DFS(w)
			elif (self.NUM[w] < self.NUM[v]):
				self.FRON.append((v, w))
				self.step3(v)

	def DFS(self, v):
		print("Vertex : ", v)
		print("PALM : ")
		print(self.PALM)
		print("FRON: ")
		print(self.FRON)
		print("NUM: ")
		print(self.NUM)
		print("Traversed Edges: ")
		print(self.traversed_edges)
		input()
		# Step 2
		self.count += 1
		self.NUM[v] = self.count

		# Step 3
		self.step3(v)
				
		for (i,j) in self.PALM:
			if(j == v):
				self.DFS(i)



g = Graph()

n = int(input("Enter number of vertices : "))
g.init_graph(n)

g.DFS(4)

print("_________________________ FINAL _________________________")
print("PALM : ")
print(g.PALM)
print("FRON: ")
print(g.FRON)
print("NUM: ")
print(g.NUM)
print("Traversed Edges: ")
print(g.traversed_edges)