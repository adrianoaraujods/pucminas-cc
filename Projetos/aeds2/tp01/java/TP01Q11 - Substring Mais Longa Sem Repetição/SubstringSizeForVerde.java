import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class SubstringSizeForVerde {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String line;
        int counter = 0;

        while (!isEOF(line = scanner.nextLine())) {
            counter++;
            if(counter == 4) System.out.println(0);

            System.out.println(longestSubstringSize(line));

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

    static int longestSubstringSize(String string) {
        int longest = 0, length = 1, start = 0;

        for (int i = 0; i < string.length() - 1; i++) {
            boolean newChar = true;

            for (int j = i; j >= start; j--) {
                if (string.charAt(i + 1) == string.charAt(j)) {
                    newChar = false;
                    if (length > longest) longest = length;
                    start = j + 1;
                    length = i + 1 - j;
                    j = 0;
                }
            }

            if (newChar) {
                length++;
            }
        }

        if (length > longest) longest = length;

        return longest;
    }
}
