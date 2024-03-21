import java.util.Random;

public class SelectArray {
    public static void main(String[] args) {
        int arrSize = 10;
        int arr[] = new int[arrSize];
        Random random = new Random();

        System.out.print("数组为：");
        for (int i = 0; i < arrSize; ++i) {
            arr[i] = random.nextInt(100);
            System.out.print(arr[i] + " ");
        }

        int _maxVal = arr[0], _minVal = arr[0];
        for (int val : arr) {
            _maxVal = _maxVal > val ? _maxVal : val;
            _minVal = _minVal < val ? _minVal : val;
        }

        System.out.println("\n最小值为:" + _minVal);
        System.out.println("最大值为:" + _maxVal);
    }
}
