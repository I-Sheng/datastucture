#include <ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define DBG
#undef DBG
#define FDBG

using namespace __gnu_pbds;
using namespace std;


inline const int max_vertex = 1000;

struct Node{
	int d, vertex;
	Node(int v,int d) : d(d), vertex(v){}
	bool operator>(const Node& n) const{return d > n.d;}
	bool operator<(const Node& n) const{return d < n.d;}
};


bool find(const vector<int>& v, int target){
	for(const int& i : v)
		if(i == target)
			return true;
	return false;
}



int main(){
#ifdef FDBG
	ofstream fout;
	fout.open("./debug", ios_base::out);
#endif
	int const average_time = 10;
	const int count_time = 100;
	srand(time(0));
	for(int x = 5;x <= 200;x += 5){
#ifdef DBG
		cout << x << endl;
#endif
		for(int y = 5;y <= 200;y += 5){
			double sum = 0;
			for(int round = 0;round < average_time; ++round){
				int edges_num = x;
				int length = y;
				vector<vector<int> > connection(max_vertex); //init relation
				for(int i = 0;i < max_vertex;++i){ // connect the adjacent vertex
					if(i)
						connection[i].push_back(i-1);
					else
						connection[i].push_back(max_vertex - 1);
					if(i != 999)
						connection[i].push_back(i+1);
					else
						connection[i].push_back(0);
				}


				for(int i = 0;i < x;++i){ //add x edge
					int vertex = rand() % max_vertex ;
					if(find(connection[vertex], (vertex + y) % max_vertex)){
						--i;
						continue;
					}
					connection[vertex].push_back((vertex + y) % max_vertex);
					connection[(vertex + y) % max_vertex].push_back(vertex);
				}


				double ans = 0;
				for(int i = 0;i < count_time;++i){
#ifdef DBG
					cout << "i = " << i << endl;
#endif
					__gnu_pbds::priority_queue<Node,std::greater<Node>,__gnu_pbds::binary_heap_tag> binaryHeap;
					vector<bool> usage(max_vertex, false);
					int start = rand() % max_vertex;
					int end = rand() % max_vertex;
					while(start == end)
						end = rand() % max_vertex;
					binaryHeap.push({start,0});
					while(!binaryHeap.empty() ){
						Node cur = binaryHeap.top();
#ifdef FDBG
						fout << "vertex is " << cur.vertex << " and distance is " << cur.d <<endl;
#endif
						usage[cur.vertex] = true;
						binaryHeap.pop();
						for(const auto& num : connection[cur.vertex]){
							if(num == end){
								ans += cur.d + 1;
								while(!binaryHeap.empty())
									binaryHeap.pop();
								break;
							}
							else if(usage[num]){
								continue;
							}
							else{
								binaryHeap.push({num, cur.d + 1});
								usage[num] = true;
							}
						}

					}
				}
				sum += (ans / count_time);
#ifdef FDBG
				fout << (ans / count_time) << endl << endl;
#endif
			}
			cout << (sum / average_time) << " ";
#ifdef FDBG
			fout << (sum / average_time) << endl << endl;
#endif
		}
		cout << endl;

	}
	return 0;
}
