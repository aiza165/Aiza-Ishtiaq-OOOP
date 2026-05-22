#include <iostream>
using namespace std;

class Device {
    string name;
    bool ison;
    int brightness;

public:

    Device() {
        name = "unknown";
        ison = false;
        brightness = 50;
    }

    Device(string n, bool i, int b) {
        name = n;
        ison = i;
        brightness = b;
    }

    ~Device()
    {
        cout << "Device [" << name << "] is being removed." << endl;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setBrightness(int b) {
        if (b >= 0 && b <= 100) {
            brightness = b;
        }
        else {
            brightness = 0;
        }
    }

    int getBrightness() const {
        return brightness;
    }

    void turnOn() {
        ison = true;
    }

    void turnOff() {
        ison = false;
    }

    bool getStatus() const {
        return ison;
    }

    void showInfo() const
    {
        cout << "Name: " << name;

        if (ison)
            cout << " Status: ON";
        else
            cout << " Status: OFF";

        cout << " Brightness: " << brightness << endl;
    }

};


class Room {

    string roomname;
    Device devices[5];
    int count;

public:

    Room(string r) {
        roomname = r;
        count = 0;
    }

    ~Room() {
        cout << "Room [" << roomname << "] removed" << endl;
    }

    void addDevice(Device d) {

        if (count < 5) {

            devices[count] = d;
            count++;

        }
        else
            cout << "full room" << endl;
    }


    void showAllDevices() const {

        if (count == 0) {

            cout << "No devices found." << endl;
            return;
        }

        for (int i = 0; i < count; i++) {

            devices[i].showInfo();
        }
    }


    int findDevice(string name) {

        for (int i = 0; i < count; i++) {

            if (devices[i].getName() == name)
                return i;
        }

        return -1;
    }


    void toggleDevice(string name)
    {
        int index = findDevice(name);

        if (index == -1) {

            cout << "Device not found." << endl;
            return;
        }

        if (devices[index].getStatus())
            devices[index].turnOff();
        else
            devices[index].turnOn();
    }


    void setDeviceBrightness(string name, int bright)
    {
        int index = findDevice(name);

        if (index == -1) {

            cout << "Device not found." << endl;
            return;
        }

        devices[index].setBrightness(bright);
    }

};



int main()
{

    string roomName;

    cout << "Enter Room Name: ";
    cin >> roomName;

    Room room(roomName);

    int choice;

    do
    {

        cout << endl;
        cout << "1. Add a Device" << endl;
        cout << "2. Show All Devices" << endl;
        cout << "3. Turn Device ON/OFF" << endl;
        cout << "4. Change Brightness" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            string name;
            bool status;
            int brightness;

            cout << "Enter Device Name: ";
           getline(cin, name);

            cout << "Enter Status (1 ON, 0 OFF): ";
            cin >> status;

            cout << "Enter Brightness: ";
            cin >> brightness;

            Device d(name, status, brightness);

            room.addDevice(d);
        }

        else if (choice == 2)
        {
            room.showAllDevices();
        }

        else if (choice == 3)
        {
            string name;

            cout << "Enter Device Name: ";
            getline(cin, name);

            room.toggleDevice(name);
        }

        else if (choice == 4)
        {
            string name;
            int bright;

            cout << "Enter Device Name: ";
            getline(cin, name);

            cout << "Enter Brightness: ";
            cin >> bright;

            room.setDeviceBrightness(name, bright);
        }

    } while (choice != 5);

    return 0;
}