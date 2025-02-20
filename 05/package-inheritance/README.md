# File: /package-inheritance/package-inheritance/README.md

# Package Inheritance Project

This project demonstrates the concept of inheritance in C++ through the implementation of a package shipping system. It includes three classes: `Package`, `TwoDayPackage`, and `OvernightPackage`, showcasing how derived classes can extend the functionality of a base class.

## Overview

- **Package**: The base class that contains member data for sender and receiver details, weight, and cost per ounce. It provides methods for initializing these details and calculating the shipping cost.
  
- **TwoDayPackage**: A derived class that inherits from `Package`. It adds a member for a two-day shipping fee and overrides the cost calculation method to include this fee.

- **OvernightPackage**: Another derived class that inherits from `Package`. It includes a member for the overnight shipping rate and also overrides the cost calculation method to account for this rate.

## Files

- `src/main.cpp`: Contains the main function that demonstrates the functionality of the classes and handles user interaction.
- `src/package.h`: Header file for the `Package` class.
- `src/package.cpp`: Implementation file for the `Package` class.
- `src/twodaypackage.h`: Header file for the `TwoDayPackage` class.
- `src/twodaypackage.cpp`: Implementation file for the `TwoDayPackage` class.
- `src/overnightpackage.h`: Header file for the `OvernightPackage` class.
- `src/overnightpackage.cpp`: Implementation file for the `OvernightPackage` class.
- `CMakeLists.txt`: Build configuration file for the project.

## Compilation and Running

To compile the project, use the following command:

```
cmake .
make
```

To run the program, execute the following command:

```
./package-inheritance
```

## Additional Information

This project serves as an educational example of object-oriented programming principles in C++, specifically inheritance and polymorphism.