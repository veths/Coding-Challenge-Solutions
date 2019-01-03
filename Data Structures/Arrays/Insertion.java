import java.util.ArrayList;
import java.util.Random;

public class Insertion{
	public static int getMax(ArrayList<Integer> x){
		int max = x.get(0);
		for (Integer n: x){
			if(n>max) max=n;
		}
		return max;
	}
	
	public static int getMin(ArrayList<Integer> x){
		int min = x.get(0);
		for (Integer n: x){
			if(n<min) min=n;
		}
		return min;
	}
	
	public static boolean isSorted(ArrayList<Integer> x){
		for(int i=0; i<x.size()-1; i++){
			if(x.get(i)>x.get(i+1)) return false;
		}
		return true;
	}
	
	public static ArrayList<Integer> sort(ArrayList<Integer> x){
		ArrayList<Integer> copy = new ArrayList<Integer>(x);
		int length = copy.size();
		
		//Insertion Sort
		for(int i=0; i<length-1; i++){
			if(copy.get(i)<copy.get(i+1)) continue;
			//So we know i+1<i
			int j=i+1;
			while(j>=0){
				j--;
				if(j==-1 || copy.get(j)<copy.get(i+1)){
					int temp = copy.get(i+1);
					copy.remove(i+1);
					copy.add(j+1,temp);
					break;
				}
			}
		}
		return copy;
	}
	
	public static void main(String[] args){
		//Make ArrayList
		ArrayList<Integer> arr = new ArrayList<Integer>();
		
		//Make a random Object to generate random numbers
		Random r = new Random();
		
		//Add random numbers to ArrayList
		int nums = 10;
		int range = 1000;
		for(int i=0; i<nums; i++){
			//Make sure all numbers are distinct
			while(true){
				int z = r.nextInt(range+1)-range/2; //Numbers in range [-range/2,range/2]
				if(!arr.contains(z)){
					arr.add(z);
					break;
				}
				continue;
			}
		}
		
		//Print Array
		System.out.println("Array: " + arr);
		//Print min and max of arr
		System.out.println("Max: " + getMax(arr));
		System.out.println("Min: " + getMin(arr));
		//Print sorted array
		ArrayList<Integer> output = sort(arr);
		System.out.println("Sorted: " + output);
		//Assert array is sorted
		System.out.println("is Sorted? " + isSorted(output));
	}
}
