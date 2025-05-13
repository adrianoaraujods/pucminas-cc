
public class Algorithm {

    protected static long comparisons = 0;
    protected static long swaps = 0;
    private static long start;

    public Algorithm() {
        start = System.currentTimeMillis();
        System.out.println("start: " + start); // debug
    }

    public void sort(int[] array) {
        System.err.println("");
    }

    public static void swap(int[] array, int firstIndex, int secondIndex) {
        array[firstIndex] += array[secondIndex];
        array[secondIndex] = array[firstIndex] - array[secondIndex];
        array[firstIndex] = array[firstIndex] - array[secondIndex];

        swaps++;
    }

    public long comparisons() {
        return comparisons;
    }

    public long swaps() {
        return swaps;
    }

    public long duration() {
        long end = System.currentTimeMillis();
        System.out.println("end: " + end); // debug

        return end - start;
    }
}
