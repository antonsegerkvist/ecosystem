#ifndef GRAPH_LIB
#define GRAPH_LIB

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>


using namespace std;


//unweighted directed graph class
template <class Tkey>
class graph{
	public:
		//Vertices are an unordered set of keys.
		unordered_set<Tkey> V;
		//Edges are unordered maps from the keys representing the tail vertices,
		//to unordered sets of keys representing the head vertices.
		unordered_map<Tkey, unordered_set<Tkey>> E;
	
		//add vertex and edges methods
		void addVertex(Tkey key){
			V.insert(key);
		}
		void addEdge(Tkey tail, Tkey head){
			E[tail].insert(head);
		}

		//Breadth First Search Algorithm to get optimal path
		//Given start vertex and end vertex returns path as a list of sequential vertices
		list<Tkey> getPathBFS(Tkey start, Tkey finish){
			//unordered set "searched" to quickly check which vertices don't need to be added to the search queue
			unordered_set<Tkey> searched;
			//The search queue.
			queue<list<Tkey>> toSearch;
			
			//the shortest path to the current vertex. Init with start vertex
			list<Tkey> current;
			current.push_back(start);
			//dummy variable to update search paths
			list<Tkey> temp;
			
			//search until target vertex has been found
			while(*current.rbegin() != finish){
				//look at the head of all edges begining from the current vertex
				for( auto i = E[*current.rbegin()].begin(); i != E[*current.rbegin()].end(); ++i){
					//if the head has not been searched before, add it to the search queue
					if(searched.find(*i) == searched.end()){
						//make sure the head isn't searched again
						searched.insert(*i);
						//set up the optimal search path leading to the node
						temp=current;
						temp.push_back(*i);
						//add it to the search queue
						toSearch.push(temp);
					}
				}
				//check if there still more to search
				if(!toSearch.empty()){
					//if so dequeue to the current and keep searching
					current = toSearch.front();
					toSearch.pop();
				}
				else{
					//if not, then the search has failed, return an empty list
					list<Tkey> emptyList;
					return emptyList;
				}
			}
			
			//return the found path
			return current;
		}
	
		//Tarjan's Strongly Connected Components Algorithm to get sets of mutually reachable nodes
		list<unordered_set<Tkey>> stronglyConnectedComponents(){
			//index of order reached so far
			int index=0;
			//indices of the of the vertices
			unordered_map<Tkey, int> indices;
			//lowest index of the of the vertex in the cycle (strongly connected component) to which a vertex belongs
			unordered_map<Tkey, int> lowindices;
			
			//Stack of elements reached to far, which an unordered set to check if they're there
			stack<Tkey> S;
			unordered_set<Tkey> onStack;
			
			//the list of strongly connected components to return
			list<unordered_set<Tkey>> returnVal;
			
			//for every vertex in the graph, skipping ones already sorted, check their strongly connected components
			for( auto v = V.begin(); v != V.end(); ++v)	if(indices.find(*v) == indices.end()){
				strongconnect(*v,S,indices, lowindices, index, onStack, returnVal);
			}
			return returnVal;
		}
	
		//Print the graph in edge list form
		void print(){
			for(auto v = V.begin(); v != V.end(); ++v){
				cout << *v << " -> ";
				for(auto e = E[*v].begin(); e != E[*v].end(); ++e){
					cout << *e << ", ";
				}
				cout << "\n";
			}
		}
	
	
	private:
		void strongconnect(Tkey v, stack<Tkey>& S, unordered_map<Tkey, int>& indices, unordered_map<Tkey, int>& lowindices, int& index,unordered_set<Tkey>& onStack, list<unordered_set<Tkey>>& returnVal){
			//first time a vertex has been reached
			//set it's index, and as far as we know lowindex
			indices[v]=index;
			lowindices[v]=index;
			//update index for the next vertex found
			index++;
			
			//put the vertex on the stack for later
			S.push(v);
			onStack.insert(v);
		
			//for every successor node to v
			for(auto w = E[v].begin(); w != E[v].end(); ++w){
				//if the successor vertex w has not been found yet, recurse
				if(indices.find(*w) == indices.end()){
					strongconnect(*w, S, indices, lowindices, index, onStack, returnVal);
					//if v is actually part of a cycle including w update it's lowindex
					lowindices[v]=min(lowindices[v],lowindices[*w]);
				}
				else if(onStack.find(*w) != onStack.end()){
					//else if w is part of the currently SCC that has yet to be popped, update lowindex of v
					lowindices[v]=min(lowindices[v],indices[*w]);
				}
			}
		
			//if we found the root (lowest index) of the cycle (strongly connected component)
			if(lowindices[v]==indices[v]){
				//we are now ready to collect all vertices in the component
				unordered_set<Tkey> component;
				
				//until v (the root) is removed from the stack
				while(onStack.find(v) != onStack.end()){
					//pop elements from the stack S into the component
					onStack.erase(S.top());
					component.insert(S.top());
					S.pop();
				}
				
				//add the component found to the final set of components
				returnVal.push_front(component);
			}
		}
};


