from threading import *
import time
import random


'''
https://www.youtube.com/watch?v=KpAjnBKn3XE&t=3019s   <-- Complete video explanation
'''

class DiningPhilosophers:
	def __init__(self, number_of_philosophers=5, meal_size=7):
		
		self.number_of_philosophers = number_of_philosophers
		self.meal_size = meal_size

		self.meals = [meal_size for _ in range(number_of_philosophers)]
		self.chopsticks = [Lock() for _ in range(number_of_philosophers)]
		
		self.status = ['  T  ' for _ in range(number_of_philosophers)]
		'''
			status
			'  T  ' <- Thinking
			'  -  ' <- decide to eat
			'  E  ' <- Eat
		'''

		self.chopstick_holders = ['     ' for _ in range(number_of_philosophers)]




	def philosopher(self, i): # i - index of the ith philosopher
		j = (i+1) % self.number_of_philosophers
		while(self.meals[i] > 0):
			self.status[i] = '  T  '   
			time.sleep(random.random()) # phi thinking
			self.status[i] = '  -  '

			if not self.chopsticks[i].locked():
				self.chopsticks[i].acquire()
				self.chopstick_holders[i] = ' /   '
				time.sleep(random.random())

				if not self.chopsticks[j].locked():
					self.chopsticks[j].acquire()
					self.chopstick_holders[i] = ' / \ '
					# having 2 chopsticks we can change the status 
					self.status[i] = '  E  '

					time.sleep(random.random())

					self.meals[i] -= 1	
					self.chopsticks[j].release()
					self.chopstick_holders[i] = ' /   '
					self.chopsticks[i].release()
					self.chopstick_holders[i] = '     '
					self.status[i] = '  T  '

				else:
					self.chopsticks[i].release()
					self.chopstick_holders[i] = '     '
			


def main():
	n = 10  # number of phi
	m = 9   # meal size
	dining_philosophers = DiningPhilosophers(n,m)
	philosophers = [Thread(target = dining_philosophers.philosopher, args = (i,)) for i in range(n)]
	for philosopher in philosophers:
		philosopher.start()
		time.sleep(0.2)

	while sum(dining_philosophers.meals) > 0:
		print("=" * (n*5))
		print("".join(map(str, dining_philosophers.status)), " : ",
			  str(dining_philosophers.status.count('  E  ')))
		print("".join(map(str, dining_philosophers.chopstick_holders)))
		print("".join("{:3d}  ".format(m) for m in dining_philosophers.meals), " : ",
				str(sum(dining_philosophers.meals)))
		time.sleep(0.1)

	for philosopher in philosophers:
		philosopher.join()


if __name__ == "__main__":
	main()
