impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        return Solution::sort(s) == Solution::sort(t);
    }

    fn sort(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();

        for i in 1..chars.len() {
            let mut j = i;
            while j > 0 && chars[j] < chars[j - 1]{
                chars.swap(j, j - 1);
                j -= 1;
            }
        }

        return chars.into_iter().collect();
    }
}
