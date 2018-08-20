import java.util.*;

public class ABC {
	public static void main(String args[]) {
		Scanner I = new Scanner(System.in);
		String s = I.nextLine();
		String[] strArray = s.split(" ");
		int[] intArray = new int[strArray.length];
		for(int i = 0; i < strArray.length; i++) {
			intArray[i] = Integer.parseInt(strArray[i]);
		}
		Arrays.sort(intArray);
		String order = I.nextLine();
		for(int j = 0; j < order.length(); j++) {
			if(order.charAt(j) == 'A') {
				System.out.print(intArray[0]);
			}
			else if(order.charAt(j) == 'B') {
				System.out.print(intArray[1]);
			}
			else {
				System.out.print(intArray[2]);
			}
			if(j != order.length() - 1) {
				System.out.print(" ");
			}
		}
	}
}
