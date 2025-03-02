import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;

public class PageReader {
    static Scanner scanner = new Scanner(System.in);

    static char[] vowels = {
            'a', 'e', 'i', 'o', 'u', 'á', 'é', 'í',
            'ó', 'ú', 'à', 'è', 'ì', 'ò', 'ù', 'ã',
            'õ', 'â', 'ê', 'î', 'ô', 'û'
    };
    static String[] tags = { "br", "table" };

    public static void main(String[] args) {
        String title, url;

        while (!isEOF(title = scanner.nextLine())) {
            url = scanner.nextLine();

            readPage(getHtml(url), title);
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

    static String getHtml(String href) {
        URL url;
        InputStream inputStream = null;
        BufferedReader br;
        String html = "", line;

        try {
            url = new URL(href);
            inputStream = url.openStream();  // throws an IOException
            br = new BufferedReader(new InputStreamReader(inputStream));

            while ((line = br.readLine()) != null) {
                html += line + "\n";
            }
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return html;
    }

    static void readPage(String html, String title) {
        int[] vowelsCount = new int[vowels.length];
        for (int i = 0; i < vowels.length; i++) vowelsCount[i] = 0;

        int[] tagsCount = new int[tags.length];
        for (int i = 0; i < tags.length; i++) tagsCount[i] = 0;

        int consonantsCount = 0;

        for (int i = 0; i < html.length(); i++) {
            if (html.charAt(i) == '<') {
                for (int t = 0; t < tags.length; t++, i++) {
                    if (html.length() - i - tags[t].length() > 1) {
                        boolean match = true;

                        for (int c = 0; c < tags[t].length(); c++) {
                            if (html.charAt(i + 1 + c) != tags[t].charAt(c)) {
                                match = false;
                                c = tags[t].length();
                            }
                        }

                        if (match && html.charAt(i + tags[t].length() + 1) == '>') tagsCount[t]++;
                    }
                }
            } else if (isConsonants(html.charAt(i))) {
                consonantsCount++;
            } else {
                for (int v = 0; v < vowels.length; v++) {
                    if (Character.toLowerCase(html.charAt(i)) == vowels[v]) {
                        vowelsCount[v]++;
                        v = vowels.length;
                    }
                }
            }
        }

        printStats(vowelsCount, tagsCount, consonantsCount, title);
    }

    static void printStats(int[] vowelsCount, int[] tagsCount, int consonantsCount, String title) {
        for (int i = 0; i < vowels.length; i++) {
            printCount(Character.toString(vowels[i]), vowelsCount[i]);
        }

        printCount("consoante", consonantsCount);

        for (int i = 0; i < tags.length; i++) {
            printCount('<' + tags[i] + '>', tagsCount[i]);
        }

        System.out.print(title + '\n');
    }

    static void printCount(String label, int count) {
        System.out.print(label + '(' + count + ") ");
    }

    static boolean isConsonants(char character) {
        boolean isConsonant = true;

        if ((character >= 'A' && character <= 'Z')
                || (character >= 'a' && character <= 'z')
                || (character >= 128 && character <= 154)
                || (character >= 160 && character <= 165)
        ) {
            isConsonant = false;
        } else {
            for (int j = 0; j < vowels.length; j++) {
                if (character == vowels[j]) {
                    isConsonant = false;
                    j = vowels.length;
                }
            }
        };

        return isConsonant;
    }
}
