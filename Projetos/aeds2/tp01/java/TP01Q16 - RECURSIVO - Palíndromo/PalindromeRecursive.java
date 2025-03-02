import java.util.Scanner;

class PalindromeRecursive {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.println(isPalindrome(line) ? "SIM" : "NAO");
        }
    }

    static boolean isPalindrome(String string) {
        return isPalindromeRecursive(string, true, 0, string.length() - 1);
    }

    static boolean isPalindromeRecursive(
            String string, boolean palindrome, int start, int end
    ) {
        boolean result = palindrome;

        if (start < end && palindrome) {
            result = isPalindromeRecursive(string,
                    string.charAt(start) == string.charAt(end),
                    start + 1,
                    end - 1
            );
        }

        return result;
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
}
