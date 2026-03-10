#include<iostream>
#include<thread>
#include<vector>

int main() {

    auto peer_thread = [] (int arg)
    {
        std::cout << "Hello from peer_thread, thread_id: " \
        << std::this_thread::get_id() << std::endl ; 
        std::cout << "Argument passed is :" << arg << std::endl; 
    };

    std::vector<std::jthread> jthreads;

    for(int counter=0; counter < 10; counter++)
    {
        jthreads.push_back(std::jthread(peer_thread, counter));
    }


    std::cout << "Hello from main thread. Thread_id is: "\
    << std::this_thread::get_id() << std::endl; 
    
    return 0;
}