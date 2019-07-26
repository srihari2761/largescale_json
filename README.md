# Assignment: Large-scale Processing of JSON Objects

## Task 1.
### 1) small_test2.cpp

This program uses nlohmann's JSON library for modern c++

Ubuntu Installation:
```
sudo apt install Dnlohmann-json-dev
```
OS X and Homebrew installation:

> If you are using OS X and Homebrew, just type brew tap nlohmann/json and brew install nlohmann-json and you're set. If you want the bleeding edge rather than the latest release, use brew install nlohmann-json --HEAD.

Compiling:
```
g++ small_test2.cpp
./a.out <INSERT_FILENAME>
```

### 2) small_test3.cpp

This program uses Tencent's rapidJSON library 

Ubuntu Installation:
```
sudo apt-get install rapidjson-dev
```
Other operating systems:

> RapidJSON is a header-only C++ library. Just copy the include/rapidjson folder to system or project's include path.

### 2) small_test4.cpp

This program uses Tencent's rapidJSON library 

Ubuntu Installation:
```
sudo apt-get install rapidjson-dev
```
Other operating systems:

> RapidJSON is a header-only C++ library. Just copy the include/rapidjson folder to system or project's include path.


Compiling:
```
g++ small_test3.cpp
./a.out <INSERT_FILENAME>
```
> Added code to perform operations on a hash table, to reduce search complexity to O(1) and O(n) (for cost components). More experiments to be performed and logged.

### Execution Time

| Filename | nlohmann's library | rapidJSON library | 
| -------- | ------------------ | ----------------- |
| small.json | 54.6274 ms | 30.1546 ms |
| medium.json | 4700.8 ms | 3043.91 ms |
| large.json | 46116.1 ms | 28324.4 ms |

## Advantage/disadvantages of using nlohmann's library
Advantage
- JSON objects can be parsed as STL objects, making it easily interpretable

Disadvantage
- No memory managment, does not work on large files
- Parsing speed is slow compared to other libraries

## Advantage/disadvantages of using rapidJSON's library
- File is loaded as chunks using FileStreamReader, thus can handle large files
- Fastest parsing time compared to other libraries
- Only disadvantage - no inbuilt multithreading option

# TO-DO
- [x] Test all use cases
- [ ] Document the functions used
- [ ] Implement profiling applications and log bottlenecks (task 3)
- [ ] Read the JSON file byte by byte to parse it in chunks without the libraries mentioned
- [ ] Implement multithreading and techniques to improve performance (task 2)
- [ ] Experiment hash maps without chunk based reading and with proper memory managment


# Task 2
### COMING SOON

# Task 3
### Configuration:
- Number of cores : 4 cores (Intel core i5-6500 3.20GHzx4)
- Size of physical memory : 16 GB (2x8GB DDR4 LPX 2400MHz)
- Type of Disk : 256GB SSD, 1TB HDD
- Operating system and version - Ubuntu 19.04


