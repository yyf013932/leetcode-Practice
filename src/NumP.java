import java.util.ArrayList;
import java.util.List;

/**
 * Created by Daniel on 2017/4/11.
 */
public class NumP {
    List<Integer> nums = new ArrayList<>();
    int[] res = new int[50];

    public static void main(String[] args) {
        for (int i = Integer.MIN_VALUE; i < Integer.MAX_VALUE; i++) {
            if (i * -1 != i / -1)
                System.out.println(i);
        }
    }

    public void calculate() {
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        nums.add(2);
        for (int i = 2; i < 50; i++) {

        }
    }

}
