
import java.math.*; 
import java.util.*;

public class Main { 	 	
	public static void main(String[] args){ 		
		BigInteger fac[] = new BigInteger[3100]; 		
		Scanner cin = new Scanner(System.in); 		
		fac[0] = fac[1] = BigInteger.ONE; 		
		for(int i = 2; i <= 3000; i++){ 			
			fac[i] = fac[i-1].multiply(BigInteger.valueOf(i)); 		
		} 		
		int T, n; 		
		
		T = cin.nextInt(); 		
		for(int j = 1; j <= T; j++){ 		
			n = cin.nextInt();
			BigInteger ans = BigInteger.ZERO;
			for(int i = 1; i <= n; i++){
				ans = ans.add(fac[n].divide(BigInteger.valueOf(i)));
			}
			System.out.println(ans + ".0"); 			 		
		} 	
	} 
}