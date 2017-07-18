import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Daniel on 2017/4/19.
 */
public class BS_Stock {
    int[][] profit;
    List<Integer> high;
    List<Integer> low;
    int size;

    public static void main(String[] args) {
        int[] prices = new int[]{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
        int transactions = 2;
        BS_Stock bs_stock = new BS_Stock();
        System.out.println(bs_stock.maxProfit(transactions, prices));
    }

    int maxProfit(int k, int[] prices) {
        preHandle(prices);
        profit = new int[size][k];
        for (int i = 0; i < size; i++)
            Arrays.fill(profit[i], -1);
        return profit(size, k);
    }

    int profit(int n, int k) {
        if (k == 0 || n == 0)
            return 0;
        if (profit[n - 1][k - 1] == -1) {
            if (k >= n) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += high.get(i) - low.get(i);
                }
                profit[n - 1][k - 1] = sum;
            } else {
                int outMaxValue = 0;
                int outMax = 0;
                for (int r = n - 1; r >= 0; r--) {
                    outMaxValue = Math.max(outMaxValue, high.get(r));
                    int outTemMax = (outMaxValue-low.get(r)) + profit(r, k - 1);
                    outMax = Math.max(outMax, outTemMax);
                }
                profit[n - 1][k - 1] = outMax;
            }
        }
        return profit[n - 1][k - 1];
    }


    void preHandle(int prices[]) {
        low = new ArrayList<>();
        high = new ArrayList<>();
        int length = prices.length;
        if (length > 1) {
            boolean nextSmall = true;
            for (int i = 0; i < length; i++) {
                if (i == 0) {
                    if (prices[i] < prices[i + 1]) {
                        low.add(prices[i]);
                        nextSmall = false;
                    }
                } else if (i == length - 1) {
                    if (!nextSmall && prices[i - 1] <= prices[i]) {
                        high.add(prices[i]);
                        nextSmall = true;
                    }
                } else {
                    if (!nextSmall && prices[i - 1] <= prices[i] && prices[i] > prices[i + 1]) {
                        high.add(prices[i]);
                        nextSmall = true;
                    }
                    if (nextSmall && prices[i - 1] >= prices[i] && prices[i] < prices[i + 1]) {
                        low.add(prices[i]);
                        nextSmall = false;
                    }

                }
            }
        }
        size = low.size();
    }
}
