use std::io;

fn solve() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();

    let n: usize = n.trim().parse().unwrap();
    for _ in 0..n {
        print!("a"); 
    }
    print!("b"); 
    for _ in 0..n {
        print!("a");
    }
    
}

fn main() {
    solve();
}