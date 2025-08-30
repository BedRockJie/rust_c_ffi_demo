# Rust C FFI Demo

This project demonstrates how to use Rust's Foreign Function Interface (FFI) to interact with C code. It includes a Rust application that calls a C function and passes a callback function implemented in Rust back to the C code.

## Project Structure

- **src/main.rs**: The main Rust file that defines the Rust-to-C function bindings and the Rust callback function.
- **c_src/**: Contains the C source files (`c_lib.c` and `c_lib.h`) that define the C functions used in this project.
- **build.rs**: A build script that compiles the C code into a static library, which is then linked to the Rust application.
- **Cargo.toml**: The Rust project configuration file, including dependencies for the `cc` crate to compile the C code.

## How It Works

1. The Rust code declares the C function signatures using `extern "C"` and links to the compiled C library.
2. A Rust callback function is defined and passed to the C code.
3. The C code calls the Rust callback function, demonstrating bidirectional communication between Rust and C.

## Prerequisites

- Rust (with Cargo) installed.
- A C compiler (e.g., GCC or Clang).

## Build and Run

1. Build the project:
   ```bash
   cargo build
   ```
2. Run the project:
   ```bash
   cargo run
   ```

## Example Output

When you run the project, you should see output similar to the following:
```
[Rust] Main function started.
[C] Hello from C! Received number: 42
[C] Now, I will call the Rust callback function.
[Rust] Received from C: 84
[C] Rust callback finished. C function is done.
[Rust] Back in main. Program finished.
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.
