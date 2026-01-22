import java.util.Scanner;
class MatrixAddition {
	public static void main(String[] ar) {
		int m,n;
		int[][] a = new int[10][10];
		int[][] b = new int[10][10];
		int[][] c = new int[10][10];
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of Row : ");
		m = sc.nextInt();
		System.out.println("Enter the size of Column : ");
		n = sc.nextInt();
		 
		System.out.println("Enter the first Matrix : ");
		for(int i = 0;i < m;i ++){
			for(int j = 0; j < n; j ++) {
				a[i][j] = sc.nextInt();
			}
		}
		
		System.out.println("Enter the Second Matrix : ");
		for(int i = 0;i < m;i ++){
			for(int j = 0; j < n; j ++) {
				b[i][j] = sc.nextInt();
			}
		}
		
		
		System.out.println("First Matrix : ");
		for(int i = 0;i < m;i ++){
			for(int j = 0; j < n; j ++) {
				System.out.print(a[i][j] + "\t");
			}
			System.out.println("\n");
		}
		
		System.out.println("Second Matrix : ");
		for(int i = 0;i < m;i ++){
			for(int j = 0; j < n; j ++) {
				System.out.print(a[i][j] + "\t");
			}
			System.out.println("\n");
		}
		
		System.out.println("Addition : \n");
		for(int i = 0;i < m;i ++){
			for(int j = 0; j < n; j ++) {
				c[i][j] = a[i][j] + b[i][j];
				System.out.print(c[i][j] + "\t");
			}
			System.out.println("\n");
		}
		
	}
}
		
		
		
		
		
