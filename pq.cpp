#include<bits/stdc++.h>
using namespace std;

class Cclass{
    public:
    bool operator()(int a , int b){
        return a > b;
    }
};
int main(){
    int arr[] = { 3, 1, 4, 2, 1, 0 , 3, 2, 6};

	priority_queue<int,vector<int>, Cclass>pq(arr, arr+9);
	cout << pq.top() << endl;
	pq.push(7);
	cout << pq.top() <<endl;
	pq.pop();pq.pop();
	cout << pq.top() <<endl;
    return 0;
}
