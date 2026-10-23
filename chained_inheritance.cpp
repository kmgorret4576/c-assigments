// Chained (multilevel) inheritance: PowerSource -> SolarPanel -> SolarHomeSystem
#include <iostream>
#include <string>
using namespace std;

// Level 1: creating the Base class
class PowerSource
{
protected:
    string name;
    double voltage; // units in volts
public:
    PowerSource(string n, double v) : name(n), voltage(v) {}
    void showSource() const
    {
        cout << "Source: " << name << " | Voltage: " << voltage << " V" << endl;
    }
    void supplyPower() const
    {
        cout << name << " is supplying power at " << voltage << " V." << endl;
    }
};

// Level 2: Derived calss from PowerSource
class SolarPanel : public PowerSource
{
protected:
    double wattage;  // power in watts
    double sunHours; // peak sun hours per day
public:
    SolarPanel(string n, double v, double w, double h)
        : PowerSource(n, v), wattage(w), sunHours(h) {}
    double dailyEnergy() const
    { // watt-hours per day
        return wattage * sunHours;
    }
    void showPanel() const
    {
        cout << "Panel rating: " << wattage << " W | Daily energy: "
             << dailyEnergy() << " Wh" << endl;
    }
};

// Level 3: SolarHomeSysyem classs Derived from SolarPanel
class SolarHomeSystem : public SolarPanel
{
private:
    int panels;
    double batteryWh; // battery capacity in watt-hours
public:
    SolarHomeSystem(string n, double v, double w, double h, int p, double b)
        : SolarPanel(n, v, w, h), panels(p), batteryWh(b) {}
    void showSystem() const
    {
        double total = panels * dailyEnergy();
        cout << panels << " panels produce " << total << " Wh/day." << endl;
        cout << "Battery capacity: " << batteryWh << " Wh" << endl;
    }
    void daysOfBackup(double dailyLoadWh) const
    {
        cout << "Battery backs up a " << dailyLoadWh << " Wh/day load for "
             << batteryWh / dailyLoadWh << " day(s)." << endl;
    }
};

int main()
{
    cout << "--- Level 1: PowerSource ---" << endl;
    PowerSource grid("National Grid", 240);
    grid.showSource();
    grid.supplyPower();

    cout << "\n--- Level 2: SolarPanel (inherits from PowerSource) ---" << endl;
    SolarPanel panel("Rooftop Panel", 12, 200, 5);
    panel.showSource();  // inherited
    panel.supplyPower(); // inherited
    panel.showPanel();   // own

    cout << "\n--- Level 3: SolarHomeSystem (inherits from SolarPanel and PowerSource) ---" << endl;
    SolarHomeSystem home("Home Solar Kit", 12, 200, 5, 3, 2400);
    home.showSource();       // from PowerSource (two levels up)
    home.supplyPower();      // from PowerSource
    home.showPanel();        // from SolarPanel
    home.showSystem();       // own
    home.daysOfBackup(1200); // own
    return 0;
}