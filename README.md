# HOMEWORK-4

## USING SFINAE

## Min. Requirements

+ Git
+ Ninja 1.10
+ Cmake 3.25
+ C++20 support compiler

### Configure

* create `build` folder

#### Linux x86_64

`cmake --preset linux-x64-release`

### Building

#### Linux x86_64

`cmake --build --preset linux-x64-release`


### Testing

#### Linux x86_64

`ctest --test-dir ./build/linux-x64-release/homework-4`

### Packing to deb

`cpack --config build/linux-x64-release/CPackConfig.cmake`

#### Running

Execute is shell ``print_ip
