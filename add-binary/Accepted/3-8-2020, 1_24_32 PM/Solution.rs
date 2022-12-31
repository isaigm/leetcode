// https://leetcode.com/problems/add-binary


fn fill_with_zeros(st : &mut String, n : usize){
    let mut z = 0;
    while z  < n{
        st.insert(0, '0');
        z += 1;
    }
}
impl Solution {
    pub fn add_binary(s1 : String, s2 : String) -> String{
    let mut result = String::from("");
    let mut r1 = s1.clone(); 
    let mut r2 = s2.clone();
    let l1 = s1.len();
    let l2 = s2.len();
    if l1 > l2{
        fill_with_zeros(&mut r2, l1 - l2);
    }
    else if l2 > l1{
        fill_with_zeros(&mut r1, l2 - l1);
    }
    let mut carry = 0;
    let mut s = 0;
    let mut bit : char;
    println!("{}", r1);
    println!("{}", r2);
    for idx in (0..r1.len()).rev(){
        let b1 = r1.as_bytes()[idx] as u32 - '0' as u32;
        let b2 = r2.as_bytes()[idx] as u32 - '0' as u32;
        s = b1 + b2 + carry;
        if s == 2{
            bit = '0';
            carry = 1;
        }else if s == 3{
            bit = '1';
            carry = 1;
        }
        else{
            bit = match std::char::from_digit(s, 2){
                Some(b) => b,
                None => '0'
            };
            carry = 0;
        }
        result.insert(0, bit);
    }
    if carry == 1{
        result.insert(0, '1');
    }
    return result;
}
}