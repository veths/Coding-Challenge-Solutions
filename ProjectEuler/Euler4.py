from math import *

#Check if a number is a palindrome by comparing beginning and
# reverse of the end
def isPalindrome(n):
	n = str(n)
	return n==n[::-1]

def isProduct(n, numset):
	for i in range(100,1000):
		if n/i in numset:
			return True
	return False
		
def palindromeProduct(n):
	x = set([i for i in range(100,1000)])
	while True:
		n-=1
		if isPalindrome(n) and isProduct(n,x):
			return n
