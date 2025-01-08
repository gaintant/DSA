class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        return IntStream.range(0, words.length)
                    .map(i -> (int) IntStream.range(i+1, words.length)
                            .filter(j -> words[j].startsWith(words[i]) && words[j].endsWith(words[i]))
                            .count())
                    .sum();
    }
}