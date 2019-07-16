---
title: Intro to BitBot
description: Learn to code a dancing robot, make it light up with your favourite 
  colours and follow a torch or line!

beta: true

language: JavaScript
est_time: 30&ndash;90min
difficulty: Moderate
completion: 
  - JavaScript

header_img: /assets/media/hedgehog-led-top.png
header_bg: "#FCFDF6"
---

1.  #### Let's Go!

    This workshop focuses on giving a BitBot robot commands using code, written in a language called JavaScript. It has motors, sensors and lights controlled by a Micro:Bit. We can also use JavaScript to make websites, apps and many other things.

    To get started, go to [makecode.microbit.org](https://makecode.microbit.org){: target='_blank' rel='nofollow noopener noreferrer'} and click **New Project**.

    ![The <strong>New Project</strong> button is large, purple and has a plus (+) on it]({{'/assets/media/bitbot-intro/block-new-project.png' | relative_url}}){: .u-max-full-width}

    &#8203;

    This'll open a new project in the editor. We first need to add the BitBot libraries to the Micro:Bit editor, so click **Advanced&rarr;Extensions** in the Block Library on the left.

    ![]({{'/assets/media/bitbot-intro/block-editor.png' | relative_url}}){: .u-max-full-width}

    Search for 'bitbot' and click on `BitBot - Official Microsoft MakeCode package`.
    
    ![]({{'/assets/media/bitbot-intro/block-extension-bitbot.png' | relative_url}}){: .u-max-full-width}
    
    From there, go back to the editor and click **{} JavaScript** at the top, and you're good to go!

2.  #### Turn on the Lights

    Let’s do some coding and test the botbit is working by turning on it’s lights! At the moment, your code editor should read...

    ```js
    basic.forever(function () {
      
    })
    ```
    {: .ide}

    There's a lot to learn here so we might come back to it -- for now, replace it with (or type below it):

    ```js
    bitbot.neoRainbow()
    ```
    {: .ide}

    As you start typing, the editor will pop up suggestions of what you're trying to type. You can select a completion from the list by pressing the up and down arrows on your keyboard to select the right one, and pressing the tab key.
    {: .requisite-warning .warning .info .compact}

    &#8203;

    ##### Copying It to the Micro:Bit

    Click the download button and the bottom of the screen and save the code (hex file) to the Micro:Bit.

    ![]({{'/assets/media/bitbot-intro/block-download.png' | relative_url}}){: .u-max-full-width}

    The code will often download to your _Downloads_ folder. You'll need to open _File Explorer_ (_Finder_ on macOS), and copy the file to _MICROBIT_. On Windows, you can find _MICROBIT_ in _This PC_ or _My Computer_ &mdash; on other operating systems, it'll be wherever you find USB drives.
    {: .requisite-warning .warning .compact}

    You should see a little yellow light flashing on the Micro:Bit (next to the USB port) while the hex file is copying over. Once it’s stopped flashing, unplug the USB cable and switch on the BitBot with the on/off switch!

    &#8203;

    ##### A BitBot to be Proud of

    Hopefully when you turn on the BitBot you can see a rainbow of lights like so:

    ![Image: the LEDs on the BitBot are lit different colours, like a rainbow.]({{'/assets/media/bitbot-intro/bitbot-rainbow.jpg' | relative_url}}){: .u-max-full-width}

    If it doesn’t look like this check your code and make sure it has downloaded to the right place. Also make sure you unplug the USB cable. If it’s still not working ask a helper for help.

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

    Next, see if you can make another LED light up a different colour. You can see on the BitBot that each LED is numbered...

    ![Image: each LED on the BitBot is numbered from 0 to 11]({{'/assets/media/bitbot-intro/bitbot-leds.png' | relative_url}}){: .u-max-full-width}

    Duplicate and amend this line for all of the LEDs you'd like to set the colour of. When you’re happy with your code, click **Download** and save it to the Micro:Bit. Once it’s finished copying to the Micro:Bit and the USB light has stopped flashing, unplug the USB cable and switch on the bitbot. Are the lights working like you expected?

    &#8203;

    ##### Take Your Time

    You could also try adding lines that read:

    ```js
    basic.pause(200)
    ```
    {: .ide}

    Try adding this line in between two lines that turn on LEDs. What do you think this will do?
    
    &#8203;

    ##### For Smart Cookies (Extension)

    This part is optional &mdash; you can skip to step 4 if you prefer!
    {: .requisite-warning .warning .compact}

    A **for** loop allows us to repeat code without typing it again and again. It has the form:

    ```js
    for (<start>; <condition>; <each_time>) {
      <code>
    }
    <then>
    ```

    where `<start>` contains instructions to perform before the first time the `<code>` runs, and the `<condition>` tells the computer whether to loop again or skip to `<then>`. For example, what you expect `x` to equal after the following code has run?

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

    Try using a for loop to animate the lights! You can also make it run forever by wrapping your code with:

    ```js
    basic.forever(() => {
      <code>
    })
    ```

    ```js
    basic.forever(() => {

      bitbot.neoRainbow()
      
      for (let i = 0; i < 11; i++) {     // i++ adds 1 to i
        basic.pause(200)
        bitbot.neoSetPixelColor(i, bitbot.BBColours(BBColors.Black))
      }

    })
    ```
    {: .spoiler .ide data-spoiler-text="<em class="hidden-print">Click to show example</em>"}

4.  #### Making It Move

    Remember the code we started with?

    ```js
    basic.forever(function () {
      
    })
    ```
    {: .ide}

    Code you put in the gap will loop forever! Let’s test this out by getting your BitBot to move. Copy the code below into the editor:

    ```js
    basic.forever(() => {
      bitbot.driveMilliseconds(600, 400)
      basic.pause(500)
    })
    ```
    {: .ide}

    This code will make the bitbot drive forward at speed **600** for **400** milliseconds (or 0.4 seconds), then pause for half a second (500ms).

    `() => {}`  and `function () {}` are very similar, and define functions (blocks of code, which we can give names and reuse). There's subtle differences we won't get into here as they don't affect us with what we're doing. If you're really curious, you can learn more on the [MDN web docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions){: target='_blank' rel='nofollow noopener noreferrer'}.
    {: .spoiler .requisite-warning .warning .info .compact data-spoiler-text="<em class="hidden-print">If you're curious: What's the difference between <em><code>() =></code></em> and <em><code>function ()?</code></em></em>" }

    Download it to your Micro:Bit. Remember: once the USB light on the Micro:Bit has stopped flashing, unplug the USB cable and switch on the bitbot.
    
    Is the bitbot moving? Does the code behave like you think it should? If so, now switch off the bitbot.
    
    Now, try changing the speed of the motors (the maximum speed is 1023, and you can only use integers/whole numbers). Try negative numbers - what do you think will happen?

    &#8203;

    ##### Like a Spinning Top...

    You can also make your Bit:Bot spin clockwise by replacing the line `bitbot.driveMilliseconds(600, 400)` with the line:

    ```js
    bitbot.driveTurnMilliseconds(BBRobotDirection.Right, 600, 400)
    ```
    {: .ide}

    Try changing the direction, speed and duration of the turn, and combining driving, turns, pauses and lights to make a little disco robot. If you get stuck, you can click on **Blocks** at the top to see your code as blocks!

    ```js
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

6.  #### Do You Have the Lämp Bröther?