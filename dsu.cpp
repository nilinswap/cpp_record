#include <bits/stdc++.h>
using namespace std;



#define N 1000

int find_root(vector<int>& parr, int x ){
        stack<int> sta;
        //handle negative x
		while(parr[x] != -1){
		    sta.push(x);
			x = parr[x];
		}
		while(!sta.empty()){
		    parr[sta.top()] = x;
		    sta.pop();
		}
		return x;
}

void unionf(vector<int>& parr, int x, int y){
		int a = find_root(parr, x);
		int b = find_root(parr, y);
		if(a != b){
			parr[a] = b;
		}
		return;
}

bool is_same_set(vector<int>& parr, int x, int y){
	return find_root(parr, x) == find_root(parr, y);
}
int main(){
	vector<int> parent_arr(N, -1);

	cout << find_root(parent_arr, 2) << " " << find_root(parent_arr,5) << endl;
	unionf(parent_arr, 2, 5);
	cout << find_root(parent_arr,2) << " " << find_root(parent_arr,5) << " " << is_same_set(parent_arr, 2, 5) << endl;
	unionf (parent_arr, 4, 3);
	cout << find_root(parent_arr,3) << " " << find_root(parent_arr,5) << " " << is_same_set(parent_arr, 3, 5) << endl;
 unionf(parent_arr, 4, 2);
cout << find_root(parent_arr,3) << " " << find_root(parent_arr,5) << " " << is_same_set(parent_arr, 3, 5) << endl;

}
