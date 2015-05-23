import java.io.*;  
import java.math.*;  
import java.util.*;  
//java POJ1131 Octal Fractions
public class Main
{  
    public static void main(String[] args)
    {  
        Scanner in = new Scanner(new BufferedInputStream(System.in));  
        //BigDecimal one = new BigDecimal(1);  
        BigDecimal eight = new BigDecimal(8);  
        String s;  
        while (in.hasNext())  
        {  
            s = in.nextLine();  
            BigDecimal ans = new BigDecimal(0);  
            BigDecimal wei = new BigDecimal(1);  
            for (int i=2;i<s.length();i++)
            {  
                wei = wei.divide(eight);//通过wei来控制数位  
                //System.out.println(wei.toString());  
                ans = ans.add(new BigDecimal(s.charAt(i)-48).multiply(wei));  
                //System.out.println(ans);  
                //public char charAt(int index)返回指定索引处的 char 值。索引范围为从 0 到 length() - 1。
                //序列的第一个 char 值位于索引 0 处，第二个位于索引 1 处，依此类推，这类似于数组索引。  
                //multiply()为高精度乘法。  
                //把char型数字转换成的int型数字-48，因为它们的ASCII码值恰好相差48  
            }  
            System.out.println(s+" [8] = "+ans.toString()+" [10]");  
        }  
    }  
}  
