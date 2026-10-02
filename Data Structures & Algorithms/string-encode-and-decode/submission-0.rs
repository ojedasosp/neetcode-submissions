const KEY: &[u8] = b"santisecretk";

fn xor(data: &[u8]) -> Vec<u8> {
    data.iter()
        .enumerate()
        .map(|(i, b)| b ^ KEY[i % KEY.len()])
        .collect()
}

impl Solution {
  pub fn encode(strs: Vec<String>) -> String {
    let encoded: Vec<String> = strs
        .iter()
        .map(|s| {
            xor(s.as_bytes())
                .iter()
                .map(|b| format!("{:02x}", b))
                .collect()
        })
        .collect();

    format!("{}#{}", strs.len(), encoded.join(","))
}

pub fn decode(s: String) -> Vec<String> {
    let (len_str, body) = s.split_once('#').expect("falta '#'");
    let len: usize = len_str.parse().expect("longitud inválida");

    if len == 0 {
        return vec![];
    }

    let result: Vec<String> = body
        .split(',')
        .map(|h| {
            let bytes: Vec<u8> = (0..h.len())
                .step_by(2)
                .map(|i| u8::from_str_radix(&h[i..i + 2], 16).unwrap())
                .collect();
            String::from_utf8(xor(&bytes)).unwrap()
        })
        .collect();

    assert_eq!(result.len(), len);
    result
}
}
