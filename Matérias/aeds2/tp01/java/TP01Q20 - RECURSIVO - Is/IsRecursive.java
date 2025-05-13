import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class IsRecursive {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);
    static char[] vowels = {
            'a', 'e', 'i', 'o', 'u', 'á', 'é', 'í',
            'ó', 'ú', 'à', 'è', 'ì', 'ò', 'ù', 'ã',
            'õ', 'â', 'ê', 'î', 'ô', 'û',

            'A', 'E', 'I', 'O', 'U', 'Á', 'É', 'Í',
            'Ó', 'Ú', 'À', 'È', 'Ì', 'Ò', 'Ù', 'Ã',
            'Õ', 'Â', 'Ê', 'Î', 'Ô', 'Û'
    };

    public static void main(String[] args) {
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.print(isOnlyVowels(line) ? "SIM" : "NAO");
            System.out.print(isOnlyConsonants(line) ? " SIM" : " NAO");
            System.out.print(isInteger(line) ? " SIM" : " NAO");
            System.out.print(isFloat(line) ? " SIM" : " NAO");
            System.out.print('\n');
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

    static boolean isVowel(char character) {
        boolean vowel = false;

        for (int i = 0; i < vowels.length; i++) {
            if (character == vowels[i]) {
                vowel = true;
                i = vowels.length;
            }
        }

        return vowel;
    }

    static boolean isConsonant(char character) {
        boolean consonant = true;

        if ((character >= 'a' && character <= 'z')
                || (character >= 'A' && character <= 'Z')
                || (character >= 128 && character <= 154)
                || (character >= 160 && character <= 165)
        ) {
            for (int i = 0; i < vowels.length; i++) {
                if (character == vowels[i]) {
                    consonant = false;
                    i = vowels.length;
                }
            }
        } else {
            consonant = false;
        }

        return consonant;
    }

    static boolean isInteger(char character) {
        return character >= '0' && character <= '9';
    }

    // Indirect recursive methods
    static boolean isOnlyVowels(String expression) {
        return _isOnlyVowels(expression, expression.length() - 1);
    }

    static boolean isOnlyConsonants(String expression) {
        return _isOnlyConsonants(expression, expression.length() - 1);
    }

    static boolean isInteger(String expression) {
        return _isInteger(expression, expression.length() - 1);
    }

    static boolean isFloat(String expression) {
        return _isFloat(expression, expression.length() - 1, ' ');
    }

    // Recursive methods
    private static boolean _isOnlyVowels(String expression, int index) {
        boolean isOnlyVowels = true;

        if (index >= 0) {
            isOnlyVowels = isVowel(expression.charAt(index))
                    && _isOnlyVowels(expression, index - 1);
        }

        return isOnlyVowels;
    }

    private static boolean _isOnlyConsonants(String expression, int index) {
        boolean isOnlyConsonants = true;

        if (index >= 0) {
            isOnlyConsonants = isConsonant(expression.charAt(index))
                    && _isOnlyConsonants(expression, index - 1);
        }

        return isOnlyConsonants;
    }

    private static boolean _isInteger(String expression, int index) {
        boolean isInteger = true;

        if (index >= 0) {
            isInteger = isInteger(expression.charAt(index))
                    && _isInteger(expression, index - 1);
        }

        return isInteger;
    }

    private static boolean _isFloat(String expression, int index, char floating) {
        boolean isFloat = true;

        if (index >= 0) {
            if (expression.charAt(index) == '.') {
                if (floating == ' ') {
                    floating = '.';
                } else if (floating == '.') {
                    isFloat = false;
                }
            } else if (expression.charAt(index) == ',') {
                if (floating == ' ') {
                    floating = ',';
                } else if (floating == ',') {
                    isFloat = false;
                }
            } else if (!isInteger(expression.charAt(index))) {
                isFloat = false;
            }

            isFloat = isFloat && _isFloat(expression, index - 1, floating);
        }

        return isFloat;
    }
}
