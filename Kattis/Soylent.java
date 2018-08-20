import java.util.*;
import java.io.*;

public class Soylent {
	public static void main(String args[]) {
		Scanner I = new Scanner(System.in);
		int a = I.nextInt();
		int[] myarray = new int[a];
		for(int i = 0; i < a; i++) {
			myarray[i] = I.nextInt();
		}
		for(int j = 0; j< a; j++) {
			if(myarray[j] % 400 == 0) {
				System.out.println(myarray[j]/400);
			}
			else {
				System.out.println(1 + myarray[j]/400);
			}
		}
	}
}
