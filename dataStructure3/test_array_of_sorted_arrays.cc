#include<bits/stdc++.h>
#include"array_of_sorted_arrays.cc"
using namespace std;

int main(){
	array_of_sorted_arrays a;
	int n = pow(2, 19);
	for(int i = 0;i < n;++i)
		a.insert(rand() % n);
	vector<vector<int> > v = a.getV();
	for(int i = 0;i <= 30;++i)
		cout << i << " " << v[i].size() << endl;
	for(int i = 0;i < n - 1;++i)
		if(v[19][i] > v[19][i + 1])
			cout << "bug in sorting" << endl;
}
