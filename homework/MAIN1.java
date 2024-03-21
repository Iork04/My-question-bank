import java.util.Random;
import java.util.Scanner;

public class MAIN1 {
    public static void main(String[] args) {
        int arrSize = 10;
        int input;
        int[] arr = new int[arrSize];
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);

        // 生成随机数组
        for (int i = 0; i < arrSize; ++i)
            arr[i] = random.nextInt(100);

        System.out.print("数组为：");
        for (int i = 0; i < arrSize; ++i)
            System.out.print(arr[i] + " ");

        System.out.print("\n请输入数字：");
        input = scanner.nextInt();

        if (FindVal(input, arr, arrSize))
            System.out.println("数字存在数组中！");
        else
            System.out.println("数字不存在数组中！");

    }

    public static boolean FindVal(int val, int[] arr, int arrSize) {
        for (int i = 0; i < arrSize; ++i) {
            if (arr[i] == val)
                return true;
        }
        return false;
    }
}