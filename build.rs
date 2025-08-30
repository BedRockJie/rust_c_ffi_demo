fn main() {
    println!("Hello from build.rs!");
    cc::Build::new()
        .file("c_src/c_lib.c")
        .include("c_src")
        .compile("libc_lib.a");
    println!("cargo:rerun-if-changed=c_src/c_lib.c");
}