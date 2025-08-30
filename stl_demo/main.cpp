#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<algorithm>
int main(){
    cout << "code started" << endl;

    // int depth = 2;
    // int rows = 4;
    // int cols = 8;
    // vector<vector<int>> vec(rows,vector<int>(cols,1));
    // for(auto row : vec){
    //     for(auto ele : row){
    //         cout << ele << " ";
    //     }
    //     cout << endl;
    // }

    // 3D vector
    // vector<vector<vector<int>>> vec2(depth,vector<vector<int>>(rows,vector<int>(cols,2)));

    set<int> st;
    st.insert(10);
    st.insert(30);
    st.insert(8);
    for(auto ele : st){
        cout << ele << " ";
    }

    map<int,string> mp;
    mp.insert({2,"tomato"});
    mp[2] = "apple";

    for(auto ele : mp){
        cout << ele.first << " " << ele.second << " ";
        cout << endl;
    }

    priority_queue<int> q;
    q.push(10);
    q.push(40);
    q.push(30);
    while(!q.empty()){
        cout << q.top() << endl;
        q.pop();
    }

    priority_queue<int,vector<int>,greater<int>> q1;
    q1.push(10);
    q1.push(40);
    q1.push(30);
    while(!q1.empty()){
        cout << q1.top() << endl;
        q1.pop();
    }

    vector<int> v {2,34,5};
    int sum = accumulate(v.begin(),v.end(),0);
    cout << sum << endl;

    vector<int> v4 {2,34,5};
    int prod = accumulate(v4.begin(),v4.end(),1,[](int product,int element){
        return product*element;
    });
    cout << prod << endl;

    vector<int> vec = {3,2,8,0};
    auto it = remove(vec.begin(),vec.end(),2);
    vec.resize(distance(vec.begin(),it));
    for(auto ele : vec){
        cout << ele << endl;
    }

    vector<int> vec1 = {4,6,8,9,10,12,56};
    auto it1 = remove_if(vec1.begin(),vec1.end(),[](int x){
        return x > 10;
    });
    vec1.resize(distance(vec1.begin(),it1));
    for(auto ele : vec1){
        cout << ele << endl;
    }

    vector<int> v5 = {2,4,6,8};
    vector<int> result(v5.size());
    transform(v5.begin(),v5.end(),v5.begin(),[](int x){
        return x*2;
    });
    for(auto ele : v5){
        cout << ele << endl;
    }
    
    return 0;

}