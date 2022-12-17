#include<bits/stdc++.h>
#include"structure.cc"
using namespace std;

int main() {
	int nums[] = {1,7,6,4,3,2,8,9,10 };
	int a = sizeof(nums)/sizeof(int);
	BST t;
	srand(time(nullptr));
	for (int n: nums)
		t.insert(n);
	cout << "Constructed Treap:\n\n";
	int n = 34;
	for(int i = 0;i < n;++i)
		cout << "i = " << i << " is " << t.search(i) << endl;
	return 0;
}
