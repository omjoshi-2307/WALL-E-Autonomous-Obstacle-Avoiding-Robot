🤖 WALL-E — Autonomous Obstacle-Avoiding Robot
![Project Badge](https://img.shields.io/badge/Project-Active-brightgreen)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![Electronics](https://img.shields.io/badge/Electronics-Projects-blue)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)
![License](https://img.shields.io/badge/License-Educational-orange)
WALL-E is a low-cost autonomous obstacle-avoiding robot built using Arduino UNO and ultrasonic sensing.
The system detects obstacles in real time, makes autonomous navigation decisions, and avoids collisions without any human control.
📍 Institute: PCET’s Nutan Maharashtra Institute of Engineering and Technology, Pune
🕒 Duration: 4 Weeks
🎓 Project Type: Academic Team Project
👨‍💻 Role: Hardware & Documentation Lead
🚀 Project Objective
To design and implement a fully autonomous robotic system capable of detecting obstacles and navigating safely using embedded system logic and real-time sensor data.
✨ Key Features
Autonomous obstacle detection and avoidance
Real-time distance measurement using ultrasonic sensor
Servo-based environmental scanning (180° / 360°)
Intelligent direction selection algorithm
Smooth DC motor control via motor driver
Energy-efficient and low-cost design
Modular architecture for future upgrades (IoT, GPS, Bluetooth, Camera)
🛠️ Tech Stack & Components
Component
Purpose
Arduino UNO
Central control unit
Ultrasonic Sensor (HC-SR04)
Distance measurement
Servo Motor
Directional scanning
Motor Driver (L298N / L293D)
Motor control
DC Motors
Robot movement
Battery Pack
Power supply
Robot Chassis
Mechanical framework
⚙️ System Working
Ultrasonic sensor continuously measures distance ahead
Arduino processes sensor data in real time
If distance < predefined threshold:
Robot stops
Servo scans left and right
Distances are compared
Safest direction is selected
Motor driver executes movement commands
Process repeats continuously for autonomous navigation
🧠 Algorithm Overview
Copy code
Text
Start
→ Initialize sensors and motors
→ Measure distance
→ If obstacle detected:
    Stop
    Scan left & right
    Compare distances
    Move toward safest direction
→ Else:
    Move forward
→ Repeat
📊 System Parameters
Parameter
Value
Obstacle Detection Threshold
~20 cm
Servo Rotation Range
0° – 180°
Power Supply
9V / 12V
Control Logic
Embedded C (Arduino)
🧑‍💻 Individual Contribution — Om Joshi
Led complete hardware assembly and chassis integration
Performed circuit wiring and component interfacing
Integrated ultrasonic sensor, servo motor, and motor driver
Designed and created the complete project PPT presentation
Assisted in debugging motor and sensor issues
Supported team during testing and final demonstration
👥 Team Members & LinkedIn Profiles
- Om Joshi – [LinkedIn](https://www.linkedin.com/in/0m-joshi2307/)  
- Khushal Choudhary – [LinkedIn](https://www.linkedin.com/in/khushal-choudhary-a022b6374/)  
- Aryan Ahirrao – [LinkedIn](https://www.linkedin.com/in/aryan-ahirrao-80087b372/)  
- Virendra Bendale – [LinkedIn](https://www.linkedin.com/in/virendra-bendale-bb339a371/)  
- Sarthak Ghogare – [LinkedIn](https://www.linkedin.com/in/sarthak-ghogare-b4218a385/)  
- Shreyas Gore – [LinkedIn](https://www.linkedin.com/in/shreyas-gore-1416823a2/)  
📦 Project Deliverables
Fully functional autonomous robot
Project PPT presentation
Project poster
Working demonstration video
📈 Learning Outcomes
Embedded systems fundamentals
Sensor interfacing and calibration
Motor control using drivers
Hardware debugging techniques
Team collaboration and technical documentation
🔮 Future Enhancements
Bluetooth / mobile application control
IoT-based monitoring system
GPS-based navigation
AI-powered obstacle recognition
Camera module integration
📜 License
This project is developed strictly for educational purposes.