
import java.util.Scanner;

class Cell<T> {

    Cell<T> top, right, bottom, left;
    T value;

    public Cell() {
        top = right = bottom = left = null;
        value = null;
    }

    public Cell(T value) {
        super();
        this.value = value;
    }

    @Override
    public String toString() {
        return value != null ? value.toString() : "null";
    }
}

class Matrix<T> {

    public Cell<T> topLeftCell;
    protected final int rows, columns;

    public Matrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;

        if (columns <= 0 || rows <= 0) {
            topLeftCell = null;
            return;
        }

        topLeftCell = new Cell<>();

        // create first row
        Cell<T> rowCell = topLeftCell;
        for (int c = 1; c < columns; c++) {
            Cell<T> newCell = new Cell<>();
            rowCell.right = newCell;
            newCell.left = rowCell;

            rowCell = newCell;
        }

        // create next rows
        rowCell = topLeftCell;
        for (int r = 1; r < rows; r++) {
            // create first cell from row
            Cell<T> newCell = new Cell<>();
            rowCell.bottom = newCell;
            newCell.top = rowCell;
            rowCell = newCell;

            // create next cells from row
            Cell<T> colCell = rowCell;
            for (int c = 1; c < columns; c++) {
                newCell = new Cell<>();
                colCell.right = newCell;
                newCell.left = colCell;

                Cell<T> topCell = colCell.top.right;
                topCell.bottom = newCell;
                newCell.top = topCell;

                colCell = newCell;
            }
        }
    }

    public int getRows() {
        return rows;
    }

    public int getColumns() {
        return columns;
    }

    public void printCells() {
        Cell<T> rowCell = topLeftCell;
        for (int r = 0; r < rows; r++, rowCell = rowCell.bottom) {

            Cell<T> colCell = rowCell;
            for (int c = 0; c < columns; c++, colCell = colCell.right) {
                System.out.print(colCell.value.toString() + " ");
            }
            System.out.println();
        }
    }

    public void printMainDiagonal() {
        Cell<T> cell = topLeftCell;

        while (cell != null) {
            System.out.print(cell.value.toString() + " ");

            cell = cell.bottom != null ? cell.bottom.right : null;
        }
        System.out.println();
    }

    public void printSecondaryDiagonal() {
        Cell<T> cell = topLeftCell;

        while (cell.right != null) {
            cell = cell.right;
        }

        while (cell != null) {
            System.out.print(cell.value.toString() + " ");

            cell = cell.bottom != null ? cell.bottom.left : null;
        }
        System.out.println();
    }
}

class IntMatrix extends Matrix<Integer> {

    public IntMatrix(int rows, int columns) {
        super(rows, columns);
    }

    public IntMatrix plus(IntMatrix matrix) {
        int maxRows = Math.max(rows, matrix.rows);
        int maxColumns = Math.max(columns, matrix.columns);

        IntMatrix result = new IntMatrix(maxRows, maxColumns);

        Cell<Integer> thisRow = this.topLeftCell;
        Cell<Integer> thatRow = matrix.topLeftCell;
        Cell<Integer> resultRow = result.topLeftCell;

        for (int r = 0; r < maxRows; r++) {
            Cell<Integer> thisCell = thisRow;
            Cell<Integer> thatCell = thatRow;
            Cell<Integer> resultCell = resultRow;

            for (int c = 0; c < maxColumns; c++) {
                int val1 = (thisCell != null && thisCell.value != null) ? thisCell.value : 0;
                int val2 = (thatCell != null && thatCell.value != null) ? thatCell.value : 0;

                resultCell.value = val1 + val2;

                thisCell = (thisCell != null) ? thisCell.right : null;
                thatCell = (thatCell != null) ? thatCell.right : null;
                resultCell = resultCell.right;
            }

            thisRow = (thisRow != null) ? thisRow.bottom : null;
            thatRow = (thatRow != null) ? thatRow.bottom : null;
            resultRow = resultRow.bottom;
        }

        return result;
    }

    public IntMatrix times(IntMatrix matrix) {

        IntMatrix result = new IntMatrix(this.rows, matrix.columns);

        Cell<Integer> aRow = this.topLeftCell;
        Cell<Integer> resRow = result.topLeftCell;

        for (int r = 0; r < this.rows; r++) {
            Cell<Integer> resCell = resRow;

            for (int c = 0; c < matrix.columns; c++) {

                int sum = 0;

                Cell<Integer> aCell = aRow;

                Cell<Integer> bCell = matrix.topLeftCell;
                for (int step = 0; step < c && bCell != null; step++) {
                    bCell = bCell.right;
                }

                while (aCell != null || bCell != null) {
                    int valA = (aCell != null && aCell.value != null) ? aCell.value : 0;
                    int valB = (bCell != null && bCell.value != null) ? bCell.value : 0;

                    sum += valA * valB;

                    aCell = (aCell != null) ? aCell.right : null;
                    bCell = (bCell != null) ? bCell.bottom : null;
                }

                resCell.value = sum;
                resCell = resCell.right;
            }

            aRow = (aRow != null) ? aRow.bottom : null;
            resRow = (resRow != null) ? resRow.bottom : null;
        }

        return result;
    }
}

public class DynamicMatrix {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            IntMatrix matrix1 = readMatrix();
            IntMatrix matrix2 = readMatrix();

            IntMatrix matrixS = matrix1.plus(matrix2);
            IntMatrix matrixM = matrix1.times(matrix2);

            matrix1.printMainDiagonal();
            matrix1.printSecondaryDiagonal();
            matrixS.printCells();
            matrixM.printCells();
        }
    }

    static IntMatrix readMatrix() {
        int rows = scanner.nextInt();
        scanner.nextLine();
        int columns = scanner.nextInt();
        scanner.nextLine();

        IntMatrix matrix = new IntMatrix(rows, columns);

        Cell<Integer> rowCell = matrix.topLeftCell;
        for (int r = 0; r < rows; r++, rowCell = rowCell.bottom) {

            Cell<Integer> colCell = rowCell;
            for (int c = 0; c < columns; c++, colCell = colCell.right) {
                colCell.value = scanner.nextInt();
            }
            scanner.nextLine();
        }

        return matrix;
    }
}
