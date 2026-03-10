#include<iostream>
#include<thread>

int main() {

    auto peer_thread = [] (int arg)
    {
        std::cout << "Hello from peer_thread, thread_id: " \
        << std::this_thread::get_id() << std::endl ; 
        std::cout << "Argument passed is :" << arg << std::endl; 
    };
    // Note no &peer_thread here
    // It will throw error as
    // Address of the lambda object — not invocable
    
    //void(*)(int)    — function pointer   → callable (language built-in)
    //Lambda          — object with op()   → callable (operator() found)
    //Lambda*         — pointer to object  → NOT callable (no dereference rule)
    
    std::thread t1(peer_thread, 1);
    t1.join();
    std::cout << "Hello from main thread. Thread_id is: "\
    << std::this_thread::get_id() << std::endl; 
    
    return 0;
}