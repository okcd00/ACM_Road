import java.io.*;  
import java.math.*;  
import java.util.*;  
//java POJ2305 Basic remains  
public class Main	//Change the name as Main.java or Main.class
{  
    public static void main(String[] args)
    {  
        Scanner in = new Scanner(new BufferedInputStream(System.in));  
        BigInteger a,b;  
        int n;  
        String str;  
        while (true)
        {  
            n = in.nextInt();  
            if (n==0) break;  
            str = in.next();  
            a = new BigInteger(str,n);  
            str = in.next();  
            b = new BigInteger(str,n);  
            a = a.mod(b);  
            System.out.println(a.toString(n));  
        }  
    }  
}  
