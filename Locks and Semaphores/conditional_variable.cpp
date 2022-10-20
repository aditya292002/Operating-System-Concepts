#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std; 


mutex m;
condition_variable cv;
string data_content;
bool ready = false;
bool processed = false;
 
void worker_thread()
{
    // Wait until main() sends data
    unique_lock lk(m);
    cv.wait(lk, []{return ready;});
 
    // after the wait, we own the lock.
    cout << "Worker thread is processing data\n";
    data_content+= " after processing";
 
    // Send data_contentback to main()
    processed = true;
    cout << "Worker thread signals data_contentprocessing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    
    // lk.unlock();  // automatically unlocks by destructor
    cv.notify_one();
}
 
int main()
{
    thread worker(worker_thread);
 
    data_content= "Example data";
    // send data_contentto the worker thread
    {
        lock_guard lk(m);  //***************************** lockgroud will release mutex or lock after the scope ends
        ready = true;
        cout << "main() signals data_contentready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        unique_lock lk(m);
        cv.wait(lk, []{return processed;});
    }
    cout << "Back in main(), data_content= " << data_content<< '\n';
 
    worker.join();
}



// https://www.youtube.com/watch?v=eh_9zUNmTig

