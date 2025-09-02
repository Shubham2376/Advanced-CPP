#include <iostream>
#include <thread> //since c++11
#include "threading.h"
#include <chrono>
#include <string>
#include <mutex>
using namespace std;
void startFunction(int& x, string s){
    cout << "Printing from thread function" << endl;
    x = 30;
    cout << "value of x inside the fun: " << x << endl;
    //cout << x << " " << s << endl;
 }
 mutex mt; //simple mutex
 recursive_mutex r_mtx; // Recursive mutex
 void recursiveFunction(int count)
{
    if (count <= 0)
        return;

    r_mtx.lock();
    std::cout << "Recursive function count: " << count << std::endl;
    recursiveFunction(count - 1); // Recursively call the function
    r_mtx.unlock();
}

// Example of DeadLock
void thread1()
{
    std::lock(mtx1,mtx2);
    //std::lock_guard<std::mutex> lock1(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    //std::lock_guard<std::mutex> lock2(mtx2);
    std::cout << "Thread 1 finished" << std::endl;
}

void thread2()
{
    std::lock(mtx1,mtx2);
    //std::lock_guard<std::mutex> lock2(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    //std::lock_guard<std::mutex> lock1(mtx2);
    std::cout << "Thread 2 finished" << std::endl;
}

 void printSafe(const string& message){
    cout << message << endl;
 }
 void threadFunction(int id){
    for(int i = 0; i<5; i++){
        //mt.lock(); //Lock the mutex
        {
        lock_guard<mutex> lg(mt);
        cout << "Thread" + to_string(id) + "is running" << endl; //Critical Section
        }
        //mt.unlock(); //Unlock the mutex
    }
 }
 class myClass{
    public:
    void operator()(){ //operator overloading
        cout << "Functors" << endl;
    }

    void memberFunction(){
        cout << "Print inside myClass";
    }
 };
int main(){
    cout << "multi threading demo" << endl;
    // int x = 50;
    // thread t1(startFunction,ref(x),"shubham");
    // t1.join();
    // cout << "Value of x inside the main thread: "<< x << endl;

    // myClass obj;
    // thread t4(obj);
    // t4.join();

    // thread t2([](int y, string s2){
    //     cout << "Printing from thread function inside the lambda function";
    //     cout << y << " " << s2 << endl;
    // },2,"siddharth");

    // myClass obj;
    // thread t3(&myClass::memberFunction,&obj);

    

    // t2.join();
    // t3.join();
    // cout << "print from main thread" << endl;

    // const int TOTAL_DATA = 100000000;
    // vector<int> vec(TOTAL_DATA,1);

    // sum of all elements inside the vector vec

    // Calculate time for single Threaded Sum
    // auto start = chrono::high_resolution_clock::now();
    // long long res = getSingleThreadedSum(vec);
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> time_taken = end - start;
    // cout << "time taken for single thread: " << time_taken.count() << " seconds\n";

    // cout << "Single Threaded Sum: " << res << endl;

    // Calculate time for multi Threaded Sum 
    // auto start1 = chrono::high_resolution_clock::now();
    // long long res2 = getMultiThreadedSum(vec);
    // auto end1 = chrono::high_resolution_clock::now();
    // time_taken = end1 - start1;
    // cout << "time taken for multi thread: " << time_taken.count() << " seconds\n";
    
    // cout << "Multi Threaded Sum: " << res2 << endl;

    thread t1(threadFunction,1);
    thread t2(threadFunction,2);
    t1.join();
    t2.join();
    return 0;
}