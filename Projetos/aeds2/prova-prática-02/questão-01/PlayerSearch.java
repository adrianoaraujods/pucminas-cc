
import java.util.Scanner;

class Date {

    String day;
    String month;
    String year;
}

class Player {

    public String name;
    public String img;
    public Date birth;
    public int id;
    public int[] teams;

    public void read(String input) {
        int i = 0;
        String index = split(input, i, ',');
        i += index.length() + 1;
        this.name = split(input, i, ',');
        i += name.length() + 1;
        this.img = split(input, i, ',');
        i += img.length() + 1;
        this.birth = new Date();
        this.birth.day = split(input, i, '/');
        i += birth.day.length() + 1;
        this.birth.month = split(input, i, '/');
        i += birth.month.length() + 1;
        this.birth.year = split(input, i, ',');
        i += birth.year.length() + 1;
        index = split(input, i, ',');
        i += index.length() + 1;
        String idString = split(input, i, ',');
        this.id = Integer.parseInt(idString);
        i += idString.length() + 1;
        int n = countTimes(input, i);
        if (input.charAt(i) == '"') {
            i += 2;
        } else {
            i++;
        }
        this.teams = new int[n];
        for (int j = 0; j < n - 1; j++) {
            String teamsString = split(input, i, ',');
            this.teams[j] = Integer.parseInt(teamsString);
            i += teamsString.length() + 2;
        }
        String teamsString = split(input, i, ']');
        this.teams[n - 1] = Integer.parseInt(teamsString);
    }

    public String split(String input, int i, char delimiter) {
        String stringer = "";
        while (input.charAt(i) != delimiter) {
            stringer += input.charAt(i);
            i++;
        }
        return stringer;
    }

    public int countTimes(String input, int i) {
        int count = 1;
        while (input.charAt(i) != ']') {
            if (input.charAt(i) == ',') {
                count++;
            }
            i++;
        }
        return count;
    }

    public void print() {
        System.out.print(this.id + " " + this.name + " " + this.birth.day + "/"
                + this.birth.month + "/" + this.birth.year + " " + this.img + " " + "(");
        for (int i = 0; i < teams.length - 1; i++) {
            System.out.print(teams[i] + ", ");
        }
        System.out.println(teams[teams.length - 1] + ")");
    }
}

class PlayerList {

    private int startIndex;
    private int endIndex;
    private Player[] array;

    PlayerList(int size) {
        array = new Player[size];
        startIndex = 0;
        endIndex = 0;
    }

    public void insert(Player element) {
        int count = endIndex - startIndex;

        if (count >= array.length) {
            Player[] newArray = new Player[count * 2];

            for (int i = startIndex; i < endIndex; i++) {
                newArray[i] = array[i];
            }

            array = newArray;
        }

        array[endIndex++] = element;
    }

    public int getStartIndex() {
        return startIndex;
    }

    public int getEndIndex() {
        return endIndex;
    }

    public boolean binarySearch(String playerName) {
        boolean found = false;

        int start = startIndex;
        int end = endIndex - 1;

        while (start <= end) {
            int pivot = start + (end - start) / 2;
            int comparison = array[pivot].name.compareToIgnoreCase(playerName);

            if (comparison < 0) {
                start = pivot + 1;

            } else if (comparison > 0) {
                end = pivot - 1;

            } else {
                found = true;
                break;
            }
        }

        return found;
    }

}

public class PlayerSearch {

    static Scanner scanner = new Scanner(System.in);
    static PlayerList players = new PlayerList(16);

    public static void main(String[] args) {
        String line;

        // read players
        while ((line = scanner.nextLine()).compareToIgnoreCase("FIM") != 0) {
            Player player = new Player();
            player.read(line);
            players.insert(player);
        }

        // read search
        while ((line = scanner.nextLine()).compareToIgnoreCase("FIM") != 0) {
            System.out.println(players.binarySearch(line) ? "SIM" : "NAO");
        }
    }
}
