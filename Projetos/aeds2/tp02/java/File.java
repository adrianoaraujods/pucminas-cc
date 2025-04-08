import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class File {
  static String path = "disneyplus.csv";

  public static String readLine(int index) {
    String line = null;

    if (index > 0) {
      try {
        BufferedReader reader = new BufferedReader(new FileReader(path));

        int i = 0;
        while (((line = reader.readLine()) != null) && i < index) i++;
      } catch (IOException _) {
        // file doesn't exist
      }
    }

    return line;
  }

  public static ArrayList<String> readAllLines() {
    ArrayList<String> lines = null;

    try {
      lines = new ArrayList<>(Files.readAllLines(Paths.get(path)));
    } catch (IOException _) {
      // file doesn't exist
    }

    return lines;
  }

  public static ArrayList<String> readUntil(int index) {
    ArrayList<String> lines = new ArrayList<>();

    if (index > 0) {
      try {
        BufferedReader reader = new BufferedReader(new FileReader(path));
        String line;

        int i = 0;
        while (((line = reader.readLine()) != null) && i < index) {
          lines.add(line);

          i++;
        }
      } catch (IOException _) {
        // file doesn't exist
      }
    }

    return lines;
  }

  /**
   * Use for testing
   */
  public static void main(String[] args) { // for testing
    System.out.println(File.readLine(3));
  }
}
