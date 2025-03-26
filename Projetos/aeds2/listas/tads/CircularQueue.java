package tads;

public class CircularQueue {
    int[] array;
    int first;
    int last;

    public CircularQueue(int max) {
        array = new int[max + 1];
        first = last = 0;
    }

    public void append(int x) {
        if ((last + 1) % array.length == first) {
            throw new ArrayIndexOutOfBoundsException("The Queue is full.");
        }

        array[last] = x;
        last = (last + 1) % array.length;
    }

    public int dequeue() {
        if (first == last) {
            throw new ArrayIndexOutOfBoundsException("The Queue is empty.");
        }

        int x = array[first];
        first = (first + 1) % array.length;
        return x;
    }

    public void print() {
        System.out.print("\n[ ");

        int i = first;
        while (i != last) {
            System.out.print(array[i] + " ");
            i = (i + 1) % array.length;
        }

        System.out.print("]");
    }
}
