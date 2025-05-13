import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static int n;
    static int total = 0;
    static int coelhos = 0;
    static int ratos = 0;
    static int sapos = 0;

    public static void main(String[] args) {
        n = scanner.nextInt();

        for(int i = 0; i < n; i++) {
            int amount = scanner.nextInt();
            char type = scanner.nextLine().charAt(1);

            switch(type) {
                case 'C':
                    coelhos += amount;
                    break; 
                case 'R': 
                    ratos += amount;
                    break; 
                case 'S': 
                    sapos += amount;
                    break; 
            }
        }

        total = coelhos + ratos + sapos;

        System.out.println("Total: " + total + " cobaias");
        System.out.println("Total de coelhos: " + coelhos);
        System.out.println("Total de ratos: " + ratos);
        System.out.println("Total de sapos: " + sapos);
        System.out.println("Percentual de coelhos: " + Math.floor((float) coelhos * 10000 / total) / 100 + " %");
        System.out.println("Percentual de ratos: " + Math.floor((float) ratos * 10000 / total) / 100 + " %");
        System.out.println("Percentual de sapos: " + Math.floor((float) sapos * 10000 / total) / 100 + " %");
    }
}
