// Runtime polymorphism: Sensors in an electronic monitoring system
#include <iostream>
#include <string>
using namespace std;

//  creating Base class with a virtual function
class Sensor
{
protected:
    string location;

public:
    Sensor(string loc) : location(loc) {}
    virtual void readAndReport() const
    {
        cout << "[" << location << "] Generic sensor reading taken." << endl;
    }
    virtual ~Sensor() {}
};

class TemperatureSensor : public Sensor
{
    double celsius;

public:
    TemperatureSensor(string loc, double c) : Sensor(loc), celsius(c) {}
    void readAndReport() const override
    {
        cout << "[" << location << "] Temperature: " << celsius << " C";
        if (celsius > 35)
            cout << " -> HIGH, switch on the fan.";
        cout << endl;
    }
};

class MotionSensor : public Sensor
{
    bool detected;

public:
    MotionSensor(string loc, bool d) : Sensor(loc), detected(d) {}
    void readAndReport() const override
    {
        cout << "[" << location << "] Motion: "
             << (detected ? "DETECTED -> turn on the light." : "none.") << endl;
    }
};

class LightSensor : public Sensor
{
    int lux;

public:
    LightSensor(string loc, int l) : Sensor(loc), lux(l) {}
    void readAndReport() const override
    {
        cout << "[" << location << "] Light: " << lux << " lux"
             << (lux < 100 ? " -> dark, switch on street lamp." : " -> bright enough.")
             << endl;
    }
};

// Works for any Sensor type via reference
void monitor(const Sensor &s) { s.readAndReport(); }

int main()
{
    TemperatureSensor t("Server Room", 38.5);
    MotionSensor m("Hallway", true);
    LightSensor l("Car Park", 60);

    cout << "--- Base-class pointers ---" << endl;
    Sensor *sensors[] = {&t, &m, &l};
    for (Sensor *s : sensors)
        s->readAndReport(); // same call, different behaviour

    cout << "\n--- Base-class reference ---" << endl;
    monitor(t);
    monitor(m);
    monitor(l);

    cout << "\n--- Base object for comparison ---" << endl;
    Sensor g("Unknown");
    g.readAndReport();
    return 0;
}