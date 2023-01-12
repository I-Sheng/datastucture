#include <ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define DBG
#undef DBG
#define FDBG
#undef FDBG
#define COUNT

using namespace __gnu_pbds;
using namespace std;


inline const int max_vertex = 1000;

struct Node{
	int d, vertex;
	Node(int v,int d) : d(d), vertex(v){}
	bool operator>(const Node& n) const{return d > n.d;}
	bool operator<(const Node& n) const{return d < n.d;}
};


bool find(const vector<Node>& v, int target){
	for(const auto& i : v)
		if(i.vertex == target)
			return true;
	return false;
}



int main(){
#ifdef FDBG
	ofstream fout;
	fout.open("./debug", ios_base::out);
#endif
#ifdef COUNT
	ofstream avout;
	avout.open("./binary_time", ios_base::out);
#endif
	int const average_time = 10;
	const int count_time = 100;
	srand(time(0));
	for(int x = 0;x <= 500;x += 5){
#ifdef DBG
		cout << x << endl;
#endif
		for(int y = 1;y <= 50;++y){
			double sum = 0;
#ifdef COUNT
			double average_clock_time = 0;
			auto clock_start = chrono::steady_clock::now();
			auto clock_end = chrono::steady_clock::now();
#endif
			for(int round = 0;round < average_time; ++round){
				int edges_num = x;
				int length = y;
				vector<vector<Node> > connection(max_vertex); //init relation
				for(int i = 0;i < max_vertex;++i){ // connect the adjacent vertex
					if(i)
						connection[i].push_back({i-1,1});
					else
						connection[i].push_back({max_vertex - 1,1});
					if(i != 999)
						connection[i].push_back({i+1,1});
					else
						connection[i].push_back({0,1});
				}


				for(int i = 0;i < x;++i){ //add x edge
					int vertex = rand() % max_vertex ;
					int vertex2 = vertex;
					while(vertex == vertex2)
						vertex2 = rand() % max_vertex;
					if(find(connection[vertex], vertex2)){
						--i;
						continue;
					}
					connection[vertex].push_back({vertex2, y});
					connection[vertex2].push_back({vertex, y});
				}


				double ans = 0;
				for(int i = 0;i < count_time;++i){
#ifdef DBG
					cout << "i = " << i << endl;
#endif
#ifdef COUNT
					clock_start = chrono::steady_clock::now();
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
							if(num.vertex == end){
								ans += cur.d;
								while(!binaryHeap.empty())
									binaryHeap.pop();
								break;
							}
							else if(usage[num.vertex]){
								continue;
							}
							else{
								binaryHeap.push({num.vertex, cur.d + num.d});
								usage[num.vertex] = true;
							}
						}

					}
#ifdef COUNT
					clock_end = chrono::steady_clock::now();
					average_clock_time += (double)chrono::duration_cast<chrono::microseconds>(clock_end - clock_start).count() / 1000000;
#endif
				}
				sum += (ans / count_time);
				ans = 0;
#ifdef FDBG     
				fout << (ans / count_time) << endl << endl;
#endif

			}
			cout << (sum / average_time) << " ";
			sum = 0;
#ifdef FDBG
			fout << (sum / average_time) << endl << endl;
#endif
#ifdef COUNT
			average_clock_time /= average_time;
			average_clock_time /= count_time;
			avout << average_clock_time << " ";
#endif
		}
		cout << endl;
#ifdef COUNT
		avout << endl;
#endif

	}
	return 0;
}
