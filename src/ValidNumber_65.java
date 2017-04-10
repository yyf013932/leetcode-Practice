import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Daniel on 2017/4/10.
 */
public class ValidNumber_65 {


    public static void main(String[] args) {
        ValidNumber_65 validNumber_65 = new ValidNumber_65();
        System.out.println(validNumber_65.isNumber("+E3"));
    }


    Map[] trans = new Map[6];
    List<Integer> frontEndStates = Arrays.asList(2, 3, 4);
    List<Integer> endEndState = Arrays.asList(2);


    public void init() {
        for (int i = 0; i < trans.length; i++) {
            trans[i] = new HashMap<>();
        }
        trans[0].put('+', 1);
        trans[0].put('-', 1);
        trans[0].put('.', 5);
        trans[1].put('.', 5);
        trans[2].put('.', 3);

        for (char c : "0123456789".toCharArray()) {
            trans[1].put(c, 2);
            trans[0].put(c, 2);
            trans[2].put(c, 2);
            trans[3].put(c, 4);
            trans[4].put(c, 4);
            trans[5].put(c, 4);
        }
    }

    public boolean isNumber(String s) {
        init();
        String tem = s.trim();
        int index;
        index = tem.indexOf('E');
        if (index == -1)
            index = tem.indexOf('e');
        if (index == -1) {
            return validFront(tem);
        } else {
            String front = tem.substring(0, index);
            String end = tem.substring(index + 1);
            return validFront(front) && validEnd(end);
        }
    }

    public boolean isSingleNum(String s, List<Integer> endStates) {
        int state = 0;
        for (char c : s.toCharArray()) {
            Object obj = trans[state].get(c);
            if (obj == null)
                return false;
            state = (Integer) obj;
        }
        return endStates.contains(state);
    }

    public boolean validFront(String s){
        return isSingleNum(s,frontEndStates);
    }

    public boolean validEnd(String s) {
        return isSingleNum(s, endEndState);
    }
}
