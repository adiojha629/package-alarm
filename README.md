# package-alarm

# The Problem
Is no surprise that more people around the world are getting packages delivered to their homes. However, this cargo is in a very precarious position: it can get stolen easily! According to C+R Research [link](https://www.crresearch.com/blog/2019-package-theft-statistics-report) 36% of people have had a package stolen, and over half of people surveyed revealed that they knew someone who had had a package stolen.

A common solution is door-bell cameras or extra video cameras, but those innovations didn't stop 42% of respondents from saying that they avoid purchasing certain items online due to the threat of theft. 

There's an easy way to stop this problem; make the package an alarm. In this proof of concept project, we show a way to prevent theft by building a small portable alarm, that will ring an alarm when the package leaves the home. 

# Our project
Our alarm consisted of an Arduino (SparkFun Red Board edition), an ESP8266, and a DC buzzer. The ESP8266 is a WiFi module, and is programmed to connect to the WiFi network of the delivery address. When the ESP loses WiFi connection, it alerts the Arduino, which sounds the buzzer.

In practice, when the package gets stolen, the ESP will lose connection with the intended recipient's WiFi, signalling the alarm. The alarm turns off once the ESP regains the connection, which only happens if the package is returned to intended house.

# Future Improvements
Our project implementation was limited by the hardware accessible. We list several improvements here:
1. 4 AA batteries were used to power the device; the Arduino only needs 5 Volts. Using less batteries would lower the weight and bulk of the alarm.

2. A smaller micro-controller could run the device. The Arduino was needed only to sound the buzzer; in a industrial application a smaller micro-controller (Arduino Nano for example) could perform this task.

3. A Louder buzzer. The small DC buzzer used offers a shrill sound, but the louder the better. An industrial application will require a louder buzzer.

##Closing Remarks
View the video below to see the device in action. With better materials this device can be put inside Amazon packages, and keep our packages safe!
