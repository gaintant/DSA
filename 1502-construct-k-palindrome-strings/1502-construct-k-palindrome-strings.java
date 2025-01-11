class Solution {
    public boolean canConstruct(String s, int k) {
        List<Long> freq = s.chars().collect(() ->  {
                                          // Initialize an ArrayList of size 26, filled with 0L
                                          List<Long> list = new ArrayList<>(26);
                                          for (int i = 0; i < 26; i++) {
                                              list.add(0L);
                                          }
                                          return list;},
                    (arrayList, val) -> arrayList.set(val - 'a', arrayList.get(val - 'a') + 1),
                    (list1, list2) -> {
                        for (int i = 0; i < 26; i++) {
                            list1.set(i, list1.get(i) + list2.get(i));
                        }
                    });
            long c = freq.stream().filter(a -> a%2 == 1).count();
            return c <= k && (s.length() >= 1L *k);   
    }
}