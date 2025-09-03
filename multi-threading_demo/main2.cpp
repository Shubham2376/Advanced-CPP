#include <iostream>
#include <thread> //since c++11
#include "threading.h"
#include <chrono>
#include <string>
#include <mutex>
#include <shared_mutex>
#include <queue>
#include <condition_variable>
#include <future>
using namespace std;
// void square(int& num){
//     int square = num * num;
//     num = square;
// }

// int square(int num, promise<int> pr){
//     int result = num*num;
//     pr.set_value(result);
// }

int printValue(int value){
    cout << "print" << endl;
    return 23;
}
int main(){
    // cout << "Code Started " << endl;
    // int var = 5;
    // thread t1(square,ref(var));
    // t1.join();
    // cout << var << endl;

    // promise<int> pr1, pr2;
    // future<int> res1 = pr1.get_future();
    // future<int> res2 = pr2.get_future();

    // thread t1(square,5,pr1);
    // thread t2(square,6,pr2);

    // int res1 = res1.get(); //Thread will get block until result is there 
    // int res2 = res2.get();

    // t1.join();
    // t2.join();

    future<int> res = async(launch::async,printValue,5);
    res.get();

    return 0;
}