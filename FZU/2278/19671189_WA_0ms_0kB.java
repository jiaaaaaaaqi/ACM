import java.math.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args){
		BigDecimal fac[] = new BigDecimal[3100];
		Scanner cin = new Scanner(System.in);
		fac[0] = fac[1] = BigDecimal.ONE;
		for(int i = 2; i <= 3000; i++){
			fac[i] = fac[i-1].multiply(BigDecimal.valueOf(i));
		}
		int T;
		double n;
		Double[] dp = new Double[3100];
		
		T = cin.nextInt();
		for(int j = 1; j <= T; j++){
			n = cin.nextDouble();
			dp[(int)n] = 0.0;
			double k = n-1;
			for(int i = (int)n-1; i >= 0; i--){
				double ans = n/(n-k);
				dp[i] = ans+dp[i+1];
				k--;
				
			}
			BigDecimal a;
			a = fac[(int)n-1].multiply(BigDecimal.valueOf(dp[0]));
			
			System.out.println(a.setScale(1, RoundingMode.HALF_UP));
			
		}
	}
}
