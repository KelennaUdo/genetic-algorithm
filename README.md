# Genetic Algorithm String Matcher

This project demonstrates a simple genetic algorithm in C++ that evolves a population of random strings to match a user-provided target string.

## How It Works

- The program starts with a population of randomly generated strings.
- Each string (an "Individual") is evaluated for its "fitness"—how many characters differ from the target string.
- The fittest individuals are selected to "mate" and produce offspring for the next generation, with occasional mutations to maintain diversity.
- This process repeats until a string matches the target exactly.

## Files

- [`genetic_algorithm.cpp`](genetic_algorithm.cpp): Main program implementing the genetic algorithm.
- [`Individual.h`](Individual.h): Definition of the `Individual` class used in the algorithm.
- `output/genetic_algorithm.exe`: Compiled executable (if present).

## How to Build

1. Make sure you have a C++ compiler (e.g., g++) installed.
2. Compile the program:

    ```sh
    g++ genetic_algorithm.cpp -o output/genetic_algorithm.exe
    ```

## How to Run

1. Run the executable:

    ```sh
    ./output/genetic_algorithm.exe
    ```

2. Enter your target string when prompted.
3. Watch as the algorithm evolves a population to match your target string.

## Example Output

```
Welcome to my genetic algorithm program!
A Genetic Algorithm (GA) is an optimization technique inspired by the process of natural selection.
...
Please Enter a target string: Hello, World!
Generation: 0    String: 3eZt...    Fitness: 13
...
Generation: 87   String: Hello, World!   Fitness: 0
```

## Author

Created by [Your Name Here].

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.