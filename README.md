# Function Plotter

## 📖 Overview
This project implements a mathematical function plotter in **C++**, using **SDL3** for graphical rendering and **TinyExpr** for parsing user-defined expressions.  
It allows users to input functions such as `sin(x)`, `x^2`, or `exp(-x)` and visualize them on a Cartesian coordinate system.

---

## 🔬 Mathematical Background
Plotting a function requires translating continuous mathematics into discrete pixel coordinates:

1. **Function Evaluation**  
   - A function f(x) is sampled at discrete points x.  
   - Example: For f(x) = sin(x), values are computed at intervals Delta x = 1.  
   - This discretization approximates the continuous curve.

2. **Coordinate Transformation**  
   - Mathematical coordinates must be mapped to screen coordinates.  
   - Conversion formula:

$$
\text{eval X} = \left( \frac{\text{pixel X}}{\text{width}} \times \text{max X} \times 2 \right) - \text{max X}
$$
$$
\text{pixel Y} = \left( \frac{\text{eval Y} + \text{max Y}}{2 \times \text{max Y}} \right) \text{height}
$$
   - eval_x is passed in f(x) or eval_y and then the pixel_y found by the second formula.  
   - Scaling ensures the graph fits within the window, while offset centers it. 

---

## ⚙️ Technologies
- **C++** — core logic and numerical evaluation  
- **SDL3** — graphics rendering  
- **TinyExpr** — expression parsing

---

## 🎨 Demo
Here is an example of plotting sin(x):

![Sine Function](images/prompt.png)

And here’s a short animation of the plotter in action:

![Plotter Demo](images/img.gif)

---

## 🚀 How to Run
Compile and run with:
```bash
g++ main.cpp -lSDL3 -o plotter
./plotter "sin(x)"
