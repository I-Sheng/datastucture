#include<bits/stdc++.h>
#include"BTree.h"
#ifndef STD
#define STD
using namespace std;
#endif
int main(){
	const int range = 30;
	const int Max = pow(2, 30);
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	ofstream fout;
	fout.open("./Btreeout", ios_base::out);
	for(int round = 0;round < 10;++round){

		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			BPlusTree<int> btree(3);
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				btree.insert(rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				btree.search(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "btree end" << endl << endl;

		fout << round << " round is end." << endl << endl;
		cout << round << " round is end." << endl << endl;
	}

	fout.close();
	return 0;	
}
