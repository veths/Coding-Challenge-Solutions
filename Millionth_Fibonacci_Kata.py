def fib(n):
    fib0=0
    fib1=1
    fibn=1
    if n==0:
        return fib0
    if n==1:
        return fib1
    if n<0:
         for i in range(abs(n)):
            fibn=fib1-fib0
            fib1=fib0
            fib0=fibn
            
         return fibn
    else:
        for i in range(n-1):
            fibn=fib0+fib1
            fib0=fib1
            fib1=fibn
        return fibn
    
while True:
	n=int(input())
	print(fib(n))
