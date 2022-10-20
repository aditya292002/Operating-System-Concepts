from threading import *
import time
import random

count_phi = int(input("Enter no. of Philosopher: "))
print()

fork = [Semaphore(1) for n in range(count_phi)] #initialising array of semaphore i.e forks
mutex = [Semaphore(1) for n in range(count_phi)] #initialising array of semaphore i.e forks


def pick_fork(name, i):
	mutex[i].acquire()
	fork[i].acquire();
	fork[(i+1) % count_phi].acquire();
	mutex[i].release()	


	print(name)
	print (f'Philosopher eating, by {name}')
	print(f'forks begin used {i} and  {((i + 1) % count_phi)}')
	time.sleep(3)
	print(f"Done eating {name}")
	print()

	mutex[i].acquire()
	fork[i].release()
	fork[(i + 1) % count_phi].release()
	mutex[i].release()
	print(f'-----------------------{name} exited----------------------------------')



def main():
	print()
	print("[+] Start")
	print()

	for i in range(count_phi):
		t = Thread(target=pick_fork, args=(f'Thread-{i}',i))
		t.start()
		t.join()



	# or 


	# t1 = Thread(target=pick_fork, args=('Thread-1',0))
	# t2 = Thread(target=pick_fork, args=('Thread-2',1))
	# t3 = Thread(target=pick_fork, args=('Thread-3',2))
	# t4 = Thread(target=pick_fork, args=('Thread-4',3))
	# t5 = Thread(target=pick_fork, args=('Thread-5',4))

		
	# t1.start()
	# t2.start()
	# t3.start()
	# t4.start()
	# t5.start()

	
	# t1.join()
	# t2.join()
	# t3.join()
	# t4.join()
	# t5.join()

	print()
	print("[+] Done")


if __name__ == '__main__':
	main()