/**
 * Created by Daniel on 2017/4/10.
 */
public class SortColor_75 {
    public void sortColors(int[] nums) {
        int size[] = new int[3];
        for (int i = 0; i < 3; i++) {
            size[i] = 0;
        }
        for (int i : nums) {
            size[i]++;
        }
        int j = 0;
        int k;
        for (int i = 0; i < 3; i++) {
            k = j;
            while (j < size[i] + k)
                nums[j++] = i;
        }
    }
}
