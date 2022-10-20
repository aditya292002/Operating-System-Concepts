





// https://leetcode.com/problems/print-in-order/submissions/





///////////////////////////****************     Code     ***************//////////////////////////////////////

using namespace std;
mutex m;
condition_variable cv;
int turn;


class Foo {

public:

    
    Foo() {
        turn = 0;
    }
    
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1;
        cv.notify_all();        
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(m);
        
        cv.wait(lk, []{return (turn == 1);});
        /*
        or
        while(turn != 2) {
            cv.wait(lk);
        }

        both work in almost same way

        */


        printSecond();
        turn = 2;

        cv.notify_one();
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lk(m);


        cv.wait(lk, [this]{return (turn == 2);});
        /*
        or
        while(turn != 2) {
            cv.wait(lk);
        }
    
        both work in almost same way
        */

        printThird();
    }
};