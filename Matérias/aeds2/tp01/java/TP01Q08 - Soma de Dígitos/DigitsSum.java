import java.util.Scanner;

public class DigitsSum {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.println(digitsSum(Integer.parseInt(line)));
        }
    }

    static boolean isEOF(String line) {
        boolean eof = true;
        String flag = "FIM";

        if (flag.length() == line.length()) {
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(i) != flag.charAt(i)) {
                    eof = false;
                    i = flag.length();
                }
            }
        } else {
            eof = false;
        }

        return eof;
    }

    static int digitsSum(int number) {
        int sum = 0;

        while (number > 0) {
            sum += number % 10;
            number -= number % 10;
            number /= 10;
        }

        return sum;
    }
}
