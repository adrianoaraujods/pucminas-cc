import java.util.Scanner;

public class BooleanAlgebraRecursive {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n;

        while ((n = scanner.nextInt()) > 0) {
            String expression = readExpression(readValues(n));

            System.out.println(solveExpression(expression));
        }
    }

    static String solveExpression(String expression) {
        String result;

        if (expression.length() == 1) {
            result = expression;
        } else {
            StringBuilder expressionBuilder = new StringBuilder();
            StringBuilder operatorBuilder = new StringBuilder();
            StringBuilder paramsBuilder = new StringBuilder();

            int left = expression.length() - 1;
            while (expression.charAt(left) != '(') left--;

            int right = left + 1;
            while (expression.charAt(right) != ')') {
                paramsBuilder.append(expression.charAt(right));
                right++;
            }

            right++;
            while (right < expression.length()) {
                expressionBuilder.append(expression.charAt(right));
                right++;
            }

            left--;
            while (left >= 0 && expression.charAt(left) != '(' && expression.charAt(left) != ',') {
                operatorBuilder.append(expression.charAt(left));
                left--;
            }

            expressionBuilder.insert(0, operation(
                    operatorBuilder.reverse().toString(),
                    paramsBuilder.toString()
            ) ? '1' : '0');

            while (left >= 0) {
                expressionBuilder.insert(0, expression.charAt(left));
                left--;
            }

            result = solveExpression(expressionBuilder.toString());
        }

        return result;
    }

    static boolean operation(String operator, String params) {
        boolean result = false;

        switch (operator) {
            case "not":
                result = !(params.charAt(0) == '1');

                break;
            case "or":
                for (int i = 0; i < params.length(); i++) {
                    if (params.charAt(i) == '1') {
                        result = true;
                        i = params.length();
                    }
                }

                break;
            case "and":
                result = true;

                for (int i = 0; i < params.length(); i++) {
                    if (params.charAt(i) == '0') {
                        result = false;
                        i = params.length();
                    }
                }

                break;
        }

        return result;
    }

    static boolean[] readValues(int n) {
        boolean[] values = new boolean[n];

        for (int i = 0; i < n; i++) {
            values[i] = scanner.next("[0-9]").charAt(0) != '0';
        }

        return values;
    }

    static String readExpression(boolean[] values) {
        String expression = scanner.nextLine();

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) != ' ') {
                if (expression.charAt(i) >= 'A' && expression.charAt(i) <= 'Z') {
                    stringBuilder.append(values[expression.charAt(i) - 'A'] ? '1' : '0');
                } else {
                    stringBuilder.append(expression.charAt(i));
                }
            }
        }

        return stringBuilder.toString();
    }
}
