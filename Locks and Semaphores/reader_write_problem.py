from threading import *
import time
import random


"""
Let a the string type variable s_res be our shared resource and cirtical section
"""

s_res = ""
mutex = Semaphore(1)   # locks are binary semaphores, so you can also use locks
wrt = Semaphore(1)  # same as above

read_count = 0  # how many readers are reading critical section


def writer(name, content):
	global s_res
	wrt.acquire()

	print(f"{name} writing")
	s_res = s_res + content
	print()
	time.sleep(1)
	
	wrt.release()


def reader(name):

	global read_count, s_res


	# mutex to update read_count variable, bcz count++ is not a atomic operation
	mutex.acquire()
	read_count += 1
	if (read_count == 1):
		wrt.acquire()		# bcz, wrt semph.. (1), 1 (so, writer thread value change -> 1/0 -> so already 1 hai to yaha zero hokar block
							#                                -> aur agar 0 hai to -1 bhi block)                                                                          
	mutex.release()


	
	print(f"{name} reading")
	if (s_res == ""):  # condition bcz for empty string nothing is printed
		print("''")   
	else:
		print(s_res)
	print()
	time.sleep(1)



	# mutex to update read_count variable, bcz count-- is not a atomic operation
	mutex.acquire()
	read_count -= 1
	if(read_count == 0):
		wrt.release()    # wrt release karne time -> don't matter wrt negative hai, agar blocklist me koi hai, to release call karne pe release 
								#    ho jayega
	mutex.release()




if __name__ == '__main__':

	print()
	print("[+] Start")
	print()

	t1 = Thread(target=reader, args=('Thread-1',))
	t2 = Thread(target=reader, args=('Thread-2',))
	t3 = Thread(target=writer, args=('Thread-3', "abcd"))
	t4 = Thread(target=writer, args=('Thread-4', "efgh"))
	t5 = Thread(target=writer, args=('Thread-5', "uvwx"))
	t6 = Thread(target=reader, args=('Thread-6',))
	t7 = Thread(target=writer, args=('Thread-7', "mnop"))

		
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

	for i in range(10):
		num = random.randint(0,100);
		if(num % 2 == 0):
			t1 = Thread(target = reader, args = (f'Thread-{8 + i}',))
			t1.start()
			t1.join()
		else:
			t2 = Thread(target = writer, args = (f'Thread-{8 + i}',f"  written by thread {8+i} "))
			t2.start()
			t2.join()



	print(s_res)
	print()
	print("[+] Done")
