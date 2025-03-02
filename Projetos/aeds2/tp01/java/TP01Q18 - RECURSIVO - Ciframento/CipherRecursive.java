import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

class CipherRecursive {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.println(cipherString(line, 3));
        }
    }

    static String cipherString(String string, int key) {
        return cipherStringRecursion(string, key, "");
    }

    static String cipherStringRecursion(String input, int key, String output) {
        String result;

        if(output.length() == input.length()) {
            result = output;
        } else {
            result = cipherStringRecursion(input, key,
                    output + (char) (input.charAt(output.length()) + key)
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
