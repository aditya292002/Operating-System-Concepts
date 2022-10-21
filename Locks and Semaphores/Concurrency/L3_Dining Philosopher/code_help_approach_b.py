

#  https://leetcode.com/problems/the-dining-philosophers/   <-- problem link

#  https://leetcode.com/submissions/detail/826546856/    <-- submission link 


'''
Allow a ph. To pick up his fork only if both forks are available and to do this, he must
pick them up in a critical section (atomically).

'''

from threading import *

class DiningPhilosophers:
    def __init__(self, np=5):
        self.np = np
        self.fork = [Semaphore() for i in range(np)]
        self.m = Lock()
    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   p: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        


        ''' 
        locks helps to allow atomic opeartion 
        so, 
        when the C.S is held it is exec. first -> mutex is unlocked -> so, m is always available for next 
        operation
        '''
        self.m.acquire()


        # C.S start
        self.fork[p].acquire()
        self.fork[(p+1)%5].acquire()
        #C.S end
        
        self.m.release()

        pickLeftFork()
        pickRightFork()
        
        eat()
        
        putLeftFork()
        self.fork[(p+1)%5].release()
        putRightFork()
        self.fork[p].release()