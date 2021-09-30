# arduino

As I learn about [arduino](https://www.youtube.com/watch?v=UoBUXOOdLXY) I write small scripts to achieve _something_.

_Please note:_ the code is written with the [Arduino UNO](https://www.arduino.cc/en/Guide/ArduinoUno) board in mind.

## message

Send a message to the serial monitor.

The project is small enough to introduce arduino and its two main functions: `setup` and `loop`.

```c++
void setup() {
}

void loop() {
}
```

The main difference is that `setup` runs once, while `loop` is executed continuously.

The `Serial` interface provides an immediate way to communicate with the board.

```c++
Serial.begin(9600);
Serial.println("Booting up");
```

- `begin` sets up a channel with a specific data rate (in the monitor there is a drop-down menu with different rates)

- `print` and `println` display a message in the monitor (accessed through tools -> serial monitor or the shortcut `ctrl+shift+m`)

To show how the loop is run continuously, the script updates and displays a counter variable.

```c++
void loop() {
    Serial.println(i);
    i++;
}
```

The function `delay` finally helps to pause the execution of the loop and avoid an excessive number of updates.

```c++
void loop() {
    delay(1000);
}
```

## switch

Toggle a led — or a buzzer — on and off.

In terms of software, the program introduces two essential functions:

- `pinMode` sets up a pin, in a specific digital pin and with a specific type

  ```c++
  void setup() {
  pinMode(8, OUTPUT);
  }
  ```

  In this instance the board would send data through pin number eight

- `digitalWrite` sends a signal to the initialized pin

  ```c++
  digitalWrite(8, 1);
  ```

  `1` turns the switch on, `0` turns it off

With a controlling variable and a sensible delay it is possible to alternate the state of the switch.

- send a signal through a variable (initialized at `0`)

  ```c++
  digitalWrite(PIN, state);
  ```

- toggle the variable between the two values

  ```c++
  if (state == 0) state = 1;
  else state = 0;
  ```

- delay the execution of the iteration which follows

  ```c++
  delay(1000);
  ```

In terms of hardware, it is necessary to create a circuit connecting the led to the board.

```text
    ^
(-)| |(+)
 - | |
 |   |
gnd  |-/\/\- pin
```

## switches

Alternate between switches and with a delay.

Expanding the [**switch**](#switch) program the idea is to set up multiple pins, three led and one buzzer, and loop through the pins in a specific order.

In loop the code actually sends `0` to every pin before sending `1` to the relevant destination.

```c++
digitalWrite(LED_1, 0);
digitalWrite(LED_2, 0);
digitalWrite(LED_3, 0);
digitalWrite(BUZZER, 0);

digitalWrite(pin, 1);
```

With every iteration the `pin` variable is then updated with a `switch` statement.

In terms of hardware, it is necessary to repeat the circuit for every pin.

## keypress

Light up a led following keyboard input.

The `switch ` statement lights up a different pin according to the input received through the `Serial` interface.

In sequence:

- initialize the monitor with `Serial.begin()`

- use `Serial.available()` to consider input from the serial monitor

- with `Serial.parseInt()` you'd be able to parse the input to an integer, but the function would also return `0` after the actual input (possibly due to the new line chartacter)

- use `Serial.readStringUntil("\n")` to consider the input until a new line character

- coerce the input string to an integer with `toInt()` (provided by Arduino)

In terms of hardware the board is similar to that described for the program [**switches**](#switches).

## buttonpress

Toggle a led at the press of a button.

Starting with the hardware, the structure of the board, it is necessary to set up a button. A _pushbutton_ to be precise. [arduino.cc](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button) provides a helpful picture for the circuit:

- connecting a pin on one side of the button to a digital pin

- on the opposite side

  - connect the opposing pin to the ground and through a resistance

  - connect the other pin to voltage (5V)

As I understood the component, the idea is to have current flow through the button, and stop (or limit) the flow when the button is pressed. Reading the voltage it is possible to know if the button is pressed or not.

In terms of script, the program registers the button with the `pinMode` function, but initializes the pin as an input (as opposed to the led, initialized as output).

```c++
void setup() {
    pinMode(BUTTON, INPUT);
}
```

The essential function is then `digitalRead`, reading the value registered by the button.

```c++
int value = digitalRead(BUTTON);
```

To have the led light up while the button is pressed, it is enough to check the value.

```c++
if (value == 1) {
    digitalWrite(LED, 1);
}
else {
    digitalWrite(LED, 0);
}
```

To toggle the led instead it is necessary to have a bit more logic. `isPressed` is initialized as a boolean with the idea of updating the led only once, as the button is pressed.

```c++
if (value == 1) {
    if (!isPressed) {
        isPressed = true;

        -- update led
    }
} else {
    isPressed = false;
}
```

To toggle the value of the pin it would be possible to use an additional variable, as in the [**switch**](#switch) program, but `digitalRead` is also able to read the value from the output pin.

```c++
int state = digitalRead(LED);
```

## delays

Alternate between leds with independent delays.

_Please note:_ the program, works as a stepping stone for a future script creating a stoplight.

With the script introduced in the [**switches**](#switches) demo it is possible to loop between a set up switches with a fixed delay, thanks to the `delay` function. The drawback of the approach is that not only the delay is the same for every switch, but the logic in the `loop` function is not run until the prescribed amount of time has passed.

Here the program keeps track of the number of milliseconds in an unsigned long variable.

```c++
unsigned long previousMillis = 0;
```

In the loop, the `millis()` function then provides the number of milliseconds since the board was initialized.

```c++
unsigned long currentMillis = millis();
```

With this information it is possible to do something, light up a led, as the difference between the two values crosses the chosen threshold.

```c++
if(currentMillis - previousMillis > 1000) {
}
```

Note that, as `millis` provides the time since the board was set up, it is essential to update `previousMillis` with the current value.

```c++
if(currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis;
}
```
