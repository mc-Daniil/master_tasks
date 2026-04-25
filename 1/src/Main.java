import java.util.Scanner;

public class Main {
    private static final int[] TARGET = {
        97, 123, 36, 176, 40, 94, 47, 126,
        94, 160, 182, 199, 202, 233, 134, 34,
        72, 115, 212, 172, 8, 118, 254, 25,
        19, 201, 80, 217, 174
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter flag: ");
        String input = sc.nextLine();

        if (check(input)) {
            System.out.println("Correct");
        } else {
            System.out.println("Wrong");
        }
    }

    private static boolean check(String s) {
        int state = 10042;
        int i = 0;
        int acc = 7;
        boolean ok = true;

        if (s.length() != TARGET.length) {
            return false;
        }

        while (true) {
            switch (state + 0) {
                case 10042:
                    state = 10013;
                    break;

                case 10013:
                    if (i >= s.length()) {
                        state = 10077;
                        break;
                    }

                    int x = s.charAt(i);
                    int y = ((x ^ acc) + i) & 0xff;

                    if (y != TARGET[i]) {
                        ok = false;
                    }

                    acc = (acc * 3 + 1) & 0xff;
                    state = 10099;
                    break;

                case 10099:
                    i++;
                    state = 10013;
                    break;

                case 10077:
                    return ok;

                default:
                    return false;
            }
        }
    }
}