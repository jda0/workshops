---
title: Intro to BitBot
description: Learn to code a dancing robot, make it light up with your favourite 
  colours and follow a torch or line!

beta: true

language: JavaScript
est_time: 30&ndash;90min
difficulty: Moderate
completion: 
  - if statements
  - for loops
  - coding in JavaScript
  - dancing 
  - generative art


header_img: /assets/media/hedgehog-led-top.png
header_bg: "#FCFDF6"
---

1.  #### Let's Go!

    This workshop focuses on giving a BitBot robot commands using code, written 
    in a language called JavaScript. It has motors, sensors and lights 
    controlled by a Micro:Bit. We can also use JavaScript to make websites, apps 
    and many other things.

    To get started, go to [makecode.microbit.org](https://makecode.microbit.org){: target='_blank' rel='nofollow noopener noreferrer'} 
    and click **New Project**.

    ![The <strong>New Project</strong> button is large, purple and has a plus (+) on it]({{'/assets/media/bitbot-intro/block-new-project.png' | relative_url}}){: .u-max-full-width}

    &#8203;

    This'll open a new project in the editor. We first need to add the BitBot 
    libraries to the Micro:Bit editor, so click **Advanced&rarr;Extensions** in 
    the Block Library on the left.

    ![]({{'/assets/media/bitbot-intro/block-editor.png' | relative_url}}){: .u-max-full-width}

    Search for 'bitbot' and click on 
    `BitBot - Official Microsoft MakeCode package`.
    
    ![]({{'/assets/media/bitbot-intro/block-extension-bitbot.png' | relative_url}}){: .u-max-full-width}
    
    From there, go back to the editor and click **{} JavaScript** at the top, 
    and you're good to go!

2.  #### Turn on the Lights

    Let’s do some coding and test the BitBot is working by turning on it’s 
    lights! At the moment, your code editor should read...

    ```js
    basic.forever(function () {
      
    })
    ```
    {: .ide}

    There's a lot to learn here so we might come back to it -- for now, replace 
    it with (or type below it):

    ```js
    bitbot.neoRainbow()
    ```
    {: .ide}

    As you start typing, the editor will pop up suggestions of what you're 
    trying to type. You can select a completion from the list by pressing the up 
    and down arrows on your keyboard to select the right one, and pressing the 
    tab key.
    {: .requisite-warning .warning .info .compact}

    &#8203;

    ##### Copying It to the Micro:Bit

    Click the download button and the bottom of the screen and save the code 
    (hex file) to the Micro:Bit.

    ![]({{'/assets/media/bitbot-intro/block-download.png' | relative_url}})
    {: .u-max-full-width}

    The code will often download to your _Downloads_ folder. You'll need to open 
    _File Explorer_ (_Finder_ on macOS), and copy the file to _MICROBIT_. On 
    Windows, you can find _MICROBIT_ in _This PC_ or _My Computer_ &mdash; on 
    other operating systems, it'll be wherever you find USB drives.
    {: .requisite-warning .warning .compact}

    You should see a little yellow light flashing on the Micro:Bit (next to the 
    USB port) while the hex file is copying over. Once it’s stopped flashing, 
    unplug the USB cable and switch on the BitBot with the on/off switch!

    &#8203;

    ##### A BitBot to be Proud of

    Hopefully when you turn on the BitBot you can see a rainbow of lights like 
    so:

    ![Image: the LEDs on the BitBot are lit different colours, like a rainbow.]({{'/assets/media/bitbot-intro/bitbot-rainbow.jpg' | relative_url}}){: .u-max-full-width}

    If it doesn’t look like this check your code and make sure it has downloaded 
    to the right place. Also make sure you unplug the USB cable. If it’s still 
    not working ask a helper for help.

    **Now switch off the BitBot.**

3.  #### Making it our own

    Now the lights are working it’s time to customise them! 

    Delete the line you added above, and replace it with the line:

    ```js
    bitbot.neoSetPixelColor(0, bitbot.BBColours(BBColors.Red))
    ```
    {: .ide}

    Download it to your Micro:Bit and see what happens!

    &#8203;

    #### We Need More Colours...

    Next, see if you can make another LED light up a different colour. You can 
    see on the BitBot that each LED is numbered...

    ![Image: each LED on the BitBot is numbered from 0 to 11]({{'/assets/media/bitbot-intro/bitbot-leds.png' | relative_url}}){: .u-max-full-width}

    Duplicate and amend this line for all of the LEDs you'd like to set the 
    colour of. When you’re happy with your code, click **Download** and save it 
    to the Micro:Bit. Once it’s finished copying to the Micro:Bit and the USB 
    light has stopped flashing, unplug the USB cable and switch on the bitbot. 
    Are the lights working like you expected?

    &#8203;

    ##### Take Your Time

    You could also try adding lines that read:

    ```js
    basic.pause(200)
    ```
    {: .ide}

    Try adding this line in between two lines that turn on LEDs. What do you 
    think this will do?
    
    &#8203;

    ##### For Smart Cookies (Extension)

    {::options parse_block_html="true" /}
    <div class="spoiler" data-spoiler-text="This part is optional &mdash; you can skip to <strong>step 4</strong> if you prefer! <em>Click to show anyway.</em>">

    A **for** loop allows us to repeat code without typing it again and again. 
    It has the form:

    ```js
    for (<start>; <condition>; <each_time>) {
      <code>
    }
    <then>
    ```

    where `<start>` contains instructions to perform before the first time the 
    `<code>` runs, and the `<condition>` tells the computer whether to loop 
    again or skip to `<then>`. For example, what do you expect `x` to equal 
    after the following code has run?

    ```js
    let x = 0
    for (let i = 1; i < 5; i++) {     // i++ adds 1 to i
      x += i                          // x += i adds i to x
    }
    x -= 5                            // What do you think this does?
    ```

    The answer is:
    
    ## x = 0 + { 1 + 2 + 3 + 4 } - 5 = 5
    {: .spoiler data-spoiler-text="<em class="hidden-print">Click to show answer</em>"}

    &#8203;

    Try using a for loop to animate the lights! You can also make it run forever 
    by wrapping your code with:

    ```js
    basic.forever(() => {
      <code>
    })
    ```

    ```js
    // Animated lights example
    basic.forever(() => {
      bitbot.neoRainbow()
      for (let i = 0; i < 12; i++) {     // i++ adds 1 to i
        basic.pause(200)
        bitbot.neoSetPixelColor(i, bitbot.BBColours(BBColors.Black))
      }
    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show example</em>"}

    </div>

4.  #### Making It Move

    Remember the code we started with?

    ```js
    basic.forever(function () {
      
    })
    ```
    {: .ide}

    Code you put in the gap will loop forever! Let’s test this out by getting 
    your BitBot to move. Copy the code below into the editor:

    ```js
    basic.forever(() => {
      bitbot.driveMilliseconds(600, 400)
      basic.pause(500)
    })
    ```
    {: .ide}

    This code will make the bitbot drive forward at speed **600** for **400** 
    milliseconds (or 0.4 seconds), then pause for half a second (500ms)... and 
    repeat it forever!

    `() => {}`  and `function () {}` are very similar, and define functions 
    (blocks of code, which we can give names and reuse). There's subtle 
    differences we won't get into here as they don't affect us with what we're 
    doing. If you're really curious, you can learn more on the 
    [MDN web docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions){: target='_blank' rel='nofollow noopener noreferrer'}.
    {: .spoiler .requisite-warning .warning .info .compact data-spoiler-text="<em class="hidden-print">If you're curious: What's the difference between <em><code>() =></code></em> and <em><code>function ()?</code></em></em>" }

    Download it to your Micro:Bit. Remember: once the USB light on the Micro:Bit 
    has stopped flashing, unplug the USB cable and switch on the bitbot.
    
    Is the bitbot moving? Does the code behave like you think it should? If so, 
    now switch off the bitbot.
    
    Now, try changing the speed of the motors (the maximum speed is 1023, and 
    you can only use integers/whole numbers). Try negative numbers - what do you 
    think will happen?

    &#8203;

    ##### Like a Spinning Top...

    You can also make your Bit:Bot spin clockwise by replacing the line 
    `bitbot.driveMilliseconds(600, 400)` with the line:

    ```js
    bitbot.driveTurnMilliseconds(BBRobotDirection.Right, 600, 400)
    ```
    {: .ide}

    Try changing the direction, speed and duration of the turn, and combining 
    driving, turns, pauses and lights to make a little disco robot. If you get 
    stuck, you can click on **Blocks** at the top to see your code as blocks!

    ```js
    // Dancing Example
    bitbot.neoRainbow()
    basic.forever(() => {
      bitbot.driveMilliseconds(600, 400)
      basic.pause(500)
      bitbot.driveTurnMilliseconds(BBRobotDirection.Left, 200, 1000)
      bitbot.driveMilliseconds(-600, 400)
      basic.pause(200)
      bitbot.driveTurnMilliseconds(BBRobotDirection.Right, 1023, 300)
    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show example</em>"}

    **Remember to switch off the BitBot while you code!**

5.  #### Line Following

    On the bottom of your BitBot you'll see two line sensors:

    ![Image: the line sensors on your bitbot look like a pair of translucent domes, coloured blue and black]({{ '/assets/media/bitbot-intro/bitbot-sensors.png' | relative_url }}){: .u-max-full-width}

    We're going to use these line sensors to tell the bitbot to follow a line.

    ![]({{ 'assets/media/bitbot-intro/bitbot-line.jpg' | relative_url }}){: .u-max-full-width}

    &#8203;

    ##### If This Then That

    To follow a line, we need to do the following:

    - **If** the left line sensor detects a line, **then** spin left;
    - **Else If** the right line sensor detects a line, **then** spin right;
    - **Else** drive straight on.

    We can express this in code using an **if statement**, which takes the form:
    
    ```js
    if (<condition>) <then>             // <then> can only be one line of code
    else if (<other_condition>) <then>
    else <otherwise>
    
    // or

    if (<condition>) {
      <then>                            // <then> can be as much code as you like
                                        //   if you add parentheses around it!
    } else if (<other_condition>) {
      <then>
    } else {
      <otherwise>
    }
    ```
    
    **Note the brackets around the condition!** We can turn "***if** the 
    left line sensor detects a line, **then** spin left*" into the code:

    ```js
    basic.forever(() => {
      if (bitbot.readLine(BBLineSensor.Left)) {
        bitbot.driveTurn(BBRobotDirection.Left, 300)
      }
    })
    ```
    {: .ide}

    **Delete your `forever` loop and replace it with the code above.** Can you 
    do the other conditions from above on your own? Once you’ve finished your 
    code, download it to the Micro:Bit and switch on the BitBot to test it out. 
    If you’re stuck ask for help. 

    ```js
    // Line following
    basic.forever(() => {
      if (bitbot.readLine(BBLineSensor.Left)) {
        bitbot.driveTurn(BBRobotDirection.Left, 300)
      } else if (bitbot.readLine(BBLineSensor.Right)) {
        bitbot.driveTurn(BBRobotDirection.Right, 300)
      } else {
        bitbot.drive(300)
      }
    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show solution</em>"}

    Why not add LEDs to show when the bitbot is turning left and right?
    
    Setting an LED to black turns it off.
    {: .requisite-warning .warning .info .compact}


6.  #### Do You Have the Lämp Bröther?

    Now we’ve done line following, how about light following? Just like the 
    line following sensors, the BitBot has two light following sensors:

    ![Image: the light sensors on your bitbot are on the tips of the two 'arms' and look like a pair of small white squares.]({{ '/assets/media/bitbot-intro/bitbot-ldrs.png' | relative_url }}){: .u-max-full-width}

    You can get the amount of light hitting the left sensor (an integer between 
    0 and 1023) by writing:
    
    ```js
    bitbot.readLight(BBLightSensor.Left)`
    ```
    
    You can swap `Left` with `Right` to get the amount of light hitting the 
    other sensor.
    
    Try writing some code to control the speed and direction of the motors 
    depending on the amount of light hitting the sensors! You can control the speed an individual motor by writing:
    
    ```js
    bitbot.motor(BBMotor.Left, 600)
    ```

    ```js
    // Simple light following
    basic.forever(() => {
      bitbot.motor(BBMotor.Left, bitbot.readLight(BBLightSensor.Left))
      bitbot.motor(BBMotor.Right, bitbot.readLight(BBLightSensor.Right))
    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show simple solution</em>"}

    ```js
    // Advanced light following
    const lbg = bitbot.readLight(BBLightSensor.Left)
    const rbg = bitbot.readLight(BBLightSensor.Right)

    basic.forever(function () {
        const lls = bitbot.readLight(BBLightSensor.Left) - lbg
        const rls = bitbot.readLight(BBLightSensor.Right) - rbg

        if (Math.abs(lls - rls) < 64)
          bitbot.drive(300)
        else if (lls > rls) {
          bitbot.driveTurn(BBRobotDirection.Left, 300)
        } else {
          bitbot.driveTurn(BBRobotDirection.Right, 300)
        }
    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show advanced solution</em>"}

7.  #### Is This Art?

    Before continuing, put your robot onto **at least 3 layers** of flipchart 
    paper or similar &mdash; we don't want to mark tables or the floor!
    {: .requisite-warning .warning .compact }

    Let's put a Sharpie&#174; (other marker brands are available) into the pen 
    holder on the back of your robot, and make some art! 
    
    Now, turn on your robot and let it dance. What does it draw?

    ![]({{ '/assets/media/art.jpg' | relative_url }}){: .u-max-full-width}

    Lets draw something pretty, like a flower. Lots of flowers have 
    *rotational symmetry*, meaning that they look exactly the same from 
    different angles. We can recreate this using for loops!

    For example, to draw something like a daffodil we can write:
    
    ```js
    basic.pause(2000)
    for (let i = 0; i < 6; i++) {
        bitbot.driveTurnMilliseconds(BBRobotDirection.Left, 300, 335)
        basic.pause(100)
        bitbot.driveMilliseconds(300, 200)
        basic.pause(100)
    }
    ```
    {: .ide}

    Try lots of repetitions so that petals overlap. What do you think?

    How might you draw a rose? *A hint: your BitBot should draw shorter lines 
    as it goes around. How might you do this?*