class Solution {
    public List<String> stringMatching(String[] words) {
        return Arrays.stream(words)
                    .filter(word -> Arrays.stream(words)
                            .anyMatch(parentWord -> !parentWord.equals(word) && parentWord.contains(word)))
                    .distinct()
                    .collect(Collectors.toList());
    }
}