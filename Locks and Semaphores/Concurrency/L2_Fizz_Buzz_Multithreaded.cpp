
class FizzBuzz {

private:
    mutex m;
    condition_variable cv;
    int n;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n) {
            
            unique_lock<mutex> lk(m);

            while(  (i <= n) ) {

                if((i % 3 == 0) and (i % 5 != 0)) break;    
                cv.wait(lk);
            }

            if(i <= n) {
                printFizz();
                i += 1;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        
        while(i <= n) {

            unique_lock<mutex> lk(m);
            while(i <= n) {

                if((i%5 == 0) and (i%3 != 0)) break;
                cv.wait(lk);
            }

            if(i <= n) {
                printBuzz();
                i += 1;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while(i <= n) {
            
            unique_lock<mutex> lk(m);
            while(i <= n) {

                if((i%5 == 0) and (i%3 == 0))break;
                cv.wait(lk);
            }

            if(i <= n) {
                printFizzBuzz();
                i += 1;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n) {
            
            unique_lock<mutex> lk(m);
            while(i <= n) {

                if((i%5 != 0) and (i%3 != 0)) break;
                cv.wait(lk);
            }
            
            if(i <= n) {
                printNumber(i);
                i += 1;
            }
            cv.notify_all();
        }
    }
};