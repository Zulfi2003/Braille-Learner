#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>

// Constants
const char* ssid = "YourWiFiSSID"; // Replace with your WiFi SSID
const char* password = "YourWiFiPassword"; // Replace with your WiFi password
const int servoPins[] = {D1, D2, D3, D4, D5, D6}; // Servo pins
const int defaultAngle = 80; // Default servo angle

// Servo objects
Servo servos[6];

// Web server object
ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Print the local IP address

  // Initialize servos
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]); // Attach servos to pins
  }

  // Define web server routes
  server.on("/", HTTP_GET, handleRoot); // Root route
  server.on("/setServoCase", HTTP_GET, handleSetServoCase); // Set servo case route

  // Start the web server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient(); // Handle web server requests
}

// Handle root route
void handleRoot() {
  String html = "<html><body style='text.align:center;'>";
  html += "<h1 style='font-size: 24px;'>Touch Speak Braille Learner</h1>";
  html += "<p style='font-size: 18px:'>Enter a letter:</p>";
  html += "<input type='text' id='letterInput' maxlength='1' size='5'>";
  html += "<br>";  // Add a line break to move to the next line
  html += "<button style='font size: 16px;' onclick='setLetter()'>Enter</button>";
  html += "<script>";
  html += "function setLetter() {";
  html += "  var letter = document.getElementById('letterInput').value;";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/setServoCase?letter=' + letter, true);";
  html += "  xhr.send();";
  html += "}";
  html += "</script>";
  html += "</body></html>";

  server.send(200, "text/html", html); // Send HTML response
}

// Handle setting servo position based on the entered letter
void handleSetServoCase() {
  String letterParam = server.arg("letter");
  char letter = letterParam[0]; // Extract the entered letter

  // Map letters to servo angles
  int servoAngles[6];
  switch (letter) {
    // Define servo angles for each letter
    case 'a':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 80;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'b':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'c':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'd':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'e':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 80;
      servoAngles[3] = 80;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'f':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'g':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'h':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 80;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'i':
      servoAngles[0] = 80;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'j':
      servoAngles[0] = 80;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'k':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'l':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'm':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'n':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'o':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'p':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 'q':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'r':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 's':
      servoAngles[0] = 80;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 80;
      break;
    case 't':
      servoAngles[0] = 80;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 80;
      break;
    case 'u':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 150;
      break;
    case 'v':
      servoAngles[0] = 120;
      servoAngles[1] = 0;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 80;
      servoAngles[5] = 150;
      break;
    case 'w':
      servoAngles[0] = 80;
      servoAngles[1] = 0;
      servoAngles[2] = 80;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 150;
      break;
    case 'x':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 80;
      servoAngles[5] = 150;
      break;
    case 'y':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 0;
      servoAngles[4] = 120;
      servoAngles[5] = 150;
      break;
    case 'z':
      servoAngles[0] = 120;
      servoAngles[1] = 80;
      servoAngles[2] = 0;
      servoAngles[3] = 80;
      servoAngles[4] = 120;
      servoAngles[5] = 150;
      break;
    default:
      // Handle invalid letters or reset to a default state
      for (int i = 0; i < 6; i++) {
        servoAngles[i] = defaultAngle; // Set default angle for all servos
      }
      break;
  }

  // Move the servos to the desired angles
  for (int i = 0; i < 6; i++) {
    servos[i].write(servoAngles[i]); // Set servo angle
    delay(100);
  }
}
