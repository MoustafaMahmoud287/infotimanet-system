# 🚗 Infotimanet System

A modern C++/QML-based car infotainment system UI built using the Qt Framework. This project simulates a vehicle dashboard, displaying real-time speed, fuel, and RPM information using interactive gauges.

## 🛠 Technologies Used

- **C++** for backend logic
- **QML** for front-end user interface
- **Qt 6 Framework** (QtQuick & QtWidgets)

## 📁 Project Structure

infotimanet-system/ 
├── *.cpp / *.h → C++ core logic 
├── *.qml → Gauge visual components 
├── *.pro → Qt project configuration 
├── *.qrc → Qt resource files 
└── build/ → ⚠️ Build folder (ignore when uploading to GitHub)

## 🚀 Features

- Custom-built UI with animated QML gauges:
  - `SpeedGauge.qml`
  - `FuelGauge.qml`
  - `RpmGauge.qml`
- Qt Resource system for bundling images and assets
- Modular C++ design with QWidget and QML hybrid interface

## ▶️ How to Run

1. Open `InfoScreen.pro` in **Qt Creator**
2. Configure the Qt Kit (preferably Qt 6)
3. Build and run the project

## ⚠️ Notes

- The `build/` folder is auto-generated and should be excluded from version control.
- This project is currently unlicensed and intended for educational/demo purposes.

## 📸 Preview

Coming soon — UI screenshots and demo video.

---

Made with ❤️ by [Moustafa Mahmoud](https://github.com/MoustafaMahmoud287)
