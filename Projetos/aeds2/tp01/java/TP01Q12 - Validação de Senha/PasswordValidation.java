import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class PasswordValidation {
    static Scanner scanner = new Scanner(System.in, StandardCharsets.ISO_8859_1);

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.ISO_8859_1));
        String line;

        while (!isEOF(line = scanner.nextLine())) {
            System.out.println(validation(line) ? "SIM" : "NÃO");
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

    static boolean validation(String password) {
        boolean isValid;
        boolean hasUpper = false;
        boolean hasLower = false;
        boolean hasDigit = false;
        boolean hasSpecial = false;

        if (password.length() < 8) {
            isValid = false;
        } else {
            int i = 0;
            while (i < password.length() && (!hasUpper || !hasLower || !hasDigit || !hasSpecial)) {
                if (password.charAt(i) >= 'A' && password.charAt(i) <= 'Z') hasUpper = true;
                if (password.charAt(i) >= 'a' && password.charAt(i) <= 'z') hasLower = true;
                if (password.charAt(i) >= '0' && password.charAt(i) <= '9') hasDigit = true;
                if ((password.charAt(i) >= '!' && password.charAt(i) <= '/')
                        || (password.charAt(i) >= ':' && password.charAt(i) <= '@')
                        || (password.charAt(i) >= '[' && password.charAt(i) <= '`')
                        || (password.charAt(i) >= '{' && password.charAt(i) <= '~')
                ) hasSpecial = true;

                i++;
            }

            isValid = hasUpper && hasLower && hasDigit && hasSpecial;
        }

        return isValid;
    }
}
