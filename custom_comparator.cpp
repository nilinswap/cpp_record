#include<bits/stdc++.h>
using namespace std;


void printarr(vector<int>&vec){

    for( auto v: vec)
        cout << v << " ";
    cout << endl<<endl;;
}



bool comp(int a, int b){
    return a > b;
}

class CompClass{
    public:

    bool operator()(int a, int b){
        return a > b;
    }
}cc;

struct Rectangle{
    public:
        int a;
        int b;
        Rectangle(int aa, int bb){
            a = aa;
            b = bb;
        }
        friend bool operator < (Rectangle here, Rectangle other){
            return (here.a*here.b) > (other.a)*(other.b);
        }
};



void printrec(vector<Rectangle>&rv){

    for( auto r: rv)
        cout << r.a << " " << r.b << "  ";
    cout << endl<<endl;;
}




int main(){
    int arr[] = {3, 5, 2, 1, 7, 9, 0};
    vector<int> vec(arr, arr+7);
    vector<int> svec(arr, arr+7);
    printarr(vec);

// sort
    // default is less<int>()
    sort(vec.begin(), vec.end());
    printarr(vec);
    vec = svec;


    //function based
        sort(vec.begin(), vec.end(), greater<int>());
        printarr(vec);
        vec = svec;

        sort(vec.begin(), vec.end(), comp);
        printarr(vec);
        vec = svec;


    //compartor class based - notince cc is instantiation of such class
        sort(vec.begin(), vec.end(), cc);
        printarr(vec);
        vec = svec;


    //Seperate class based
        Rectangle rarr[] = {Rectangle(2, 3), Rectangle(4, 5), Rectangle(1,5)};
        Rectangle srarr[] = {Rectangle(2, 3), Rectangle(4, 5), Rectangle(1,5)};

        vector<Rectangle> rec_vec(rarr, rarr+3);

        sort(rec_vec.begin(), rec_vec.end());
        printrec(rec_vec);



// priority_queue

    // default is max_heap
    priority_queue<int> pq(svec.begin(), svec.end());
    priority_queue<int> spq(svec.begin(), svec.end());

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.push(-1);
    cout << pq.top()<<endl;
    pq.push(0);
    cout << pq.top()<<endl;
    pq.pop();
    cout << pq.top()<<endl<<endl;


    //compartor class based - notince cc is instantiation of such class
    priority_queue<int, vector<int>, CompClass> pqc(svec.begin(), svec.end());
    cout << pqc.top() << endl;
    pqc.pop();
    cout << pqc.top() << endl;
    pqc.push(-1);
    cout << pqc.top()<<endl;
    pqc.push(0);
    cout << pqc.top()<<endl;
    pqc.pop();
    cout << pqc.top()<<endl;

    //Seperate class based
    priority_queue<Rectangle> pqr(srarr, srarr+3);
    cout << pqr.top().a << " " << pqr.top().b << endl;
    pqr.pop();
    cout << pqr.top().a << " " << pqr.top().b << endl;
    pqr.push(Rectangle(1, 9));
    cout << pqr.top().a << " " << pqr.top().b<<endl;
    pqr.push(Rectangle(1, 6));
    cout << pqr.top().a << " " << pqr.top().b<<endl;
    pqr.pop();
    cout << pqr.top().a << " " << pqr.top().b<<endl<<endl;



//set
    //default is ascending
    set<int> ses(arr, arr+7);
    for(auto s: ses){
        cout << s << " ";
    }
    cout <<endl;


    //comparator class based
    set<int, CompClass> se(arr, arr+7);
    for(auto s: se){
        cout << s << " ";
    }
    cout <<endl;


    //separate class based
    set<Rectangle> rse(srarr, srarr+3);
    for(auto s: rse){
        cout << s.a << " " << s.b << "   ";
    }
    cout <<endl;






    return 0;
}


