import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Random;
import java.util.Scanner;

class RandomSwitch {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);
    static Random generator = new Random();

    static char randomChar() {
        return (char) ((int) 'a' + (Math.abs(generator.nextInt()) % 26));
    }

    static String randomSwitchLine(String line) {
        String string = "";
        char swapChar = randomChar();
        char swapBy = randomChar();

        for (int i = 0; i < line.length(); i++) {
            string += line.charAt(i) == swapChar ? swapBy : line.charAt(i);
        }

        return string;
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

        generator.setSeed(4);
        String line = scanner.nextLine();

        while (!isEOF(line)) {
            System.out.println(randomSwitchLine(line));

            line = scanner.nextLine();
        }
    }
}