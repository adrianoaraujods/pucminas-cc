
public class InserionSort extends Algorithm {

    public InserionSort() {
        super();
    }

    @Override
    public void sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int current = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > current) {
                comparisons++;

                swaps++;
                array[j + 1] = array[j];

                j--;
            }

            swaps++;
            array[j + 1] = current;
        }
    }
}
