import java.util.*;

public class nthFibonacci {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the Number : ");
		int n = in.nextInt();
		int[] a = new int[n+1];

		System.out.println(fibonacciRecursive(n,a));	
	}
	private static int fibonacciRecursive(int n, int[] a) {
		if(n <= 1){
			return n;
		}else if(a[n] == 0) {
			a[n] = fibonacciRecursive(n-1, a) + fibonacciRecursive(n-2,a);
		}
		return a[n];

	}
}