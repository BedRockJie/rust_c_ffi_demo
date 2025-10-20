#include <stdio.h>
#include "c_lib.h"

void process_data_in_c(int32_t number, rust_callback callback) {
    printf("[C] Hello from C! Received number: %d\n", number);
    printf("[C] Now, I will call the Rust callback function.\n");

    // 调用从 Rust 传来的回调函数
    callback(number * 2);

    printf("[C] Rust callback finished. C function is done.\n");
}

int32_t add_c(int32_t a, int32_t b) {
    return a + b;
}

void display_string(const char* str) {
    printf("[C] Displaying string from Rust: %s\n", str);
}

double calculator_float(double a, double b) {
    printf("[C] calculator_float: %f + %f = %f\n", a, b, a + b);
    return a + b;
}

