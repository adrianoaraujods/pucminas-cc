
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class SortingAlgorithms {

    static Random random;

    static int n = 100;
    static char key = 'i';
    static int[] array;

    public static void main(String[] args) {
        if (args.length > 0) {
            n = Integer.parseInt(args[0]);
        }

        if (args.length > 1) {
            key = args[1].toLowerCase().charAt(0);
        }

        if (args.length > 2) {
            random = new Random(Integer.parseInt(args[2]));
        } else {
            random = new Random();
        }

        array = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = Math.abs(random.nextInt() % 100_000);
        }

        Algorithm algorithm;
        switch (key) {
            case 'b' ->
                algorithm = new BubbleSort();
            case 'i' ->
                algorithm = new InserionSort();
            case 's' ->
                algorithm = new SelectionSort();
            default -> {
                key = 'q';
                algorithm = new QuickSort();
            }
        }

        algorithm.sort(array);

        log(algorithm.duration(), algorithm.comparisons(), algorithm.swaps());

        for (int i = 0; i < n; i++) { // debug
            System.out.println(i + ": " + array[i]);
        }
    }

    static void log(long duration, long comparisons, long swaps) {
        try (BufferedWriter writer = new BufferedWriter(
                new FileWriter("log.csv", true)
        )) {
            writer.write(
                    key
                    + "," + n
                    + "," + duration
                    + "," + comparisons
                    + "," + swaps
            );
            writer.newLine();
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}
