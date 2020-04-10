#include<bits/stdc++.h>
using namespace std;
class Heap{
	public:
	vector<int> heapvec;
	int size;
	void heapify(int i){

		int lc_ind = 2*i + 1;
		int rc_ind = 2*i + 2;
		int min_ind = i;

		//find out minimum
		if(lc_ind < size && heapvec[min_ind] > heapvec[lc_ind]){
			min_ind = lc_ind;
			}
			if(rc_ind < size && heapvec[min_ind] > heapvec[rc_ind]){
			min_ind = rc_ind;
			}

		//do the swap
		if(min_ind != i){
			int temp = heapvec[min_ind];
			heapvec[min_ind] = heapvec[i];
					heapvec[i] = temp;

 			//recursive call
			heapify(min_ind);

		}

	}
	Heap(vector<int>& heapvecay){
		heapvec = heapvecay;
		size = heapvecay.size();
        for(int i = size/2; i >= 0; i--){
                    heapify(i);
        }

	};
	int pop(){
        if(size <= 0){
            return -1;
        }
        int min = heapvec[0];
        heapvec[0] = heapvec[size-1];
        size -= 1;//imp
        heapify(0);
        return min;
    }
    void bubble_up(int ind){

        int par_ind = ind/2;

        while(ind && heapvec[par_ind] > heapvec[ind]){
            int temp = heapvec[ind];
            heapvec[ind] = heapvec[par_ind];
            heapvec[par_ind] = temp;
            ind = par_ind;
            par_ind = ind/2;
        }

    }
    void insert( int x){
        if(size == heapvec.size()){
            heapvec.push_back(x);
        }
        else{
            heapvec[size] = x;
        }
        size += 1; //imp
        bubble_up(size-1);
    }
    int top(){
        if(size <= 0){
            return -1;
        }
        return heapvec[0];
    }
    int printheap(){
        for(int i = 0; i < heapvec.size(); i++)
            cout << heapvec[i] << " ";
        cout << endl;
        return 0;
    }
};


int main(){
    int arr[] = { 3, 1, 4, 2, 1, 0 , 3, 2, 6};
	vector<int> vec(arr, arr+9);
    Heap heap = Heap(vec);

	cout << heap.top() << endl;
    heap.pop();
    heap.printheap();
    cout << heap.top() << endl;
    heap.insert(-1);
    heap.printheap();
    cout << heap.top()<<endl;
    heap.insert(0);
    heap.printheap();
    cout << heap.top()<<endl;
    heap.pop();
    heap.printheap();
    cout << heap.top()<<endl;


    stack<int> sta;
    sta.push(1);
    sta.pop();

    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.pop_front();
    dq.front();
    dq.pop_back();
    dq.back();


    return 0;



}

