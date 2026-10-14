# Rectangle Class (C++)

A small C++ program that models a rectangle. The width and length are kept private, and you work with them through simple functions.

## What it does

- Set the width and length with `setWidth()` and `setLength()`
- Read them back with `getWidth()` and `getLength()`
- Get the area and perimeter with `getArea()` and `getPerimeter()`

`main()` creates two rectangles (5 x 10 and 4 x 6), prints their details, then tries a few invalid values to show the validation working.

## Input validation

Width and length must be greater than 0. Zero or negative values throw an `invalid_argument` error, and the rectangle keeps its previous size. New rectangles start at 1 x 1.

## Run it

```bash
g++ main.cpp -o rectangle
./rectangle
```

## Output

```
Rectangle 1
Width: 5
Length: 10
Area: 50
Perimeter: 30

Rectangle 2
Width: 4
Length: 6
Area: 24
Perimeter: 20

Error: Width must be greater than 0
Error: Length must be greater than 0

After invalid inputs:
Rectangle 1 width: 5
Rectangle 2 length: 6
```
