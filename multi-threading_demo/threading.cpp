#include "threading.h"
#include<numeric>
#include <thread>
#include <functional>
#include<vector>

long long getSingleThreadedSum(vector<int>& data){
    long long res = accumulate(data.begin(),data.end(),0LL);
    return res;
}
void partial_sum(vector<int>& data, int start, int end, long long& res){
    res = accumulate(data.begin()+start,data.begin()+end,0LL);
}
long long getMultiThreadedSum(vector<int>& data){
    int num_threads = thread::hardware_concurrency(); // This will give me no of cores in my machine 
    vector<long long> res(num_threads,0LL);
    vector<thread> threads;
    long long chunk_size = data.size()/num_threads;

    for(int i = 0; i<num_threads; i++){
        int start = i*chunk_size;
        int end = (i == num_threads-1) ? data.size() : (i+1)*chunk_size;
        // thread t(partial_sum,ref(data),start,end,ref(res[i]));
        // t.join();
        //threads.push_back(thread(partial_sum,ref(data),start,end,ref(res[i])));
        threads.emplace_back(partial_sum,ref(data),start,end,ref(res[i]));
    }

    for(auto &thread : threads){
        thread.join();
    }
    // we have to sum all the chunks sum for the final sum
    return accumulate(res.begin(),res.end(),0LL);
}