import java.util.*;
import java.io.*;

public class Aaah {
	public static void main(String args[]) {
		Scanner I = new Scanner(System.in);
		String hecansay = I.nextLine();
		String doctorwants = I.nextLine();
		if(hecansay.length() >= doctorwants.length()) {
			System.out.println("go");
		}
		else {
			System.out.println("no");
		}
	}

}
