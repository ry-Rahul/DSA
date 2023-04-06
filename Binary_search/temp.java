
import java.time.LocalDateTime;
import java.util.Scanner;
public class temp {

    public static void main(String[] args) {
        //  write the program day of the week along with the time in a am and pm format and import Data and Time API
        // local date time
        // local date

        LocalDateTime now = LocalDateTime.now();
        System.out.println("Current Date and Time is: " + now);
        System.out.println("Day of the week is: " + now.getDayOfWeek());
        System.out.println("Day of the month is: " + now.getDayOfMonth());
        // time in am and pm format
        System.out.println("Time  is: " + now.getHour() + ":" + now.getMinute() + ":" + now.getSecond());
    }
}