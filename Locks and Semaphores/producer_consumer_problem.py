from threading import *
import time


CAPACITY = 3
buffer = []


# Binary Semaphore -- used to lock buffer (critical section) by both producer and consumer
"""
	Why ??

	1) Only one producer can produce at a time, bcz the production might not be a atomic opeartion and as a result 
		produce inconsistent data, vice-versa for consumer

	2) Once producer is producing, consumer doesn't consume, bcz, this still can produce inconsistent data, vice-versa for consumer

"""

mutex = Semaphore(1)  


empty = Semaphore(CAPACITY)  
full = Semaphore(0)
# Semaphore(x) -- x number of threads get parallel execution access


def producer(name, val):
	empty.acquire()
	mutex.acquire()

	print(f"{name} producing")
	buffer.append(val)
	print()
	time.sleep(1)

	mutex.release()
	full.release()

def consumer(name):
	full.acquire()
	mutex.acquire()

	print(f"{name} consuming")
	ans = buffer.pop()
	print(f"{ans} consumed")
	print()

	time.sleep(1)

	mutex.release()
	empty.release()


if __name__ == '__main__':	

	print()
	print("[+] Start")
	print()

	t1 = Thread(target = producer, args = ('Thread-1', 1))
	t2 = Thread(target = consumer, args = ('Thread-2',))
	t3 = Thread(target = producer, args = ('Thread-3', 2))
	t4 = Thread(target = producer, args = ('Thread-4', 3))
	t5 = Thread(target = producer, args = ('Thread-5', 4))
	t6 = Thread(target = producer, args = ('Thread-6', 5))
	t7 = Thread(target = consumer, args = ('Thread-7',))

	t1.start()
	t2.start()
	t3.start()
	t4.start()
	t5.start()
	t6.start()
	t7.start()

	
	t1.join()
	t2.join()
	t3.join()
	t4.join()
	t5.join()
	t6.join()
	t7.join()


	print(buffer)
	print()
	print("[+] Done")