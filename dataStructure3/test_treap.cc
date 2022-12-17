#include<bits/stdc++.h>
#include"treap.cc"
using namespace std;

int main() {
	int nums[] = {1,7,6,4,3,2,8,9,10 };
	int a = sizeof(nums)/sizeof(int);
	Treap t;
	srand(time(nullptr));
	for (int n: nums)
		t.insertNod(t.getR(),n);
	cout << "Constructed Treap:\n\n";
	t.displayTreap(t.getR());
	return 0;
}
