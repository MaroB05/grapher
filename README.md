# Grapher

A lightweight, no-frills 2D plotting tool written in pure C for when the internet abandons you but graphs don't.

## Overview

Grapher is a minimalist graphing utility born out of necessity during an internet-deprived trip. When fancy graphing libraries aren't available but you still need to visualize data, Grapher has your back. It generates simple bitmap (PBM) visualizations from point data.

## Features

- **Dependency-free**: Just plain C, no external libraries needed
- **Portable**: Works wherever a C compiler exists
- **Small footprint**: Tiny codebase that's easy to understand and modify
- **Paired with a data generator**: Generate test data with configurable mathematical functions

## How It Works

Grapher takes a binary data file of x,y coordinates and renders them as a bitmap image. The companion generator tool can create test data following mathematical patterns.

### Components

- **main.c**: The core graphing logic
- **defs.h**: Core definitions and file handling
- **fileio.h**: File I/O utilities
- **generator.c**: Test data generator (follows pattern y = n*x^p)

## Usage

### Generating Test Data

```bash
# Syntax: generator [num_points] [factor] [power]
# Creates test.data with y = factor*x^power pattern
./generator 100 2 2   # Creates 100 points following y = 2x²
```

### Creating a Graph

```bash
# Syntax: grapher [data_file] [width] [height] [x_scale] [y_scale]
./grapher test.data 800 600 1 1
```

The output is saved as `output.pbm`, which can be viewed with most image viewers.

## Building

```bash
# Compile the grapher
gcc main.c -o grapher

# Compile the generator
gcc generator.c -o generator
```

## Todo

- Implement the `draw_line` function to connect points
- Add axis lines and labels
- Support for multiple data series

## Why Grapher?

In a world of sophisticated graphing libraries and tools, why would anyone use Grapher?

- **When the internet is down**: No downloading packages or searching Stack Overflow
- **Learning purposes**: Understand the basics of programmatic visualization
- **Minimalism**: Sometimes simple is better
- **Customization**: Easy to modify for your specific needs
- **Because sometimes the only tool you have is a C compiler and a dream**

## License

This project is open source. Feel free to use, modify, and distribute as you wish.

---

*"Graphs are just pictures for people who don't want to admit they like art."* - Unknown
