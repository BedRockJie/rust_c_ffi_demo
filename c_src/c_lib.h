#ifndef C_LIB_H
#define C_LIB_H

#include <stdint.h> // 使用标准整数类型，以保证与 Rust 的类型兼容

// 声明一个函数指针类型，这个函数接收一个 int32_t 参数，没有返回值
// 这是 C 调用 Rust 函数的"契约"
typedef void (*rust_callback)(int32_t);

// 声明 C 函数，供 Rust 调用
// 它接收一个数字和一个回调函数指针
void process_data_in_c(int32_t number, rust_callback callback);

#endif // C_LIB_H