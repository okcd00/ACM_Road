import java.math.*;  
import java.util.*;
//POJ1001 Exponentiation 
public class Main //Change the name as Main.java or Main.class
{  
    public static void main(String[] args)
    {  
        Scanner in=new Scanner(System.in);  
        while(in.hasNext())
        {  
            BigDecimal val=in.nextBigDecimal();  
            int n=in.nextInt();  
            BigDecimal ret=val.pow(n).stripTrailingZeros();  
            System.out.println( ret.toPlainString().replaceAll("^0", "") );  
        }
    }  
}  
