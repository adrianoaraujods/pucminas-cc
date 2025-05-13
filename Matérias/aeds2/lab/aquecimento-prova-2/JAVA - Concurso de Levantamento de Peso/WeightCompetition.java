
import java.util.Scanner;

class Atlete {

    final private String name;
    final private int maxLifted;

    public Atlete(String name, int maxLifted) {
        this.name = name;
        this.maxLifted = maxLifted;
    }

    public String getName() {
        return name;
    }

    public int getMaxLifted() {
        return maxLifted;
    }

    @Override
    public String toString() {
        return name + " " + maxLifted;
    }
}

public class WeightCompetition {

    static Atlete[] atletes;

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int competitors = Integer.parseInt(scanner.nextLine());
        atletes = new Atlete[competitors];

        for (int competitor = 0; competitor < competitors; competitor++) {
            String[] line = scanner.nextLine().split(" ");
            String name = line[0];
            int maxLifted = Integer.parseInt(line[1]);

            atletes[competitor] = new Atlete(name, maxLifted);
        }

        sort();
        for (Atlete atlete : atletes) {
            System.out.println(atlete.toString());
        }
    }

    static void sort() {
        quicksort(0, atletes.length - 1);
    }

    static void quicksort(int left, int right) {
        int i = left, j = right;
        String pivotName = atletes[(i + j) / 2].getName();
        int pivotMaxLifted = atletes[(i + j) / 2].getMaxLifted();

        while (i <= j) {
            while (atletes[i].getMaxLifted() > pivotMaxLifted
                    || (atletes[i].getMaxLifted() == pivotMaxLifted
                    && atletes[i].getName().compareToIgnoreCase(pivotName) < 0)) {
                i++;
            }

            while (atletes[j].getMaxLifted() < pivotMaxLifted
                    || (atletes[j].getMaxLifted() == pivotMaxLifted
                    && atletes[j].getName().compareToIgnoreCase(pivotName) > 0)) {
                j--;
            }

            if (i <= j) {
                swap(i++, j--);
            }
        }

        if (j > left) {
            quicksort(left, j);
        }

        if (i < right) {
            quicksort(i, right);
        }
    }

    static void swap(int firstIndex, int secondIndex) {
        Atlete temp = atletes[firstIndex];
        atletes[firstIndex] = atletes[secondIndex];
        atletes[secondIndex] = temp;
    }
}
