#include <iostream>

using namespace std;

int count1(int N){
	int count = 0;
	//So we want to find the sum of all multiples of 3 or 5 below N
	for(int i=0; i<N; i+=3){
		count+=i;
	}
	for(int i=0; i<N; i+=5){
		count+=i;
	}
	//But we have to subtract the intersection of the two so we arent double counting
	for(int i=0; i<N; i+=15){
		count-=i;
	}
	return count;
	//This works but we can do better
	//This is O(n) time but we want O(1)
	//This also doesnt handle large numbers very well
}

long long sumToN(long long x){
	//So we want the sum of all of the numbers to N
	//Knowing a little bit of math will tell you this formula is n(n+1)/2
	return (x*(x+1))/2;
	
}

long long count2(long long N){
	//To get O(1) we need an explicit formula
	//3 + 3(2) + 3(3)
	//3(1+2+3)
	//from this if we know how many times 3 or 5 goes into a number we
	//can find an explicit formula
	N = N-1;
	//Just to make sure we arent counting N itself in our calculations
	//because we want values less than N
	long long threes = N/3;
	long long fives = N/5;
	//we still need to subtract the intersection
	long long fifteens = N/15;
	//voila a O(1) formula
	return 3*sumToN(threes)+5*sumToN(fives)-15*sumToN(fifteens);
}

//After running some test cases I decided to change all of my ints
// to long longs because of large numbers



int main(){
	int N = 0;
	cin >> N;
	
	cout << count1(N) << endl;
	cout << count2(N) << endl;
}	
