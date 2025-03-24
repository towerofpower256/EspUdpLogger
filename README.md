## EspLogUdp
A simple and fast library for sending log messages from ESP8266 and ESP32 microcontrollers.

Great when you want to send debug and log messages, but:
* you can't use serial
* it's not right next to you

## Usage
Setup

```cpp
const char* logPrefix = "[MyLog] ";
EspLogUdp logger;

setup() {
    //...

    logger.setPrefix(logPrefix);
    
    // Optional: set the target and port. Default: broadcast on port 12345
    //logger.init(IPAddress(192, 168, 1, 1), 8888); // logger.init(ip_address, port)

    //...
}
```

Sending a simple message.
```cpp
logger.send("Hello there, I am OK");
```

Building and sending complex message.

```cpp
// Build and send a larger message
logger.start();
logger.print("Running for ");
logger.print(millis());
logger.print(" millis");
logger.end();

// > [MyLog] Running for 1234 millis
```

## Receiving log messages
The "tools" folder includes some scripts for receiving log messages sent by the library (or any other UDP library).

* [PythonUdpListener](tools/PythonUdpListener.py) for Win/Linux/Mac users using Python
* Linux users can use `netcat` or `nc`. `nc -u -l -k 12345`
* [PowershellUdpListener](toos/PowershellUdpListener.ps1) for Powershell / Windows