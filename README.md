# **Pacemaker Simulation Project – Group 5**  
**SFWRENG 3K04**  
**McMaster University**  
**Term:** Winter 2023

---

## 📘 **Project Overview**  
This project simulates the behavior of a dual-chamber pacemaker using a combination of a GUI, backend database, and signal modeling. The system allows users to log in, configure pacemaker parameters, validate those parameters against clinical constraints, and simulate pacemaker activity using a Simulink model.

---

## 🖥️ **Key Components**

### 🔹 **Pacemaker GUI (PHP + HTML + CSS)**  
- User authentication: login, register, and session tracking  
- User-specific pacemaker configuration stored in MySQL  
- Parameter validation with dynamic input restrictions  
- Responsive interface for entering and editing pacemaker settings  

### 🔹 **Simulink Model**  
- Models the behavior of a dual-chamber pacemaker  
- Takes saved parameter values from the database and simulates pacemaker pulses  
- Visualizes electrical activity and chamber pacing events  
- Implements timing constraints and pacing logic per medical requirements  

### 🔹 **Database (MySQL via XAMPP)**  
- Stores user login credentials securely  
- Stores validated pacemaker parameters per user  
- Accessible through `phpMyAdmin` for management and testing  

---

## 🛠️ **Technologies Used**  
- **Frontend:** HTML, CSS  
- **Backend:** PHP  
- **Simulation:** MATLAB Simulink  
- **Database:** MySQL  
- **Local Server:** XAMPP (Apache + MySQL)

---

## 🚀 **How to Run the Project**

1. **Install XAMPP**  
   Download it from [apachefriends.org](https://www.apachefriends.org/download.html)  
2. **Start XAMPP Control Panel**  
   Enable both Apache and MySQL services  
3. **Clone this repository** into your XAMPP `htdocs` folder  
4. **Launch phpMyAdmin**  
   Visit [http://localhost/phpmyadmin](http://localhost/phpmyadmin)  
5. **Create the `login_db` database** and import the required tables  
   > ⚠️ If you use a different DB name, update the PHP source code accordingly  
6. **Run the Web Interface**  
   Open [http://localhost/pacemakerGUI/welcome.php](http://localhost/pacemakerGUI/welcome.php) in your browser  
7. **Use Simulink**  
   Open the Simulink model (`.slx`) and run the simulation using the settings pulled from the database  

If you have any questions or run into issues, contact: **jiangc46@mcmaster.ca**

---

## 📚 **Learning Outcomes**
- Developed a web-based GUI for user input and configuration  
- Applied real-world constraints to validate pacemaker parameters  
- Simulated cardiac behavior using MATLAB Simulink  
- Integrated embedded system simulation with dynamic web technologies  
- Gained experience working in a multi-language, multi-platform development environment  
