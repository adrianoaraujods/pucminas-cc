import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

class Is {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    static char[] vowels = {'a', 'e', 'i', 'o', 'u'};

    public static boolean isOnlyVowels(String string) {
        boolean onlyVowels = true;

        for (int i = 0; i < string.length(); i++) {
            boolean isVowel = false;
            char character = Character.toLowerCase(string.charAt(i));

            for (int j = 0; j < vowels.length; j++) {
                if (character == vowels[j]) {
                    isVowel = true;
                    j = vowels.length;
                }
            }

            if (!isVowel) {
                onlyVowels = false;
                i = string.length();
            }
        }

        return onlyVowels;
    }

    public static boolean isOnlyConsonants(String string) {
        boolean onlyConsonants = true;

        for (int i = 0; i < string.length(); i++) {
            boolean isConsonant = true;
            char character = Character.toLowerCase(string.charAt(i));

            if ((int) character > 96 && (int) character < 123) {
                for (int j = 0; j < vowels.length; j++) {
                    if (character == vowels[j]) {
                        isConsonant = false;
                        j = vowels.length;
                    }
                }
            } else isConsonant = false;

            if (!isConsonant) {
                onlyConsonants = false;
                i = string.length();
            }
        }

        return onlyConsonants;

    }

    public static boolean isInteger(String string) {
        boolean integer = true;

        for (int i = 0; i < string.length(); i++) {
            if ((int) string.charAt(i) < 48 || (int) string.charAt(i) > 57) {
                integer = false;
                i = string.length();
            }
        }

        return integer;
    }

    public static boolean isFloat(String string) {
        boolean isFloat = true;
        boolean hasFraction = false;

        for (int i = 0; i < string.length(); i++) {
            if ((int) string.charAt(i) < 48 || (int) string.charAt(i) > 57) {
                if (!hasFraction && (string.charAt(i) == '.' || string.charAt(i) == ',')) {
                    hasFraction = true;
                } else {
                    isFloat = false;
                    i = string.length();
                }
            }
        }

        return isFloat;
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
            System.out.print(isOnlyVowels(input) ? "SIM" : "NAO");
            System.out.print(isOnlyConsonants(input) ? " SIM" : " NAO");
            System.out.print(isInteger(input) ? " SIM" : " NAO");
            System.out.print(isFloat(input) ? " SIM\n" : " NAO\n");

            input = scanner.nextLine();
        }
    }
}