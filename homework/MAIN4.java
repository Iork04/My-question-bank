import java.util.Random;

public class MAIN4 {
    public static void main(String[] args) {
        int arrSize = 10;
        int[] arr = new int[arrSize];
        Random random = new Random();

        for (int i = 0; i < arrSize; ++i)
            arr[i] = random.nextInt(100);

        System.out.print("排序前数组为：");
        for (int i = 0; i < arrSize; ++i)
            System.out.print(arr[i] + " ");

        // 冒泡排序
        for (int i = 0; i < arrSize - 1; ++i) {
            for (int j = 0; j < arrSize - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int cur = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = cur;
                }
            }
        }

        System.out.print("\n排序后数组为：");
        for (int i = 0; i < arrSize; ++i)
            System.out.print(arr[i] + " ");

    }

}