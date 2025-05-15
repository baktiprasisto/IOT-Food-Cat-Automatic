# 🐾 IoT Cat Food Dispenser (Makan Kucing Otomatis)

This project is an **automatic cat feeder** that uses a **NodeMCU (ESP8266)**, a **servo motor**, and the **Blynk app** to remotely feed your cat. With one tap on your smartphone, the servo rotates to release food and returns back automatically.

---

## 🚀 Features

- Remote cat feeding via **Blynk App**
- Servo motor rotates to release food
- Live status monitor through Serial Monitor
- WiFi-based system (ESP8266 / NodeMCU)

---

## 🛠️ Hardware Requirements

- NodeMCU ESP8266
- Servo Motor (SG90 or similar)
- Internet connection
- Power source (USB or battery)
- Optional: Food container and mechanical dispenser system

---

## 📲 Software Requirements

- Arduino IDE
- Blynk Library
- ESP8266 Board Manager
- Blynk App (on your phone)

---

## 📦 Blynk Configuration

- **BLYNK_TEMPLATE_ID**: `TMPL6JsRP8Hlq`
- **BLYNK_TEMPLATE_NAME**: `Makan Kucing`
- **BLYNK_AUTH_TOKEN**: Replace with your own from the Blynk App
- Add **Datastream V0** in Blynk (type: Integer / Switch)

---

## 🧠 How It Works

- The servo starts at position `185°`.
- When the app sends `1` to **V0**, the servo slowly rotates from `185°` to `10°` to release food, then returns to `185°`.
- Once done, it automatically resets the button (V0) back to `0`.

---

## 🧾 Code Overview

- WiFi Connection via `WiFi.begin("SSID", "password")`
- Blynk connection using `Blynk.begin()`
- `BLYNK_WRITE(V0)` is triggered when you press the button
- `BeriMakan()` handles servo movement

---

## 🔧 Setup Instructions

1. Open Arduino IDE and install:
   - Blynk Library
   - ESP8266 Board via Board Manager

2. Select board: **NodeMCU 1.0 (ESP-12E Module)**

3. Upload the code to your NodeMCU

4. Open **Blynk App**:
   - Create a new project
   - Add a **Button Widget** (linked to V0)
   - Set mode to **Switch**

5. Press the button and watch the servo feed your cat! 🐱

---

## 📸 Preview Video

(https://youtu.be/-YEiBKsmXJ8?si=n2uzap_7Qo8nwFR1) 

---

## 👤 Author

**Anugerah Bakti Prasisto**  
<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://twitter.com/zonehell1" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="zonehell1" height="30" width="40" /></a>
<a href="https://www.linkedin.com/in/anugerah-bakti-prasisto-04422122b/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="anugerah bakti prasisto" height="30" width="40" /></a>
<a href="https://www.facebook.com/profile.php?id=100006615318141&locale=id_ID" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="anugrah bakti" height="30" width="40" /></a>
<a href="https://www.instagram.com/bakti_011/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/instagram.svg" alt="baktiprasisto" height="30" width="40" /></a>
<a href="https://www.youtube.com/@baktiprasisto" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/youtube.svg" alt="4ia16_anugerah bakti prasisto" height="30" width="40" /></a>
</p>

---

> This project was created for learning and for fun — and to make sure my cat never misses a meal 😸
