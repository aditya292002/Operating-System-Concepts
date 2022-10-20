

# https://leetcode.com/problems/the-dining-philosophers/   <-- problem link

# https://leetcode.com/submissions/detail/826536027/       <-- submission link 

from threading import *

class DiningPhilosophers:
    
    def __init__(self, np=5):
        self.np = np
        self.fork = [Lock() for i in range(np)]
        self.even = Lock()
        # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   phi: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        
        

        

        if(phi%2 == 0):
            self.even.acquire()
            
        i = phi
        j = ((phi + 1) % 5)

        self.fork[i].acquire()
        self.fork[j].acquire()

        pickLeftFork()
        pickRightFork()

        eat()

        putLeftFork()
        putRightFork()

        self.fork[i].release()
        self.fork[j].release()

                
                
        if(i%2 == 0):
            self.even.release()
        