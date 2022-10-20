#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;




/* 
atomic<int> cnt = 0;
*/





/*
mutex lock1; // defining lock

void task() {
    lock1.lock();
    for(int i = 0; i < 1e6; i++) {
        cnt++;
    }
    lock1.unlock();
}
*/





/*

// Single flag -- Mutually exclusive but not progressive

int cnt = 0;
int turn = 1; 
// int turn = 0;

void taskA() {
    while(turn != 0);
    for(int i = 0; i < 1e6; i++) {
        cnt++;
    } 
    turn = 1;
}


void taskB() {
    while(turn != 1);
    for(int i = 0; i < 1e6; i++) {
        cnt++;
    } 
    turn = 0;
}
*/






/*


// peterson's solution 
// (Code Not working correctly)

int cnt = 0;
int turn;
vector<bool> flag(2,false);

void taskA() {
    while(1) {
        cout << "TASK-A" <<endl;         // to check the order in which the tasks are executed     
        flag[0] = true;
        turn = 1;

        while(turn == 1 and flag[1] == true) 
            cout << " Trapped in task A " << endl;
        

        // while(flag[1] == true)  // just this condition works
        //     cout << " Trapped in task A " << endl;
        

        for(int i = 0; i < 1e6; i++) {
            cnt++;
        }
        flag[0] = false;

        cout << "taskA completed " << endl;

        break;
    }
}


void taskB() {
    while(1) {
        cout << "TASK-B" <<endl;    
        flag[1] = true;
        turn = 0;

        while(turn == 0 and flag[0] == true)
            cout << " Trapped in task B " << endl;


        // while(flag[0] == true)    // just this condition works
        //     cout << " Trapped in task B " << endl;
        

        for(int i = 0; i < 1e6; i++) {
            cnt++;
        } 
        flag[1] = false;

        cout << "taskB completed " << endl;
        
        break;
    }
}





int main() {
    thread t1(taskA), t2(taskB);  // thread t1 is defined first so, may be it is initilized the first.

    t2.join();
    t1.join();  // doesn't let main thread to exit unless t1 thread completes execution 

    cout << cnt << endl;
    return 0;
}






*/ 



int main() {
    thread t1(taskA);
    thread t2(taskB);

    t1.join();  // doesn't let main thread to exit unless t1 thread completes execution 
    t2.join();

    cout << cnt << endl;
    return 0;
}


