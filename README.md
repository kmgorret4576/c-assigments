KARUNGI MARY GORRET
# C++ Take-Home Assignment: Inheritance and Polymorphism
This assignment has two C++ programs that demonstrate core Object-Oriented Programming ideas using real-world electrical engineering examples.

chained_inheritance.cpp` | Chained (multilevel) inheritance | PowerSource → SolarPanel → SolarHomeSystem` |
| `polymorphism.cpp` | Runtime polymorphism | `Sensor → TemperatureSensor, MotionSensor, LightSensor` |

## How to compile and run
Requires a C++11 (or newer) compiler 
```bash
g++ -std=c++11 chained_inheritance.cpp -o chained_inheritance
./chained_inheritance
g++ -std=c++11 polymorphism.cpp -o polymorphism
./polymorphism
```
On Windows, run `chained_inheritance.exe` and `polymorphism.exe` instead.
## 1. Chained inheritance

### Real-world idea
A solar home system is a kind of solar panel setup, and a solar panel is a kind of power source. Each level adds more specific features and keeps everything from the level above.

### Class chain

| Level | Class   | Inherits from | Data members | Member functions |
|        |         |                |               |                 |
| 1 (base)         | `PowerSource` | none | `name`, `voltage` | `showSource()`, `supplyPower()` |
| 2 | `SolarPanel` | `PowerSource` | `wattage`, `sunHours` | `dailyEnergy()`, `showPanel()` |
| 3 | `SolarHomeSystem` | `SolarPanel` | `panels`, `batteryWh` | `showSystem()`, `daysOfBackup()` |

### What it demonstrates
- `SolarPanel` uses `showSource()" and `supplyPower()` from `PowerSource`.
- `SolarHomeSystem` uses members from all three levels: `showSource()` (two levels up), `showPanel()` (one level up) and its own `showSystem()

"protected` members let derived classes use the parent's data while hiding it from outside code.
- Constructors are chained: each derived constructor passes values up to its parent's constructor.

### Sample output
--- Level 3: SolarHomeSystem (inherits from SolarPanel and PowerSource) ---
Source: Home Solar Kit | Voltage: 12 V
Home Solar Kit is supplying power at 12 V.
Panel rating: 200 W | Daily energy: 1000 Wh
3 panels produce 3000 Wh/day.
Battery capacity: 2400 Wh
Battery backs up a 1200 Wh/day load for 2 day(s).

## 2. Polymorphism

### Real-world idea
An electronic monitoring system holds many different sensors. The system asks every sensor to do the same thing, `readAndReport()`, and each sensor responds in its own way.

### Class structure

| Class | Role | `readAndReport()` behaviour |
|-------|------|-----------------------------|
| `Sensor` | Base class | Declared `virtual`; reports a generic reading |
| `TemperatureSensor` | Derived | Prints the temperature and switches on a fan if above 35 C |
| `MotionSensor` | Derived | Reports motion and turns on a light if detected |
| `LightSensor` | Derived | Prints the lux value and switches on a street lamp if dark |

### What it demonstrates
- A `virtual` function in the base class, overridden with `override` in each derived class.
- Runtime polymorphism through a `Sensor*` array and a `const Sensor&` reference.
- The same call, `readAndReport()`, gives different results depending on the actual object.
 A `virtual` destructor so derived objects are cleaned up correctly.

### Sample output
Base-class pointers 
[Server Room] Temperature: 38.5 C -> HIGH, switch on the fan.
[Hallway] Motion: DETECTED -> turn on the light.
[Car Park] Light: 60 lux -> dark, switch on street lamp.

## Hand-drawn illustrations
Hand-drawn diagrams accompany this submission:
1. **Inheritance diagram:** three stacked class boxes with upward arrows labelled "inherits from".
2. **Polymorphism diagram:** the `Sensor` base class, three derived classes, and a `Sensor* ptr` with dashed arrows to each object showing the different outputs.
## Key terms

| Term | Meaning |
|------|---------|
| Inheritance | A derived class reuses members of a base class |
| Chained (multilevel) inheritance | A class inherits from a class that itself inherits from another |
| `protected` | Accessible in the class and its derived classes, but not outside |
| `virtual` function | A function whose version is chosen at runtime based on the actual object |
| `override` | Marks a derived function that replaces a base class `virtual  "function |
| Runtime polymorphism | One interface, many behaviours, decided while the program runs |