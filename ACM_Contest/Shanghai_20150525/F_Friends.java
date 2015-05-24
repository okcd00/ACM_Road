import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		if(k==0) System.out.println("Case #"+z+": "+"1");
		else
		{
			BigInteger ans=BigInteger.valueOf(1);
			for(int i=1;i<=k;i++) ans=ans.multiply(BigInteger.valueOf(32));
			System.out.println("Case #"+z+": "+ans);
		}
	}
}
