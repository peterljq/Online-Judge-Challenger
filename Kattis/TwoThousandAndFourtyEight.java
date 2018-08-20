import java.util.*;
import java.io.*;

public class TwoThousandAndFourtyEight {
	public static void main(String args[]) {
		Scanner I = new Scanner(System.in);
		int[][] gamesquare = new int[5][4];
		readMatrix(gamesquare);
		playMatrix(gamesquare);
		printSquareMatrix(gamesquare);
	}
	
	private static void printSquareMatrix(int[][] m) {
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 3; j++) {
				System.out.print(m[i][j] + " ");
			}
			System.out.println(m[i][3]);
		}
	}
	private static void readMatrix(int[][] m) {
		Scanner I = new Scanner(System.in);
		for(int j = 0; j < 4; j++) {
			m[4][j] = 9999;
		}
		for(int i = 0; i < 5; i++) {
			String s = I.nextLine();
			String[] myarray = s.split(" ");
			for(int j = 0; j < myarray.length; j++) {
				m[i][j] = Integer.parseInt(myarray[j]);
			}
		}
	}
	
	private static void playMatrix(int[][] m) {
		for(int aa = 0; aa < 4; aa++) {
			if(m[4][aa] == 9999) {}
			if(m[4][aa] == 0) {
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int i = 0; i < 4; i++) {
						for(int j = 0; j < 3; j++) {
							if(m[i][j] == 0) {
								m[i][j] += m[i][j+1];
								m[i][j+1] = 0;
							}
						}
					}
				}
				//Merge
				for(int i = 0; i < 4; i++) {
					for(int j = 0; j < 3; j++) {
						if(m[i][j] == m[i][j+1]) {
							m[i][j] += m[i][j+1];
							m[i][j+1] = 0;
						}
					}
				}
			
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int i = 0; i < 4; i++) {
						for(int j = 0; j < 3; j++) {
							if(m[i][j] == 0) {
								m[i][j] += m[i][j+1];
								m[i][j+1] = 0;
							}
						}
					}
				}
			}
			
			if(m[4][aa] == 2) {
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int i = 0; i < 4; i++) {
						for(int j = 3; j > 0; j--) {
							if(m[i][j] == 0) {
								m[i][j] += m[i][j-1];
								m[i][j-1] = 0;
							}
						}
					}
				}
				//Merge
				for(int i = 0; i < 4; i++) {
					for(int j = 3; j > 0; j--) {
						if(m[i][j] == m[i][j-1]) {
							m[i][j] += m[i][j-1];
							m[i][j-1] = 0;
						}
					}
				}
			
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int i = 0; i < 4; i++) {
						for(int j = 3; j > 0; j--) {
							if(m[i][j] == 0) {
								m[i][j] += m[i][j-1];
								m[i][j-1] = 0;
							}
						}
					}
				}
			}
			
			if(m[4][aa] == 3) {
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int j = 0; j < 4; j++) {
						for(int i = 3; i > 0; i--) {
							if(m[i][j] == 0) {
								m[i][j] += m[i-1][j];
								m[i-1][j] = 0;
							}
						}
					}
				}
				//Merge
				for(int j = 0; j < 4; j++) {
					for(int i = 3; i > 0; i--) {
						if(m[i][j] == m[i-1][j] ) {
							m[i][j] += m[i-1][j];
							m[i-1][j] = 0;
						}
					}
				}
			
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int j = 0; j < 4; j++) {
						for(int i = 3; i > 0; i--) {
							if(m[i][j] == 0) {
								m[i][j] += m[i-1][j];
								m[i-1][j] = 0;
							}
						}
					}
				}
			}
			if(m[4][aa] == 1) {
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int j = 0; j < 4; j++) {
						for(int i = 0; i < 3; i++) {
							if(m[i][j] == 0) {
								m[i][j] += m[i+1][j];
								m[i+1][j] = 0;
							}
						}
					}
				}
				//Merge
				for(int j = 0; j < 4; j++) {
					for(int i = 0; i < 3; i++) {
						if(m[i][j] == m[i+1][j]) {
							m[i][j] += m[i+1][j];
							m[i+1][j] = 0;
						}
					}
				}
				//Clear 0
				for(int t = 0; t < 3; t++) {
					for(int j = 0; j < 4; j++) {
						for(int i = 0; i < 3; i++) {
							if(m[i][j] == 0) {
								m[i][j] += m[i+1][j];
								m[i+1][j] = 0;
							}
						}
					}
				}
			}
		}
	}
}
