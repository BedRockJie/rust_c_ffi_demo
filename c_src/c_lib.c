#include <stdio.h>
#include "c_lib.h"

void process_data_in_c(int32_t number, rust_callback callback) {
    printf("[C] Hello from C! Received number: %d\n", number);
    printf("[C] Now, I will call the Rust callback function.\n");

    // 调用从 Rust 传来的回调函数
    callback(number * 2);

    printf("[C] Rust callback finished. C function is done.\n");
}