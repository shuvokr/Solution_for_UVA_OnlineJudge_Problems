import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
  public static void main(String[] args) {
    
    Scanner input = new Scanner(System.in);
    int n;
    BigDecimal val;
    n = input.nextInt();
    
    while ( n-- > 0 ) {
      BigDecimal sum = new BigDecimal("0");
      while ( true ) {
        val = input.nextBigDecimal();
        if ( val.equals(BigDecimal.ZERO) ) break;
        
        sum = sum.add(val);
        
      }
      
      int i = new Integer(0);
      
      char out[] = sum.toString().toCharArray();
      
      int len;
      
      for (len=out.length-1 ; len>0 && out[len]=='0' ; len--);
      if (len>0 && out[len]=='.') len--;
      for (i=0 ; i<=len ; i++) {
        System.out.print(out[i]);
      }
      System.out.println();
      
    }
    
  }
}