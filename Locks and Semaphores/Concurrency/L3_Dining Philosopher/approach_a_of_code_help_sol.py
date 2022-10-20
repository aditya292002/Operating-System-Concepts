



'''
Approach : 
Allow at most 4 ph. To be sitting simultaneously.

'''


# https://leetcode.com/problems/the-dining-philosophers/   <-- problem link

# https://leetcode.com/submissions/detail/826536027/       <-- submission link 

from threading import *

class DiningPhilosophers:
    
    def __init__(self, np=5):
        self.np = np
        self.fork = [Lock() for i in range(np)]
        self.allow_4 = Semaphore(4)

        
    def wantsToEat(self,
                   p: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        

        self.allow_4.acquire()
        
        self.fork[p].acquire()
        self.fork[(p+1)%5].acquire()
        pickLeftFork()
        pickRightFork()
        
        eat()

        self.fork[p].release()
        self.fork[(p+1)%5].release()
        putLeftFork();
        putRightFork();
        self.allow_4.release()