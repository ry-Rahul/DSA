public class perfectSqrOrNot {
    public static boolean isPerfectSquare(int num) {
        int st = 1;
        int en = num;
        while (st <= en) {
            int mid = st + (en - st) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int num = 25;
        boolean ans = isPerfectSquare(num);
    }
}
