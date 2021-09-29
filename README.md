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

Expanding the [switch](#switch) program the idea is to set up multiple pins, three led and one buzzer, and loop through the pins in a specific order.

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
