Platformio and Emacs
..............................................................

To use Emacs to handle Platformio projects, follow the next steps:

Create your project directory and enter on it:

.. code-block:: bash

 mkdir ~/your-project
 cd ~/your-project

Obtain your board ID, you can use platformio to search for your board IDE, for
example, to show the boards that are compatible with the ESP8266
microcontroller, use the following command:

.. code-block:: bash

 pio boards wemos

 # Shows something like:
 Platform: espressif8266
 -----------------------------------------------------------------------------
 ID                  MCU           Frequency  Flash   RAM    Name
 -----------------------------------------------------------------------------
 d1                  ESP8266       80Mhz     4096kB  80kB   WeMos D1(Retired)
 d1_mini             ESP8266       80Mhz     4096kB  80kB   WeMos D1 R2 & mini

For arduino you can use:

.. code-block:: bash

 pio boards arduino

 # Shows something like:
 Platform: atmelavr
 -----------------------------------------------------------------------------
 ID                  MCU           Frequency  Flash   RAM    Name
 -----------------------------------------------------------------------------
 nanoatmega328new    ATMEGA328P    16MHz      30KB    2KB     Arduino Nano
 pro16MHzatmega328   ATMEGA328P    16MHz      30KB    2KB     Arduino Pro
 robotControl        ATMEGA32U4    16MHz      28KB    2.50KB  Arduino Robot
 uno                 ATMEGA328P    16MHz      31.50KB 2KB     Arduino Uno

You can also choose your board ID by using the
`platformio boards <https://is.gd/D01WDa>`_ or the
`Embedded Boards <https://platformio.org/boards>`_ Explorer command.

Once you have your board ID, generate the project via the
platformio init **--ide command**, for example using the *d1_mini* board ID:

.. code-block:: bash

 platformio init --ide emacs --board d1_mini

Or for the Arduino Uno:

.. code-block:: bash

 platformio init --ide emacs --board uno

The **init** command will create the project structure, a *platformio.ini* file
will be created on the project's root directory, edit this *platformio.ini* to
specify the serial port that your microcontroller is using on your computer, it
could be something like */dev/ttyUSB0*, */dev/ttyACM0* or similar, for the
ESP8266 add:

.. code-block:: bash

 [env:d1_mini]
 platform = espressif8266
 board = d1_mini
 framework = arduino
 upload_port = /dev/ttyUSB0

For the Arduino Uno add:

.. code-block:: bash

 [env:uno]
 platform = atmelavr
 board = uno
 framework = arduino
 upload_port = /dev/ttyACM0

In order to activate the **platformio** commands on Emacs, you will need to
add a *.projectile* file on the root directory of your project (as Emacs uses
`projectile <https://github.com/bbatsov/projectile>`_
as its only requirement), create an empty *.projectile* file on root directory:

.. code-block:: bash

 touch .projectile

Next, create the file *src/Blink.ino* with the following content and save it:

.. code-block:: bash

 /*
 ESP8266 Blink
 Blink the blue LED on the ESP8266 module.
 */

 #define LED 2 // Define blinking LED pin.

 void setup() {
   pinMode(LED, OUTPUT); // Initialize the LED pin as an output.
 }
 // The loop function runs over and over again forever.
 void loop() {
   digitalWrite(LED, LOW); // Turn LED on (Note that LOW is the voltage level).
   delay(1000); // Wait for a second
   digitalWrite(LED, HIGH); // Turn LED off by making the voltage HIGH.
   delay(1000); // Wait for two seconds.
 }

Open the *src/Blink.ino* file with Emacs, if you are opening a *.ino* file for
the very first time, you probably have to close Emacs and open it again to
refresh the changes made by the package manager.

When Editing on Emacs, you can use the following keybindings:

- C-c i b: Build the project without auto-uploading.

- C-c i c: Clean compiled objects.

- C-c i u: Build and upload.

For more available keybindings, see the
`official documentation <https://is.gd/8HIcsb>`_.