//edge struct allows for creation of map from edges to weights
template <class Tkey>
struct edge{
	Tkey tail;
	Tkey head;
	bool operator==(const edge &other) const {
			if(head == other.head && tail == other.tail) return true;
			return false;
	}
};
template<class Tkey>
class hash<edge<Tkey>> {
	public:
	size_t operator()(const edge<Tkey> &input) const {
		size_t nbit = sizeof(size_t)*8;
		//hash the head, then shift
		size_t returnVal = hash<Tkey>()(input.tail);
		returnVal = (returnVal<<(nbit/2)) | (returnVal>>(nbit-(nbit/2)));
		//hash the tail, combind
		returnVal ^= hash<Tkey>()(input.head);
		return returnVal;
	}
};


//directed graph with edge weights class
template <class Tkey, class TEdgeWeight>
class weighted_graph: public graph<Tkey>{
	public:
		//Edges are unordered maps from the keys representing the tail vertices, to the vertices lead to
		//which are represented as an unordered map leading to their edge data.
		unordered_map<edge<Tkey>, TEdgeWeight> weights;
	
		//add vertex and edges methods
		void addVertex(Tkey key){
			this->V.insert(key);
		}
		void addEdge(Tkey tail, Tkey head, TEdgeWeight weight){
			this->E[tail].insert(head);
			weights[edge<Tkey>{tail, head}] = weight;
		}
	
		//get weight method
		TEdgeWeight weight(Tkey tail, Tkey head){
			return weights[edge<Tkey>{tail, head}];
		}
	
		//Print the graph in edge list form with weights
		void print(){
			for(auto v = this->V.begin(); v != this->V.end(); ++v){
				cout << *v << " -> ";
				for(auto e = this->E[*v].begin(); e != this->E[*v].end(); ++e){
					cout << *e << "(" << weight(*v, *e) << "), ";
				}
				cout << "\n";
			}
		}
};


//directed graph with both edge and vertex data class
template <class Tkey, class TVertex, class TEdge>
class data_graph: public graph<Tkey>{
	public:
		//Edges are unordered maps from the keys representing the tail vertices, to the vertices lead to
		//which are represented as an unordered map leading to their edge data.
		unordered_map<edge<Tkey>, TEdge> EDataSet;
		unordered_map<Tkey, TVertex> VDataSet;
	
		//add vertex and edges methods
		void addVertex(Tkey key, TVertex data){
			this->V.insert(key);
			VDataSet[key] = data;
		}
		void addEdge(Tkey tail, Tkey head, TEdge data){
			this->E[tail].insert(head);
			EDataSet[edge<Tkey>{tail, head}] = data;
		}
	
		//get data methods
		TVertex Vdata(Tkey key){
			return VDataSet[key];
		}
		TEdge Edata(Tkey tail, Tkey head){
			return EDataSet[edge<Tkey>{tail, head}];
		}
	
		//Print the graph in edge list form with weights
		void print(){
			for(auto v = this->V.begin(); v != this->V.end(); ++v){
				cout << *v << "(" << Vdata(*v) << ") -> ";
				for(auto e = this->E[*v].begin(); e != this->E[*v].end(); ++e){
					cout << *e << "(" << Edata(*v, *e) << "), ";
				}
				cout << "\n";
			}
		}
};

#endif