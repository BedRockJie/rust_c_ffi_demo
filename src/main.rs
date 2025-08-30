use std::os::raw::c_int;

// extern "C" 块用于声明外部 C 函数的签名
// Rust 编译器会知道这些函数是在其他地方定义的，并在链接阶段找到它们
#[link(name = "c_lib")] // 链接我们在 build.rs 中编译的 c_lib 静态库
unsafe extern "C" {
    // 声明 C 函数的 Rust 版本签名
    // 注意类型映射：int32_t -> i32, rust_callback -> extern "C" fn(i32)
    unsafe fn process_data_in_c(number: c_int, callback: extern "C" fn(c_int));
}

// 这个是我们将要传递给 C 的回调函数
// #[no_mangle] 告诉 Rust 编译器不要修改这个函数的名字，以便 C 能按名字找到它
// extern "C" 表示这个函数应该使用 C 的调用约定 (ABI)
#[unsafe(no_mangle)]
pub extern "C" fn rust_callback(number: c_int) {
    println!("[Rust] Received from C: {}", number);
}

fn main() {
    println!("[Rust] Main function started.");
    let number_to_send: i32 = 42;

    // 调用 C 函数是不安全的，因为它绕过了 Rust 的安全保证
    // 例如，C 代码可能会访问空指针或无效内存
    unsafe {
        process_data_in_c(number_to_send, rust_callback);
    }
    println!("[Rust] Back in main. Program finished.");
}
