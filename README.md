# Arduino integration as an IDF component example

Using the information in https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html we have integrated Arduino as a component in IDF, and we have created a convenient wrapper component named ArduinoSubsystem.

Apart from the `arduino-esp32` conponent parameters, we have added the ARDUINO_LOOP_HZ parameter to determine how often the `loop()` function will be invoked from the FreeRTOS task which calls it.

For creating the task we have used the `CONFIG_ARDUINO_LOOP_STACK_SIZE` and the `CONFIG_ARDUINO_RUNNING_CORE` configuration parameters coming from the `arduino-esp32` component, but we are not using the `CONFIG_AUTOSTART_ARDUINO` option, we are creating our own task creation method.

Two comments:
* Activating `CONFIG_AUTOSTART_ARDUINO` will cause an issue because `app_main()` is already defined.  Do not activate it, or then Arduino will be the owner of your startup sequence and you'll have to create a task for pure native ESP-IDF code, because you'll have to comment out main's `app_main()` function.
* We are, at the moment, not making use of some other configuration parameters that we assume are taken into account only when `CONFIG_AUTOSTART_ARDUINO` is active, as for example: `CONFIG_ARDUINO_EVENT_RUNNING_CORE`, `CONFIG_ARDUINO_SERIAL_EVENT_TASK_RUNNING_CORE`, CONFIG_ARDUINO_SERIAL_EVENT_TASK_STACK_SIZE, `CONFIG_ARDUINO_SERIAL_EVENT_TASK_PRIORITY`, `CONFIG_ARDUINO_UDP_RUNNING_CORE`, `CONFIG_ARDUINO_UDP_STACK_SIZE`, `CONFIG_ARDUINO_UDP_PRIORITY`.

## How to Use Example

In main you'll find the typical blink feature implemented in native ESP-IDF source code.  You can adjust its configuration in the section 'Blink main Configuration' of the project sdkconfig.

You can adjust the ArduinoSubsystem component's configuration parameters in the 'ArduinoSubsystem Configuration' section of the project's sdkconfig.

You can adjust the `arduino-esp32` component's configuration parameters in the 'Arduino Configuration' section of the project's sdkconfig.  As stated above, don't activate `CONFIG_AUTOSTART_ARDUINO`.

You'll find the setup() and loop() functions in the ArduinoSubsystem.cpp file inside the ArduinoSubsystem component.

In the app_main() function you can see the `ArduinoSubsystem_start()` function invocation.  Please consider, depending on your project, if this configuration shall be executed after all the hardware is correctly configured by the ESP-IDF's side of the project, or if you have to execute it before this initialization is finished.

## Example Output


