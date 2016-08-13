package monkey;
import java.util.Scanner;
import java.util.Arrays;

public class uva10892 
{
	public static void main(String[] args) 
	{
		Scanner sf = new Scanner(System.in);
		long n;
		long ar[] = new long[ 10000 ];
		while(sf.hasNext())
		{
			n = sf.nextInt();
			if(n == 0) break;
			if(n == 1) 
			{
				System.out.println("1 1");
				continue;
			}
			int srt = (int)Math.sqrt(n) + 1, res = 0, cou = 0;
			ar = new long[ar.length];
			for(int i = 1; i < srt; i++)
			{
				if(n % i == 0)
				{
					ar[ cou++ ] = i;
					if(n / i != i) ar[ cou++ ] = n / i;
				}
			}
			Arrays.sort(ar, 0, cou);
			//for(int i = 0; i < cou; i++) System.out.println(ar[i]);
			for(int i = 0; i < cou; i++)
				for(int j = i; j < cou; j++)
				{
					long gcd = ar[ i ] * ar[ j ] /  GCD(ar[ i ], ar[ j ]);
					//System.out.print(gcd + " ");
					if(gcd == n) res++;
				}
			System.out.println(n + " " + res);
		}
	}
	
	public static long GCD(long a, long b) { return b==0 ? a : GCD(b, a%b); }
}