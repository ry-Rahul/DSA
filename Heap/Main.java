package Heap;

public class Main {

    public static int linearSearch(char[] arr, char key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        char x[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                't' };

        char key = 'a';
        int index = linearSearch(x, key);
        if (index == -1) {
            System.out.println("Key not found");
        } else {
            System.out.println("Key found at index " + index);
        }

        index = linearSearch(x, 'A');
        if (index == -1) {
            System.out.println("Key not found");
        } else {

            System.out.println("Key found at index " + index);
        }
    }
}