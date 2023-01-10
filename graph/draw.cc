#include<bits/stdc++.h>
#include"graphics.h"

const double r = 20.0;
const double angle = 2 * M_PI / 1000;
const int max_vertex = 1000;
using namespace std;

struct Point{
	int x,y;
	Point(double x, double y) : x(x), y(y) {}
};

bool find(const vector<int>&v , int target){
	for(int i = 0;i < v.size();++i)
		if(v.at(i) == target)
			return true;
	return false;
}

int main(){

	//first create first point relative to the primitive one
	//rotate it for 2Pi / 1000 for 999 times to create the other 999 points

	vector<Point> points;
	for(int i = 0;i < 1000;++i){
		double theta = angle * i;
		double left = r * cos(theta);
		double right = r * sin(theta);
		points.push_back(Point(left, right));
	}

	initwindow(600,600);
	for(int i = 0;i < 1000;++i)
		line(points[i].x, points[i].y, points[(i+1) % 1000].x, points[(i+1) % 1000].y);


	//add 100 diff connection between this 1000 points
	vector<vector<int> > edges(1000);
	for(int i = 0;i < 1000;++i){
		if(i)
			edges[i].push_back(i - 1);
		else
			edges[i].push_back(999);
		if(i != 999)
			edges[i].push_back(i + 1);
		else
			edges[i].push_back(0);
	}

	const int edges_num = 100;
	//with y equal to 100
	const int y = 100;
	for(int i = 0;i < edges_num;++i){
		int vertex = rand() % max_vertex ;
		if(find(edges[vertex], (vertex + y) % max_vertex)){
			--i;
			continue;
		}
		edges[vertex].push_back((vertex + y) % max_vertex);
		edges[(vertex + y) % max_vertex].push_back(vertex);
		line(points[vertex].x, points[vertex].y, points[(i+y) % 1000].x, points[(i+y) % 1000].y);
	}



	return 0;
}
