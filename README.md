# WALL-E – Autonomous Obstacle-Avoiding Robot 🤖

![Project Badge](https://img.shields.io/badge/Project-Active-brightgreen)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![Electronics](https://img.shields.io/badge/Electronics-Projects-blue)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)
![License](https://img.shields.io/badge/License-Educational-orange)

---

## 📌 Project Overview

**WALL-E** is a low-cost **autonomous obstacle-avoiding robot** developed as part of an Electronics Engineering academic project.  
The system uses **real-time ultrasonic sensing** and **embedded decision-making logic** to navigate safely without human intervention.

📍 **Institute:** PCET's Nutan Maharashtra Institute of Engineering and Technology, Pune  
🕒 Duration: 4 Weeks  
👨‍💻 Role: Hardware & Documentation Lead  
🛠️ Domain: Embedded Systems & Robotics  
🎓 Project Type: Academic Team Project

---

## 🚀 Project Objective

To design and build a **fully autonomous robotic system** capable of detecting obstacles in real time and avoiding collisions using efficient embedded system logic.

---

## ✨ Key Features

- Automatic obstacle detection using ultrasonic sensor  
- Autonomous navigation powered by Arduino UNO  
- Real-time distance measurement and response  
- Collision-avoidance decision algorithm  
- 180° / 360° environment scanning via servo motor  
- Smooth direction control using motor driver  
- Low power and efficient operation  
- Expandable architecture (IoT, Bluetooth, GPS, Camera ready)

---

## 🛠️ Components & Technologies Used

| Component | Description |
|---------|-------------|
| Arduino UNO | Main microcontroller |
| Ultrasonic Sensor (HC-SR04) | Obstacle detection & distance measurement |
| Servo Motor | Directional scanning |
| Motor Driver (L298N / L293D) | DC motor control |
| DC Motors | Robot movement |
| Battery (9V / 12V / Li-ion) | Power supply |
| Robot Chassis | Mechanical structure |

---

## ⚙️ Working Principle

1. Ultrasonic sensor continuously measures distance from obstacles  
2. Arduino processes the sensor data  
3. When an obstacle is detected within a threshold distance:
   - Robot stops  
   - Servo motor scans left and right  
   - Arduino compares distances  
   - Safest direction is selected  
   - Motor driver executes movement commands  

This logic enables **collision-free autonomous navigation**.

---

## 🧠 Algorithm Overview
1. Initialize ultrasonic sensor, servo, and motors  
2. Measure distance continuously  
3. If distance < threshold:
   - Stop movement
   - Rotate servo to scan left & right
   - Compare distances
   - Move in safest direction
4. Repeat loop

---

| Parameter | Value |
|---------|-------|
| Obstacle Distance Threshold | 20 cm |
| Servo Scan Angle | 0° – 180° |
| Motor Voltage | 9V |

---

## 👥 Team Members

- Om Joshi – [LinkedIn](https://www.linkedin.com/in/0m-joshi2307/)  
- Khushal Choudhary – [LinkedIn](https://www.linkedin.com/in/khushal-choudhary-a022b6374/)  
- Aryan Ahirrao – [LinkedIn](https://www.linkedin.com/in/aryan-ahirrao-80087b372/)  
- Virendra Bendale – [LinkedIn](https://www.linkedin.com/in/virendra-bendale-bb339a371/)  
- Sarthak Ghogare – [LinkedIn](https://www.linkedin.com/in/sarthak-ghogare-b4218a385/)  
- Shreyas Gore – [LinkedIn](https://www.linkedin.com/in/shreyas-gore-1416823a2/)  

---

## 🧑‍💻 Individual Contribution (Om Joshi)
- Led hardware assembly and end-to-end circuit integration  
- Implemented obstacle detection logic using ultrasonic sensor & Arduino  
- Designed and created the complete project PPT for evaluation and demo  
- Assisted team members in troubleshooting wiring and motor issues  
- Ensured smooth robot operation during final demonstration  

---

## 📂 Project Deliverables

- Fully functional autonomous robotic model  
- Technical PPT presentation  
- Project poster  
- Working demonstration video  

---

## 📈 Learning Outcomes

- Fundamentals of embedded systems  
- Sensor interfacing and motor control  
- Hardware debugging and circuit troubleshooting  
- Team-based project collaboration  
- Practical robotics problem-solving experience  

---

## 🧰 Skills Gained
- Arduino programming  
- Ultrasonic sensor calibration  
- Motor driver interfacing  
- Embedded hardware debugging  
- Technical presentation design

---

## 🔮 Future Enhancements

- Bluetooth / mobile application control  
- IoT-based monitoring system  
- GPS-assisted navigation  
- AI-based obstacle recognition  
- Camera module integration  

---

## 📜 License

This project is developed for **educational purposes only**.