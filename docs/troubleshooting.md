# Troubleshooting

## "I can't program my robot"

* Does the wemos board show up in device manager?
  * Yes
    * Is it assigned a port?
      * Yes -> Try resetting the board, unplugging the robot and power cycling everything
      * No -> Something is wrong with the drivers, try power cycling
      * Still not working -> Reinstall the drivers
  * No
    * Does a different tested working board show up?
      * Yes -> Replace the wemos board
      * No -> Try another USB cable and/or port
      * Still not working -> Reinstall the drivers

## Anything related to robot not performing actions

* Check code has been uploaded
* Check code is correct
* Check wiring
