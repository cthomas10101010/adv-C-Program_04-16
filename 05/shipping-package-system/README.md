# README.md

# Shipping Package System

## Purpose
The Shipping Package System is a C++ application that demonstrates the principles of object-oriented programming, specifically inheritance. It allows users to calculate shipping costs for different types of packages, including standard packages, two-day packages, and overnight packages.

## Features
- **Package Class**: Represents a generic package with sender and receiver details, weight, and cost per ounce.
- **TwoDayPackage Class**: Inherits from Package and adds a two-day shipping fee.
- **OvernightPackage Class**: Inherits from Package and adds an additional cost per ounce for overnight shipping.
- User interaction for inputting package details and displaying calculated shipping costs.

## File Structure
```
shipping-package-system
├── include
│   ├── package.h
│   ├── twodaypackage.h
│   └── overnightpackage.h
├── src
│   ├── main.cpp
│   ├── package.cpp
│   ├── twodaypackage.cpp
│   └── overnightpackage.cpp
├── Statements.txt
└── README.md
```

## Compilation and Running
To compile the project, use the following command in the terminal:
```
g++ -o shipping-package-system src/*.cpp
```

To run the application, execute:
```
./shipping-package-system
```

## Requirements
This project adheres to the requirements specified in the assignment, demonstrating the use of inheritance and providing appropriate user interaction.

## Author
[Your Name]  
[Date]