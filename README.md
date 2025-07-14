# Infotimanet System

A modern C++/QML-based **Infotainment System UI** built using the Qt Framework. This system simulates a vehicle dashboard, displaying real-time speed, fuel, and RPM information using interactive gauges.

## 🛠 Technologies Used

- **C++** for backend logic
- **QML** for front-end user interface
- **Qt 6** framework (QtQuick & QtWidgets)

## 📁 Project Structure

```
InfoScreen/
├── *.cpp / *.h         → C++ core logic
├── *.qml               → Gauge visual components
├── *.pro               → Qt project configuration
├── *.qrc               → Qt resource files
└── build/              → ⚠️ Build folder (ignore when uploading to GitHub)
```

## 🚀 Features

- Custom-built UI with animated QML gauges:
  - **SpeedGauge**
  - **FuelGauge**
  - **RpmGauge**
- Qt Resource system for bundling images and assets
- Modular C++ design with QWidget and QML hybrid interface

## 🧪 How to Run

1. Open `InfoScreen.pro` in **Qt Creator**.
2. Configure the Qt Kit (preferably Qt 6).
3. Build and run the project.

## ❗ Notes

- The `build/` folder is auto-generated and should be excluded from version control.
- This project is currently unlicensed and for educational/demo purposes.

## 📷 Preview

c:\Users\MILLIONAIRE\Pictures\Screenshots\Screenshot 2025-07-14 120156.png