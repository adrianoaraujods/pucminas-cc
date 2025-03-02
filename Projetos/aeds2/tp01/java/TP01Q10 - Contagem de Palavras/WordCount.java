import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class WordCount {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.println(wordCount(line));
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

    static int wordCount(String string) {
        int count = 1;

        for (int i = 0; i < string.length(); i++) {
            if (string.charAt(i) == ' ') count++;
        }

        return count;
    }
}
