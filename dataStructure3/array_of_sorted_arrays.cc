using namespace std;

class array_of_sorted_arrays{
	public:
		array_of_sorted_arrays();
		void insert(int);
		bool search(int) const;
		vector<int> merge(const vector<int>&, const vector<int>&) const;
		vector<vector<int>>& getV() {return v;}
	private:
		int usage;
		vector<vector<int>> v;
};

array_of_sorted_arrays::array_of_sorted_arrays(){
	usage = 0;
	v.resize(31);
}

void array_of_sorted_arrays::insert(int num){
	vector<int> tmp;
	tmp.push_back(num);
	for(int i = 0;i <= 30;++i){
		if(usage & 1 << i){  //judge if array i has used, if used then merge
			tmp = merge(v[i], tmp);
			usage &= ~(1 << i); 
			v[i].clear();
		}
		else{ // if i not used, just insert the array.
			v[i] = tmp;
			usage |= 1 << i;
			break;
		}
	}
}

bool array_of_sorted_arrays::search(int target) const{
	for(int i = 0;i <= 30;++i){ // use binary_search to search every sorted_arrays
		if(binary_search(v[i].begin(), v[i].end(), target))
			return true;
	}
	return false;
}

vector<int> array_of_sorted_arrays::merge(const vector<int>& v1, const vector<int>&v2) const{
	vector<int> v;
	int x = 0, y = 0;
	if(v1.size()!= v2.size()){ //default debuger
		cout << "v1 and v2 size are diff" << endl;
		exit(0);
	}
	while(1){ //merge to sorted_arrays
		if(x < v1.size() && y < v2.size()){
			if(v1[x] < v2[y])
				v.push_back(v1[x++]);
			else
				v.push_back(v2[y++]);
		}
		else if(x < v1.size()){
			v.push_back(v1[x++]);
		}
		else if(y < v2.size()){
			v.push_back(v2[y++]);
		}
		else{
			break;
		}
	}
	return v;
}
