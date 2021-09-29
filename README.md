# arduino

As I learn about [arduino](https://www.youtube.com/watch?v=UoBUXOOdLXY) I write small scripts to achieve _something_.

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