```text
I (315) main_task: Calling app_main()
I (319) example: Example configured to blink addressable LED!
I (326) gpio: GPIO[48]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
[    67][I][ArduinoSubsystem.cpp:21] setup(): setup
I (351) uart: queue free spaces: 20
[    77][I][ArduinoSubsystem.cpp:26] setup(): setup end
[    82][I][ArduinoSubsystem.cpp:63] ArduinoSubsystem_start(): [Arduino] ArduinoSubsystem_start launches arduino_main task
[    93][I][ArduinoSubsystem.cpp:32] loop(): loop
I (368) example: Turning the LED OFF!
[   103][I][ArduinoSubsystem.cpp:32] loop(): loop
[   113][I][ArduinoSubsystem.cpp:32] loop(): loop
[   123][I][ArduinoSubsystem.cpp:32] loop(): loop
[   133][I][ArduinoSubsystem.cpp:32] loop(): loop
[   143][I][ArduinoSubsystem.cpp:32] loop(): loop
[   153][I][ArduinoSubsystem.cpp:32] loop(): loop
[   163][I][ArduinoSubsystem.cpp:32] loop(): loop
[   173][I][ArduinoSubsystem.cpp:32] loop(): loop
[   183][I][ArduinoSubsystem.cpp:32] loop(): loop
[   193][I][ArduinoSubsystem.cpp:32] loop(): loop
[   203][I][ArduinoSubsystem.cpp:32] loop(): loop
[   213][I][ArduinoSubsystem.cpp:32] loop(): loop
[   223][I][ArduinoSubsystem.cpp:32] loop(): loop
[   233][I][ArduinoSubsystem.cpp:32] loop(): loop
[   243][I][ArduinoSubsystem.cpp:32] loop(): loop
[   253][I][ArduinoSubsystem.cpp:32] loop(): loop
[   263][I][ArduinoSubsystem.cpp:32] loop(): loop
[   273][I][ArduinoSubsystem.cpp:32] loop(): loop
[   283][I][ArduinoSubsystem.cpp:32] loop(): loop
[   293][I][ArduinoSubsystem.cpp:32] loop(): loop
[   303][I][ArduinoSubsystem.cpp:32] loop(): loop
[   313][I][ArduinoSubsystem.cpp:32] loop(): loop
[   323][I][ArduinoSubsystem.cpp:32] loop(): loop
[   333][I][ArduinoSubsystem.cpp:32] loop(): loop
[   343][I][ArduinoSubsystem.cpp:32] loop(): loop
[   353][I][ArduinoSubsystem.cpp:32] loop(): loop
[   363][I][ArduinoSubsystem.cpp:32] loop(): loop
[   373][I][ArduinoSubsystem.cpp:32] loop(): loop
[   383][I][ArduinoSubsystem.cpp:32] loop(): loop
[   393][I][ArduinoSubsystem.cpp:32] loop(): loop
[   403][I][ArduinoSubsystem.cpp:32] loop(): loop
[   413][I][ArduinoSubsystem.cpp:32] loop(): loop
[   423][I][ArduinoSubsystem.cpp:32] loop(): loop
[   433][I][ArduinoSubsystem.cpp:32] loop(): loop
[   443][I][ArduinoSubsystem.cpp:32] loop(): loop
[   453][I][ArduinoSubsystem.cpp:32] loop(): loop
[   463][I][ArduinoSubsystem.cpp:32] loop(): loop
[   473][I][ArduinoSubsystem.cpp:32] loop(): loop
[   483][I][ArduinoSubsystem.cpp:32] loop(): loop
[   493][I][ArduinoSubsystem.cpp:32] loop(): loop
[   503][I][ArduinoSubsystem.cpp:32] loop(): loop
[   513][I][ArduinoSubsystem.cpp:32] loop(): loop
[   523][I][ArduinoSubsystem.cpp:32] loop(): loop
[   533][I][ArduinoSubsystem.cpp:32] loop(): loop
[   543][I][ArduinoSubsystem.cpp:32] loop(): loop
[   553][I][ArduinoSubsystem.cpp:32] loop(): loop
[   563][I][ArduinoSubsystem.cpp:32] loop(): loop
[   573][I][ArduinoSubsystem.cpp:32] loop(): loop
[   583][I][ArduinoSubsystem.cpp:32] loop(): loop
[   593][I][ArduinoSubsystem.cpp:32] loop(): loop
[   603][I][ArduinoSubsystem.cpp:32] loop(): loop
[   613][I][ArduinoSubsystem.cpp:32] loop(): loop
[   623][I][ArduinoSubsystem.cpp:32] loop(): loop
[   633][I][ArduinoSubsystem.cpp:32] loop(): loop
[   643][I][ArduinoSubsystem.cpp:32] loop(): loop
[   653][I][ArduinoSubsystem.cpp:32] loop(): loop
[   663][I][ArduinoSubsystem.cpp:32] loop(): loop
[   673][I][ArduinoSubsystem.cpp:32] loop(): loop
[   683][I][ArduinoSubsystem.cpp:32] loop(): loop
[   693][I][ArduinoSubsystem.cpp:32] loop(): loop
[   703][I][ArduinoSubsystem.cpp:32] loop(): loop
[   713][I][ArduinoSubsystem.cpp:32] loop(): loop
[   723][I][ArduinoSubsystem.cpp:32] loop(): loop
[   733][I][ArduinoSubsystem.cpp:32] loop(): loop
[   743][I][ArduinoSubsystem.cpp:32] loop(): loop
[   753][I][ArduinoSubsystem.cpp:32] loop(): loop
[   763][I][ArduinoSubsystem.cpp:32] loop(): loop
[   773][I][ArduinoSubsystem.cpp:32] loop(): loop
[   783][I][ArduinoSubsystem.cpp:32] loop(): loop
[   793][I][ArduinoSubsystem.cpp:32] loop(): loop
[   803][I][ArduinoSubsystem.cpp:32] loop(): loop
[   813][I][ArduinoSubsystem.cpp:32] loop(): loop
[   823][I][ArduinoSubsystem.cpp:32] loop(): loop
[   833][I][ArduinoSubsystem.cpp:32] loop(): loop
[   843][I][ArduinoSubsystem.cpp:32] loop(): loop
[   853][I][ArduinoSubsystem.cpp:32] loop(): loop
[   863][I][ArduinoSubsystem.cpp:32] loop(): loop
[   873][I][ArduinoSubsystem.cpp:32] loop(): loop
[   883][I][ArduinoSubsystem.cpp:32] loop(): loop
[   893][I][ArduinoSubsystem.cpp:32] loop(): loop
[   903][I][ArduinoSubsystem.cpp:32] loop(): loop
[   913][I][ArduinoSubsystem.cpp:32] loop(): loop
[   923][I][ArduinoSubsystem.cpp:32] loop(): loop
[   933][I][ArduinoSubsystem.cpp:32] loop(): loop
[   943][I][ArduinoSubsystem.cpp:32] loop(): loop
[   953][I][ArduinoSubsystem.cpp:32] loop(): loop
[   963][I][ArduinoSubsystem.cpp:32] loop(): loop
[   973][I][ArduinoSubsystem.cpp:32] loop(): loop
[   983][I][ArduinoSubsystem.cpp:32] loop(): loop
[   993][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1003][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1013][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1023][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1033][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1043][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1053][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1063][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1073][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1083][I][ArduinoSubsystem.cpp:32] loop(): loop
I (1368) example: Turning the LED ON!
[  1093][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1103][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1113][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1123][I][ArduinoSubsystem.cpp:32] loop(): loop
[  1133][I][ArduinoSubsystem.cpp:32] loop(): loop
```
