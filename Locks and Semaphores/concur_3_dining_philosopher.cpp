


// https://leetcode.com/problems/the-dining-philosophers/   <-- problem link

// https://leetcode.com/submissions/detail/826546856/    <-- submission link 

using namespace std;
class Semaphore {
    private:
    mutex m;
    condition_variable cv;
    int count;
    
    public:

	Semaphore() {}
    Semaphore(int c): count(c){};

    void setCount(int a) {
        count = a;
    }
    
    inline void signal() {
        unique_lock<mutex> lk(m);
        count++;
        if(count <= 0)
            cv.notify_one();
    }
    
    inline void wait() {
        unique_lock<mutex> lk(m);
        count--;
        while(count < 0) {
            cv.wait(lk);
        }
    }    
};


class DiningPhilosophers {
public:
    Semaphore fork[5];
    mutex m, l;    

    DiningPhilosophers() {    
        for(int i = 0; i < 5; i++) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int p,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        
        
        {
            lock_guard<mutex> lk(m);
            fork[p].wait();
            fork[(p+1)%5].wait();
        }
        
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        fork[(p+1)%5].signal();
        putRightFork();
        fork[p].signal();
    }
};