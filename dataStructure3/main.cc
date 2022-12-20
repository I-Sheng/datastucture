#include<bits/stdc++.h>
#include"structure.cc"
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
	fout.open("./out", ios_base::out);
	for(int round = 0;round < 10;++round){

		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			BST bst;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				bst.insert(rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				bst.search(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "bst end" << endl << endl;
		cout << "bst end" << endl << endl;
		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			Treap t;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				t.insert(t.getR(), rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				t.search(t.getR(), rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "treap end" << endl << endl;
		cout << "treap end" << endl << endl;


		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			Skiplist s;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				s.add(rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				s.search(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "skip-list end" << endl << endl;
		cout << "skip-list end" << endl << endl;


		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			array_of_sorted_arrays a;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				a.insert(rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				a.search(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "array_of_sorted_arrays end" << endl << endl;
		cout << "array_of_sorted_arrays end" << endl << endl;

		for(int j = 10;j <= range;++j){
			bool flag = 0;
			const int times = pow(2, j);
			unordered_set<int> st;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i){
				st.insert(rand() % Max);
			}
			end = chrono::steady_clock::now();
			auto time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " ";
			if(time > 900)
				flag = true;
			start = chrono::steady_clock::now();
			for(int i = 0;i < times;++i)
				st.find(rand() % Max);
			end = chrono::steady_clock::now();
			time = (double)chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000;
			fout << time << " " << endl;
			if(time > 900 || flag)
				break;
		}
		fout << "hast table end" << endl << endl;
		cout << "hast table end" << endl << endl;


		fout << round << " round is end." << endl << endl;
		cout << round << " round is end." << endl << endl;
	}

	fout.close();
	return 0;	
}
