/**
 * Created by Daniel on 2017/7/9.
 */
public class MediaOfTwoSortedArrays_4 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] tem;
        int len1, len2;
        if (nums1.length > nums2.length) {
            tem = nums1;
            nums1 = nums2;
            nums2 = tem;
        }
        len1 = nums1.length;
        len2 = nums2.length;
        if (len1 == 0) {
            if (len2 % 2 == 0)
                return (0.0 + nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2;
            else
                return nums2[len2 / 2];
        }

        int mediaLength = (len1 + len2 + 1) / 2;
        double mediaValue;
        int i = len1 / 2;
        int j;
        while (i <= len1 && i >= 0) {
            j = mediaLength - i;
            if (i > 0 && nums1[i - 1] > nums2[j]) {
                i--;
                continue;
            }
            if (i < len1 && nums2[j - 1] > nums1[i]) {
                i++;
                continue;
            }
            int leftMax, rightMin;
            if (i == 0) {
                leftMax = nums2[j - 1];
                if (j == len2)
                    rightMin = nums1[i];
                else
                    rightMin = Math.min(nums1[i], nums2[j]);
            } else if (i == len1) {
                if (j == 0)
                    leftMax = nums1[i - 1];
                else
                    leftMax = Math.max(nums1[i - 1], nums2[j - 1]);
                rightMin = nums2[j];
            } else {
                leftMax = Math.max(nums1[i - 1], nums2[j - 1]);
                rightMin = Math.min(nums1[i], nums2[j]);
            }
            if ((len1 + len2) % 2 == 0) {
                mediaValue = (leftMax + rightMin + 0.0) / 2;
            } else {
                mediaValue = leftMax;
            }
            return mediaValue;

        }
        return -1;
    }

    public static void main(String[] args) {
        MediaOfTwoSortedArrays_4 m = new MediaOfTwoSortedArrays_4();
        int[] a1 = new int[]{1};
        int[] a2 = new int[]{1};
        double mv = m.findMedianSortedArrays(a1, a2);
        System.out.println(mv);
    }
}
