package tads;

public class List {
    int[] array;
    int n = 0;

    public List(int max) {
        array = new int[max];
        n = 0;
    }

    public boolean insert(int x, int index) {
        if (n >= array.length || index > n) return false;

        shiftPositive(index);
        array[n] = x;
        n++;

        return true;
    }

    public boolean insertStart(int x) {
        return insert(x, 0);
    }

    public boolean append(int x) {
        return insert(x, n);
    }

    public int remove(int index) {
        if (index < 0 || index >= n) return -1;

        int element = array[index];
        shiftNegative(index);
        n--;

        return element;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            System.out.println(i + ": " + array[i]);
        }
    }

    private void shiftPositive(int start) {
        for (int i = n; i > start; i--) {
            array[i] = array[i - 1];
        }
    }

    private void shiftNegative(int start) {
        for (int i = start; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
    }
}
