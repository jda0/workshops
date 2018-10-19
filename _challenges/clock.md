---
title: Clock
description: Time to wake up! Turn your Hedgehog Bot into a runaway alarm clock and learn some more about how your Hedgehog Bot works.

beta: true

requires_workshop: Bot
language: C++
est_time: 60&mdash;120min
difficulty: Tricky
completion: 
  - network time protocol
  - writing a program using multiple files
  - namespaces
  - classes
  - structs
  - enums

header_img: /assets/media/hedgehog-clock-top.png
header_bg: "#FAF5FF"
---

1.  #### Download and unzip the starter template
    [Download from GitHub](https://github.com/jda0/hedgehog-clock/releases/latest){: .download}

2.  #### Open **src/src.ino** in Arduino IDE
    You can also open the top folder in any PlatformIO-compatible IDE (such as 
    Visual Studio Code + the PlatformIO IDE extension), and start in 
    **src/hh_clock.cpp**.

3.  #### Follow the instructions, and complete the TODOs, from there

    {: .card-list}
    - ![]({{'/assets/media/screen-connecting.svg' | relative_url}}){: .u-max-full-width}
      Your hedgehog should try and connect to WiFi

    - ![]({{'/assets/media/screen-connectfail.svg' | relative_url}}){: .u-max-full-width}
      If you see 'Connection Failed', check your network's SSID and passphrase _(TODO&nbsp;#2)_

    - ![]({{'/assets/media/screen-alarmface.svg' | relative_url}}){: .u-max-full-width}
      After connecting to the NTP server (check _TODOs #4&nbsp;&&nbsp;#5_ if you don't see 'Getting time' flash up, and your hedgehog freezes) you should see the current time

    - ![]({{'/assets/media/screen-ipface.svg' | relative_url}}){: .u-max-full-width}
      After a second, the alarm icon and alarm time will change to a signal icon and an IP address...

    - ![]({{'/assets/media/screen-phone.svg' | relative_url}}){: .u-max-full-width}
      ...you can type this into your web browser to change the alarm or time zone! If it doesn't work, check _TODO&nbsp;#13_

    - ![]({{'/assets/media/screen-dance.svg' | relative_url}}){: .u-max-full-width}
      When the alarm rings, your hedgehog will dance and the screen will flash! Check _TODO&nbsp;#6_ if it doesn't, and _TODO&nbsp;#7_ to make it dance as you'd like!

    - ![]({{'/assets/media/screen-reset.svg' | relative_url}}){: .u-max-full-width}
      Press RESET on the WeMos to stop the alarm. Check _TODO&nbsp;#12_ if it keeps ringing, and check _TODOs&nbsp;#3&nbsp;&&nbsp;#8-11_ if it resets your alarm and timezone, and/or shows *00:00*.