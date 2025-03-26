public class Lista01 {
    static int n = 3;

    public static void main(String[] args) {

        System.out.println("Total de execuções: " + ex10());
    }

    static int ex10() {
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                count++;
                count++;
            }
            count++;
        }

        return count;
    }

    static int ex11() {
        int count = 0;

        for (int i = 1; i <= n; i++, count++) {
            for (int j = i; j <= n; j++, count++) {
                count += 1;
            }
        }

        count += 2;

        return count;
    }

    static int ex12() {
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = 0; k < j; k++) {
                    count++;
                    count++;
                }
            }
        }

        return count;
    }

    static int ex13() {
        int count = 0;

        for (int i = 5 ; i < n; i++) {
            count++;

            for (int j = i + 1; j < n - 2; j++) {
                count++;
                count++;
            }
            count++;
        }

        return count;
    }
}
