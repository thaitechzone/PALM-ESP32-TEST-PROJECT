# สรุปตำแหน่งพินและอุปกรณ์บนบอร์ด ESP32 Devkit V2 (ThaiTechZone V2)

เอกสารสรุปตำแหน่งขาใช้งาน (Pinout) อุปกรณ์อินพุต Output และอินเทอร์เฟซการสื่อสารบนบอร์ด **ESP32 Devkit V2**

---

## 1. ตารางสรุป Pin Mapping

| หมวดหมู่ | ชื่ออุปกรณ์ / ฟังก์ชัน | ตำแหน่ง GPIO / พิน | ลักษณะการทำงาน / หมายเหตุ |
| :--- | :--- | :--- | :--- |
| **Push Buttons** | **SW1** | `GPIO34` | สวิตช์กดติด-ปล่อยดับ (Input Only) |
| | **SW2** | `GPIO35` | สวิตช์กดติด-ปล่อยดับ (Input Only) |
| | **SW3** | `GPIO32` | สวิตช์กดติด-ปล่อยดับ |
| **Isolated Inputs** | **ISO1** | `GPIO33` | Optocoupler Input (แยกสัญญาณไฟฟ้า) |
| | **ISO2** | `GPIO27` | Optocoupler Input (แยกสัญญาณไฟฟ้า) |
| **Relay Outputs** | **Relay 1** | `GPIO17` | ควบคุมรีเลย์ช่องที่ 1 |
| | **Relay 2** | `GPIO16` | ควบคุมรีเลย์ช่องที่ 2 |
| | **Relay 3** | `GPIO4` | ควบคุมรีเลย์ช่องที่ 3 |
| **External I/O Ports** | **Port 1** | `GPIO14` | พินเชื่อมต่อภายนอก (พร้อมสกรีน +5V) |
| | **Port 2** | `GPIO13` | พินเชื่อมต่อภายนอก (พร้อมสกรีน +5V) |
| **Display Interface** | **OLED Display** | `I2C Bus` | รองรับจอ OLED ผ่านบัส I2C (SDA / SCL) |
| **Serial Communication**| **RS485 (Serial0)** | Terminal `B-`, `A+` | สื่อสารอนุกรมผ่าน RS485 |
| **Mode Switch** | **SW Mode** | - | • **กด:** เลือกโหมด RS485<br>• **ลอย (ไม่กด):** เลือกโหมด RS232 |
| **Board Control Buttons**| **BOOT** | - | กดค้างขณะ Upload โค้ด (หากบอร์ดไม่เข้า Bootloader อัตโนมัติ) |
| | **Reset** | - | ปุ่ม Hard Reset บอร์ด ESP32 |
| **Power Supply** | **Power Input** | `9 - 12V` / `9 - 24V` | ขั้วต่อไฟเลี้ยงบอร์ด (DC/AC Supply) |

---

## 2. ตัวอย่างการประกาศ Pin Definition (C++ / PlatformIO)

สามารถคัดลอกโค้ดนี้ไปไว้ในไฟล์ Header เช่น `pin_config.h` หรือส่วนบนของ `main.cpp` ได้ทันที:

```cpp
#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// ==========================================
// Push Buttons (Digital Inputs)
// ==========================================
#define PIN_SW1       34  // Input Only (ต้องใช้ External Pull-up/down)
#define PIN_SW2       35  // Input Only (ต้องใช้ External Pull-up/down)
#define PIN_SW3       32

// ==========================================
// Optocoupler Isolated Inputs
// ==========================================
#define PIN_ISO1      33
#define PIN_ISO2      27

// ==========================================
// Relay Outputs
// ==========================================
#define PIN_RELAY1    17
#define PIN_RELAY2    16
#define PIN_RELAY3    4

// ==========================================
// External Header I/O Ports
// ==========================================
#define PIN_EXT_IO14  14
#define PIN_EXT_IO13  13

// ==========================================
// Setup Function Helper
// ==========================================
inline void setupBoardPins() {
    // Configuration for Inputs
    pinMode(PIN_SW1, INPUT);
    pinMode(PIN_SW2, INPUT);
    pinMode(PIN_SW3, INPUT_PULLUP);
    
    pinMode(PIN_ISO1, INPUT);
    pinMode(PIN_ISO2, INPUT);
    
    // Configuration for Outputs
    pinMode(PIN_RELAY1, OUTPUT);
    pinMode(PIN_RELAY2, OUTPUT);
    pinMode(PIN_RELAY3, OUTPUT);
    
    // Default Relay OFF State (ขึ้นอยู่กับวงจรว่าเป็น Active High หรือ Active Low)
    digitalWrite(PIN_RELAY1, LOW);
    digitalWrite(PIN_RELAY2, LOW);
    digitalWrite(PIN_RELAY3, LOW);
}

#endif // PIN_CONFIG_H