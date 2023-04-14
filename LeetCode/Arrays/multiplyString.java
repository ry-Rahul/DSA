
public class multiplyString {
    public static String multiply(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        if (n1 == 0 || n2 == 0) {
            return "0";
        }
        int result[] = new int[n1 + n2];
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            int carry = 0;
            int p = str1.charAt(i) - '0';
            i_n2 = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int k = str2.charAt(j) - '0';
                int sum = p * k + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0) {
                result[i_n1 + i_n2] += carry;
            }
            i_n1++;
        }
        int i = result.length - 1;
        while (i >= 0 && result[i] == 0) {
            i--;
        }
        if (i == -1) {
            return "0";
        }
        String s = "";
        while (i >= 0) {
            s += (result[i--]);
        }
        return s;
    }
    public static void main(String[] args) {
        String str = "123";
        String str2 = "5";
        String result = multiply(str, str2);
        System.out.println(result);
    }
}
