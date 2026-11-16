# OOPVC Laboratory Practical Programs

Organized into the **9 official practicals**. Each source file is a separate, standalone C++ program with its own `main()` and an algorithm comment at the top.

Compile and run **one file at a time**.

## Practical01 — Basic OOP Implementation

- [system01.cpp — 1.1 Classes and objects](./Practical01/system01.cpp)
- [system02.cpp — 1.2 Constructors and destructors](./Practical01/system02.cpp)
- [system03.cpp — 1.3 Dynamic memory allocation](./Practical01/system03.cpp)

## Practical02 — Inheritance & Polymorphism

- [system04.cpp — 2.1 Inheritance types](./Practical02/system04.cpp)
- [system05.cpp — 2.2 Compile-time and runtime polymorphism](./Practical02/system05.cpp)
- [system06.cpp — 2.3 Virtual functions and overriding](./Practical02/system06.cpp)

## Practical03 — Exception Handling & File Handling

- [system07.cpp — 3.1 Exception handling](./Practical03/system07.cpp)
- [system08.cpp — 3.2 File creation, reading, and writing](./Practical03/system08.cpp)
- [system09.cpp — 3.3 File-based record storage and retrieval](./Practical03/system09.cpp)

## Practical04 — OOP Design Patterns

- [system10.cpp — 4.1 Observer pattern concepts](./Practical04/system10.cpp)
- [system11.cpp — 4.2 Factory and Singleton](./Practical04/system11.cpp)
- [system12.cpp — 4.3 Strategy pattern](./Practical04/system12.cpp)

## Practical05 — Visual Computing & Graphics Programming

- [system13.cpp — 5.1 Visual computing basics](./Practical05/system13.cpp)
- [system14.cpp — 5.2 Graphics window initialization](./Practical05/system14.cpp)
- [system15.cpp — 5.3 Graphics primitives](./Practical05/system15.cpp)
- [system28.cpp — 10.1 Moving-object animation](./Practical05/system28.cpp)
- [system30.cpp — 10.3 Ping Pong game](./Practical05/system30.cpp)

## Practical06 — 2D Transformations

- [system16.cpp — 6.1 2D transformation concepts](./Practical06/system16.cpp)
- [system17.cpp — 6.2 Translation, rotation, and scaling](./Practical06/system17.cpp)
- [system18.cpp — 6.3 Reflection and shearing](./Practical06/system18.cpp)
- [system32.cpp — 10.5 2D shape transformation visualizer](./Practical06/system32.cpp)

## Practical07 — 3D Transformations

- [system19.cpp — 7.1 3D transformation concepts](./Practical07/system19.cpp)
- [system20.cpp — 7.2 3D transformation matrices](./Practical07/system20.cpp)
- [system21.cpp — 7.3 3D object visualization](./Practical07/system21.cpp)
- [system29.cpp — 10.2 Interactive 3D graphics](./Practical07/system29.cpp)

## Practical08 — Line Drawing & Clipping Algorithms

- [system22.cpp — 8.1 DDA line drawing](./Practical08/system22.cpp)
- [system23.cpp — 8.2 Bresenham line drawing](./Practical08/system23.cpp)
- [system24.cpp — 8.3 Cohen–Sutherland clipping](./Practical08/system24.cpp)

## Practical09 — Image Processing Basics

- [system25.cpp — 9.1 Image processing basics](./Practical09/system25.cpp)
- [system26.cpp — 9.2 Grayscale and thresholding](./Practical09/system26.cpp)
- [system27.cpp — 9.3 Image blurring](./Practical09/system27.cpp)
- [system31.cpp — 10.4 Image filtering application](./Practical09/system31.cpp)

## Notes

- The original `System/system.cpp` file is retained unchanged.
- Programs numbered 10.1–10.5 are additional application programs, not a tenth official practical. They are placed in the closest related practical folder.
- Standard C++ files can be compiled with `g++ systemNN.cpp -o program`.
- Graphics programs require a compatible `graphics.h` implementation such as WinBGIm; standard GCC alone is not sufficient.
- OpenCV programs require OpenCV development libraries and an `image.jpg` input file in the working directory.
