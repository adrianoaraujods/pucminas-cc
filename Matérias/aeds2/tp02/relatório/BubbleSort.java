
public class BubbleSort extends Algorithm {

    public BubbleSort() {
        super();
    }

    @Override
    public void sort(int[] array) {
        for (int i = array.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {

                comparisons++;
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                }
            }
        }
    }
}
