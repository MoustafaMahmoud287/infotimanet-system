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
  - **Trip Information control**
  - **Cllimate control**
- Modular C++ design with QWidget and QML hybrid interface

## 🧪 How to Run

1. Open `InfoScreen.pro` in **Qt Creator**.
2. Configure the Qt Kit (preferably Qt 6).
3. Build and run the project.

## ❗ Notes

- The `build/` folder is auto-generated and should be excluded from version control.
- This project is currently unlicensed and for educational/demo purposes.

## 📷 Preview
DashBoard Information
<img width="960" height="656" alt="Screenshot 2025-07-14 120156" src="https://github.com/user-attachments/assets/a0c59d1a-1c32-44aa-b057-be2e19294bc2" />

Trip Informtion
<img width="959" height="652" alt="Screenshot 2025-07-14 120203" src="https://github.com/user-attachments/assets/54478a44-383e-441b-a958-b5823ce0d69c" />

Climate Control 
<img width="956" height="653" alt="Screenshot 2025-07-14 120214" src="https://github.com/user-attachments/assets/af429b69-6293-4a0e-8ff4-c058b56011bd" />

