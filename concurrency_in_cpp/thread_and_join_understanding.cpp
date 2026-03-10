#include<iostream>
#include<thread>

void peer_thread(int arg)
{
    std::cout << "Hello from peer_thread, thread_id: " \
    << std::this_thread::get_id() << std::endl ; 
    std::cout << "Argument passed is :" << arg << std::endl; 
}

int main() {

    std::thread t1(&peer_thread, 1);
    t1.join();
    std::cout << "Hello from main thread. Thread_id is: "\
    << std::this_thread::get_id() << std::endl; 
    
    return 0;
}