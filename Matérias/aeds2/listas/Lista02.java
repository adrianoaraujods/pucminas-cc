import tads.CircularQueue;

public class Lista02 {
    public static void main(String[] args) {
        CircularQueue queue = new CircularQueue(5);

        queue.append(1);
        queue.append(3);
        queue.append(5);
        queue.append(9);
        queue.append(11);

        queue.print();

        queue.dequeue();

        queue.print();

        queue.append(13);

        queue.print();
    }
}
