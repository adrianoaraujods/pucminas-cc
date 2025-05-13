import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class ReverseString {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String line = scanner.nextLine();

        while (!isEOF(line)) {
            System.out.println(reverseString(line));

            line = scanner.nextLine();
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

    static String reverseString(String string) {
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = string.length() - 1; i >= 0; i--) {
            stringBuilder.append(string.charAt(i));
        }

        return stringBuilder.toString();
    }
}
