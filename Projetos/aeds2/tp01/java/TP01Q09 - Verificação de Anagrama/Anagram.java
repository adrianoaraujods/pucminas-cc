import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.text.Normalizer;
import java.util.Scanner;

public class Anagram {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String[] words = readLine();

        while (!isEOF(words[0])) {
            System.out.println(isAnagram(words[0], words[1]) ? "SIM" : "NÃO");

            words = readLine();
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

    static String[] readLine() {
        String line = scanner.nextLine();

        StringBuilder stringBuilder1 = new StringBuilder();
        StringBuilder stringBuilder2 = new StringBuilder();

        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) == ' ') {
                i += 3;

                while (i < line.length()) {
                    stringBuilder2.append(line.charAt(i));

                    i++;
                }
            } else {
                stringBuilder1.append(line.charAt(i));
            }
        }

        return new String[]{stringBuilder1.toString(), stringBuilder2.toString()};
    }

    static boolean isAnagram(String word1, String word2) {
        boolean anagram = true;

        char[] chars1 = toCharArray(word1);
        char[] chars2 = toCharArray(word2);

        if (chars1.length != chars2.length) {
            anagram = false;
        } else {
            for (int i = 0; i < chars2.length; i++) {
                boolean match = false;

                for (int j = 0; j < chars1.length; j++) {
                    if (chars2[i] == chars1[j]) {
                        match = true;
                        chars1[j] = ' ';

                        j = chars1.length;
                    }
                }

                if (!match) {
                    anagram = false;
                    i = chars1.length;
                }
            }
        }

        return anagram;
    }

    static char[] toCharArray(String string) {
        char[] chars = new char[string.length()];

        for (int i = 0; i < string.length(); i++) {
            chars[i] = toLowerCase(string.charAt(i));
        }

        return chars;
    }

    static char toLowerCase(char character) {
        if (character >= 'A' && character <= 'Z') {
            character = (char) (character + 32);
        }

        character = normalize(character);

        return character;
    }

    static char normalize(char character) {
        return Normalizer.normalize(
                Character.toString(character), Normalizer.Form.NFD
        ).charAt(0);
    }
}
