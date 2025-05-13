
public class SelectionSort extends Algorithm {

    public SelectionSort() {
        super();
    }

    @Override
    public void sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int smallest = getSmallestIndex(array, i);
            swap(array, i, smallest);
        }
    }

    private static int getSmallestIndex(int array[], int startPosition) {
        int smallest = startPosition;

        for (int i = startPosition + 1; i < array.length; i++) {

            comparisons++;
            if (array[i] < array[smallest]) {
                smallest = i;
            }
        }

        return smallest;
    }
}
