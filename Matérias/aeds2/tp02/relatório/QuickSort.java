
public class QuickSort extends Algorithm {

    public QuickSort() {
        super();
    }

    @Override
    public void sort(int[] array) {
        quicksort(array, 0, array.length - 1);
    }

    private void quicksort(int[] array, int start, int end) {
        int i = start, j = end;
        int pivot = array[(i + j) / 2];

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
                comparisons++;
            }

            while (array[j] > pivot) {
                j--;
                comparisons++;
            }

            if (i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }

        if (start < j) {
            quicksort(array, start, j);
        }

        if (i < end) {
            quicksort(array, i, end);
        }
    }
}
