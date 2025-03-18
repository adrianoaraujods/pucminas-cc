import java.util.Scanner;

public class MirrorSequence {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (scanner.hasNext()) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();

            mirrorSequence(start, end);
        }
    }

    static void mirrorSequence(int start, int end) {
        for (int i = start; i <= end; i++) {
            System.out.print(i);
        }

        for (int i = end; i >= start; i--) {
            printDigitsInverted(i);
        }

        System.out.println();
    }

    static void printDigitsInverted(int number) {
        if (number < 10) {
            System.out.print(number);
        } else {
            System.out.print(number % 10);

            printDigitsInverted(number / 10);
        }
    }
}
