# Hovercraft-Code
Arduino code used for a remote controlled Hovercraft
Control_Brushless_Motor is test code used to figure out how the brushless motors we used on the fans could be controlled. 
RC_Control has several variants posted here, which go in numerical order from earliest to latest date of creation. 

Background:
Hovercrafts typically function by generating a pressure higher than atmospheric underneath the base of the craft, which generates lift..  Typically this high pressure “air cushion” is partly contained within a skirt, which acts as a momentum curtain (restricts airflow out from under the base leading to less friction and a higher stagnation pressure acting on the underside of the base).  In a traditional commercial hovercraft, a large lateral fan provides the forward thrust for the hovercraft with air rudders or swivelling the thrust fan providing directional control. Unlike most aircraft, hovercrafts can generate lift while stationary (the mechanism being nearly identical to a helicopter in ground effect).

Control System:
The hovercraft’s control system was designed through the usage of an Arduino Uno Rev3 control board and the FS-TH9X remote controller. This remote controller is commonly used for recreational RC planes and helicopters, allowing for ranges of over 100ft of uninterrupted control. The FS-TH9X reciever is hooked up through 3 channels to the Arduino board, allowing the user to move two joysticks through their entire range of motion to control lift, thrust, and turning. Vertical movement of the joysticks manipulates the speed of the lift and thrust fans, while horizontal movement is connected to a servo motor. This servo in response turns a plate to redirect a percentage of the air used for lift into the side ducts, turning the hovercraft without the manipulation of any forwards thrust. 
