import java.util.*;
import java.io.*;

public class MatrixReader {
	public static void main(String args[]) {
		Scanner I = new Scanner(System.in);
		int[][] mymatrix = new int[4][4];
		for(int i = 0; i < 4; i++) {
			String s = I.nextLine();
			String[] myarray = s.split(" ");
			for(int j = 0; j < 4; j++) {
				mymatrix[i][j] = Integer.parseInt(myarray[j]);
			}
		}
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				System.out.print(mymatrix[i][j] + " ");
			}
			System.out.println();
		}
	}

}
