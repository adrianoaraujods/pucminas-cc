import java.util.Scanner;

class Palindrome {
    static Scanner scanner = new Scanner(System.in);

    static boolean isPalindrome(String string) {
        boolean palindrome = true;
        int start = 0, end = string.length() - 1;

        while (start < end) {
            if (string.charAt(start) != string.charAt(end)) {
                palindrome = false;
                end = 0;
            }

            start++;
            end--;
        }

        return palindrome;
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

    public static void main(String[] args) {
        String input = scanner.nextLine();

        while (!isEOF(input)) {
            System.out.println(isPalindrome(input) ? "SIM" : "NAO");

            input = scanner.nextLine();
        }
    }
}
