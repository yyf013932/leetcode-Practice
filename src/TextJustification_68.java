import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Daniel on 2017/4/19.
 */
public class TextJustification_68 {

    public static void main(String[] args) {
        String[] words = new String[]{"This", "is", "an", "example", "of", "text", "justification."};
        TextJustification_68 textJustification_68 = new TextJustification_68();
        textJustification_68.fullJustify(words, 16).forEach(System.out::println);
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int startIndex = 0, length = words.length;
        int offset = 0, currentLength;
        while (startIndex + offset < length) {
            currentLength = words[startIndex].length();
            offset++;
            while (startIndex + offset < length && (currentLength + words[startIndex + offset].length() +
                    offset) <= maxWidth) {
                currentLength += words[startIndex + offset].length();
                offset++;
            }
            int leftSpace = maxWidth - currentLength;
            String temResult = "";
            if (startIndex + offset == length) {
                int rightBlanks = maxWidth - currentLength - offset + 1;
                for (int i = 0; i < offset - 1; i++) {
                    temResult += words[startIndex + i] + " ";
                }
                char[] tem = new char[rightBlanks];
                Arrays.fill(tem, ' ');
                temResult += words[startIndex + offset - 1] + new String(tem);
            } else {
                if (offset == 1) {
                    char[] tem = new char[leftSpace];
                    Arrays.fill(tem, ' ');
                    temResult = words[startIndex] + new String(tem);
                } else {
                    int unitBlank = leftSpace / (offset - 1);
                    int plusCount = leftSpace - (offset - 1) * unitBlank;
                    char[] padding = new char[unitBlank];
                    char[] paddingPlus = new char[unitBlank + 1];
                    Arrays.fill(padding, ' ');
                    Arrays.fill(paddingPlus, ' ');
                    String pad1 = new String(padding);
                    String pad2 = new String(paddingPlus);
                    for (int i = 0; i < plusCount; i++) {
                        temResult += words[startIndex + i] + pad2;
                    }
                    for (int i = plusCount; i < offset - 1; i++) {
                        temResult += words[startIndex + i] + pad1;
                    }
                    temResult += words[startIndex + offset - 1];
                }
            }
            result.add(temResult);
            startIndex += offset;
            offset = 0;
        }

        return result;
    }
}
