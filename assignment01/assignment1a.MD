# Assignment 1.a

### Description

**Using the telegraph example, and the challenges listed in the module as reference, describe another device that you
would like to discuss.  Describe how you think its embedded system works, and what design challenges it presents.**

#### Device: the FitBit Blaze

My embedded device that I wear every day is the FitBit Blaze Smart Fitness Watch.  My primary use of this device is to
capture my **heart rate** and **step count** while wearing the device; additional data can also be provided, such
as **distance traveled** (a product of **step count** and not how far the device has traveled) and **flights ascended**.

On the backside of the device is what some sort of sensor that is responsible for reading **heart rate**.  When I take
the watch off, I can see LEDs flickering at a rate just below what is noticeable by the human eye.  I assume the green
LEDs play some role in helping the device detect what the **heart rate** is currently at.

For the **step count**, I assume that the device has one or more accelerometers that feed the software data.  The software
will then look at this data to determine if the acceleration profile matches to some extent a typical acceleration profile
for movement.  Based on this profile, the software will calculate an approximate distance traveled and even a delta in elevation.

##### DESIGN CHALLENGES

###### Throughput

The device is constantly receiving data when it is being worn (less so when it is taken off); it needs to take data from
more than a single subsystem and crunch the numbers to provide the end user with useful data.

###### Response

Almost immediate response desired by users once the device is being worn.

###### Testability

Need a human in the loop to test step detection algorithms; probably many testers required because there may be several
different acceleration profiles to test against.

###### Debuggability

Display is available for debug output but no direct methods of actively controlling the software.

###### Reliability

The device is expected to be running correctly for months on end while only needing to be recharged.

###### Memory Space

The device has limited memory and is expected to keep an unknown amount of data on the device until it is transferred
from the device via the accompanying smart phone application.

###### Program Installation and Updates

After initial installation, a smart phone with Bluetooth capability and an application is required to update the device.

###### Power Consumption

The device is running running on battery power.  Software must conserve battery life by suspending processes that are not
being actively used (**heart rate** sensor when the device is not worn, display when the user has their wrist at their
side).

###### Security

The device uses Bluetooth for remote connection between the smart phone application and itself.  Whatever security design
challenges are present with the specific version of Bluetooth will be present in this device.

###### Cost

Keep the cost of the device down to drive up profits; consumers don't seem to be bothered much by expensive smart watches.
