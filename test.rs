use std::io::{self, Read};

fn main() {
	let mut input = String::new();
	io::stdin().read_to_string(&mut input).unwrap();
	let mut it = input.split_whitespace();

	let n: usize = match it.next() {
		Some(v) => v.parse().unwrap(),
		None => return,
	};

	let mut a: Vec<i32> = Vec::with_capacity(n);
	for _ in 0..n {
		if let Some(v) = it.next() {
			a.push(v.parse().unwrap());
		}
	}

	let x: i32 = match it.next() {
		Some(v) => v.parse().unwrap(),
		None => {
			println!("-1");
			return;
		}
	};

	let mut ans: i32 = -1;
	for (i, &val) in a.iter().enumerate() {
		if val == x {
			ans = i as i32;
			break;
		}
	}

	println!("{}", ans);
}