# 🌞 2-DOF Solar Tracker (Math-Based, Sensorless)

A **two-axis solar tracking system** that uses astronomical calculations (no sensors) to track the sun’s position in real time and orient a solar panel accordingly.

This project demonstrates how to convert **time + location → sun position → servo motion** using embedded systems.

---

## 🚀 Features

* 📍 Computes **Sun Azimuth & Elevation** using mathematical models
* 🔄 Controls **2 Servo Motors (Horizontal + Vertical)**
* ⚡ **Sensorless tracking** 
* 🎯 Smooth servo motion with interpolation
* 🧠 Modular code structure (easy to extend)

---

## 🧠 How It Works

The system calculates the sun’s position based on:

* Latitude & Longitude
* Day of the year
* Time of day

### Core Steps:

1. Compute **Declination Angle**
2. Compute **Hour Angle**
3. Calculate:

   * 🌅 Elevation (vertical angle)
   * 🧭 Azimuth (horizontal angle)
4. Map angles to servo positions
5. Move motors smoothly

---

## 🛠 Hardware Requirements

* Arduino (Uno / Nano / Mega)
* 2 × Servo Motors (SG90 / MG90S)
* External 5V supply (recommended)
* Jumper wires
* Mount/frame for 2-DOF movement

---

## ⚙️ Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------- |
| Azimuth Servo   | D6          |
| Elevation Servo | D9          |

---

## 🧭 Mechanical Setup

### Horizontal Axis (Azimuth)

* 0° → East
* 90° → North
* 180° → West

### Vertical Axis (Elevation)

* 0° → Horizon (South direction)
* 90° → Straight Up

---

## 📊 Expected Behavior

| Time  | Direction | Movement         |
| ----- | --------- | ---------------- |
| 6 AM  | East      | Panel horizontal |
| 12 PM | South     | Panel tilted up  |
| 6 PM  | West      | Panel horizontal |

---

## ▶️ How to Run

1. Upload the Arduino code
2. Open Serial Monitor (9600 baud)
3. Watch:

   * Time simulation
   * Servo movement tracking the sun

---


## ⚠️ Notes

* System currently uses **simulated time**
* Replace with RTC module for real-world tracking
* Tracking range is limited to **East → West (180°)**

---

## 🔥 Future Improvements

* ⏱ Add RTC module for real-time tracking
* 🌤 Hybrid system (Math + LDR sensors)
* 🎮 Manual override (keyboard/joystick control)
* 📱 IoT dashboard for monitoring

---


Give it a ⭐ on GitHub!
