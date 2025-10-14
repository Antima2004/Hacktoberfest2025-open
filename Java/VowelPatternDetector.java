import java.util.*;

public class VowelPatternDetector {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sentence = sc.nextLine().toLowerCase();

        Set<String> vowelPatterns = new HashSet<>();
        String vowels = "aeiou";

        String[] words = sentence.split("[ ,.!?;]+");

        for (String word : words) {
            String pattern = "";
            for (char ch : word.toCharArray()) {
                if (vowels.indexOf(ch) != -1) {
                    pattern += ch;
                }
            }
            if (pattern.length() > 1) { // consider only multiple vowel patterns
                vowelPatterns.add(pattern);
            }
        }

        System.out.println("\nUnique Vowel Patterns Found:");
        if (vowelPatterns.isEmpty()) {
            System.out.println("No vowel patterns detected.");
        } else {
            for (String vp : vowelPatterns) {
                System.out.println("→ " + vp);
            }
        }

        sc.close();
    }
}
