



'''
Approach : 

Philosophers on odd indices(1 and 3) are allowed to pick forks, parallely and and complete execution.

Only one of the philosophers on even indices(0, 2, 4) are allowed to pick forks. 
(Use a lock 'even' to let only one philosopher at even index to pick forks)

'''






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
            #rest of philosophers at other even indices are can't pick fork now
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
        