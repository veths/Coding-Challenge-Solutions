from math import *

def isPrime(n):
	divs = 0
	for i in range(1,int(sqrt(n))+1):
		if n%i==0:
			divs+=1
	return divs<2

def largestPfactor(n):
	maxp = 0
	if isPrime(n):
		return n
	#I modified my for loop and reimplemented it as a while loop
	# in order reduce n every time a prime factor was found
	i = 1
	while(i<n):
		i+=1
		if (n%i==0 and isPrime(i)):
			maxp=i
			print(maxp)
			while(n%maxp==0):
				n=n//maxp
	"""	
	for i in range(1,n+1):
		if (n%i==0 and isPrime(i)):
			maxp = i
			"""
	return maxp
	
print(largestPfactor(1))
