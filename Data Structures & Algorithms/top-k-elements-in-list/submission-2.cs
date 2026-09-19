public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        // 1. Contar frecuencias
        Dictionary<int, int> freq = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!freq.ContainsKey(num)) {
                freq[num] = 0;
            }
            freq[num]++;
        }

        // 2. Crear lista de pares
        List<(int, int)> pairs = new List<(int, int)>();
        foreach (var p in freq) {
            pairs.Add((p.Key, p.Value));
        }

        // 3. Sortear por frecuencia (descendente)
        pairs.Sort((a, b) => b.Item2.CompareTo(a.Item2));

        // 4. Extraer primeros k
        List<int> ans = new List<int>();
        for (int i = 0; i < k; i++) {
            ans.Add(pairs[i].Item1);
        }

        return ans.ToArray();
    }
}
