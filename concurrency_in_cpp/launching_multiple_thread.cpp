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

    std::vector<std::thread> threads;

    for(int counter=0; counter < 10; counter++)
    {
        threads.push_back(std::thread(peer_thread, counter));
        /*
        Here's what happens if we keep join just after creating threads in loop:

        Create thread 0 → join() → thread 0 finishes and is destroyed → OS reclaims its thread ID
        Create thread 1 → OS reuses the same ID → join() → thread 1 finishes → ID reclaimed again
        ... repeat
        Each thread runs and completes before the next one is created. The OS is free to reuse the same underlying thread ID since the previous thread is already dead.

        You're essentially running 10 sequential threads, not 10 concurrent threads.

        To run them concurrently, move the join loop after all threads are created
        */
        //threads[counter].join();  
    }

    //fix:
    for(int counter=0; counter < 10; counter++)
    {
        //join() does two things:

        //1)Waits for the thread to finish (instant if already done)
        //2)Releases the thread's resources back to the OS

        /*
        The key insight is: a thread's ID is not reclaimed when it finishes executing — it's reclaimed when join() is called.

            Think of it like this:

            Original (join inside creation loop):
            Create thread 0 (ID: 1000)
            join() thread 0    → resources released, ID 1000 is free
            Create thread 1    → OS reuses ID 1000 (it's free!)
            join() thread 1    → resources released, ID 1000 is free again
            ...

            Only one thread exists at a time. The ID gets recycled immediately.
        
            Fixed (join in separate loop):

            Create thread 0 (ID: 1000)  → running
            Create thread 1 (ID: 1001)  → running
            Create thread 2 (ID: 1002)  → running
            ...
            Create thread 9 (ID: 1009)  → running

            — even if threads 0-9 have all FINISHED by now —
            — their IDs are NOT free yet because join() hasn't been called —

            join() thread 0  → NOW ID 1000 is released
            join() thread 1  → NOW ID 1001 is released
            ...

            All 10 std::thread objects exist simultaneously. Even if a thread's function has returned, the OS keeps its resources (including the thread ID) alive until join() is called. This is similar to how a Unix process becomes a zombie after it exits — it still holds its PID until the parent calls wait().

            So it's not about whether the thread is still running. It's about whether join() has been called to release its identity.

            What does the OS keep?
            The OS keeps all the thread's resources, not just the ID. Specifically:

            Thread control block (kernel data structure describing the thread)
            Thread ID (can't be reused while the control block exists)
            Exit status / return value
            Some kernel accounting info
            The thread's stack memory is typically freed once it finishes, but the control block stays until join() (or detach()) is called. This is called a joinable thread — it's analogous to a zombie process in Unix.

            Your real question: both versions have finished threads, so why different IDs?
            The difference isn't about whether threads are running — it's about how many thread control blocks exist simultaneously.

            Original:

            time →
            [create t0] [join t0 → resources freed] [create t1] [join t1 → resources freed] ...

            Alive at any moment: 1 thread control block
            OS has freed IDs to reuse

            Fixed:

            time →
            [create t0] [create t1] [create t2] ... [create t9]  ←  all 10 exist
                ... threads finish running, but NOT joined yet ...
                ... 10 control blocks still alive, 10 IDs held ...
            [join t0 → freed] [join t1 → freed] ... [join t9 → freed]

            Alive between creation and join: 10 thread control blocks simultaneously
            OS cannot reuse any ID — they're all still held


            So yes, in the fixed version threads may have finished running too. 
            But their control blocks still exist because join() hasn't been called yet. 
            The OS can't reuse an ID that's still assigned to an existing (even if finished) control block.

        */
        threads[counter].join();
    }
    std::cout << "Hello from main thread. Thread_id is: "\
    << std::this_thread::get_id() << std::endl; 
    
    return 0;
}