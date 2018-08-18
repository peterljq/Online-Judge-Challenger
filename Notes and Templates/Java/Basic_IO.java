import java.util.*;
import java.io.*;
public class Basic_IO{
	public static void main(String args[]) //throws IOException
	{
		
		//Collect char using (char) system.in.read()
		System.out.println("Pls input a character and I will output its neighbor: ");
		try {
			char c = (char) System.in.read();
			System.out.printf("The neighbor character of %c in ASCII is: %c\n",c,c+1);
		}catch(IOException e) {}
		
		//Collect string, int, double using readLine method
		BufferedReader I = new BufferedReader(new InputStreamReader(System.in));
		String s = null;
		System.out.print("Pls input a string: \n");
		try{
			s = I.readLine(); 
			s = I.readLine(); //I also dont know why to put readLine twice, but in this case only readLine twice works fine.
			System.out.printf("Let's trverse your %s: ",s);
			for(int i = 0;i<s.length();i++) {
				char traverse = s.charAt(i);
				System.out.printf("%c ",traverse);
			}
			System.out.println();
		}catch(IOException e){}
		
		System.out.println("Pls input an integer and I will do an increment: ");
		try {
			s = I.readLine();
			int convert = Integer.parseInt(s);
			System.out.printf("The increment of %d is %d\n",convert,convert + 1);
		}catch(IOException e) {}
		
		System.out.printf("pls input a double and I will produce its cube: \n");
		try {
			s = I.readLine();
			double convertdd = Double.parseDouble(s);
			System.out.printf("The cube of %f is %f\n",convertdd,convertdd*convertdd*convertdd);
		}catch(IOException e) {}
		
		//Collect string, int, double using scanner
		Scanner II = new Scanner(System.in);
		System.out.printf("Pls input a string: \n");
		String ss = II.nextLine();
		System.out.println("The string that you input is: " + ss);
		
		System.out.println("Pls input an integer and I will output its square: ");
		int a = II.nextInt(); //double a = II.nextDouble();
		System.out.printf("%d is the square of %d\n",a*a,a);
	}
}
