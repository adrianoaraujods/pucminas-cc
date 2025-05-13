import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class FileInverter {
    static Scanner scanner = new Scanner(System.in);
    static String fileName = "numbers.temp";

    public static void main(String[] args) {
        int n = Integer.parseInt(scanner.nextLine());

        try {
            writeFile(n);
            readFile();
        } catch (IOException e) {
            //
        }
    }

    static void writeFile(int n) throws IOException {
        RandomAccessFile accessor = new RandomAccessFile(fileName, "rw");

        for (int i = 0; i < n; i++) {
            accessor.write(('\n' + scanner.nextLine()).getBytes());
        }

        accessor.close();
    }

    static void readFile() throws IOException {
        RandomAccessFile accessor = new RandomAccessFile(fileName, "r");
        int endOfLine = (int) accessor.length();

        for (int i = endOfLine; i >= 0; i--) {
            accessor.seek(i);
            char character = (char) accessor.read();

            if (character == '\n' || i == 0) {
                accessor.seek(i + 1);
                character = (char) accessor.read();

                if (i + 1 < endOfLine && character == '.') {
                    System.out.print("0.");
                } else {
                    System.out.print(character);
                }

                for (int j = i + 2; j < endOfLine; j++) {
                    accessor.seek(j);
                    character = (char) accessor.read();
                    System.out.print(character);


                }

                System.out.print('\n');

                endOfLine = i;
            } else if (i + 1 >= endOfLine && character == '0') {
                for (int j = i - 1; j > 0; j--) {
                    accessor.seek(j);
                    character = (char) accessor.read();

                    if (character == '.') {
                        endOfLine--;
                        j = 0;
                    } else if (character == '\n') {
                        j = 0;
                    }
                }

            }
        }
    }
}
