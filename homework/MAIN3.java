
public class MAIN3 {
    public static void main(String[] args) {

        int input1 = 4;
        float input2 = 4.4f;
        double input3 = 4.44;
        System.out.println("正方形面积为：" + solve(input1) + "(int)");
        System.out.println("正方形面积为：" + solve(input2) + "(float)");
        System.out.println("正方形面积为：" + solve(input3) + "(double)");

    }

    public static int solve(int val) {
        return val * val;
    }

    public static float solve(float val) {
        return val * val;
    }

    public static double solve(double val) {
        return val * val;
    }
}
