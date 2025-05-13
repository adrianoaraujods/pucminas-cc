import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

class Cipher {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    static String cipherString(String string, int key) {
        String cipheredString = "";

        for (int i = 0; i < string.length(); i++) {
            int charValue = (int) string.charAt(i);

            cipheredString += (char) (charValue + key);
        }

        return cipheredString;
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
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));

        String input = scanner.nextLine();

        while (!isEOF(input)) {
            System.out.println(cipherString(input, 3));

            input = scanner.nextLine();
        }
    }
}
