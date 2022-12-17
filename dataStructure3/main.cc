#include<bits/stdc++.h>
#include"structure.cc"
#ifndef STD
#define STD
using namespace std;
#endif
int main(){
	const int start_num = 0;
	const int Max = pow(2, 30);
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	ofstream fout;
	fout.open("./out", ios_base::app);
	for(int round = 0;round < 10;++round){

		for(int j = 0;j <= 10;++j){
			unsigned int times = pow(2, start_num + j);
			BST bst;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				bst.insert(rand() % Max);
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				bst.search(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900)
				break;
		}
		fout << endl;



		fout << round << " round is end." << endl << endl;
	}

	fout.close();
	return 0;	
}
