# fridgeSensor

https://lh3.googleusercontent.com/pw/AP1GczPJCIxtVFK7uQCfm6RUJHEf0isPyK9iRUglZuzypdGe1IJhN_08Lq05Ni7DR94snB5KxXct9gGgMjQHYn4ddHNwBKOXio66lBWL05n09xguc6RNPfDp_nZs8Mbc00N5wqsQF6Sbq6vA-SGys2qTESDvqFtdkfPy9O2qrezK708GJ9cS3HxBWZZcH4QRBB634If4ZNVc3TyfhI_YO3kBpIz39Goei3a1csDvxtNjpGvkLmNL5hG01fDHeC677fPO-XRcxpn67wVfmVKrNt0rq7D9bUXJkaKvqmlzO7GVhHOtqMWF8djqsHo5gF2-3_FaZL5TGJfXq5MoITLlRjDr6ClXoQn6XUdoSus-6xe14F8bDkmMb442jLzUGt-q2WPallch_BToThaHa0KDuYRrdi8AiT2UKDuMuKd5lq8q3KsjIxcA2AD1OIwzTihSGT9YWT9bpBW_F857PJtA1aEq9wXsyYkiJ1fx4R8ptFN1_1hUXfKtGbVCxSHuyUE4nWF9nPrJA2SDRckjF3yS_CYJ7hJ4z0waM6k-_hTuXBaf-aQBqknPaD5zjO4DHM3NBljo_Viz17rxk346p9PB6SxzG4RLyYLfDIPCqkLexqRGhiGKcvZoRG-1DQgV2mKQaIUk8KN9aYwOIpAJxQaeCJo4kGmKfG-ov1K4-EsiO1SZgsoBrpRWy5BWJ-lg8mM_ann-lbQTf0y7jir1t4CdnqZw47VeQQh4Pur3IKQug08s15gncVfOrD0hBByLntIlYQlIpkJc0L14t0KDiQzL0GWVpQbfXbFog_F354hl9iM-V-l293T7eCloKHwjXGBElKTJhC7J3Vy6EGoTeYV1MxPAEItYnkhh74Rqt7mg3d7L7zCcO3eku0KNkUXCQTm2RUfhiySy0EEaVOoJYKfZixlyQoPt3u1s=w1098-h1463-s-no-gm?authuser=0 

My fridge opens randomly, and if no one is in the kitchen, it stays open for a long time. I really don't want the food to go bad, so I made a sensor that beeps very loud until someone closes the fridge door. 

Video Demonstration: 
https://photos.app.goo.gl/chd5CcAcaTNBbfrV7


Rough Order of Events/Timeline: 
- test ultrasonic sensor with Arduino Nano
- write the code so an LED blinks when the fridge door has been open for a certain time, then the LED turns off when the fridge door is closed
- make it so the LED only goes off when the fridge door is closed for 3 seconds, so that the sensor isn't too sensitive and isn't fooled easily
- make it so that the LED blinks instead of just going on and off, and do this without delays (use a boolean and millis) to increase responsiveness
- add a buzzer, and since the Arduino Nano pins cannot supply enough current to make the buzzer very loud, use a transistor
- modify the constants for the time the door must be open for the buzzer to start beeping, and the time the door must be closed for the buzzer to stop beeping, then put everything on the breadboard and attach it to the wall

Last updated: 
March 31st 2024 

Possible Improvements: 
- use the ATtiny85 instead of the Arduino nano as it is smaller, cheaper, and more energy efficient
- try using a battery, and to make this last long, try using a low-power or sleep mode on the ATtiny85**
- 3D print a case so this is much prettier and more durable 

**Note: 
the current consumption of the ATtiny85 is 2mA, the buzzer is 50mA, and the ultrasonic sensor is 15mA max, so totals to about 67mA max with the buzzer on, and 17 mA max with the buzzer off, and for the Duracell 9V alkaline battery I plan to use, the rating is about 550 mAh, so I would get about 8.5 hours of buzzer on and 32 hours without the buzzer, which isn’t even a day. I will try and use a low power mode or something. 
