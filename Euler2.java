import java.util.*;

public class Euler2{
	
	//Sum of all even fibonacci
	//So generate the fibonacci numbers and add even ones to sum up to n
	public static long getEvenSum(long n){
            long fib0=0;
            long fib1=1;
            long fibn=1;
            long sum=0;
            while(fibn<n){
                if(fibn%2==0) sum+=fibn;
                fibn = fib0 + fib1;
                fib0 = fib1;
                fib1 = fibn;
            }
            return sum;
    }
	
	public static void main(String[] args){
		System.out.println(getEvenSum(10)); //10
		System.out.println(getEvenSum(100)); //44
	}
}
