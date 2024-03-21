import java.util.Scanner;

public class MAIN2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入数字:");
        int input = scanner.nextInt();

        System.out.print(input + "!=" + solve(input));

    }

    public static int solve(int val) {
        int output = 1;
        for (int i = 2; i <= val; ++i)
            output *= i;
        return output;
    }
}
