#include <iostream>
#include <iomanip>
using namespace std;

// Function 1: Read input
void readInput(double &scheduledStart, double &clockIn,
               double &clockOut, double &breakDuration,
               double &standardHours)
{
    cout << "Enter scheduled start time: ";
    cin >> scheduledStart;

    cout << "Enter clock-in time: ";
    cin >> clockIn;

    cout << "Enter clock-out time: ";
    cin >> clockOut;

    cout << "Enter break duration (hours): ";
    cin >> breakDuration;

    cout << "Enter standard working hours: ";
    cin >> standardHours;
}

// Function 2: Calculate working hours
double calculateWorkingHours(double clockIn, double clockOut,
                             double breakDuration)
{
    double totalHours, workingHours;

    totalHours = clockOut - clockIn;
    workingHours = totalHours - breakDuration;

    return workingHours;
}

// Function 3: Calculate overtime
double calculateOvertime(double workingHours, double standardHours)
{
    double overtime;

    if (workingHours > standardHours)
    {
        overtime = workingHours - standardHours;
    }
    else
    {
        overtime = 0;
    }

    return overtime;
}

// Function 4: Check attendance
void checkAttendance(double clockIn, double scheduledStart)
{
    if (clockIn > scheduledStart)
    {
        cout << "Attendance Status: Late" << endl;
    }
    else
    {
        cout << "Attendance Status: On Time" << endl;
    }
}

// Function 5: Display details
void displayDetail(double workingHours, double overtime,
                   double clockIn, double scheduledStart)
{
    cout << fixed << setprecision(2);

    cout << "\n===== Attendance Report =====" << endl;
    cout << "Working Hours: " << workingHours << endl;
    cout << "Overtime Hours: " << overtime << endl;

    checkAttendance(clockIn, scheduledStart);
}

int main()
{
    double scheduledStart, clockIn, clockOut;
    double breakDuration, standardHours;
    double workingHours, overtime;

    cout << "===== Employee Attendance System =====" << endl;

    readInput(scheduledStart, clockIn, clockOut,
              breakDuration, standardHours);

    workingHours = calculateWorkingHours(clockIn, clockOut,
                                         breakDuration);

    overtime = calculateOvertime(workingHours, standardHours);

    displayDetail(workingHours, overtime, clockIn, scheduledStart);

    return 0;
}
