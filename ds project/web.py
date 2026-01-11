# import requests
# from bs4 import BeautifulSoup

# res = requests.get("https://quotes.toscrape.com/")

# content = BeautifulSoup(res.content,"html.parser")
# qoutes = content.find_all("div",class_="quote")
# for q in qoutes:
#     qot = q.find("span",class_="text").text
#     auth = q.find("small",class_="author").text
#     print(f"q:{qot} and a:{auth}")
import pydot

# Create a graph
graph = pydot.Dot(graph_type='graph')

# Create nodes
node1 = pydot.Node("A")
node2 = pydot.Node("B")

# Add nodes to graph
graph.add_node(node1)
graph.add_node(node2)

# Create and add an edge
edge = pydot.Edge(node1, node2)
graph.add_edge(edge)

# Save graph as an image
graph.write_png("simple_graph.png")
